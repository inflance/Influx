//
// Created by liyun on 2024/6/26.
//

#ifndef WINDOWSWINDOW_H
#define WINDOWSWINDOW_H

#include <GLFW/glfw3.h>

#include "Engine/Core/Export.h"
#include "Engine/Platform/Window.h"

namespace influx {
    class INFLUX_API WindowsWindow : public Window {
    public:
        explicit WindowsWindow(const WindowCreateInfo& windowCreateInfo);

        void OnCreate() override;

        void OnUpdate() override;

        void OnResize(uint32_t width, uint32_t height) override;

        void OnClose() override;

        INFLUX_INLINE void SetVSync(bool enabled) override;

        INFLUX_NODISCARD INFLUX_INLINE bool IsVSync() const override;

        INFLUX_NODISCARD INFLUX_INLINE uint32_t GetWidth() const override;

        INFLUX_NODISCARD INFLUX_INLINE uint32_t GetHeight() const override;

        INFLUX_NODISCARD INFLUX_INLINE const std::string &GetWindowTitle() const override;

        INFLUX_NODISCARD INFLUX_INLINE void *GetNativeWindow() const override;

        void SwapBuffers() override;

        INFLUX_NODISCARD INFLUX_INLINE bool ShouldClose() const override;

    private:
        WindowCreateInfo m_create_info{};
        GLFWwindow* m_window = nullptr;
    };
}

#endif //WINDOWSWINDOW_H
