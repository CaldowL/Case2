#pragma once
#include "ui.h"
#include "player_page.h"
#include "common_pages.h"
#include "utils.h"

void set_volume(int vol) {
    lv_slider_set_value(uic_Slider2, vol, LV_ANIM_OFF);
    lv_label_set_text(uic_Label8, std::to_string(vol).c_str());
    Volume = vol;
}

void volume_slider_value_changed(lv_event_t *lv_event) {
    int v = lv_slider_get_value(uic_Slider2);
    set_volume(v);
}

void volume_slider_value_released(lv_event_t *lv_event) {
    JsonDocument doc;
    doc["action"] = "volume_set";
    doc["type"] = "request";
    doc["value"] = lv_slider_get_value(uic_Slider2);
    String jsonStr;
    serializeJson(doc, jsonStr);
    Serial.println(jsonStr);
}

PagePlayer::PagePlayer(lv_obj_t *screen, PagesManager &pm) : Page(screen) {
    lv_obj_add_event_cb(uic_Slider2, volume_slider_value_changed, LV_EVENT_VALUE_CHANGED, nullptr);
    lv_obj_add_event_cb(uic_Slider2, volume_slider_value_released, LV_EVENT_RELEASED, nullptr);
}

void PagePlayer::on_page_show() {
    Serial.println("PageWifi on_page_show");
    set_volume(0);

    JsonDocument doc;
    doc["action"] = "volume_get";
    doc["type"] = "request";
    String jsonStr;
    serializeJson(doc, jsonStr);
    Serial.println(jsonStr);
}

void PagePlayer::on_page_hide() {
}

void PagePlayer::page_loop() {
}

void PagePlayer::handle_msg(String msg) {
    String action = get_json_string(msg, "action", "");
    if (action == "volume_get") {
        set_volume(get_json_int(msg, "value", 0));
    }
}
