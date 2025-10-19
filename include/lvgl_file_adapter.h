/*
 * SD Card Pin Configuration
 * pin 1 - not used          |  Micro SD card     |
 * pin 2 - CS (SS)           |                   /
 * pin 3 - DI (MOSI)         |                  |__
 * pin 4 - VDD (3.3V)        |                    |
 * pin 5 - SCK (SCLK)        | 8 7 6 5 4 3 2 1   /
 * pin 6 - VSS (GND)         | ▄ ▄ ▄ ▄ ▄ ▄ ▄ ▄  /
 * pin 7 - DO (MISO)         | ▀ ▀ █ ▀ █ ▀ ▀ ▀ |
 * pin 8 - not used          |_________________|
 */
#pragma once

#include "FS.h"
#include "SD.h"
#include "SPI.h"
#include "lvgl.h"

#define SD_CS 12

// LVGL文件系统变量
lv_fs_drv_t fs_drv;

// 初始化SD卡
inline bool initSDCard() {
    // 设置SD卡CS引脚为输出并置高
    pinMode(SD_CS, OUTPUT);
    digitalWrite(SD_CS, HIGH);

    // 初始化SD卡，使用TFT_eSPI已经初始化的SPI实例
    if (!SD.begin(SD_CS)) {
        Serial.println("Card Mount Failed");
        return false;
    }

    // // SPI.begin(sck, miso, mosi, cs);
    // if (!SD.begin(SD_CS)) {
    //     Serial.println("Card Mount Failed");
    //     return false;
    // }

    uint8_t cardType = SD.cardType();
    if (cardType == CARD_NONE) {
        Serial.println("No SD card attached");
        return false;
    }

    Serial.print("SD Card Type: ");
    if (cardType == CARD_MMC) {
        Serial.println("MMC");
    } else if (cardType == CARD_SD) {
        Serial.println("SDSC");
    } else if (cardType == CARD_SDHC) {
        Serial.println("SDHC");
    } else {
        Serial.println("UNKNOWN");
    }

    uint64_t cardSize = SD.cardSize() / (1024 * 1024);
    Serial.printf("SD Card Size: %lluMB\n", cardSize);

    return true;
}

// LVGL文件系统回调函数
inline void *fs_open(lv_fs_drv_t *drv, const char *path, lv_fs_mode_t mode) {
    Serial.printf("Opening file: %s\n", path);

    const char *flags = "";
    if (mode == LV_FS_MODE_RD) flags = "r";
    else if (mode == (LV_FS_MODE_WR | LV_FS_MODE_RD)) flags = "r+";
    else if (mode == LV_FS_MODE_WR) flags = "w";

    File *file = new File();
    *file = SD.open(path, flags);

    if (!*file) {
        Serial.printf("Failed to open file: %s\n", path);
        delete file;
        return NULL;
    }

    return file;
}

inline lv_fs_res_t fs_close(lv_fs_drv_t *drv, void *file_p) {
    File *file = (File *) file_p;
    if (file) {
        file->close();
        delete file;
    }
    return LV_FS_RES_OK;
}

inline lv_fs_res_t fs_read(lv_fs_drv_t *drv, void *file_p, void *buf, uint32_t btr, uint32_t *br) {
    File *file = (File *) file_p;
    if (!file) return LV_FS_RES_UNKNOWN;

    *br = file->read((uint8_t *) buf, btr);
    return LV_FS_RES_OK;
}

inline lv_fs_res_t fs_seek(lv_fs_drv_t *drv, void *file_p, uint32_t pos, lv_fs_whence_t whence) {
    File *file = (File *) file_p;
    if (!file) return LV_FS_RES_UNKNOWN;

    if (whence == LV_FS_SEEK_SET) {
        file->seek(pos);
    } else if (whence == LV_FS_SEEK_CUR) {
        file->seek(file->position() + pos);
    } else if (whence == LV_FS_SEEK_END) {
        file->seek(file->size() + pos);
    }

    return LV_FS_RES_OK;
}

inline lv_fs_res_t fs_tell(lv_fs_drv_t *drv, void *file_p, uint32_t *pos_p) {
    File *file = (File *) file_p;
    if (!file) return LV_FS_RES_UNKNOWN;

    *pos_p = file->position();
    return LV_FS_RES_OK;
}

// 初始化LVGL文件系统
inline void initLVGLFileSystem() {
    lv_fs_drv_init(&fs_drv);

    fs_drv.letter = 'S'; // 使用'S'作为SD卡的驱动器字母
    fs_drv.open_cb = fs_open;
    fs_drv.close_cb = fs_close;
    fs_drv.read_cb = fs_read;
    fs_drv.seek_cb = fs_seek;
    fs_drv.tell_cb = fs_tell;

    lv_fs_drv_register(&fs_drv);
}

// 测试函数：列出SD卡中的文件
inline void listFiles() {
    Serial.println("Listing files on SD card:");
    File root = SD.open("/");
    if (!root) {
        Serial.println("Failed to open root directory");
        return;
    }

    File file = root.openNextFile();
    while (file) {
        if (file.isDirectory()) {
            Serial.print("  DIR : ");
            Serial.println(file.name());
        } else {
            Serial.print("  FILE: ");
            Serial.print(file.name());
            Serial.print("  SIZE: ");
            Serial.println(file.size());
        }
        file = root.openNextFile();
    }
    root.close();
}

// 从SD卡加载图片并显示
inline void loadAndDisplayImage() {
    // 检查图片文件是否存在
    if (!SD.exists("/image.jpg") && !SD.exists("/image.bmp") && !SD.exists("/image.png")) {
        Serial.println("No image file found. Please place an image file in the root directory.");
        return;
    }

    const char *image_path = NULL;
    if (SD.exists("/image.jpg")) image_path = "S:/image.jpg";
    else if (SD.exists("/image.bmp")) image_path = "S:/image.bmp";
    else if (SD.exists("/image.png")) image_path = "S:/image.png";

    if (image_path) {
        lv_obj_t *img = lv_img_create(lv_scr_act());
        lv_img_set_src(img, image_path);
        lv_obj_center(img);
        Serial.println("Image loaded successfully!");
    }
}

// 从SD卡加载字体并使用
inline void loadAndUseFont() {
    // 检查字体文件是否存在
    if (!SD.exists("/font.ttf") && !SD.exists("/font.bin")) {
        Serial.println("No font file found. Please place a font file in the root directory.");
        return;
    }

    const char *font_path = NULL;
    if (SD.exists("/font.ttf")) font_path = "S:/font.ttf";
    else if (SD.exists("/font.bin")) font_path = "S:/font.bin";

    if (font_path) {
        // 加载字体（根据您的LVGL版本和字体格式调整）
        lv_font_t *custom_font = lv_font_load(font_path);

        if (custom_font) {
            lv_obj_t *label = lv_label_create(lv_scr_act());
            lv_obj_set_style_text_font(label, custom_font, LV_PART_MAIN);
            lv_label_set_text(label, "Custom Font from SD Card");
            lv_obj_center(label);
            Serial.println("Custom font loaded successfully!");
        } else {
            Serial.println("Failed to load font file");
        }
    }
}

//
// void setup() {
//   Serial.begin(115200);
//
//   // 初始化LVGL（假设您已经设置了显示和输入设备）
//   lv_init();
//   // 这里应该添加您的显示初始化代码
//
//   // 初始化SD卡
//   if (!initSDCard()) {
//     Serial.println("SD card initialization failed!");
//     return;
//   }
//
//   // 列出文件用于调试
//   listFiles();
//
//   // 初始化LVGL文件系统
//   initLVGLFileSystem();
//   Serial.println("LVGL file system initialized");
//
//   // 测试加载图片和字体
//   loadAndDisplayImage();
//   loadAndUseFont();
// }
//
// void loop() {
//   // LVGL任务处理
//   lv_timer_handler();
//   delay(5);
// }
