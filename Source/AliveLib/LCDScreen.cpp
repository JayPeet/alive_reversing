#include "stdafx.h"
#include "LCDScreen.hpp"
#include "Function.hpp"
#include "stdlib.hpp"
#include "SwitchStates.hpp"
#include "DebugHelpers.hpp"
#include "StringFormatters.hpp"
#include "Midi.hpp"
#include "Events.hpp"
#include "Sfx.hpp"
#include "VRam.hpp"
#include "Game.hpp"

unsigned char sLCDScreen_Palette[] =
{
    0x00, 0x00, 0x01, 0x80, 0x01, 0x84, 0x20, 0x84, 0x21, 0x80,
    0x20, 0x84, 0x21, 0x84, 0x65, 0xCE, 0x65, 0x8C, 0x8C, 0xB1,
    0x60, 0x8E, 0x64, 0xCE, 0x65, 0xCE, 0xD7, 0x98, 0x14, 0xA1,
    0x18, 0xD8
};

unsigned char sLCDScreen_Palette2[] =
{
    0x00, 0x00, 0x01, 0x80, 0x01, 0x84, 0x20, 0x84, 0x21, 0x80,
    0x20, 0x84, 0x21, 0x84, 0x05, 0x84, 0x65, 0x8C, 0x8C, 0xB1,
    0x13, 0x94, 0x64, 0xCE, 0x65, 0xCE, 0xD7, 0x98, 0x14, 0xA1,
    0x18, 0xD8
};

// TODO: Remove spaces and add them at runtime.
const char *sLCDMessageTable_555768[101] =
{
    "",
    "                               SoulStorm Mining Company is an equal opportunity employer.",
    "                               Work! Do it!",
    "                               You break it, you bought it.",
    "                               Drink cool, clear, depressing SoulStorm Brew.",
    "                               Depressed ... ? Then work harder!",
    "                               Need a (permanent) vacation?  Consult a Slig supervisor.",
    "                               Smuggling bones in your pants is grounds for immediate termination!",
    "                               Molluck's MouthLube --  Say it, don't spray it!",
    "                               FeeCo Food Extractors...Eat Twice...Feels Nice...One Price!",
    "                               SoulStorm Brew...Our spew is your brew!",
    "                               Scrab Cakes  MMMM MMMM  They'll cost ya an arm and a leg!",
    "                               New and improved SoulStorm Brew...Twice the flavor...twice the bones...twice the price!",
    "                               If yer blue, drink Brew!",
    "                               SoulStorm Brew: Just drink it!",
    "                               Feeco Depot: Where will we send you today?",
    "                               Wanted: Bullet catchers and grenade testers. Apply in person to General Dripik. Qualified recruits only.",
    "                               AzGasCo: Growing one fart at a time.",
    "                               Find the secret prize inside every specially marked package of RuptureFarms mystery meat!",
    "                               New from RuptureFarms: Weenie babies! Sausage has never been this much fun!",
    "                               Wanted: Mudokon Fleech flusher. No experience necessary.",
    "                               Vykkers Labs. Molding the future out of you.",
    "                               Phlegs Bonepaste...good to the last glop.",
    "                               Moolah Ticker...SolstrmBrw UP...FeeCo UP Bonwrkz UP...Rptfrms DOWN! DOWN! DOWN!",
    "                               Blowco Bonesaws. Perfect powder - every time.",
    "                               Keep yer employees in the dark with the all- new Eyestitch 2000. The ultimate blinding machine",
    "                               FeeCo FatVats. When you got serious fat, you need a serious vat.",
    "                               Vykkers Lab reports SoulStorm Brew totally safe! Dont think, drink!",
    "                               Legz Iz Uz : if you can find a better leg, buy it!",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "                               To enter the door, stand in front of it and press \x01.",
    "                               To enter the well, stand in front of it and press \x01.",
    "                               To hoist, stand under the falling debris and press \x01 (up arrow).",
    "                               To hop, press \x09.",
    "                               To sneak past the sleeping Slig, hold \x07 while you move.",
    "                               To pull the lever, stand next to it and press \x06.",
    "                               To use the ring, stand under it, and press \x01, just like a hoist.",
    "                               To ride the platform, stand in the center of it, and press \x01 (up).",
    "                               To enter the well, stand in front of it and press \x01.",
    "                               To deactivate a bomb, crouch next to it by pressing \x02.   Then carefully press \x06 when the bomb blinks green.  Press \x06 again to reactivate it.",
    "                               Sneak to shadows by holding \x07 while you move.   Stand still in shadows while Slig is facing you, or you will be seen.  Sneak behind Slig when it walks away from you.",
    "                               To get a rock from the rock sack, stand under it and press \x01.   To pick up a rock, crouch next to it and press \x06.   To throw the rock, hold \x08, then press any directional button.   Different directions will throw at different angles.",
    "                               Practice throwing here. You can stand on the arrow and hit every mine.   It is possible to throw while crouching.",
    "                               To alert a Mudokon, say hello by pressing \x0b.   Then, talk to Mudokons by pressing \x0b, \x0c, \x0d, \x0e, \x0f, \x10, \x11 or \x12.   Experiment!",
    "                               Possess Sligs by chanting.   Chant by holding \x13.",
    "                               To help Mudokons escape from slavery chant when you see a circle of birds.   To chant, hold \x13.",
    "                               To roll, first crouch by pressing \x02.   Then roll left or right by pressing \x03 or \x04.",
    "                               To walk, press \x03 (left) or \x04 (right). To run, hold \x05 while you move.",
    "                               To avoid the alarm, stand still when the Motion Detectors touch you.",
    "                               Use Slig to talk your way past the security door.",
    "                               Sligs can talk to Slogs.",
    "                               Use lever to operate bone saw.",
    "                               Lead Mudokons to bird portals, then chant to rescue them.  Chant by holding \x13.",
    "                               To turn the wheel, stand in front of it and press \x01.",
    "                               After saying hello to the Mudokon, tell it you are sorry by standing next to it and pressing \x11.",
    "                               Execute a roll while running by pressing \x0a while you run.",
    "                               Stand on top of the arrow and press \x02 (down arrow)",
    "                               Sligs ahead ... be quiet.",
    "                               Laughing gas makes Mudokons slap-happy.",
    "                               The only way to make a Mudokon calm down is to slap it.   To slap a Mudokon, stand next to it and press \x0f.",
    "                               Sneak behind the Slig as it walks away from you.",
    "                               You will need help to turn all the wheels at once.   Position a Mudokon in front of a wheel, then tell it to work by pressing \x0e.   You may need to slap the Mudokon to get it to calm down.",
    "                               If you sneak, any Mudokons following you will also sneak.",
    "                               Say hello to all the Mudokons at once by pressing \x10.   Then tell them to follow you by pressing \x0c.",
    "                               Try bouncing rocks off the wall.",
    "                               Blind Mudokons keep walking until you tell them to wait. Tell them to wait by pressing \x0d.",
    "                               Only a fool or a murderer would pull this lever.",
    "                               You can make a possessed Slig blast stuff in the foreground by pressing \x08 while holding \x02.",
    "                               Press \x09 to hop.",
    "                               To enter the mine car, stand in front of it and press \x01. To exit the mine car, press \x06. To make the mine car drop from a ceiling, press \x06.",
    "",
    "",
    "",
    "",
    "",
    "",
    "                               To run, hold \x05 while you move.",
    "                               If you are silent and still in shadows, you cannot be seen.",
    "",
    "",
    "",
    "",
};

void DumpLCDTextEntries()
{
    std::stringstream output;
    output << "const char *sLCDMessageTable_555768[101] =\n";
    output << "{\n";

    for (int i = 0; i < 101; i++)
    {
        auto escaped = EscapeUnknownCharacters(std::string(sLCDMessageTable_555768[i]));
        output << "\"" << escaped << "\",\n";
    }

    output << "};";

    std::ofstream fileOut("lcd_dump.h");
    fileOut << output.rdbuf();

    DEV_CONSOLE_MESSAGE_C("LCD Text Table DUMPED", 6, 0, 127, 0);
}

void LCDScreen_ForceLink() {
    //DumpLCDTextEntries();
}

LCDScreen * LCDScreen::ctor_460680(Path_LCDScreen * params, TlvItemInfoUnion itemInfo)
{
    BaseGameObject_ctor_4DBFA0(1, 0);
    SetVTable(this, 0x545AAC);

    field_C_objectId = itemInfo.all;

    field_2C0_tlv = params->field_0_mBase;

    field_2AA_message_1_id = params->field_10_message_1_id;
    field_2B0_message_2_id = params->field_16_message_2_id;
    field_2B2_swap_message_sets_switch_id = params->field_18_swap_message_sets_switch_id;
    field_2BC_tlv_item_info = itemInfo;

    if (!sFontType2LoadCount_5BC5E8)
    {
        sFont2Context_5BC5D8.LoadFontType_433400(2);
    }
    ++sFontType2LoadCount_5BC5E8;
    field_60_font.ctor_433590(60, sLCDScreen_Palette, &sFont2Context_5BC5D8);

    Pal_Allocate_483110(&field_98_pal_rect, 16);
    const PSX_RECT palSize = { field_98_pal_rect.x , field_98_pal_rect.y, 16, 1 };
    PSX_LoadImage16_4F5E20(&palSize, sLCDScreen_Palette2);

    if (SwitchStates_Get_466020(field_2B2_swap_message_sets_switch_id))
    {
        field_A0_message = sLCDMessageTable_555768[field_2B0_message_2_id];
    }
    else
    {
        field_A0_message = sLCDMessageTable_555768[field_2AA_message_1_id];
    }

    //field_A0_message = "                               THIS IS A TEST";

    String_FormatString_4969D0(field_A0_message, field_A8_message_buffer, 512, 1);
    field_A0_message = field_A8_message_buffer;
    field_A4_message_cutoff_ptr = nullptr;
    field_2AC_x_offset = 0;
    sFontDrawScreenSpace_5CA4B4 = 1;
    field_2AE_character_width = field_60_font.MeasureWidth_433630(*field_A0_message) + 2;
    sFontDrawScreenSpace_5CA4B4 = 0;
    field_2B4 = 0;
    field_2B6_message_rand_min = params->field_12_message_rand_min;
    field_6_flags.Set(BaseGameObject::eDrawable);
    field_2B8_message_rand_max = params->field_14_message_rand_max;
    field_2A8_play_sound_toggle = 0;
    gObjList_drawables_5C1124->Push_Back_40CAF0(this);

    return this;
}

void LCDScreen::Update_460A00()
{
    if (Event_Get_422C00(kEventDeathReset))
    {
        field_6_flags.Set(BaseGameObject::eDead);
    }

#if LCD_PS1_SPEED
    field_2AC_x_offset += 6;
#else
    field_2AC_x_offset += 3;
#endif

    if (field_2AC_x_offset > field_2AE_character_width)
    {
        field_2AC_x_offset -= field_2AE_character_width;
        char lastChar = *field_A0_message;
        field_A0_message++; // Offset char index

        if (lastChar == 0)
        {
            if (++field_2B4 == 1)
            {
                field_A0_message = sLCDMessageTable_555768[Math_RandomRange_496AB0(field_2B6_message_rand_min, field_2B8_message_rand_max)];
            }
            else
            {
                field_2B4 = 0;
                if (SwitchStates_Get_466020(field_2B2_swap_message_sets_switch_id))
                {
                    field_A0_message = sLCDMessageTable_555768[field_2B0_message_2_id];
                }
                else
                {
                    field_A0_message = sLCDMessageTable_555768[field_2AA_message_1_id];
                }
            }

            String_FormatString_4969D0(field_A0_message, field_A8_message_buffer, 512, 1);
            field_A0_message = field_A8_message_buffer;

            auto palSwap = field_98_pal_rect;
            field_98_pal_rect = field_60_font.field_28_palette_rect;
            field_60_font.field_28_palette_rect = palSwap;
        }

        sFontDrawScreenSpace_5CA4B4 = 1;
        field_2AE_character_width = field_60_font.MeasureWidth_433630(*field_A0_message) + 2;
        sFontDrawScreenSpace_5CA4B4 = 0;
    }

    auto screenLeft = field_2C0_tlv.field_8_top_left.field_0_x - pScreenManager_5BB5F4->field_20_pCamPos->field_0_x.GetExponent();
    auto screenRight = field_2C0_tlv.field_C_bottom_right.field_0_x - pScreenManager_5BB5F4->field_20_pCamPos->field_0_x.GetExponent();

    sFontDrawScreenSpace_5CA4B4 = 1;
    auto v14 = field_60_font.SliceText_433BD0(
        field_A0_message,
        (screenLeft * 0.575) - field_2AC_x_offset,
        FP_FromDouble(1.0),
        screenRight);
    sFontDrawScreenSpace_5CA4B4 = 0;
    if (v14 != field_A4_message_cutoff_ptr)
    {
        field_2A8_play_sound_toggle = !field_2A8_play_sound_toggle;
        field_A4_message_cutoff_ptr = v14;
        if (*v14 != ' ')
        {
            if (field_2A8_play_sound_toggle)
            {
                SFX_Play_46FA90(73u, 0, 0x10000);
            }
        }
    }
}

void LCDScreen::Render_460CB0(int ** ot)
{
    if (!word_5C1B66)
    {
        const auto camPos = pScreenManager_5BB5F4->field_20_pCamPos;
        const auto screenX = this->field_2C0_tlv.field_8_top_left.field_0_x - camPos->field_0_x.GetExponent();
        const auto screenY = ((this->field_2C0_tlv.field_8_top_left.field_2_y + this->field_2C0_tlv.field_C_bottom_right.field_2_y) / 2 - camPos->field_4_y.GetExponent()) - 7;
        const int screenXWorld = screenX / 0.575;
        const auto maxWidth = this->field_2C0_tlv.field_C_bottom_right.field_0_x - camPos->field_0_x.GetExponent();

        PSX_RECT clipRect = { 0,0,640,240 };

        Init_PrimClipper_4F5B80(&field_20_prim_clippers[0][gPsxDisplay_5C1130.field_C_buffer_index], &clipRect);
        OrderingTable_Add_4F8AA0(&ot[24], &field_20_prim_clippers[0][gPsxDisplay_5C1130.field_C_buffer_index].mBase);

        sFontDrawScreenSpace_5CA4B4 = 1;
        field_60_font.DrawString_4337D0(
            ot,
            field_A0_message,
            screenXWorld - this->field_2AC_x_offset,
            screenY,
            1,
            1,
            0,
            24,
            127,
            127,
            127,
            0,
            FP_FromDouble(1.0),
            maxWidth,
            sDisableFontFlicker_5C9304 != 0 ? 0 : 40);
        sFontDrawScreenSpace_5CA4B4 = 0;

        clipRect = { static_cast<short>(screenXWorld), static_cast<short>(screenY - 12), static_cast<short>((maxWidth - screenX) / 0.575), 48 };

        Init_PrimClipper_4F5B80(&field_20_prim_clippers[1][gPsxDisplay_5C1130.field_C_buffer_index], &clipRect);
        OrderingTable_Add_4F8AA0(&ot[24], &field_20_prim_clippers[1][gPsxDisplay_5C1130.field_C_buffer_index].mBase);

        pScreenManager_5BB5F4->InvalidateRect_40EC90(screenXWorld, screenY, clipRect.w, 24, pScreenManager_5BB5F4->field_3A_idx);
    }
}

void LCDScreen::vsub_460F10()
{
    field_6_flags.Set(BaseGameObject::eDead);
}

void LCDScreen::dtor_460920()
{
    SetVTable(this, 0x545AAC); // vTbl_LCDScreen_545AAC

    Pal_free_483390({ field_98_pal_rect.x, field_98_pal_rect.y }, field_98_pal_rect.w);

    gObjList_drawables_5C1124->Remove_Item(this);
    Path::TLV_Reset_4DB8E0(field_2BC_tlv_item_info.all, -1, 0, 0);

    if (!--sFontType2LoadCount_5BC5E8)
    {
        sFont2Context_5BC5D8.dtor_433510();
    }
    field_60_font.dtor_433540();
    BaseGameObject_dtor_4DBEC0();
}

void LCDScreen::vdtor_4608F0(signed int flags)
{
    dtor_460920();
    if (flags & 1)
    {
        Mem_Free_495540(this);
    }
}

void LCDScreen::VUpdate()
{
    Update_460A00();
}

void LCDScreen::VRender(int** pOrderingTable)
{
    Render_460CB0(pOrderingTable);
}

void LCDScreen::VDestructor(signed int flags)
{
    vdtor_4608F0(flags);
}

void LCDScreen::vnullsub_4DC0F0()
{
    vsub_460F10();
}
