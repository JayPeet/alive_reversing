#include "stdafx.h"
#include "VGA.hpp"
#include "bmp.hpp"
#include "DDraw.hpp"
#include "Function.hpp"

void VGA_ForceLink() {}

#ifdef BEHAVIOUR_CHANGE_FORCE_WINDOW_MODE
EXPORT signed int CC VGA_FullScreenSet_4F31F0(char /*bFullScreen*/)
{
    LOG_INFO("Stub"); // Can't be empty func otherwise NOT_IMPLEMENT'ed searcher will look into the next function
    return 0;
}
#endif

ALIVE_VAR(1, 0xBD0BFA, bool, sVGA_own_surfaces_BD0BFA, false);
ALIVE_VAR(1, 0xBC0BB8, bool, sVGA_Inited_BC0BB8, false);
ALIVE_VAR(1, 0xBD0BD0, Bitmap, sVGA_Bmp0_BD0BD0, {});
ALIVE_VAR(1, 0xBD2A20, Bitmap, sVGA_Bmp1_BD2A20, {});
ALIVE_VAR(1, 0xBD2A40, Bitmap, sVGA_Bmp2_BD2A40, {});

EXPORT void CC VGA_Shutdown_4F3170()
{
    if (sDD_Surface1_BBC3C8)
    {
        if (!sVGA_own_surfaces_BD0BFA)
        {
            sDD_Surface1_BBC3C8 = nullptr;
            sDD_Surface2_BBC3CC = nullptr;
        }

        if (sVGA_Bmp0_BD0BD0.field_0_pSurface)
        {
            Bmp_Free_4F1950(&sVGA_Bmp0_BD0BD0);
        }

        DD_Shutdown_4F0790(1);
        sDD_Surface1_BBC3C8 = nullptr;
        sDD_Surface2_BBC3CC = nullptr;
    }
    
    sVGA_Inited_BC0BB8 = false;

    memset(&sVGA_Bmp1_BD2A20, 0, sizeof(sVGA_Bmp1_BD2A20));
    memset(&sVGA_Bmp2_BD2A40, 0, sizeof(sVGA_Bmp2_BD2A40));
}
