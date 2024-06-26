//
// Created by liyun on 24-6-27.
//

#ifndef AABB2_HPP
#define AABB2_HPP

#include <limits>
#include <glm/glm.hpp>

#include "Engine/Core/Export.h"
#include "Engine/Utils/Internal/BoundingBoxImpl.hpp"

namespace influx {
    template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>,T>>
    class AABB2 : public BoundingBoxImpl<T> {
    public:
        static INFLUX_CONSTEXPR typename BoundingBoxImpl<T>::ValueType MaxValue = std::numeric_limits<T>::max();
        static INFLUX_CONSTEXPR typename BoundingBoxImpl<T>::ValueType MinValue = -std::numeric_limits<T>::max();
        using ElementType = glm::vec<2, T, glm::defaultp>;

        AABB2() = default;

        AABB2(const ElementType &min, const ElementType &max) : m_min(min), m_max(max) {
        }

        AABB2(const T &minX, const T &minY, const T &maxX, const T &maxY): m_min(minX, minY), m_max(maxX, maxY) {
        }

        INFLUX_INLINE const ElementType &min() const { return m_min; }

        INFLUX_INLINE const ElementType &max() const { return m_max; }

        void setMin(const ElementType &min) { m_min = min; }

        void setMax(const ElementType &max) { m_max = max; }

        void expand(const ElementType &point) {
            m_min = glm::min(m_min, point);
            m_max = glm::max(m_max, point);
        }

        INFLUX_INLINE bool contains(const ElementType &point) const {
            return point.x >= m_min.x && point.x <= m_max.x &&
                   point.y >= m_min.y && point.y <= m_max.y;
        }

        INFLUX_INLINE bool contains(const AABB2 &box) const {
            return contains(box.min()) && contains(box.max());
        }

        INFLUX_NODISCARD INFLUX_INLINE bool valid() const {
            return m_min.x <= m_max.x && m_min.y <= m_max.y;
        }

        INFLUX_INLINE AABB2 &merge(const AABB2 &box) {
            m_min = glm::min(m_min, box.min());
            m_max = glm::max(m_max, box.max());
            return *this;
        }

        INFLUX_NODISCARD INFLUX_INLINE bool empty() const {
            return (m_min.x == m_max.x && m_min.y == m_max.y) || (
                       m_min.x == MaxValue && m_min.y == MaxValue && m_max.x == MinValue && m_max.y == MinValue);
        }

    private:
        ElementType m_min{MaxValue};
        ElementType m_max{MinValue};
    };

    using AABB2f = AABB2<float>;
    using AABB2d = AABB2<double>;
    using AABB2i = AABB2<int>;
}

template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>,T>>
INFLUX_STREAM_OUT_FUNCTION(influx::AABB2<T>,
                           "AABB2: min={" << type.min().x << "," << type.min().y << "}, max={" << type.max().x << "," <<
                           type.max().y<< "}")
#endif //AABB2_HPP
