cmake_minimum_required(VERSION 3.28)

project(InfluxEngine)

set(CMAKE_CXX_STANDARD 20)

add_definitions(-DINFLUX_BUILD_DLL)

find_package(nlohmann_json)
find_package(glfw3)
find_package(spdlog)
find_package(VulkanHeaders)
find_package(glm)
find_package(GTest)

add_executable(InfluxEngine main.cpp
        Engine/Core/Engine.cpp
        Engine/Core/Engine.h
        Engine/Core/Defines.h
        Engine/Core/Export.h
        Engine/RHI/RHI.cpp
        Engine/RHI/RHI.h
        Engine/Platform/Window.cpp
        Engine/Platform/Window.h
        Engine/Platform/Window/WindowsWindow.cpp
        Engine/Platform/Window/WindowsWindow.h
        Engine/Core/Log.cpp
        Engine/Core/Log.h
        Engine/Core/Enums.h
        Engine/Utils/Internal/BoundingBoxImpl.hpp
        Engine/Utils/Internal/RectangleImpl.hpp
        Engine/Utils/AABB2.hpp
        Engine/Utils/AABB3.hpp
        Engine/Utils/BoundingSphere.hpp
        Engine/Utils/Test/TestStringUtils.cpp
        Engine/Utils/StringUtils.h
        Engine/Utils/StringUtils.cpp
        Engine/Core/Test/TestFlags.cpp
        Engine/Utils/Rect2.hpp
        Engine/Utils/Rect3.hpp
        Engine/Utils/Frustum.hpp
        Engine/Utils/Internal/RangeImpl.hpp
        Engine/Utils/Range1.hpp
        Engine/Utils/Range2.hpp
        Engine/Utils/Range3.hpp
        Engine/Utils/Ray.hpp
        Engine/Utils/Ray.hpp
        Engine/Utils/Plane.hpp
        Engine/Utils/Internal/SizeImpl.hpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(InfluxEngine
        PUBLIC
        nlohmann_json::nlohmann_json
        glfw
        spdlog::spdlog
        vulkan-headers::vulkan-headers
        glm::glm
        gtest::gtest)
#添加当前目录作为包含目录
