//
// Created by liyun on 2024/6/26.
//

#include "WindowsWindow.h"

namespace influx {
    WindowsWindow::WindowsWindow(const WindowCreateInfo &windowCreateInfo)
        :m_CreateInfo(windowCreateInfo)
    {
    }

    void WindowsWindow::onCreate() {
    }

    void WindowsWindow::onUpdate() {
    }

    void WindowsWindow::onResize(uint32_t width, uint32_t height) {
    }

    void WindowsWindow::onClose() {
    }

    void WindowsWindow::setVSync(bool enabled) {
    }

    bool WindowsWindow::isVSync() const {
    }

    uint32_t WindowsWindow::getWidth() const {
        return 0;
    }

    uint32_t WindowsWindow::getHeight() const {
        return 0;
    }

    const std::string &WindowsWindow::getWindowTitle() const {
    }

    void * WindowsWindow::getNativeWindow() const {
    }

    void swapBuffers() {
    }
}
