//
// Created by 26413 on 25-8-24.
//
#pragma once
#include "utils.h"

#include "common_pages.h"
#include "http.h"
#include "ui.h"

tm time_local;
unsigned long last_check_time = 0;
unsigned long last_performance_time = 0;
unsigned long last_vol_time = 0;

void sync_pc_vol() {
    int v = lv_slider_get_value(uic_SliderVol);
    String sss;
    httpGet(baseUrl + "/vol/set?value=" + to_string(v).c_str(), sss);
}

///刷新页面上的音量值
void refresh_label_vol(int value) {
    lv_label_set_text(uic_LabeVol, to_string(value).c_str());
    sync_pc_vol();
}


void cb_slider_vol_change(lv_event_t *e) {
    last_vol_time = millis();
    lv_label_set_text(uic_LabeVol, to_string(lv_slider_get_value(uic_SliderVol)).c_str());
}

void cb_slider_vol_released(lv_event_t *e) {
    lv_label_set_text(uic_LabeVol, to_string(lv_slider_get_value(uic_SliderVol)).c_str());
    sync_pc_vol();
}


void refresh_label_time() {
    if (!getLocalTime(&time_local, 200)) {
        lv_label_set_text(uic_LabelTime, "waiting");
        return;
    }
    get_local_time(time_local);
    char time_str[15];
    sprintf(time_str, "%02d:%02d:%02d", time_local.tm_hour, time_local.tm_min, time_local.tm_sec);
    lv_label_set_text(uic_LabelTime, time_str);
}

void refresh_performance(String httpPerformanceRes) {
    Serial.println("recv: " + httpPerformanceRes);
    set_cpu_value_with_animation(get_json_int(httpPerformanceRes, "cpu"));
    set_gpu_value_with_animation(get_json_int(httpPerformanceRes, "gpu"));

    if (millis() - last_vol_time > 2000) {
        int vol = get_json_int(httpPerformanceRes, "vol");
        lv_label_set_text(uic_LabeVol, to_string(vol).c_str());
        lv_slider_set_value(uic_SliderVol, vol, LV_ANIM_ON);
    }
}

void PageMain::button_click(lv_event_t *e) {
    PagesManager *pm = static_cast<PagesManager *>(lv_event_get_user_data(e));
    Serial.println("button click");
    pm->navigate_to(pageButtons, false);
}

PageMain::PageMain(lv_obj_t *screen, PagesManager &pm) : Page(screen) {
    // this->manager = pm;
    // lv_obj_add_event_cb(uic_Button1, button_click, LV_EVENT_CLICKED, &pm);

    lv_obj_add_event_cb(uic_Button3, button_click, LV_EVENT_CLICKED, &pm);

    lv_obj_add_event_cb(uic_SliderVol, cb_slider_vol_change, LV_EVENT_VALUE_CHANGED, nullptr);
    lv_obj_add_event_cb(uic_SliderVol, cb_slider_vol_released, LV_EVENT_RELEASED, nullptr);
}

void PageMain::on_page_show() {
    Serial.println("PageMain on_page_show");
}

void PageMain::on_page_hide() {
    Serial.println("PageMain on_page_hide");
}

void PageMain::page_loop() {
    if (millis() - last_check_time > 100) {
        last_check_time = millis();
        refresh_label_time();
    }

    if (millis() - last_performance_time > 1000) {
        last_performance_time = millis();
        httpGetAsync(baseUrl + "/system_info", refresh_performance);
    }
}

void PageMain::handle_msg(String msg) {
}
