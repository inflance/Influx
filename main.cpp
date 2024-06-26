#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "Engine/Core/Engine.h"
#include "Engine/Core/Log.h"

int main() {
    influx::Log::onCreate("Influx", "influx.log");
    influx::Engine engine;
    engine.run();
    influx::Log::onDestory();
    return 0;
}