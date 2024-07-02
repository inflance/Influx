//
// Created by liyun on 24-6-29.
//

#ifndef RANGE1_HPP
#define RANGE1_HPP

#include <algorithm>

#include "Engine/Core/Export.h"
#include "Internal/RangeImpl.hpp"

namespace influx {
	template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>, T> >
	class Range1 : public RangeImpl<T>{
	public:
		using ElementType = T;

		Range1() = default;

		Range1(const ElementType &start, const ElementType &end) : m_start(start), m_end(end) {
		}

		INFLUX_INLINE const ElementType &Start() const { return m_start; }

		INFLUX_INLINE const ElementType &End() const { return m_end; }

		INFLUX_INLINE void SetStart(const ElementType &start) { m_start = start; }

		INFLUX_INLINE void SetEnd(const ElementType &end) { m_end = end; }

		INFLUX_INLINE bool Contains(const ElementType &value) const {
			return value >= m_start && value <= m_end;
		}

		INFLUX_INLINE bool Contains(const Range1 &range) const {
			return Contains(range.m_start) && Contains(range.m_end);
		}

		INFLUX_INLINE bool Intersects(const Range1 &range) const {
			return m_start < range.m_end && m_end > range.m_start;
		}

		INFLUX_NODISCARD INFLUX_INLINE bool Valid() const {
			return m_start <= m_end;
		}

		void Merge(const Range1 &range) {
			m_start = std::min(m_start, range.m_start);
			m_end = std::max(m_end, range.m_end);
		}

		INFLUX_NODISCARD INFLUX_INLINE ElementType Length() const {
			return m_end - m_start;
		}

		INFLUX_INLINE ElementType Center() const {
			return (m_start + m_end) / 2;
		}

		INFLUX_INLINE ElementType Clamp(const ElementType &value) const {
			return std::clamp(value, m_start, m_end);
		}

		INFLUX_INLINE ElementType Lerp(const ElementType &t) const {
			return m_start + t * Length();
		}

		INFLUX_INLINE ElementType LerpClamped(const ElementType &t) const {
			return m_start + Clamp(t) * Length();
		}

	private:
		ElementType m_start {};
		ElementType m_end {};
	};
} // influx

#endif //RANGE1_HPP
