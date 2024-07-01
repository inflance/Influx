//
// Created by liyun on 2024/6/26.
//

#include "Window.h"

#include "Window/WindowsWindow.h"

namespace influx {
    std::unique_ptr<Window> Window::Create(const WindowCreateInfo &createInfo)
    {
#if defined(INFLUX_PLATFORM_WINDOWS)
        return std::make_unique<WindowsWindow>(createInfo);
#else
        INFLUX_ASSERT(false)
        return nullptr;
#endif
    }
} // influx