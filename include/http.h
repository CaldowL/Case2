//
// Created by 26413 on 2025/10/20.
//
#pragma once

#include <WiFi.h>
#include <HTTPClient.h>


// GET请求函数
// 参数: url - 请求的URL
//       response - 用于返回响应内容的引用
// 返回值: 请求成功返回true，失败返回false
inline bool httpGet(String url, String &response) {
    if (WiFi.status() != WL_CONNECTED) {
        response = "WiFi not connected";
        return false;
    }

    HTTPClient http;
    bool success = false;

    http.begin(url);
    http.setConnectTimeout(1000);
    http.setTimeout(1000);
    int httpCode = http.GET();

    if (httpCode == HTTP_CODE_OK) {
        response = http.getString();
        success = true;
    } else {
        response = "HTTP GET failed, error: " + String(http.errorToString(httpCode).c_str());
        success = false;
    }

    http.end();
    return success;
}

// POST JSON请求函数
// 参数: response - 用于返回响应内容的引用
//       url - 请求的URL
//       jsonData - 要发送的JSON数据
// 返回值: 请求成功返回true，失败返回false
inline bool httpPostJson(String url, const String &jsonData, String &response) {
    if (WiFi.status() != WL_CONNECTED) {
        response = "WiFi not connected";
        return false;
    }

    HTTPClient http;
    bool success = false;

    http.begin(url);
    http.addHeader("Content-Type", "application/json");

    int httpCode = http.POST(jsonData);

    if (httpCode == HTTP_CODE_OK) {
        response = http.getString();
        success = true;
    } else {
        response = "HTTP POST failed, error: " + String(http.errorToString(httpCode).c_str());
        success = false;
    }

    http.end();
    return success;
}

// 检查URL是否可达
// 参数: url - 要检查的URL
// 返回值: 可达返回true，不可达返回false
inline bool httpPing(String url) {
    if (WiFi.status() != WL_CONNECTED) {
        return false;
    }

    HTTPClient http;
    http.begin(url);
    int httpCode = http.GET();
    http.end();

    return (httpCode == HTTP_CODE_OK);
}


struct HttpRequest {
    String url;
    std::function<void(String)> cb;
};

// inline bool httpGet(String url, String &response) {
//     if (WiFi.status() != WL_CONNECTED) {
//         response = "WiFi not connected";
//         return false;
//     }
//
//     HTTPClient http;
//     bool success = false;
//
//     http.begin(url);
//     http.setConnectTimeout(1000);
//     http.setTimeout(1000);
//     int httpCode = http.GET();
//
//     if (httpCode == HTTP_CODE_OK) {
//         response = http.getString();
//         success = true;
//     } else {
//         response = "HTTP GET failed, error: " + String(http.errorToString(httpCode).c_str());
//         success = false;
//     }
//
//     http.end();
//     return success;
// }

inline void _http_get(void *arg) {
    // 获取参数并立即释放所有权
    std::unique_ptr<HttpRequest> body(static_cast<HttpRequest *>(arg));

    String res;
    try {
        httpGet(body->url, res);
    } catch (exception &e) {
    }
    Serial.println(res);
    // 确保回调被执行
    if (body->cb) {
        body->cb(res);
    }

    // 任务完成后自动删除自己
    vTaskDelete(nullptr);
}

inline bool httpGetAsync(String url, std::function<void(String)> cb) {
    // 动态分配内存，确保生命周期覆盖整个任务执行
    HttpRequest *body = new HttpRequest{url, cb};

    TaskHandle_t taskHandle = nullptr;
    BaseType_t result = xTaskCreatePinnedToCore(
        _http_get, // 任务函数
        "Http", // 任务名
        10000, // 任务栈大小
        body, // 任务参数（动态分配）
        1, // 任务优先级
        &taskHandle, // 保存任务句柄以便后续管理
        1 // 绑定到核心1
    );

    if (result != pdPASS) {
        delete body; // 任务创建失败，清理内存
        return false;
    }
    return true;
}
