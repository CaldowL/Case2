#pragma once
#include "pages/buttons/buttons_page.h"
#include "pages/keyboard/keyboard_page.h"
#include "pages/main/main_page.h"
#include "pages/player/player_page.h"

extern PageMain *pageMain;
extern PageKeyBoard *pageKeyBoard;
extern PageButtons *pageButtons;
extern PagePlayer *pagePlayer;


extern lv_obj_t *messageBox;

extern int Volume;

extern PagesManager pm;

extern const String baseUrl;
