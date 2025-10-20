#pragma once
#include <vector>
#include <ArduinoJson.h>
#include <Preferences.h>
#include <lvgl.h>
#include <string.h>

using namespace std;
// 定义在头文件中声明的全局变量
extern Preferences preferences;
extern lv_obj_t *messageBox;


inline std::string join_string(const std::vector<std::string> &v, std::string sep) {
    if (v.empty()) return "";

    size_t total_length = 0;
    for (const auto &s: v) {
        total_length += s.size();
    }
    total_length += sep.size() * (v.size() - 1);

    std::string result;
    result.reserve(total_length);

    for (size_t i = 0; i < v.size() - 1; ++i) {
        result += v[i];
        result += sep;
    }
    result += v.back();

    return result;
}

inline void close_message_box(lv_obj_t *msg_box) {
    lv_msgbox_close(msg_box);
}

inline void close_message_box(lv_event_t *e) {
    lv_msgbox_close(messageBox);
}

inline void show_message_box(std::string title, std::string text) {
    messageBox = lv_msgbox_create(nullptr, title.c_str(),
                                  text.c_str(), nullptr, false);
    lv_obj_add_event_cb(messageBox, close_message_box, LV_EVENT_CLICKED, nullptr);
    lv_obj_center(messageBox);
}

inline std::string config_read_string(std::string key) {
    preferences.begin("config", true);
    std::string res = preferences.getString(key.c_str()).c_str();
    preferences.end();
    return res;
}

inline void config_write_string(std::string key, std::string value) {
    preferences.begin("config", false);
    preferences.putString(key.c_str(), value.c_str());
    preferences.end();
}

inline int config_read_int(std::string key) {
    preferences.begin("config", true);
    const int res = preferences.getInt(key.c_str());
    preferences.end();
    return res;
}

inline void config_write_int(std::string key, int value) {
    preferences.begin("config", false);
    preferences.putInt(key.c_str(), value);
    preferences.end();
}


// inline std::string get_json_string(std::string jsonStr, std::string key, std::string defaultValue = "") {
//     JsonDocument doc;
//     DeserializationError error = deserializeJson(doc, jsonStr);
//
//     if (error || !doc[key]) {
//         return defaultValue;
//     }
//
//     return doc[key].as<std::string>();
// }

// 模板版本，支持任意类型
template<typename T>
inline T get_json_value(const String &jsonStr, const String &key, const T &defaultValue) {
    JsonDocument doc;
    DeserializationError error = deserializeJson(doc, jsonStr);

    if (error || !doc.containsKey(key)) {
        return defaultValue;
    }

    return doc[key].as<T>();
}

// 为常用类型提供别名，使调用更直观
inline int get_json_int(const String &jsonStr, const String &key, int defaultValue = 0) {
    return get_json_value<int>(jsonStr, key, defaultValue);
}

inline float get_json_float(const String &jsonStr, const String &key, float defaultValue = 0.0) {
    return get_json_value<float>(jsonStr, key, defaultValue);
}

inline bool get_json_bool(const String &jsonStr, const String &key, bool defaultValue = false) {
    return get_json_value<bool>(jsonStr, key, defaultValue);
}

inline String get_json_string(const String &jsonStr, const String &key, const String &defaultValue) {
    return get_json_value<String>(jsonStr, key, defaultValue);
}

inline void hello() {
    Serial.println("hello");
}


/// #### 时间相关

inline void get_local_time(tm &timeinfo) {
    if (!getLocalTime(&timeinfo)) {
        return;
    }
}

///字符串显示当前系统时间
inline void show_local_time() {
    tm timeinfo;
    get_local_time(timeinfo);
    char timeString[64];
    strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", &timeinfo);
    Serial.printf("本地时间: %s\n", timeString);
}


inline bool sync_ntp_time() {
    Serial.println("正在初始化NTP...");

    // 配置NTP服务器和时区
    configTime(8 * 3600, 0, "ntp.aliyun.com");

    tm timeinfo;
    Serial.print("等待时间同步");
    int retryCount = 0;
    while (!getLocalTime(&timeinfo) && retryCount < 20) {
        Serial.print(".");
        delay(100);
        retryCount++;
    }

    if (retryCount >= 20) {
        Serial.println("\nNTP时间同步失败！");
        return false;
    }

    Serial.println("\nNTP时间同步成功！");
    show_local_time();
    return true;
}
