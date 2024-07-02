//
// Created by liyun on 24-6-29.
//

#ifndef RANGE3_HPP
#define RANGE3_HPP

#include <glm/glm.hpp>

#include "Engine/Core/Export.h"
#include "Internal/RangeImpl.hpp"

namespace influx {
	template<typename T>
	class Range3 : public RangeImpl<T> {
	public:
		using ElementType = glm::vec<3, T, glm::defaultp>;

		Range3() = default;

		Range3(const ElementType &start, const ElementType &end) : m_start(start), m_end(end) {
		}

		Range3(const T &startX, const T &startY, const T &startZ, const T &endX, const T &endY,
		       const T &endZ) : m_start(startX, startY, startZ), m_end(endX, endY, endZ) {
		}

		INFLUX_INLINE const ElementType &Start() const { return m_start; }

		INFLUX_INLINE const ElementType &End() const { return m_end; }

		void SetStart(const ElementType &start) { m_start = start; }

		void SetEnd(const ElementType &end) { m_end = end; }


		INFLUX_INLINE bool Contains(const ElementType &point) const {
			return point.x >= m_start.x && point.x <= m_end.x &&
			       point.y >= m_start.y && point.y <= m_end.y &&
			       point.z >= m_start.z && point.z <= m_end.z;
		}

		INFLUX_INLINE bool Contains(const Range3 &range) const {
			return Contains(range.m_start) && Contains(range.m_end);
		}

		INFLUX_NODISCARD INFLUX_INLINE bool Valid() const {
			return m_start.x <= m_end.x && m_start.y <= m_end.y && m_start.z <= m_end.z;
		}

		INFLUX_INLINE Range3 &Merge(const Range3 &range) {
			m_start = glm::min(m_start, range.m_start);
			m_end = glm::max(m_end, range.m_end);
			return *this;
		}

		INFLUX_INLINE T Length() const {
			return glm::length(m_end - m_start);
		}

		INFLUX_INLINE ElementType Center() const {
			return (m_start + m_end) / 2;
		}

		INFLUX_INLINE ElementType Size() const {
			return m_end - m_start;
		}

		INFLUX_INLINE ElementType HalfSize() const {
			return (m_end - m_start) / 2;
		}

		INFLUX_INLINE ElementType Clamp(const ElementType &point) const {
			return glm::clamp(point, m_start, m_end);
		}

		INFLUX_INLINE ElementType Lerp(const T &t) const {
			return m_start + t * Length();
		}

	private:
		ElementType m_start{};
		ElementType m_end{};
	};
} // influx

#endif //RANGE3_HPP
