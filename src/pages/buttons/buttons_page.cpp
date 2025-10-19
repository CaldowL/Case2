//
// Created by 26413 on 2025/10/19.
//
#pragma once
#include <ArduinoJson.h>

#include "buttons_page.h"
#include "common_pages.h"
#include "ui.h"


void PageButtons::button_click_back(lv_event_t *e) {
    PagesManager *pm = static_cast<PagesManager *>(lv_event_get_user_data(e));
    Serial.println("button click");
    pm->navigate_back();
}

void PageButtons::button_click_player(lv_event_t *e) {
    PagesManager *pm = static_cast<PagesManager *>(lv_event_get_user_data(e));
    Serial.println("button click");
    pm->navigate_to(pagePlayer, true);
}


void PageButtons::button_click_exec(lv_event_t *e) {
    const char *msg = (const char *) lv_event_get_user_data(e);
    JsonDocument doc;
    doc["action"] = "app_exec";
    doc["type"] = "request";
    doc["command"] = msg;
    String jsonStr;
    serializeJson(doc, jsonStr);
    Serial.println(jsonStr);
}


PageButtons::PageButtons(lv_obj_t *screen, PagesManager &pm) : Page(screen) {
    // this->manager = pm;
    // lv_keyboard_set_textarea(uic_Keyboard3, uic_TextArea2);
    // lv_keyboard_set_popovers(uic_Keyboard3, true);
    // lv_obj_add_event_cb(uic_Keyboard3, keyboard_ready, LV_EVENT_READY, &pm);
    Serial.println("PageButtons init");
    lv_obj_add_event_cb(uic_ButtonBack, button_click_back, LV_EVENT_CLICKED, &pm);
    lv_obj_add_event_cb(uic_ButtonNotepad, button_click_exec, LV_EVENT_CLICKED, (void *) "notepad");
    lv_obj_add_event_cb(uic_ButtonCacl, button_click_exec, LV_EVENT_CLICKED, (void *) "cacl");
    lv_obj_add_event_cb(uic_ButtonPlayer, button_click_player, LV_EVENT_CLICKED, &pm);
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

void PageButtons::handle_msg(String msg) {
    Serial.println("handle_msg recv");
}
