//
// Created by 26413 on 2025/10/19.
//
#pragma once
#include "buttons_page.h"
#include "common_pages.h"
#include "ui.h"

void PageButtons::button_click_back(lv_event_t *e) {
    PagesManager *pm = static_cast<PagesManager *>(lv_event_get_user_data(e));
    Serial.println("button click");
    pm->navigate_back();
}


PageButtons::PageButtons(lv_obj_t *screen, PagesManager &pm) : Page(screen) {
    // this->manager = pm;
    // lv_keyboard_set_textarea(uic_Keyboard3, uic_TextArea2);
    // lv_keyboard_set_popovers(uic_Keyboard3, true);
    // lv_obj_add_event_cb(uic_Keyboard3, keyboard_ready, LV_EVENT_READY, &pm);
    Serial.println("PageButtons init");
    lv_obj_add_event_cb(uic_ButtonBack, button_click_back, LV_EVENT_CLICKED, &pm);
}

void PageButtons::on_page_show() {
    Serial.println("PageButtons on_page_show");
    // lv_textarea_set_text(uic_TextArea2, "");
}

void PageButtons::on_page_hide() {
    Serial.println("PageButtons on_page_hide");
}

void PageButtons::page_loop() {
}
