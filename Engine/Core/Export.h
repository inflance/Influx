//
// Created by liyun on 2024/6/25.
//

#ifndef EXPORT_H
#define EXPORT_H

#include "Engine/Core/Defines.h"

#if defined(INFLUX_PLATFORM_WINDOWS)
#if defined(INFLUX_BUILD_DLL)
        #define INFLUX_API __declspec(dllexport)
#else
        #define INFLUX_API __declspec(dllimport)
#endif
#else
#define INFLUX_API
#endif


#endif //EXPORT_H
