//
// Created by liyun on 2024/6/25.
//

#ifndef ENGINE_H
#define ENGINE_H

#include "Engine/Core/Export.h"

namespace influx {
    class INFLUX_API Engine {
    public:
        Engine() = default;

        ~Engine() = default;

        void run();

    private:
    };
} // influx

#endif //ENGINE_H
