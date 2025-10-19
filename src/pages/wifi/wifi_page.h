#pragma once
#include <Arduino.h>

#include <page_base.h>
#include "pages_manager.h"


class PageWifi: public Page {
public:
    PagesManager manager;

    PageWifi(lv_obj_t *screen, PagesManager &pm);

    void on_page_show() override;

    void on_page_hide() override;
    void page_loop() override;
};
