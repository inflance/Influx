#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "Engine/Core/Engine.h"
#include "Engine/Core/Log.h"
#include "Engine/Utils/AABB2.hpp"
#include "Engine/Utils/AABB3.hpp"

int main() {
    influx::Log::onCreate("Influx", "influx.log");
    std::cout << influx::AABB2<double>();
    std::cout << influx::AABB3<double>();

    influx::Engine engine;
    engine.run();
    influx::Log::onDestory();
    return 0;
}
