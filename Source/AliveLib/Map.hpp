#pragma once

#include "FunctionFwd.hpp"
#include "FixedPoint.hpp"
#include "Psx.hpp"
#include "ResourceManager.hpp"

void Map_ForceLink();

EXPORT void CC static_map_init_4802D0();

struct Map_120
{
    BYTE** field_0_pPathRecs[30];
};
ALIVE_ASSERT_SIZEOF(Map_120, 120);

class BaseAliveGameObject;
class Camera;
struct PathData;
struct Path_TLV;

class Map
{
public:
    __int16 sCurrentLevelId_5C3030;
    __int16 sCurrentPathId_5C3032;
    __int16 sCurrentCamId_5C3034;
    __int16 field_6_state;
    __int16 field_8;

    __int16 field_A_5C303A_levelId;
    __int16 field_C_5C303C_pathId;
    __int16 field_E_cameraId;
    __int16 field_10_screen_change_effect;
    __int16 field_12_ticks;

    __int16 field_14_direction;
    __int16 field_16;

    BaseAliveGameObject *field_18_pAliveObj;

    __int16 field_1C;
    __int16 field_1E_door;
    __int16 field_20;
    __int16 field_22;

    FP_Point field_24_camera_offset;

    Camera* field_2C_5C305C_camera_array[5];
    Camera* field_40_stru_5[5];
    Map_120 field_54_path_res_array;

    __int16 field_CC;
    __int16 field_CE;

    __int16 field_D0_cam_x_idx;
    __int16 field_D2_cam_y_idx;

    const PathData* field_D4_ptr;
    BYTE* field_D8_restore_quick_save;


    EXPORT void sub_480B80();
    EXPORT void sub_480740(__int16 a2);
    EXPORT void sub_481610();
    EXPORT signed __int16 sub_4811A0(int level, int path, FP xpos, FP ypos);
    EXPORT void Init_4803F0(__int16 level, __int16 path, __int16 camera, __int16 a5, __int16 a6, __int16 a7);
    EXPORT void Shutdown_4804E0();
    EXPORT void Reset_4805D0();
    EXPORT void GoTo_Camera_481890();

    EXPORT void Get_map_size_480640(PSX_Point* pPoint);
    EXPORT void GetCurrentCamCoords_480680(PSX_Point* pPoint);
    EXPORT void Get_Abe_Spawn_Pos_4806D0(PSX_Point* pPoint);
    EXPORT __int16 Get_Path_Unknown_480710();
    EXPORT void Create_FG1s_480F10();

    EXPORT signed __int16 SetActiveCam_480D30(__int16 level, __int16 path, __int16 cam, __int16 a5, __int16 a6, __int16 a7);
    EXPORT static BaseGameObject* CC FMV_482650(BYTE** ppBits, Map* pMap, int lvlId);
    EXPORT Camera* Create_Camera_4829E0(__int16 xpos, __int16 ypos, int a4);
    EXPORT static void __stdcall Load_Path_Items_482C10(Camera* pCamera, __int16 loadMode);

    EXPORT static void CC LoadResource_4DBE00(const char* pFileName, int type, int resourceId, __int16 loadMode, __int16 bDontLoad = FALSE);
    EXPORT static void CC LoadResourcesFromList_4DBE70(const char* pFileName, ResourceManager::ResourcesToLoadList* pList, __int16 loadMode, __int16 bDontLoad = FALSE);
private:
    void CreateScreenTransistionForTLV(Path_TLV* pTlv);
    void sub_480B80_Common();
};
ALIVE_ASSERT_SIZEOF(Map, 0xDC);

ALIVE_VAR_EXTERN(Map, gMap_5C3030);
