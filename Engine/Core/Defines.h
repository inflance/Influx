//
// Created by liyun on 2024/6/25.
//

#ifndef DEFINES_H
#define DEFINES_H

#if defined(_WIN32) || defined(_WIN64)
#   define INFLUX_PLATFORM_WINDOWS
#elif defined(__linux__)
#   define INFLUX_PLATFORM_LINUX
#elif defined(__APPLE__)
#   define INFLUX_PLATFORM_MACOS
#endif

#if defined(_MSVC_LANG)
#   define INFLUX_CPP _MSVC_LANG
#elif defined(__cplusplus)
#   define INFLUX_CPP __cplusplus
#endif

#if defined(__clang__)
#   define INFLUX_COMPILER_CLANG
#elif defined(__GNUC__)
#   define INFLUX_COMPILER_GCC
#elif defined(_MSC_VER)
#   define INFLUX_COMPILER_MSVC
#endif

#if INFLUX_CPP > 202002L
#   define INFLUX_CPP_VERSION 23
#elif INFLUX_CPP > 201703L
#   define INFLUX_CPP_VERSION 20
#elif INFLUX_CPP > 201402L
#   define INFLUX_CPP_VERSION 17
#elif INFLUX_CPP > 201103L
#   define INFLUX_CPP_VERSION 14
#elif INFLUX_CPP > 199711L
#   define INFLUX_CPP_VERSION 11
#endif

#if !defined(INFLUX_ASSERT)
#   include <cassert>
#   define INFLUX_ASSERT(x) assert(x)
#endif

#if !defined(INFLUX_INLINE)
#   if defined(INFLUX_COMPILER_MSVC)
#       define INFLUX_INLINE __forceinline
#   elif defined(INFLUX_COMPILER_GCC) || defined(INFLUX_COMPILER_CLANG)
#       define INFLUX_INLINE __attribute__((always_inline)) inline
#   else
#       define INFLUX_INLINE inline
#   endif
#endif

#if !defined(INFLUX_CONSTEXPR)
#   if INFLUX_CPP_VERSION >= 20
#       define INFLUX_CONSTEXPR constexpr
#   else
#       define INFLUX_CONSTEXPR
#   endif
#endif

#if !defined(INFLUX_NODISCARD)
#   if INFLUX_CPP_VERSION >= 17
#       define INFLUX_NODISCARD [[nodiscard]]
#   else
#       define INFLUX_NODISCARD
#   endif
#endif

#if !defined(INFLUX_STREAM_OUT_FUNCTION)
#include <ostream>
#define INFLUX_STREAM_OUT_FUNCTION(Type, ...)\
    INFLUX_INLINE std::ostream& operator<<(std::ostream &os, const Type& type ){\
        os << __VA_ARGS__;\
        return os;\
    }
#endif

#endif //DEFINES_H
