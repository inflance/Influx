#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "Engine/Core/Engine.h"
#include "Engine/Core/Log.h"
#include "Engine/Utils/AABB2.hpp"
#include "Engine/Utils/AABB3.hpp"
#include "Engine/Utils/BoundingSphere.hpp"

int main() {
    influx::Log::OnCreate("Influx", "influx.log");
    influx::Engine engine;
    engine.Run();
    influx::Log::OnDestory();
    return 0;
}
