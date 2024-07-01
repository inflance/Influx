//
// Created by liyun on 24-6-29.
//

#ifndef RANGEIMPL_HPP
#define RANGEIMPL_HPP

#include "Engine/Core/Export.h"

namespace influx {
	template<typename T>
	class RangeImpl {
	public:
		using ValueType = T;
		using Ref = T &;
		using Ptr = T *;
		using ConstRef = const T &;
		using ConstPtr = const T *;
		INFLUX_INLINE static INFLUX_CONSTEXPR std::string_view base_name = "RangeImpl";
	};
} // influx

#endif //RANGEIMPL_HPP
