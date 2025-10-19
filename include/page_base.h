#pragma once
#include <lvgl.h>

class Page {
public:
    virtual ~Page() = default;

    lv_obj_t *Screen = nullptr;

    explicit Page(lv_obj_t *screen) {
        this->Screen = screen;
    }


    virtual void on_page_show() =0;

    virtual void on_page_hide() =0;

    virtual void page_loop() =0;

    virtual void handle_msg(String msg) =0;
};
