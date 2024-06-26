//
// Created by liyun on 2024/6/26.
//

#ifndef LOG_H
#define LOG_H

#include <memory>
#include <spdlog/spdlog.h>

#include "Engine/Core/Export.h"

namespace influx {

class INFLUX_API Log {
public:
    Log() = default;
    ~Log() = default;

    static void onCreate(std::string_view app_name, std::string_view file_path);

    static void onDestory();

    static std::shared_ptr<spdlog::logger> getConsoleLogger() { return m_console_logger;}

    static std::shared_ptr<spdlog::logger> getFileLogger() { return m_file_logger;}

private:
    inline static std::shared_ptr<spdlog::logger> m_console_logger = nullptr;
    inline static std::shared_ptr<spdlog::logger> m_file_logger = nullptr;
};

} // influx

#define LOG_ERROR(...) influx::Log::getConsoleLogger()->error(__VA_ARGS__)
#define LOG_WARN(...) influx::Log::getConsoleLogger()->warn(__VA_ARGS__)
#define LOG_INFO(...) influx::Log::getConsoleLogger()->info(__VA_ARGS__)
#define LOG_DEBUG(...) influx::Log::getConsoleLogger()->debug(__VA_ARGS__)

#endif //LOG_H
