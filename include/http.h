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
