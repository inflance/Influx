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
		Range1() = default;

		Range1(const T &start, const T &end) : m_start(start), m_end(end) {
		}

		INFLUX_INLINE const T &Start() const { return m_start; }

		INFLUX_INLINE const T &End() const { return m_end; }

		INFLUX_INLINE void SetStart(const T &start) { m_start = start; }

		INFLUX_INLINE void SetEnd(const T &end) { m_end = end; }

		INFLUX_INLINE bool Contains(const T &value) const {
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

		void MakeEmpty() {
			m_start = std::numeric_limits<T>::max();
			m_end = -std::numeric_limits<T>::max();
		}

		INFLUX_NODISCARD INFLUX_INLINE T Length() const {
			return m_end - m_start;
		}

		INFLUX_INLINE T Center() const {
			return (m_start + m_end) / 2;
		}

		INFLUX_INLINE T Clamp(const T &value) const {
			return std::clamp(value, m_start, m_end);
		}

		INFLUX_INLINE T Lerp(const T &t) const {
			return m_start + t * Length();
		}

		INFLUX_INLINE T LerpClamped(const T &t) const {
			return m_start + Clamp(t) * Length();
		}

	private:
		T m_start = -std::numeric_limits<T>::max();
		T m_end = std::numeric_limits<T>::max();
	};
} // influx

#endif //RANGE1_HPP
