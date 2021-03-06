project(AliveLib VERSION 0.1 LANGUAGES CXX)

add_library(AliveLib
    ExportHooker.hpp
    stdafx.cpp
    stdafx.h
    logger.hpp
    Function.cpp
    Function.hpp
    Input.cpp
    Input.hpp
    DynamicArray.cpp
    DynamicArray.hpp
    Sys.cpp
    Sys.hpp
    VGA.cpp
    VGA.hpp
    DDraw.cpp
    DDraw.hpp
    Error.cpp
    Error.hpp
    Psx.cpp
    Psx.hpp
    PsxRender.cpp
    PsxRender.hpp
    Math.cpp
    Math.hpp
    Midi.cpp
    Midi.hpp
    GameSpeak.hpp
    GameSpeak.cpp
    DDCheat.hpp
    DDCheat.cpp
    Quicksave.cpp
    Quicksave.hpp
    bmp.cpp
    bmp.hpp
    Sfx.hpp
    Sfx.cpp
    Game.cpp
    Game.hpp
    Sound.cpp
    Sound.hpp
    stdlib.cpp
    stdlib.hpp
    ResourceManager.cpp
    ResourceManager.hpp
    BaseGameObject.cpp
    BaseGameObject.hpp
    BaseAliveGameObject.cpp
    BaseAliveGameObject.hpp
    BaseAnimatedWithPhysicsGameObject.cpp
    BaseAnimatedWithPhysicsGameObject.hpp
    CreditsController.cpp
    CreditsController.hpp
    PauseMenu.cpp
    PauseMenu.hpp
    Primitives.cpp
    Primitives.hpp
    Map.cpp
    Map.hpp
    PsxDisplay.cpp
    PsxDisplay.hpp
    ScreenManager.cpp
    ScreenManager.hpp
    vlctable.hpp
    Animation.cpp
    Animation.hpp
    BackgroundAnimation.cpp
    BackgroundAnimation.hpp
    PathData.cpp
    PathData.hpp
    LvlArchive.cpp
    LvlArchive.hpp
    Io.cpp
    Io.hpp
    FixedPoint.hpp
    FixedPoint.cpp
    Resources.hpp
    Resources.cpp
    Font.hpp
    Font.cpp
    RenderingTestTimData.hpp
    DebugHelpers.hpp
    DebugHelpers.cpp
    Events.cpp
    Events.hpp
    SwitchStates.hpp
    SwitchStates.cpp
    StringFormatters.hpp
    StringFormatters.cpp
    Abe.hpp
    Abe.cpp
    MusicController.hpp
    MusicController.cpp
    BackgroundMusic.hpp
    BackgroundMusic.cpp
    Path.hpp
    Path.cpp
    QuikSave.hpp
    QuikSave.cpp
    Factory.hpp
    Factory.cpp
    MainMenu.hpp
    MainMenu.cpp
    LCDScreen.hpp
    LCDScreen.cpp
    StatsSign.hpp
    StatsSign.cpp
    ObjectIds.hpp
    ObjectIds.cpp
    VRam.hpp
    VRam.cpp
    Collisions.hpp
    Collisions.cpp
    CheatController.hpp
    CheatController.cpp
    Compression.hpp
    Compression.cpp
    FG1.hpp
    FG1.cpp
    BitField.hpp
    WinMain.cpp
    WinMain.hpp
    Slurg.cpp
    Slurg.hpp)

target_include_directories(AliveLib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
    PRIVATE src ${CMAKE_BINARY_DIR})

target_compile_definitions(AliveLib PRIVATE "_CRT_SECURE_NO_WARNINGS")
target_compile_definitions(AliveLib PRIVATE "BEHAVIOUR_CHANGE_FORCE_WINDOW_MODE")

if (MSVC)
    target_compile_options(AliveLib PRIVATE /W4 /wd4996)

    set_target_properties(AliveLib PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS /functionpadmin:16")
    set_target_properties(AliveLib PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:WINDOWS /functionpadmin:16")
endif()


SET_TARGET_PRECOMPILED_HEADER(AliveLib stdafx.h stdafx.cpp)

target_compile_features(AliveLib
    PRIVATE cxx_strong_enums
    PRIVATE cxx_static_assert
    PRIVATE cxx_lambdas
    PRIVATE cxx_nullptr
    PRIVATE cxx_range_for
    PRIVATE cxx_decltype
    PRIVATE cxx_auto_type
    PRIVATE cxx_variadic_templates)

target_link_libraries(AliveLib
    Detours
    EasyLogging++
    googletest
    Winmm
    dsound
    xinput
    )

export(TARGETS AliveLib FILE AliveLib.cmake)
