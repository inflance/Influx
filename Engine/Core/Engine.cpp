//
// Created by liyun on 2024/6/25.
//

#include "Engine.h"

namespace influx {
    Engine::Engine() {
        m_window_native = Window::create({
            .title = "Influx Engine",
            .width = 1280,
            .height = 720
        });
        m_window_native->onCreate();
    }

    Engine::~Engine() {
        m_window_native->onClose();
    }

    void Engine::run() const {
        while (!m_window_native->shouldClose())
        {
            m_window_native->onUpdate();
        }
    }
} // influx
