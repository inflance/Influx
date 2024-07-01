//
// Created by liyun on 24-6-29.
//

#ifndef SIZEIMPL_HPP
#define SIZEIMPL_HPP

#include "Engine/Core/Export.h"

namespace influx {
	template<typename T>
	class SizeImpl {
	public:
		using ValueType = T;
		using Ref = T &;
		using Ptr = T *;
		using ConstRef = const T &;
		using ConstPtr = const T *;
		INFLUX_INLINE static INFLUX_CONSTEXPR std::string_view base_name = "SizeImpl";
	};
} // influx

#endif //SIZEIMPL_HPP
