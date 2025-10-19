#include <lvgl.h>
#include <TFT_eSPI.h>

#include "lvgl_adapter.h"
#include "pages_manager.h"
#include "WiFi.h"
#include "ui.h"
#include "common_pages.h"
#include "utils.h"
#include "app_event.h"
#include "pages/buttons/buttons_page.h"

using namespace std;

static const uint16_t screenWidth = 320;
static const uint16_t screenHeight = 480;
static lv_disp_draw_buf_t disp_buf;

uint32_t bufSize;
lv_disp_draw_buf_t draw_buf;
lv_color_t *disp_draw_buf1;
lv_color_t *disp_draw_buf2;

PagesManager pm;

PageMain *pageMain;
PageWifi *pageWifi;
PageKeyBoard *pageKeyBoard;
PageButtons *pageButtons;


void initHardware() {
    Serial.begin(115200);
    Serial.println("=== 内存使用情况 ===");
    Serial.printf("总堆内存: %d bytes\n", ESP.getHeapSize());
    Serial.printf("可用堆内存: %d bytes\n", ESP.getFreeHeap());
    Serial.printf("总PSRAM: %d bytes\n", ESP.getPsramSize());
    Serial.printf("可用PSRAM: %d bytes\n", ESP.getFreePsram());

    my_lcd.init();
    my_lcd.setRotation(3);
    my_lcd.fillScreen(TFT_BLUE);
    delay(20);
    my_lcd.fillScreen(TFT_RED);
    delay(20);
    my_lcd.fillScreen(TFT_BLACK);
    touch_init(my_lcd.width(), my_lcd.height(), my_lcd.getRotation());
}

void initLvgl() {
    lv_init();
    delay(10);

    bufSize = screenWidth * 50;
    disp_draw_buf1 = static_cast<lv_color_t *>(heap_caps_malloc(bufSize * 2, MALLOC_CAP_8BIT));
    disp_draw_buf2 = static_cast<lv_color_t *>(heap_caps_malloc(bufSize * 2, MALLOC_CAP_8BIT));

    lv_disp_draw_buf_init(&disp_buf, disp_draw_buf1, disp_draw_buf2, bufSize);

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = my_lcd.width();
    disp_drv.ver_res = my_lcd.height();
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &disp_buf;
    lv_disp_drv_register(&disp_drv);

    /*Initialize the (dummy) input device driver*/
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register(&indev_drv);
}


void setup() {
    initHardware();
    initLvgl();
    ui_init();

    pageMain = new PageMain(ui_Screen1, pm);
    pageButtons = new PageButtons(ui_ScreenButtons, pm);

    pm.set_default_page(pageMain);


    // WiFi.mode(WIFI_STA);
    // lv_obj_add_event_cb(uic_Button1, button_click, LV_EVENT_CLICKED, nullptr);
    // lv_obj_add_event_cb(uic_Button2, button_click_2, LV_EVENT_CLICKED, nullptr);
    //
    // lv_keyboard_set_textarea(uic_Keyboard3, uic_TextArea2);
    // lv_keyboard_set_popovers(uic_Keyboard3, true);
    // lv_obj_add_event_cb(uic_Keyboard3, kb_click, LV_EVENT_READY, nullptr);
}


void loop() {
    lv_task_handler();
    pm.loop();
    if (Serial.available() > 0) {
        String inputString = Serial.readStringUntil('\n');
        inputString.trim();
        handle_recv_msg(inputString.c_str());
    }
}
