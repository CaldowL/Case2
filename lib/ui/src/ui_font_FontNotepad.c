/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --font F:/Projects/SquareLine/DesktopScreen/assets/HarmonyOS_Sans_SC_Regular.ttf -o F:/Projects/SquareLine/DesktopScreen/assets\ui_font_FontNotepad.c --format lvgl -r 0x20-0x7f --symbols 音乐播放器歌曲 --no-compress --no-prefilter
 ******************************************************************************/

#include "ui.h"

#ifndef UI_FONT_FONTNOTEPAD
#define UI_FONT_FONTNOTEPAD 1
#endif

#if UI_FONT_FONTNOTEPAD

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xaa, 0xaa, 0x83, 0xc0,

    /* U+0022 "\"" */
    0x99, 0x99,

    /* U+0023 "#" */
    0x8, 0x86, 0x61, 0x99, 0xff, 0x11, 0xc, 0xc3,
    0x30, 0x88, 0xff, 0x88, 0x86, 0x61, 0x10,

    /* U+0024 "$" */
    0x10, 0x20, 0xe3, 0xe9, 0x72, 0x24, 0x38, 0x38,
    0x38, 0x4c, 0x99, 0x2f, 0x8e, 0x8, 0x10,

    /* U+0025 "%" */
    0x70, 0x48, 0x8c, 0x89, 0x88, 0x90, 0x73, 0x0,
    0x60, 0x6, 0x0, 0xce, 0x9, 0x11, 0x91, 0x31,
    0x12, 0xe,

    /* U+0026 "&" */
    0x1c, 0x8, 0x82, 0x20, 0x88, 0x36, 0x7, 0x3,
    0x89, 0xb6, 0xc5, 0xb0, 0xcc, 0x31, 0x9e, 0x3c,
    0xc0,

    /* U+0027 "'" */
    0xf0,

    /* U+0028 "(" */
    0x32, 0x44, 0xc8, 0x88, 0x88, 0x88, 0x44, 0x62,

    /* U+0029 ")" */
    0xc4, 0x22, 0x31, 0x11, 0x11, 0x11, 0x22, 0x64,

    /* U+002A "*" */
    0x25, 0x5c, 0xea, 0x90,

    /* U+002B "+" */
    0x10, 0x20, 0x40, 0x8f, 0xe2, 0x4, 0x8,

    /* U+002C "," */
    0xf6,

    /* U+002D "-" */
    0xfc,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0xc, 0x20, 0x86, 0x10, 0x43, 0x8, 0x21, 0x84,
    0x30,

    /* U+0030 "0" */
    0x38, 0x8a, 0x1c, 0x18, 0x30, 0x60, 0xc1, 0x83,
    0xd, 0x11, 0xc0,

    /* U+0031 "1" */
    0x37, 0xd1, 0x11, 0x11, 0x11, 0x11,

    /* U+0032 "2" */
    0x3c, 0xcb, 0x8, 0x10, 0x20, 0xc3, 0xc, 0x30,
    0x61, 0x87, 0xf0,

    /* U+0033 "3" */
    0x3c, 0x66, 0x42, 0x2, 0x6, 0x1c, 0x2, 0x1,
    0x1, 0xc1, 0x62, 0x3c,

    /* U+0034 "4" */
    0x8, 0x18, 0x10, 0x30, 0x20, 0x64, 0x44, 0xc4,
    0xff, 0x4, 0x4, 0x4,

    /* U+0035 "5" */
    0x7e, 0xc1, 0x82, 0x7, 0x88, 0x80, 0x81, 0x2,
    0x85, 0x11, 0xc0,

    /* U+0036 "6" */
    0x8, 0x30, 0xc1, 0x7, 0x88, 0xa0, 0xc1, 0x83,
    0x5, 0x11, 0xc0,

    /* U+0037 "7" */
    0xfe, 0xc, 0x10, 0x60, 0xc1, 0x6, 0x8, 0x10,
    0x60, 0x83, 0x0,

    /* U+0038 "8" */
    0x3c, 0xcd, 0xa, 0x16, 0x67, 0x91, 0xc1, 0x83,
    0x5, 0x11, 0xc0,

    /* U+0039 "9" */
    0x38, 0x8a, 0xc, 0x18, 0x28, 0xcf, 0x6, 0x18,
    0x30, 0xc1, 0x0,

    /* U+003A ":" */
    0xf0, 0x3, 0xc0,

    /* U+003B ";" */
    0xf0, 0x3, 0xd8,

    /* U+003C "<" */
    0x3, 0xe, 0x38, 0xe0, 0xe0, 0x3c, 0xf, 0x1,

    /* U+003D "=" */
    0xfe, 0x0, 0x7, 0xf0,

    /* U+003E ">" */
    0x80, 0xf0, 0x1c, 0x7, 0xe, 0x38, 0xe0, 0x80,

    /* U+003F "?" */
    0x7b, 0x38, 0x41, 0x8, 0x63, 0x8, 0x20, 0x0,
    0xc, 0x30,

    /* U+0040 "@" */
    0xf, 0xc0, 0x60, 0xc2, 0x1, 0x91, 0xd2, 0xc4,
    0xc6, 0x21, 0x18, 0x84, 0x62, 0x11, 0x88, 0x46,
    0x13, 0x2c, 0x73, 0x90, 0x0, 0x20, 0x0, 0x41,
    0x0, 0xfc, 0x0,

    /* U+0041 "A" */
    0xc, 0x1, 0x80, 0x38, 0xd, 0x1, 0x30, 0x22,
    0x8, 0x41, 0xfc, 0x60, 0x88, 0x19, 0x3, 0x60,
    0x20,

    /* U+0042 "B" */
    0xfc, 0x86, 0x82, 0x82, 0x86, 0xfc, 0x83, 0x81,
    0x81, 0x81, 0x82, 0xfc,

    /* U+0043 "C" */
    0x1e, 0x11, 0x90, 0x50, 0x8, 0x4, 0x2, 0x1,
    0x0, 0x80, 0x20, 0x88, 0xc3, 0xc0,

    /* U+0044 "D" */
    0xfc, 0x43, 0x20, 0x50, 0x38, 0xc, 0x6, 0x3,
    0x1, 0x81, 0xc0, 0xa1, 0x9f, 0x80,

    /* U+0045 "E" */
    0xff, 0x2, 0x4, 0x8, 0x1f, 0xa0, 0x40, 0x81,
    0x2, 0x7, 0xf0,

    /* U+0046 "F" */
    0xff, 0x2, 0x4, 0x8, 0x1f, 0xa0, 0x40, 0x81,
    0x2, 0x4, 0x0,

    /* U+0047 "G" */
    0x1f, 0x10, 0xd0, 0x10, 0x8, 0x4, 0x3e, 0x3,
    0x1, 0x80, 0xa0, 0x48, 0x63, 0xe0,

    /* U+0048 "H" */
    0x80, 0xc0, 0x60, 0x30, 0x18, 0xf, 0xfe, 0x3,
    0x1, 0x80, 0xc0, 0x60, 0x30, 0x10,

    /* U+0049 "I" */
    0xff, 0xf0,

    /* U+004A "J" */
    0x4, 0x10, 0x41, 0x4, 0x10, 0x41, 0x4, 0x1c,
    0xde,

    /* U+004B "K" */
    0x83, 0x43, 0x23, 0x11, 0x9, 0x5, 0x83, 0xe1,
    0x98, 0x84, 0x43, 0x20, 0xd0, 0x30,

    /* U+004C "L" */
    0x81, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x81,
    0x2, 0x7, 0xf0,

    /* U+004D "M" */
    0x80, 0x38, 0xf, 0x81, 0xf0, 0x7b, 0x1b, 0x32,
    0x66, 0xcc, 0x71, 0x84, 0x30, 0x6, 0x0, 0xc0,
    0x10,

    /* U+004E "N" */
    0x80, 0xe0, 0x78, 0x36, 0x1b, 0xc, 0xc6, 0x33,
    0xd, 0x86, 0xc1, 0xe0, 0x70, 0x10,

    /* U+004F "O" */
    0x1e, 0x8, 0x44, 0xa, 0x1, 0x80, 0x60, 0x18,
    0x6, 0x1, 0x80, 0x50, 0x22, 0x10, 0x78,

    /* U+0050 "P" */
    0xf9, 0xa, 0xc, 0x18, 0x30, 0xbe, 0x40, 0x81,
    0x2, 0x4, 0x0,

    /* U+0051 "Q" */
    0x1e, 0x4, 0x21, 0x2, 0x40, 0x28, 0x5, 0x0,
    0xa0, 0x14, 0x2, 0x80, 0x48, 0x10, 0x86, 0xf,
    0x80, 0x18, 0x1, 0x80, 0x18,

    /* U+0052 "R" */
    0xf8, 0x84, 0x82, 0x82, 0x82, 0x86, 0xfc, 0x88,
    0x8c, 0x86, 0x82, 0x83,

    /* U+0053 "S" */
    0x1e, 0x10, 0x90, 0x28, 0x6, 0x1, 0xf0, 0x1c,
    0x3, 0x0, 0xa0, 0x58, 0x43, 0xc0,

    /* U+0054 "T" */
    0xff, 0x84, 0x2, 0x1, 0x0, 0x80, 0x40, 0x20,
    0x10, 0x8, 0x4, 0x2, 0x1, 0x0,

    /* U+0055 "U" */
    0x80, 0xc0, 0x60, 0x30, 0x18, 0xc, 0x6, 0x3,
    0x1, 0x80, 0xe0, 0xd8, 0xc7, 0xc0,

    /* U+0056 "V" */
    0xc0, 0x50, 0x36, 0xd, 0x82, 0x21, 0x8c, 0x41,
    0x10, 0x4c, 0x1a, 0x2, 0x80, 0xe0, 0x10,

    /* U+0057 "W" */
    0xc1, 0x82, 0x83, 0x5, 0xe, 0x1b, 0x1c, 0x22,
    0x2c, 0x44, 0x49, 0x8d, 0x92, 0x1a, 0x34, 0x14,
    0x28, 0x38, 0x70, 0x60, 0xc0, 0x41, 0x80,

    /* U+0058 "X" */
    0x40, 0xd8, 0x23, 0x10, 0x4c, 0x1a, 0x3, 0x0,
    0xc0, 0x78, 0x13, 0xc, 0x66, 0x9, 0x3,

    /* U+0059 "Y" */
    0xc1, 0xa0, 0x98, 0xc4, 0x41, 0x40, 0xe0, 0x20,
    0x10, 0x8, 0x4, 0x2, 0x1, 0x0,

    /* U+005A "Z" */
    0xff, 0x2, 0x6, 0x4, 0xc, 0x18, 0x10, 0x30,
    0x20, 0x40, 0x40, 0xff,

    /* U+005B "[" */
    0xf2, 0x49, 0x24, 0x92, 0x49, 0x27,

    /* U+005C "\\" */
    0xc1, 0x6, 0x8, 0x20, 0xc1, 0x4, 0x18, 0x20,
    0x83,

    /* U+005D "]" */
    0xe4, 0x92, 0x49, 0x24, 0x92, 0x4f,

    /* U+005E "^" */
    0x10, 0x30, 0xe1, 0x62, 0x4c, 0x91, 0x80,

    /* U+005F "_" */
    0xfe,

    /* U+0060 "`" */
    0xc9, 0x80,

    /* U+0061 "a" */
    0x3d, 0x8c, 0x8, 0x17, 0xf8, 0x60, 0xc3, 0x7a,

    /* U+0062 "b" */
    0x80, 0x80, 0x80, 0x80, 0xbc, 0xc2, 0x81, 0x81,
    0x81, 0x81, 0x81, 0xc2, 0xbc,

    /* U+0063 "c" */
    0x3c, 0x8e, 0x4, 0x8, 0x10, 0x20, 0x23, 0x3c,

    /* U+0064 "d" */
    0x1, 0x1, 0x1, 0x1, 0x3d, 0x43, 0x81, 0x81,
    0x81, 0x81, 0x81, 0x43, 0x3d,

    /* U+0065 "e" */
    0x38, 0x8a, 0xc, 0x1f, 0xf0, 0x20, 0x23, 0x3c,

    /* U+0066 "f" */
    0x1c, 0x82, 0x8, 0xf8, 0x82, 0x8, 0x20, 0x82,
    0x8, 0x20,

    /* U+0067 "g" */
    0x3d, 0x43, 0x81, 0x81, 0x81, 0x81, 0x81, 0x43,
    0x3d, 0x1, 0x1, 0xc2, 0x3c,

    /* U+0068 "h" */
    0x81, 0x2, 0x4, 0xb, 0xd8, 0xe0, 0xc1, 0x83,
    0x6, 0xc, 0x18, 0x20,

    /* U+0069 "i" */
    0xf3, 0xff, 0xff,

    /* U+006A "j" */
    0x18, 0xc0, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31,
    0x8c, 0x7e,

    /* U+006B "k" */
    0x81, 0x2, 0x4, 0x8, 0xd1, 0x24, 0x58, 0xf1,
    0xb2, 0x64, 0x68, 0x60,

    /* U+006C "l" */
    0xff, 0xf8,

    /* U+006D "m" */
    0xb9, 0xd9, 0xce, 0x10, 0xc2, 0x18, 0x43, 0x8,
    0x61, 0xc, 0x21, 0x84, 0x20,

    /* U+006E "n" */
    0xbd, 0x8e, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x82,

    /* U+006F "o" */
    0x3c, 0x42, 0x81, 0x81, 0x81, 0x81, 0x81, 0x42,
    0x3c,

    /* U+0070 "p" */
    0xbc, 0xc2, 0x81, 0x81, 0x81, 0x81, 0x81, 0xc2,
    0xbc, 0x80, 0x80, 0x80, 0x80,

    /* U+0071 "q" */
    0x3d, 0x43, 0x81, 0x81, 0x81, 0x81, 0x81, 0x43,
    0x3d, 0x1, 0x1, 0x1, 0x1,

    /* U+0072 "r" */
    0xbc, 0x88, 0x88, 0x88, 0x80,

    /* U+0073 "s" */
    0x7a, 0x38, 0x38, 0x78, 0x38, 0x61, 0x78,

    /* U+0074 "t" */
    0x21, 0x9, 0xf2, 0x10, 0x84, 0x21, 0x8, 0x30,

    /* U+0075 "u" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x60, 0xe3, 0x7a,

    /* U+0076 "v" */
    0xc3, 0x43, 0x62, 0x26, 0x24, 0x34, 0x1c, 0x18,
    0x18,

    /* U+0077 "w" */
    0xc2, 0x14, 0x61, 0x47, 0x36, 0x52, 0x2d, 0x22,
    0x9e, 0x38, 0xc1, 0x8c, 0x10, 0xc0,

    /* U+0078 "x" */
    0x42, 0x66, 0x34, 0x18, 0x18, 0x18, 0x2c, 0x66,
    0x42,

    /* U+0079 "y" */
    0xc1, 0x43, 0x62, 0x62, 0x24, 0x34, 0x14, 0x18,
    0x18, 0x18, 0x10, 0x30, 0xe0,

    /* U+007A "z" */
    0xfc, 0x21, 0x84, 0x30, 0x86, 0x30, 0xfc,

    /* U+007B "{" */
    0x19, 0x8, 0x42, 0x10, 0x84, 0xc1, 0x8, 0x42,
    0x10, 0x83,

    /* U+007C "|" */
    0xff, 0xff,

    /* U+007D "}" */
    0xc1, 0x8, 0x42, 0x10, 0x84, 0x19, 0x8, 0x42,
    0x10, 0x98,

    /* U+007E "~" */
    0x62, 0xd2, 0x8e,

    /* U+4E50 "乐" */
    0x0, 0x38, 0xff, 0x82, 0x0, 0x8, 0x40, 0x21,
    0x1, 0x84, 0x7, 0xff, 0xc0, 0x40, 0x11, 0x20,
    0x44, 0xc3, 0x11, 0x98, 0x42, 0xc1, 0xc, 0x3c,
    0x0,

    /* U+5668 "器" */
    0x3e, 0x7c, 0x22, 0x44, 0x22, 0x44, 0x3e, 0x7c,
    0x0, 0x10, 0x1, 0x10, 0x7f, 0xfe, 0x6, 0x60,
    0x78, 0x1f, 0x3e, 0x7c, 0x22, 0x44, 0x22, 0x44,
    0x3e, 0x7c, 0x22, 0x44,

    /* U+64AD "播" */
    0x20, 0xc, 0x4f, 0xf8, 0x89, 0x37, 0x8a, 0x42,
    0x7f, 0xe4, 0x3a, 0xd, 0xd3, 0x77, 0xff, 0x22,
    0x44, 0x44, 0x88, 0x8f, 0xf1, 0x12, 0x22, 0x3f,
    0xdc, 0x40, 0x80,

    /* U+653E "放" */
    0x8, 0x20, 0x8, 0x20, 0x8, 0x60, 0x7f, 0x7e,
    0x10, 0x44, 0x10, 0xc4, 0x30, 0xc4, 0x3e, 0x4c,
    0x32, 0x68, 0x32, 0x28, 0x32, 0x38, 0x22, 0x10,
    0x22, 0x38, 0x66, 0x6c, 0x4f, 0xc7, 0x40, 0x0,

    /* U+66F2 "曲" */
    0x9, 0x0, 0x90, 0xff, 0xf8, 0x91, 0x89, 0x18,
    0x91, 0x89, 0x1f, 0xff, 0x89, 0x18, 0x91, 0x89,
    0x18, 0x91, 0xff, 0xf8, 0x1,

    /* U+6B4C "歌" */
    0xff, 0x63, 0xfd, 0x7, 0xa7, 0xd2, 0xb1, 0x7a,
    0xa8, 0xa, 0xa0, 0x2, 0x3f, 0xc8, 0x2, 0x21,
    0xe9, 0xc4, 0xa5, 0x1e, 0xb6, 0x2, 0x8c, 0x7c,
    0x10,

    /* U+97F3 "音" */
    0x2, 0x0, 0xc, 0x7, 0xff, 0x86, 0x18, 0x8,
    0x43, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x3f, 0xf0,
    0x80, 0x42, 0x1, 0xf, 0xfc, 0x20, 0x10, 0xff,
    0xc2, 0x1, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 69, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 60, .box_w = 2, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 5, .adv_w = 88, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 7, .adv_w = 165, .box_w = 10, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 22, .adv_w = 146, .box_w = 7, .box_h = 17, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 37, .adv_w = 197, .box_w = 12, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 55, .adv_w = 181, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 72, .adv_w = 48, .box_w = 1, .box_h = 4, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 73, .adv_w = 88, .box_w = 4, .box_h = 16, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 81, .adv_w = 88, .box_w = 4, .box_h = 16, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 89, .adv_w = 110, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 93, .adv_w = 146, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 100, .adv_w = 62, .box_w = 2, .box_h = 4, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 101, .adv_w = 125, .box_w = 6, .box_h = 1, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 102, .adv_w = 59, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 103, .adv_w = 100, .box_w = 6, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 112, .adv_w = 146, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 123, .adv_w = 146, .box_w = 4, .box_h = 12, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 129, .adv_w = 146, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 140, .adv_w = 146, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 152, .adv_w = 146, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 164, .adv_w = 146, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 175, .adv_w = 146, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 186, .adv_w = 146, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 197, .adv_w = 146, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 208, .adv_w = 146, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 219, .adv_w = 65, .box_w = 2, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 222, .adv_w = 68, .box_w = 2, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 225, .adv_w = 146, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 233, .adv_w = 146, .box_w = 7, .box_h = 4, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 237, .adv_w = 146, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 245, .adv_w = 111, .box_w = 6, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 255, .adv_w = 250, .box_w = 14, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 282, .adv_w = 170, .box_w = 11, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 299, .adv_w = 167, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 311, .adv_w = 167, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 325, .adv_w = 183, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 339, .adv_w = 153, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 350, .adv_w = 145, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 361, .adv_w = 179, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 375, .adv_w = 191, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 389, .adv_w = 67, .box_w = 1, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 391, .adv_w = 117, .box_w = 6, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 400, .adv_w = 174, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 414, .adv_w = 145, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 425, .adv_w = 221, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 442, .adv_w = 189, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 456, .adv_w = 195, .box_w = 10, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 471, .adv_w = 152, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 482, .adv_w = 195, .box_w = 11, .box_h = 15, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 503, .adv_w = 164, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 515, .adv_w = 147, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 529, .adv_w = 145, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 543, .adv_w = 187, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 557, .adv_w = 168, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 572, .adv_w = 247, .box_w = 15, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 595, .adv_w = 168, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 610, .adv_w = 158, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 624, .adv_w = 147, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 636, .adv_w = 88, .box_w = 3, .box_h = 16, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 642, .adv_w = 100, .box_w = 6, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 651, .adv_w = 88, .box_w = 3, .box_h = 16, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 657, .adv_w = 121, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 664, .adv_w = 106, .box_w = 7, .box_h = 1, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 665, .adv_w = 77, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 10},
    {.bitmap_index = 667, .adv_w = 140, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 675, .adv_w = 155, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 688, .adv_w = 126, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 696, .adv_w = 155, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 709, .adv_w = 140, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 717, .adv_w = 88, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 727, .adv_w = 155, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 740, .adv_w = 148, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 752, .adv_w = 62, .box_w = 2, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 755, .adv_w = 61, .box_w = 5, .box_h = 16, .ofs_x = -2, .ofs_y = -4},
    {.bitmap_index = 765, .adv_w = 134, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 777, .adv_w = 61, .box_w = 1, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 779, .adv_w = 219, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 792, .adv_w = 148, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 800, .adv_w = 151, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 809, .adv_w = 155, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 822, .adv_w = 155, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 835, .adv_w = 96, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 840, .adv_w = 116, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 847, .adv_w = 94, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 855, .adv_w = 149, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 863, .adv_w = 132, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 872, .adv_w = 199, .box_w = 12, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 886, .adv_w = 127, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 895, .adv_w = 133, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 908, .adv_w = 121, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 915, .adv_w = 94, .box_w = 5, .box_h = 16, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 925, .adv_w = 47, .box_w = 1, .box_h = 16, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 927, .adv_w = 94, .box_w = 5, .box_h = 16, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 937, .adv_w = 146, .box_w = 8, .box_h = 3, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 940, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 965, .adv_w = 256, .box_w = 16, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 993, .adv_w = 256, .box_w = 15, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1020, .adv_w = 256, .box_w = 16, .box_h = 16, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1052, .adv_w = 256, .box_w = 12, .box_h = 14, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 1073, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1098, .adv_w = 256, .box_w = 14, .box_h = 15, .ofs_x = 1, .ofs_y = -1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {
    0x0, 0x818, 0x165d, 0x16ee, 0x18a2, 0x1cfc, 0x49a3
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 20048, .range_length = 18852, .glyph_id_start = 96,
        .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 7, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 0, 0, 1, 0, 0, 0, 0,
    1, 2, 3, 0, 4, 0, 4, 0,
    5, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 4,
    6, 7, 8, 9, 10, 7, 11, 12,
    13, 14, 14, 15, 16, 17, 14, 14,
    7, 18, 0, 19, 20, 21, 15, 5,
    22, 23, 24, 25, 2, 8, 3, 0,
    0, 0, 26, 27, 28, 29, 30, 31,
    32, 26, 0, 33, 34, 29, 26, 26,
    27, 27, 0, 35, 36, 37, 32, 38,
    38, 39, 38, 40, 2, 0, 3, 4,
    0, 0, 0, 0, 0, 0, 0
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 1, 0, 2, 0, 0, 0, 0,
    2, 0, 3, 0, 4, 5, 4, 5,
    6, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 4, 0, 0,
    7, 8, 6, 9, 8, 9, 9, 9,
    8, 9, 9, 10, 9, 9, 9, 9,
    8, 9, 8, 9, 11, 12, 13, 14,
    15, 16, 17, 18, 0, 14, 3, 0,
    5, 0, 19, 20, 21, 21, 21, 22,
    21, 20, 0, 23, 20, 20, 24, 24,
    21, 0, 21, 24, 25, 26, 27, 28,
    28, 29, 28, 30, 0, 0, 3, 4,
    0, 0, 0, 0, 0, 0, 0
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, 0, 0, 0, 0, 0, 4, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 5, 0, 5, 5, 3,
    0, 4, 0, 0, 17, 0, 0, 6,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 8, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -14, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -10, 5, 5, -10, -35, -22, 6, -8,
    0, -29, -2, 5, 0, 0, 0, 0,
    0, 0, -18, 0, -17, -5, 0, -10,
    -14, 0, -10, -10, -13, -13, 0, 0,
    0, -8, -24, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -6, 0, 0,
    -11, -8, 0, 0, 0, -10, 0, -8,
    0, -8, -5, -8, -13, -6, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -10, -30, 0, -15, 8, 0,
    -17, -8, 0, 0, 0, -20, -3, -22,
    -16, 0, -27, 5, 0, 0, -3, 0,
    0, 0, 0, 0, 0, -9, 0, 0,
    0, -3, 0, 0, 0, -3, 0, 0,
    0, 4, 0, -9, 0, -11, -3, 0,
    -14, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 3,
    0, -8, 7, 0, 8, -4, 0, 0,
    0, 1, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -6, 0, 0, 0, 0, 0, 0,
    3, 0, 2, -3, 0, 3, 0, 0,
    0, -3, 0, 0, -3, 0, -3, 0,
    -3, -4, 0, 0, -2, -3, -3, -5,
    -2, 0, -3, 7, 0, 2, -34, -14,
    10, -1, 0, -36, 0, 5, 0, 0,
    0, 0, 0, 0, -11, 0, -8, -3,
    0, -5, 0, -4, 0, -5, -10, -7,
    0, 0, 0, 0, 5, 0, 2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -7, -3, 0, 0, 0, -8, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -10, 0, 0, -28, 5, 0,
    0, -14, -3, 0, -3, 0, -6, 0,
    0, 0, 0, 0, -6, 0, -8, -10,
    0, -3, -3, -8, -10, -16, -8, 0,
    -13, -26, 0, -23, 7, 0, -18, -13,
    0, 4, -3, -33, -11, -38, -27, 0,
    -45, 0, -2, 0, -6, -5, 0, -1,
    0, -7, -8, -24, 0, 0, -3, 3,
    0, 3, -37, -20, 3, 0, 0, -41,
    0, 0, 0, 0, -1, -5, 0, -8,
    -8, 0, -8, 0, 0, 0, 0, 0,
    0, 3, 0, 0, 0, -2, 0, -3,
    11, 0, -1, -3, 0, 0, 2, -2,
    -3, -6, -3, 0, -11, 0, 0, 0,
    -3, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    2, 0, 0, 0, 6, 0, 0, -3,
    0, 0, -5, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -8, 8, 0, -20, -28, -20, 8, -8,
    0, -36, 0, 5, 0, 5, 5, 0,
    0, 0, -29, 0, -28, -12, 0, -23,
    -29, -9, -21, -27, -26, -22, -3, 5,
    0, -5, -19, -16, 0, -5, 0, -17,
    0, 5, 0, 0, 0, 0, 0, 0,
    -19, 0, -15, -4, 0, -10, -10, 0,
    -7, -5, -8, -8, 0, 0, 5, -23,
    3, 0, 4, -8, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -6, 0,
    -8, 0, 0, -4, -4, -7, -7, -15,
    0, 0, -8, 4, 5, -18, -34, -27,
    2, -13, 0, -34, -5, 0, 0, 0,
    0, 0, 0, 0, -28, 0, -26, -12,
    0, -20, -23, -7, -18, -17, -15, -19,
    0, 0, 3, -13, 5, 0, 2, -8,
    0, 0, -3, 0, 0, 0, 0, 0,
    0, 0, -2, 0, -4, 0, 0, 0,
    0, 0, 0, -8, 0, 0, 0, -11,
    0, 0, 0, 0, -7, 0, 0, 0,
    0, -21, 0, -18, -16, -2, -24, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, 0, 0, -13, 0, -3,
    -8, 0, -10, 0, 0, 0, 0, -28,
    0, -17, -15, -8, -26, 0, -3, 0,
    0, -2, 0, 0, 0, -1, 0, -4,
    -6, -6, 0, 1, 0, 5, 6, 0,
    -3, 0, 0, 0, 0, -20, 0, -12,
    -8, 5, -18, 0, 1, 0, -1, 3,
    0, 0, 0, 5, 0, 0, 2, 3,
    0, 0, 4, 0, 0, 0, 3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 4, 0, 0, -6, 0, 0, 0,
    0, -18, 0, -14, -11, -3, -20, 0,
    0, 0, 0, 0, 0, 0, 3, 0,
    0, 1, -1, 0, 0, 10, 0, -3,
    -19, 0, 10, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -7, 0,
    -7, 0, 0, 0, 0, 3, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -6, 0, 0, 0, 0, -23, 0, -10,
    -10, 0, -20, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 8, 0,
    0, 0, 0, 0, 0, 0, -5, 0,
    0, -6, 7, 0, -12, 0, 0, 0,
    0, -24, 0, -15, -13, 0, -20, 0,
    -8, 0, -6, 0, 0, 0, -3, 0,
    -2, 0, 0, 0, 0, 5, 0, 2,
    -26, -9, -7, 0, 0, -28, 0, 0,
    0, -9, 0, -10, -17, 0, -11, 0,
    -8, 0, 0, 0, -1, 7, 0, 0,
    0, 0, 0, -8, 0, 0, 0, 0,
    -7, 0, 0, 0, 0, -26, 0, -17,
    -12, 0, -26, 0, 0, 0, 0, 0,
    0, 0, 2, 0, 0, -1, 0, 3,
    0, -2, 2, -1, 7, 0, -6, 0,
    0, 0, 0, -19, 0, -10, 0, 0,
    -16, 0, 0, 0, -2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -23, -9, -6, 0, 0, -19,
    0, -27, 0, -10, -5, -15, -17, 0,
    -4, 0, -4, 0, 0, 0, -2, 0,
    0, 0, 0, 0, 0, 0, 0, -5,
    3, 0, -11, 0, 0, 0, 0, -26,
    0, -13, -8, 0, -15, 0, -4, 0,
    -6, 0, 0, 0, 0, 3, 0, 0,
    0, 0, 0, 0, 0, 0, 3, 0,
    -7, 0, 0, 0, 0, -26, 0, -13,
    -7, 0, -18, 0, -4, 0, -6, 0,
    0, 0, 0, 0, 0, 0, 0, 0
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 40,
    .right_class_cnt     = 30,
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 1,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_FontNotepad = {
#else
lv_font_t ui_font_FontNotepad = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 19,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_FONTNOTEPAD*/

