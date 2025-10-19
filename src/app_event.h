#pragma once
#include "app_event.h"

#include <string>
#include "utils.h"

using namespace std;




/// 从同步设备本地时间
/// @param time_str 时间戳
inline void sync_local_time(int time_str) {
    Serial.println("开始执行时间同步任务");
    time_t timestamp = (time_t) time_str;
    configTime(0, 0, "pool.ntp.org"); // 时区偏移和夏令时偏移设为0
    setenv("TZ", "CST-8", 1);
    tzset();
    timeval tv;
    tv.tv_sec = timestamp; // 设置秒数
    tv.tv_usec = 0; // 微秒设为0
    settimeofday(&tv, nullptr);

    show_local_time();
}


/// 解析串口传入的json字符串
/// @param msg 传入的参数
inline void handle_recv_msg(string msg) {
    Serial.println("---------------------------------------------");
    Serial.println(msg.c_str());
    String action = get_json_string(msg.c_str(), "action", "");

    if (action == "sync_time") {
        int timestamp = get_json_int(msg.c_str(), "timestamp", 0);
        sync_local_time(timestamp);
    }
}
