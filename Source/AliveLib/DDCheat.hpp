#pragma once

#include "FunctionFwd.hpp"
#include "BaseGameObject.hpp"
#include "Game.hpp"
#include "Input.hpp"
#include "Function.hpp"
#include "BaseAliveGameObject.hpp"

void DDCheat_ForceLink();

struct DDCheatProperty
{
    const char * Name;
    int Unknown;
    int * ValuePtr;
};
ALIVE_ASSERT_SIZEOF(DDCheatProperty, 12);

class DDCheat : public BaseGameObject
{
public:
    virtual void VDestructor(signed int flags);
    virtual void VUpdate() override;

    DDCheat();
    EXPORT DDCheat* ctor_4153C0();
    EXPORT void dtor_415530();
    EXPORT void dtor_415500(signed int flags);

    EXPORT static void AddPropertyEntry_004162C0(const char *text, int unknown, int *valuePtr);
    static EXPORT void CC ClearProperties_415390();
    static EXPORT void DebugStr_4F5560(const char *pFormatStr, ...);

    EXPORT void Menu_Teleport_415E20();
    EXPORT void Menu_Movies_416000();

public:
    EXPORT void Update_415780();
public:
    int field_20;
    __int16 field_24_fn_idx;
    __int16 field_26_next_fn_idx;
    int field_28;
    int field_2C;
    __int16 field_30;
    __int16 field_32;
    int field_34;
    int field_38_input_pressed;
    __int16 field_3C_flags;
    __int16 field_3E;
};
ALIVE_ASSERT_SIZEOF(DDCheat, 0x40);
