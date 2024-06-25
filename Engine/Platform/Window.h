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
    uint32_t width = 800;

    uint32_t height = 600;
    std::string title;
    bool vsync = false;

    friend std::size_t hash_value(const WindowCreateInfo &obj) {
        std::size_t seed = 0x1791A227;
        seed ^= (seed << 6) + (seed >> 2) + 0x281C0CC5 + static_cast<std::size_t>(obj.width);
        seed ^= (seed << 6) + (seed >> 2) + 0x0BFC1359 + static_cast<std::size_t>(obj.height);
        seed ^= (seed << 6) + (seed >> 2) + 0x1993DFEE + std::hash<std::string>()(obj.title);
        seed ^= (seed << 6) + (seed >> 2) + 0x00C3C7BE + static_cast<std::size_t>(obj.vsync);
        return seed;
    }
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

    static std::unique_ptr<Window> create(const WindowCreateInfo& createInfo);
};

} // influx

#endif //WINDOWS_H
