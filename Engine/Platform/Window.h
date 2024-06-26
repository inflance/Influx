//
// Created by liyun on 2024/6/26.
//

#ifndef WINDOWS_H
#define WINDOWS_H

#include <cstdint>
#include <memory>
#include <string>

#include "Engine/Core/Export.h"

namespace influx {

struct WindowCreateInfo {
    std::string title;
    uint32_t width = 800;
    uint32_t height = 600;
    bool vsync = false;
};

class INFLUX_API Window {
public:
    virtual ~Window() = default;

    virtual void onCreate() = 0;
    virtual void onUpdate() = 0;
    virtual void onResize(uint32_t width, uint32_t height) = 0;
    virtual void onClose() = 0;

    virtual INFLUX_INLINE void setVSync(bool enabled) = 0;

    INFLUX_NODISCARD virtual INFLUX_INLINE bool isVSync() const = 0;
    INFLUX_NODISCARD virtual INFLUX_INLINE uint32_t getWidth() const  = 0;
    INFLUX_NODISCARD virtual INFLUX_INLINE uint32_t  getHeight() const = 0;
    INFLUX_NODISCARD virtual INFLUX_INLINE const std::string& getWindowTitle() const = 0;

    INFLUX_NODISCARD virtual INFLUX_INLINE void* getNativeWindow() const = 0;

    virtual void swapBuffers() = 0;

    INFLUX_NODISCARD virtual INFLUX_INLINE bool shouldClose() const = 0;

    static std::unique_ptr<Window> create(const WindowCreateInfo& createInfo);
};

} // influx

#endif //WINDOWS_H
