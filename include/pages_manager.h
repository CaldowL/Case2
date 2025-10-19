#pragma once
#include <string>
#include <functional>
#include <stack>
#include "page_base.h"

using namespace std;
class PagesManager;


void overwrite_navigate_back(lv_event_t *e);

class PagesManager {
    stack<Page *> pages;
    stack<string> share_infos;
    stack<function<void(string)> > func_cbs;
    Page *default_page = nullptr;


    void draw_back_button() {
        lv_obj_t *btn = lv_btn_create(pages.top()->Screen);
        lv_obj_set_size(btn, 50, 20);
        lv_obj_set_pos(btn, 2, 2);

        lv_obj_t *label = lv_label_create(btn);
        lv_label_set_text(label, "back");
        lv_obj_center(label);

        lv_obj_add_event_cb(btn, overwrite_navigate_back, LV_EVENT_CLICKED, this);
    }

    void to_new_page(const Page *to_page, bool show_back = true) {
        if (to_page != this->default_page) {
            if (show_back) {
                this->draw_back_button();
            }
        }
    }

public:
    void set_default_page(Page *default_page_) {
        pages.push(default_page_);
        this->default_page = default_page_;
        default_page_->on_page_show();
    }

    void navigate_to_(Page *page, const function<void(string)> &cb = nullptr, const string &info = "",
                      bool show_back = true, bool auto_del = false) {
        if (page == pages.top())return;
        if (pages.top()) pages.top()->on_page_hide();
        func_cbs.push(cb);
        share_infos.push(info);
        lv_scr_load_anim(page->Screen, LV_SCR_LOAD_ANIM_MOVE_LEFT, 250, 50, auto_del);
        pages.push(page);
        this->to_new_page(page, show_back);

        page->on_page_show();
    }

    void navigate_to(Page *page) {
        this->navigate_to_(page, nullptr, "", true);
    }

    void navigate_to(Page *page, bool show_back) {
        this->navigate_to_(page, nullptr, "", show_back);
    }

    void navigate_to(Page *page, const function<void(string)> &cb, bool show_back) {
        this->navigate_to_(page, cb, "", show_back);
    }

    void navigate_back(const string &info = "", bool auto_del = false) {
        pages.top()->on_page_hide();
        pages.pop();
        lv_scr_load_anim(pages.top()->Screen, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 250, 50, auto_del);
        if (func_cbs.top() != nullptr) {
            func_cbs.top()(info);
        }
        func_cbs.pop();
        share_infos.pop();
        pages.top()->on_page_show();
        this->to_new_page(pages.top());
    }


    string get_info() {
        return share_infos.top();
    }

    void handle_msg(String msg) {
        this->pages.top()->handle_msg(msg);
    }

    void loop() {
        pages.top()->page_loop();
    }
};

inline void overwrite_navigate_back(lv_event_t *e) {
    const auto manager = static_cast<PagesManager *>(lv_event_get_user_data(e));
    if (manager) {
        manager->navigate_back();
    }
}
