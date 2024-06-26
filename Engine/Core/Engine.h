//
// Created by liyun on 2024/6/25.
//

#ifndef ENGINE_H
#define ENGINE_H

#include <memory>

#include "Engine/Core/Export.h"
#include "Engine/Platform/Window.h"

namespace influx {
    class INFLUX_API Engine {
    public:
        Engine();

        ~Engine();

        void run() const;

    private:
        std::unique_ptr<Window> m_window_native = nullptr;
    };
} // influx

#endif //ENGINE_H
