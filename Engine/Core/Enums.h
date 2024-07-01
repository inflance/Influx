//
// Created by liyun on 2024/6/26.
//

#ifndef ENUMS_H
#define ENUMS_H

#include <type_traits>

#include "Engine/Core/Defines.h"

namespace influx {

    template <typename FlagBitType>
    struct FlagTraits {
        static INFLUX_CONSTEXPR bool is_bit_mask = false;
    };

    template<typename BitType>
    class Flags {
    public:
        using MaskType = std::underlying_type_t<BitType>;

        INFLUX_CONSTEXPR Flags() : m_mask(0) {}

        INFLUX_CONSTEXPR explicit Flags(BitType bit) : m_mask(static_cast<MaskType>(bit)) {}

        INFLUX_CONSTEXPR explicit Flags(MaskType bit) : m_mask(bit) {}

        INFLUX_CONSTEXPR Flags(Flags const& other) = default;

        INFLUX_CONSTEXPR bool operator<(const Flags &other) const {
            return m_mask < other.m_mask;
        }

        INFLUX_CONSTEXPR bool operator>(const Flags &other) const {
            return m_mask > other.m_mask;
        }

        INFLUX_CONSTEXPR bool operator<=(const Flags &other) const {
            return m_mask <= other.m_mask;
        }

        INFLUX_CONSTEXPR bool operator>=(const Flags &other) const {
            return m_mask >= other.m_mask;
        }

        INFLUX_CONSTEXPR bool operator==(const Flags &other) const {
            return m_mask == other.m_mask;
        }

        INFLUX_CONSTEXPR bool operator!=(const Flags &other) const {
            return m_mask != other.m_mask;
        }

        INFLUX_CONSTEXPR bool operator!() const {
            return !m_mask;
        }

        INFLUX_CONSTEXPR Flags operator&(const Flags &other) const {
            return Flags(m_mask&other.m_mask);
        }

        INFLUX_CONSTEXPR Flags operator|(const Flags &other) const {
            return Flags(m_mask | other.m_mask);
        }

        INFLUX_CONSTEXPR Flags operator^(const Flags &other) const {
            return Flags(m_mask ^ other.m_mask);
        }

        INFLUX_CONSTEXPR Flags operator~() const {
            return Flags(m_mask ^ FlagTraits<BitType>::allFlags.m_mask);
        }

        INFLUX_CONSTEXPR Flags &operator&=(const Flags &other) {
            m_mask &= other.m_mask;
            return *this;
        }

        INFLUX_CONSTEXPR Flags &operator|=(const Flags &other) {
            m_mask |= other.m_mask;
            return *this;
        }

        INFLUX_CONSTEXPR Flags &operator^=(const Flags &other) {
            m_mask ^= other.m_mask;
            return *this;
        }

        explicit INFLUX_CONSTEXPR operator bool() const {
            return !!m_mask;
        }

        explicit INFLUX_CONSTEXPR operator MaskType() const {
            return m_mask;
        }

    private:
        MaskType m_mask;
    };

    template<typename BitType>
    INFLUX_CONSTEXPR Flags<BitType> operator|(BitType bit, Flags<BitType> flags) {
        return flags | bit;
    }

    template<typename BitType>
    INFLUX_CONSTEXPR Flags<BitType> operator&(BitType bit, Flags<BitType> flags) {
        return flags & bit;
    }

    template<typename BitType>
    INFLUX_CONSTEXPR Flags<BitType> operator^(BitType bit, Flags<BitType> flags) {
        return flags ^ bit;
    }

    template<typename BitType, std::enable_if_t<FlagTraits<BitType>::is_bit_mask, bool> = true>
    INFLUX_CONSTEXPR Flags<BitType> operator&(BitType bit, BitType bit2) {
        return Flags<BitType>(bit) & Flags<BitType>(bit2);
    }

    template<typename BitType, std::enable_if_t<FlagTraits<BitType>::is_bit_mask, bool> = true>
    INFLUX_CONSTEXPR Flags<BitType> operator|(BitType bit, BitType bit2) {
        return Flags<BitType>(bit) | Flags<BitType>(bit2);
    }

    template<typename BitType, std::enable_if_t<FlagTraits<BitType>::is_bit_mask, bool> = true>
    INFLUX_CONSTEXPR Flags<BitType> operator^(BitType bit, BitType bit2) {
        return Flags<BitType>(bit) ^ Flags<BitType>(bit2);
    }

    template<typename BitType, std::enable_if_t<FlagTraits<BitType>::is_bit_mask, bool> = true>
    INFLUX_CONSTEXPR Flags<BitType> operator~(BitType bit) {
        return ~Flags<BitType>(bit);
    }

    enum class ProjectionType {
        Perspective,
        Orthographic
    };


}

#endif //ENUMS_H
