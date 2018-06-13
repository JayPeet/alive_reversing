#pragma once

#include "Function.hpp"

#define DIRECTINPUT_VERSION 0x700
#include <dinput.h>
#define DIRECTDRAW_VERSION 0x700
#include <ddraw.h>
#define DIRECT3D_VERSION 0x700
#include "d3d.h"

void BmpTests();

struct Bitmap
{
    IDirectDrawSurface* field_0_pSurface;
    void* field_4_pLockedPixels;
    int field_8_width;
    int field_C_height;
    int field_10_locked_pitch;
    char field_14_bpp;
    char field_15_pixel_format;
    __int16 field_16_pad;
    int field_18_create_flags;
};
ALIVE_ASSERT_SIZEOF(Bitmap, 0x1C);

signed int CC BMP_Blt_4F1E50(Bitmap* pDstBmp, int xPos, int yPos, Bitmap* pSrcBmp, LPRECT pRect, int flags);