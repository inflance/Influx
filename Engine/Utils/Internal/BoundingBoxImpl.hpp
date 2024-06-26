//
// Created by liyun on 24-6-26.
//

#ifndef BOUNDINGBOX_HPP
#define BOUNDINGBOX_HPP

#include <string_view>

#include "Engine/Core/Export.h"

namespace influx {
    template<typename T>
    class BoundingBoxImpl {
    public:
        using ValueType = T;
        using Ref = T &;
        using Ptr = T *;
        using ConstRef = const T &;
        using ConstPtr = const T *;
        INFLUX_INLINE static INFLUX_CONSTEXPR std::string_view base_name = "BoundingBoxImpl";
    };
} // influx

#endif //BOUNDINGBOX_HPP
