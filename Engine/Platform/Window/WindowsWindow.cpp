//
// Created by liyun on 2024/6/26.
//
#include <vulkan/vulkan.h>

#include "WindowsWindow.h"

#include "Engine/Core/Log.h"

namespace influx {
    WindowsWindow::WindowsWindow(const WindowCreateInfo &windowCreateInfo)
        :m_create_info(windowCreateInfo)
    {
    }

    void WindowsWindow::onCreate() {
        glfwInit();

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        m_window = glfwCreateWindow(m_create_info.width, m_create_info.height, m_create_info.title.c_str(), nullptr, nullptr);

        if(!m_window) {
            LOG_ERROR("Failed to create window");
        }
        LOG_INFO("Window created title={},width={},height={}", m_create_info.title, m_create_info.width, m_create_info.height);
    }

    void WindowsWindow::onUpdate() {
        glfwPollEvents();
    }

    void WindowsWindow::onResize(uint32_t width, uint32_t height) {
    }

    void WindowsWindow::onClose() {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    void WindowsWindow::setVSync(bool enabled) {
    }

    bool WindowsWindow::isVSync() const {
        return false;
    }

    uint32_t WindowsWindow::getWidth() const {
        return 0;
    }

    uint32_t WindowsWindow::getHeight() const {
        return 0;
    }

    const std::string &WindowsWindow::getWindowTitle() const {
        return m_create_info.title;
    }

    void * WindowsWindow::getNativeWindow() const {
        return nullptr;
    }

    void WindowsWindow::swapBuffers() {
    }

    bool WindowsWindow::shouldClose() const {
        return glfwWindowShouldClose(m_window);
    }
}
