//
// Created by liyun on 24-6-27.
//

#ifndef AABB3_HPP
#define AABB3_HPP

#include <limits>
#include <glm/glm.hpp>

#include "Engine/Core/Export.h"
#include "Engine/Utils/Internal/BoundingBoxImpl.hpp"

namespace influx {
    template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>,T>>
    class AABB3 {
    public:
        static INFLUX_CONSTEXPR typename BoundingBoxImpl<T>::ValueType MaxValue = std::numeric_limits<T>::max();
        static INFLUX_CONSTEXPR typename BoundingBoxImpl<T>::ValueType MinValue = -std::numeric_limits<T>::max();
        using ElementType = glm::vec<3, T, glm::defaultp>;

        AABB3() = default;

        AABB3(const ElementType &min, const ElementType &max) : m_min(min), m_max(max) {
        }

        AABB3(const T &minX, const T &minY, const T &maxX, const T &maxY, const T &minZ,
              const T &maxZ): m_min(minX, minY, minZ), m_max(maxX, maxY, maxZ) {
        }

        INFLUX_INLINE const ElementType &Min() const { return m_min; }

        INFLUX_INLINE const ElementType &Max() const { return m_max; }

        void SetMin(const ElementType &min) { m_min = min; }

        void SetMax(const ElementType &max) { m_max = max; }

        void Expand(const ElementType &point) {
            m_min = glm::min(m_min, point);
            m_max = glm::max(m_max, point);
        }

        INFLUX_INLINE bool Contains(const ElementType &point) const {
            return point.x >= m_min.x && point.x <= m_max.x &&
                   point.y >= m_min.y && point.y <= m_max.y &&
                   point.z >= m_min.z && point.z <= m_max.z;
        }

        INFLUX_INLINE bool Contains(const AABB3 &box) const {
            return contains(box.Min()) && contains(box.Max());
        }

        INFLUX_NODISCARD INFLUX_INLINE bool Valid() const {
            return m_min.x <= m_max.x && m_min.y <= m_max.y && m_min.z <= m_max.z;
        }

        INFLUX_INLINE AABB3 &Merge(const AABB3 &box) {
            m_min = glm::min(m_min, box.Min());
            m_max = glm::max(m_max, box.Max());
            return *this;
        }

        INFLUX_NODISCARD INFLUX_INLINE bool Empty() const {
            return (m_min.x == m_max.x && m_min.y == m_max.y && m_min.z == m_max.z) || (
                       m_min.x == MaxValue && m_min.y == MaxValue && m_min.z == MaxValue && m_max.x == MinValue && m_max
                       .y == MinValue && m_max.z == MinValue);
        }

    private:
        ElementType m_min{MaxValue};
        ElementType m_max{MinValue};
    };

    using AABB3f = AABB3<float>;
    using AABB3d = AABB3<double>;
    using AABB3i = AABB3<int>;
} // influx
template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>,T>>
INFLUX_STREAM_OUT_FUNCTION(influx::AABB3<T>,
                           "AABB3: min={" << type.Min().x << "," << type.Min().y << ","<< type.Min().z << "}, max={" <<
                           type.Max().x << "," << type.Max().y<< "," << type.Max().z << "}")
#endif //AABB3_HPP
