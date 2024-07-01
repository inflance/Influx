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

    virtual void OnCreate() = 0;
    virtual void OnUpdate() = 0;
    virtual void OnResize(uint32_t width, uint32_t height) = 0;
    virtual void OnClose() = 0;

    virtual INFLUX_INLINE void SetVSync(bool enabled) = 0;

    INFLUX_NODISCARD virtual INFLUX_INLINE bool IsVSync() const = 0;
    INFLUX_NODISCARD virtual INFLUX_INLINE uint32_t GetWidth() const  = 0;
    INFLUX_NODISCARD virtual INFLUX_INLINE uint32_t  GetHeight() const = 0;
    INFLUX_NODISCARD virtual INFLUX_INLINE const std::string& GetWindowTitle() const = 0;

    INFLUX_NODISCARD virtual INFLUX_INLINE void* GetNativeWindow() const = 0;

    virtual void SwapBuffers() = 0;

    INFLUX_NODISCARD virtual INFLUX_INLINE bool ShouldClose() const = 0;

    static std::unique_ptr<Window> Create(const WindowCreateInfo& createInfo);
};

} // influx

#endif //WINDOWS_H
