#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "Engine/Core/Engine.h"
#include "Engine/Core/Log.h"
#include "Engine/Utils/AABB2.hpp"
#include "Engine/Utils/AABB3.hpp"
#include "Engine/Utils/BoundingSphere.hpp"

int main() {
    influx::Log::onCreate("Influx", "influx.log");
    std::cout << influx::AABB2<double>();
    std::cout << influx::AABB3<double>();
    std::cout << influx::BoundingSphere<double>();
    influx::AABB2<double> aabb2{-1, -1, 1, 1};
    std::cout <<  aabb2.contains(glm::vec2{});
    influx::Engine engine;
    engine.run();
    influx::Log::onDestory();
    return 0;
}
