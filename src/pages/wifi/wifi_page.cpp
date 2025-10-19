#pragma once
#include "ui.h"

#include "common_pages.h"
#include "utils.h"
#include "WiFi.h"

bool wifi_scanning = false;
vector<string> ssids;

string ssid;
string password;

void refresh_ssid_label() {
    // if (ssids.empty()) {
    //     return;
    // }
    // ssid = ssids[lv_roller_get_selected(uic_Roller2)];
    // lv_label_set_text(uic_Label3, ssid.c_str());
}

void roller_value_changed(lv_event_t *e) {
    Serial.println("roller_value_changed");
    refresh_ssid_label();
}


void begin_scan_wifi(lv_event_t *e) {
    // WiFi.scanNetworks(true);
    // wifi_scanning = true;
    // ssids.clear();
    // lv_obj_clear_flag(uic_Spinner2, LV_OBJ_FLAG_HIDDEN);
}

void display_scanned_wifi() {
    // lv_obj_add_flag(uic_Spinner2, LV_OBJ_FLAG_HIDDEN);
    // lv_roller_set_options(uic_Roller2, join_string(ssids).c_str(), LV_ROLLER_MODE_NORMAL);
    //
    // lv_obj_clear_flag(uic_Label3, LV_OBJ_FLAG_HIDDEN);
    // lv_obj_clear_flag(uic_TextArea3, LV_OBJ_FLAG_HIDDEN);
    // lv_obj_clear_flag(uic_Button3, LV_OBJ_FLAG_HIDDEN);
    // refresh_ssid_label();
}

void receive_password(string password_) {
    // password = password_;
    // lv_textarea_set_text(uic_TextArea3, password.c_str());
}

void go_to_enter_pwd(lv_event_t *e) {
    PagesManager *pm = static_cast<PagesManager *>(lv_event_get_user_data(e));
    pm->navigate_to(pageKeyBoard, receive_password, false);
}

void connect_wifi(lv_event_t *e) {
    Serial.println("connect_wifi");
    show_message_box("warn", "111");
}

PageWifi::PageWifi(lv_obj_t *screen, PagesManager &pm): Page(screen) {
    // this->manager = pm;
    // lv_obj_add_flag(uic_Spinner2, LV_OBJ_FLAG_HIDDEN);
    // lv_obj_add_event_cb(uic_Button2, begin_scan_wifi, LV_EVENT_CLICKED, nullptr);
    // lv_obj_add_event_cb(uic_TextArea3, go_to_enter_pwd, LV_EVENT_CLICKED, &pm);
    // lv_obj_add_event_cb(uic_Roller2, roller_value_changed, LV_EVENT_VALUE_CHANGED, nullptr);
    // lv_obj_add_event_cb(uic_Button3, connect_wifi, LV_EVENT_CLICKED, nullptr);
    //
    // lv_roller_set_options(uic_Roller2, "please begin scan", LV_ROLLER_MODE_NORMAL);
    //
    // lv_obj_add_flag(uic_Label3, LV_OBJ_FLAG_HIDDEN);
    // lv_obj_add_flag(uic_TextArea3, LV_OBJ_FLAG_HIDDEN);
    // lv_obj_add_flag(uic_Button3, LV_OBJ_FLAG_HIDDEN);
}

void PageWifi::on_page_show() {
    Serial.println("PageWifi on_page_show");
}

void PageWifi::on_page_hide() {
    WiFi.scanDelete();
}

void PageWifi::page_loop() {
    if (wifi_scanning) {
        const int WiFiScanStatus = WiFi.scanComplete();
        if (WiFiScanStatus <= 0) {
            return;
        }
        for (int i = 0; i < WiFiScanStatus; ++i) {
            ssids.push_back(WiFi.SSID(i).c_str());
        }
        wifi_scanning = false;
        display_scanned_wifi();
    }
}
