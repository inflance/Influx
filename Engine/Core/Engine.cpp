//
// Created by liyun on 2024/6/25.
//

#include "Engine.h"

namespace influx {
	Engine::Engine() {
		m_window_native = Window::Create({
			.title = "Influx Engine",
			.width = 1280,
			.height = 720
		});
		m_window_native->OnCreate();
	}

	Engine::~Engine() {
		m_window_native->OnClose();
	}

	void Engine::Run() const {
		while (!m_window_native->ShouldClose()) {
			m_window_native->OnUpdate();
		}
	}
} // influx
