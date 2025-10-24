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

String httpPerformanceRes;

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

void set_vol_label_value(lv_event_t *e) {
    int v = lv_slider_get_value(uic_SliderVol);
    lv_label_set_text(uic_LabeVol, to_string(v).c_str());
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

    lv_obj_add_event_cb(uic_SliderVol, set_vol_label_value, LV_EVENT_VALUE_CHANGED, nullptr);
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
        if (httpGet(baseUrl + "/system_info", httpPerformanceRes)) {
            Serial.println(httpPerformanceRes);
            set_cpu_value_with_animation(get_json_int(httpPerformanceRes, "cpu"));
            set_gpu_value_with_animation(get_json_int(httpPerformanceRes, "gpu"));
        }
    }
}

void PageMain::handle_msg(String msg) {
}
