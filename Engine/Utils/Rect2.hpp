//
// Created by liyun on 24-6-29.
//

#ifndef RECT2_HPP
#define RECT2_HPP

#include <glm/glm.hpp>

#include "Engine/Core/Export.h"
#include "Internal/RectangleImpl.hpp"

namespace influx {
	template<typename T>
	class Rect2 : public RectangleImpl<T> {
	public:
		Rect2() = default;
		Rect2(const T &x, const T &y, const T &width, const T &height) : m_x(x), m_y(y), m_width(width), m_height(height) {
		}

		INFLUX_INLINE const T &X() const { return m_x; }

		INFLUX_INLINE const T &Y() const { return m_y; }

		INFLUX_INLINE const T &Width() const { return m_width; }

		INFLUX_INLINE const T &Height() const { return m_height; }

		INFLUX_INLINE void SetX(const T &x) { m_x = x; }

		INFLUX_INLINE void SetY(const T &y) { m_y = y; }

		INFLUX_INLINE void SetWidth(const T &width) { m_width = width; }

		INFLUX_INLINE void SetHeight(const T &height) { m_height = height; }

		INFLUX_INLINE bool Contains(const T &x, const T &y) const {
			return x >= m_x && x <= m_x + m_width && y >= m_y && y <= m_y + m_height;
		}

		INFLUX_INLINE bool Contains(const Rect2 &rect) const {
			return Contains(rect.m_x, rect.m_y) && Contains(rect.m_x + rect.m_width, rect.m_y + rect.m_height);
		}

		INFLUX_INLINE bool Intersects(const Rect2 &rect) const {
			return m_x < rect.m_x + rect.m_width && m_x + m_width > rect.m_x &&
				m_y < rect.m_y + rect.m_height && m_y + m_height > rect.m_y;
		}

		INFLUX_NODISCARD INFLUX_INLINE bool Valid() const {
			return m_width >= 0 && m_height >= 0;
		}

		INFLUX_INLINE Rect2 &Merge(const Rect2 &rect) {
			T x = std::min(m_x, rect.m_x);
			T y = std::min(m_y, rect.m_y);
			T width = std::max(m_x + m_width, rect.m_x + rect.m_width) - x;
			T height = std::max(m_y + m_height, rect.m_y + rect.m_height) - y;

			m_x = x;
			m_y = y;
			m_width = width;
			m_height = height;

			return *this;
		}

		INFLUX_INLINE Rect2 &Expand(const T &amount) {
			m_x -= amount;
			m_y -= amount;
			m_width += amount * 2;
			m_height += amount * 2;
			return *this;
		}

		INFLUX_INLINE Rect2 &Expand(const T &xAmount, const T &yAmount) {
			m_x -= xAmount;
			m_y -= yAmount;
			m_width += xAmount * 2;
			m_height += yAmount * 2;
			return *this;
		}

		INFLUX_INLINE Rect2 &Expand(const T &left, const T &top, const T &right, const T &bottom) {
			m_x -= left;
			m_y -= top;
			m_width += left + right;
			m_height += top + bottom;
			return *this;
		}

		INFLUX_INLINE Rect2 &Shrink(const T &amount) {
			m_x += amount;
			m_y += amount;
			m_width -= amount * 2;
			m_height -= amount * 2;
			return *this;
		}

		INFLUX_INLINE Rect2 &Shrink(const T &xAmount, const T &yAmount) {
			m_x += xAmount;
			m_y += yAmount;
			m_width -= xAmount * 2;
			m_height -= yAmount * 2;
			return *this;
		}

		INFLUX_INLINE Rect2 &Shrink(const T &left, const T &top, const T &right, const T &bottom) {
			m_x += left;
			m_y += top;
			m_width -= left + right;
			m_height -= top + bottom;
			return *this;
		}

		INFLUX_INLINE Rect2 &Translate(const T &x, const T &y) {
			m_x += x;
			m_y += y;
			return *this;
		}

		INFLUX_INLINE Rect2 &Translate(const glm::vec<2, T, glm::defaultp> &translation) {
			m_x += translation.x;
			m_y += translation.y;
			return *this;
		}

		INFLUX_INLINE T Area() const {
			return m_width * m_height;
		}

		INFLUX_INLINE T Left() const {
			return m_x;
		}

		INFLUX_INLINE T Right() const {
			return m_x + m_width;
		}

		INFLUX_INLINE T Top() const {
			return m_y;
		}

		INFLUX_INLINE T Bottom() const {
			return m_y + m_height;
		}

		INFLUX_INLINE glm::vec<2, T, glm::defaultp> TopLeft() const {
			return {m_x, m_y};
		}

		INFLUX_INLINE glm::vec<2, T, glm::defaultp> TopRight() const {
			return {m_x + m_width, m_y};
		}

	private:
		T m_x{};
		T m_y{};
		T m_width{};
		T m_height{};
	};

	using Rect2f = Rect2<float>;
	using Rect2d = Rect2<double>;
	using Rect2i = Rect2<int>;
	using Rect2u = Rect2<unsigned int>;
} // influx

#endif //RECT2_HPP
