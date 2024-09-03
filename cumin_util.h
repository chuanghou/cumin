//
// Created by houch on 2024/9/3.
//

#ifndef CUMIN_UTIL_H
#define CUMIN_UTIL_H

#include <algorithm>
#include <chrono>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>


namespace cumin_util {

    static bool IsBlank(const std::string &s) {
        bool blank = false;
        if (s.empty() || std::all_of(s.begin(), s.end(), [](char c) { return std::isspace(c); })) {
            blank = true;
        }
        return blank;
    }

    static void Spilt(const std::string &value, std::vector<std::string> &result, const std::string &delimitter) {
        boost::split(result, value, boost::is_any_of(delimitter));
    }

    static int64_t CurrentTimeSeconds() {
        return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).
                count();
    }

    static int64_t CurrentTimeMillis() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
    }

    static int64_t CurrentTimeMicros() {
        return std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
    }

    static int64_t CurrentTimeNanos() {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch())
                .count();
    }

    static std::string CurrentDateOfString() {
        const auto tm = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        const auto time_tm = std::localtime(&tm);
        char strTime[16];
        sprintf(strTime, "%d%02d%02d", time_tm->tm_year + 1900, time_tm->tm_mon + 1, time_tm->tm_mday);
        return strTime;
    }

    static int32_t CurrentDateOfInt() {
        const auto tm = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        const auto time_tm = std::localtime(&tm);
        return (time_tm->tm_year + 1900) * 10000 + (time_tm->tm_mon + 1) * 100 + time_tm->tm_mday;
    }

}


#endif
