SET(SOURCES ui_Screen1.c
    ui_ScreenButtons.c
    ui_ScreenPlayer.c
    ui.c
    ui_comp_hook.c
    ui_helpers.c
    ui_img_icon_noptepad_png.c
    ui_img_icon_cacl_png.c
    ui_img_icon_player_png.c
    ui_img_icon_back_png.c
    ui_img_1156012293.c
    ui_img_827955121.c
    ui_img_1676589243.c
    ui_img_853450402.c
    fonts/ui_font_Font15.c
    fonts/ui_font_FontNotepad.c
    fonts/ui_font_FontNotepad20.c
    fonts/ui_font_FontTime36.c)

add_library(ui ${SOURCES})
