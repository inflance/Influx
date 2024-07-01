//
// Created by liyun on 2024/6/26.
//

#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace influx {
    void Log::OnCreate(std::string_view app_name, std::string_view file_path) {
        m_console_logger = spdlog::stdout_color_mt("console");
        m_file_logger = spdlog::basic_logger_mt("file", file_path.data());
        spdlog::set_default_logger(m_console_logger);
    }

    void Log::OnDestory() {
        spdlog::drop_all();
    }
} // influx