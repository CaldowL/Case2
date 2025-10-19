#pragma once

#include <page_base.h>
#include "pages_manager.h"

class PageMain : public Page {
public:
    PagesManager manager;

    PageMain(lv_obj_t *screen, PagesManager &pm);

    static void button_click(lv_event_t *e);

    void on_page_show() override;

    void on_page_hide() override;

    void page_loop() override;

    void handle_msg(String msg) override;
};
