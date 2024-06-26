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

        void onCreate() override;

        void onUpdate() override;

        void onResize(uint32_t width, uint32_t height) override;

        void onClose() override;

        INFLUX_INLINE void setVSync(bool enabled) override;

        INFLUX_NODISCARD INFLUX_INLINE bool isVSync() const override;

        INFLUX_NODISCARD INFLUX_INLINE uint32_t getWidth() const override;

        INFLUX_NODISCARD INFLUX_INLINE uint32_t getHeight() const override;

        INFLUX_NODISCARD INFLUX_INLINE const std::string &getWindowTitle() const override;

        INFLUX_NODISCARD INFLUX_INLINE void *getNativeWindow() const override;

        void swapBuffers() override;

        INFLUX_NODISCARD INFLUX_INLINE bool shouldClose() const override;

    private:
        WindowCreateInfo m_create_info{};
        GLFWwindow* m_window = nullptr;
    };
}


#endif //WINDOWSWINDOW_H
