//
// Created by 26413 on 25-8-23.
//

#ifndef LVGL_ADAPTER_H
#define LVGL_ADAPTER_H

#endif //LVGL_ADAPTER_H

#include <FT6336.h>
#include <lvgl.h>

#define TOUCH_FT6336
#define TOUCH_FT6336_SCL 39
#define TOUCH_FT6336_SDA 41
#define TOUCH_FT6336_INT 42
#define TOUCH_FT6336_RST 40

#define TOUCH_MAP_X1 0
#define TOUCH_MAP_X2 320
#define TOUCH_MAP_Y1 0
#define TOUCH_MAP_Y2 480

TFT_eSPI my_lcd = TFT_eSPI();

int touch_last_x = 0, touch_last_y = 0;
unsigned short int width = 0, height = 0, rotation, min_x = 0, max_x = 0, min_y = 0, max_y = 0;

FT6336 ts = FT6336(TOUCH_FT6336_SDA, TOUCH_FT6336_SCL, TOUCH_FT6336_INT, TOUCH_FT6336_RST,
                   max(TOUCH_MAP_X1, TOUCH_MAP_X2), max(TOUCH_MAP_Y1, TOUCH_MAP_Y2));

void touch_init(unsigned short int w, unsigned short int h, unsigned char r) {
    width = w;
    height = h;
    switch (r) {
        case ROTATION_NORMAL:
        case ROTATION_INVERTED:
            min_x = TOUCH_MAP_X1;
            max_x = TOUCH_MAP_X2;
            min_y = TOUCH_MAP_Y1;
            max_y = TOUCH_MAP_Y2;
            break;
        case ROTATION_LEFT:
        case ROTATION_RIGHT:
            min_x = TOUCH_MAP_Y1;
            max_x = TOUCH_MAP_Y2;
            min_y = TOUCH_MAP_X1;
            max_y = TOUCH_MAP_X2;
            break;
        default:
            break;
    }
    ts.begin();
    ts.setRotation(r);
}

bool touch_touched(void) {
    ts.read();
    if (ts.isTouched) {
        //#if defined(TOUCH_SWAP_XY)
        //    touch_last_x = map(ts.points[0].y, TOUCH_MAP_X1, TOUCH_MAP_X2, 0, width - 1);
        //    touch_last_y = map(ts.points[0].x, TOUCH_MAP_Y1, TOUCH_MAP_Y2, 0, height - 1);
        //#else
        touch_last_x = map(ts.points[0].x, min_x, max_x, 0, width - 1);
        touch_last_y = map(ts.points[0].y, min_y, max_y, 0, height - 1);
        //#endif
        //    Serial.print("x = ");
        //    Serial.print(touch_last_x);
        //    Serial.print(", y = ");
        //    Serial.print(touch_last_y);
        //    Serial.print("\r\n");
        return true;
    } else {
        return false;
    }
}

bool touch_has_signal(void) {
    return true;
}

bool touch_released(void) {
    return true;
}


/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);
    my_lcd.setAddrWindow(area->x1, area->y1, w, h);
    my_lcd.pushColors((uint16_t *) &color_p->full, w * h, true);
    lv_disp_flush_ready(disp);
}

/* Reading input device (simulated encoder here) */
void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data) {
    if (touch_touched()) {
        data->state = LV_INDEV_STATE_PR;
        data->point.x = touch_last_x;
        data->point.y = touch_last_y;
    } else {
        data->state = LV_INDEV_STATE_REL;
    }
}
