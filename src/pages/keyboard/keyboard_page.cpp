//
// Created by 26413 on 25-8-24.
//
#pragma once

#include "common_pages.h"
#include "ui.h"

void keyboard_ready(lv_event_t *e) {
    // PagesManager *pm = static_cast<PagesManager *>(lv_event_get_user_data(e));
    // const char *s = lv_textarea_get_text(uic_TextArea2);
    // Serial.println(s);
    // pm->navigate_back(s, false);
}

PageKeyBoard::PageKeyBoard(lv_obj_t *screen, PagesManager &pm): Page(screen) {
    // this->manager = pm;
    // lv_keyboard_set_textarea(uic_Keyboard3, uic_TextArea2);
    // lv_keyboard_set_popovers(uic_Keyboard3, true);
    // lv_obj_add_event_cb(uic_Keyboard3, keyboard_ready, LV_EVENT_READY, &pm);
}

void PageKeyBoard::on_page_show() {
    // Serial.println("PageMain on_page_show");
    // lv_textarea_set_text(uic_TextArea2, "");
}

void PageKeyBoard::on_page_hide() {
    Serial.println("PageMain on_page_hide");
}

void PageKeyBoard::page_loop() {
}
