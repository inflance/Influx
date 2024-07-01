//
// Created by liyun on 24-6-29.
//

#ifndef RECT3_HPP
#define RECT3_HPP

#include <glm/vec3.hpp>

#include "Engine/Core/Export.h"
#include "Internal/RectangleImpl.hpp"

namespace influx {

	template<typename T>
class  Rect3  : public RectangleImpl<T>{
public:
	Rect3() = default;
	Rect3(const T &x, const T &y, const T &z, const T &width, const T &height, const T &depth) : m_x(x), m_y(y), m_z(z), m_width(width), m_height(height), m_depth(depth) {
	}

	INFLUX_INLINE const T &X() const { return m_x; }

	INFLUX_INLINE const T &Y() const { return m_y; }

	INFLUX_INLINE const T &Z() const { return m_z; }

	INFLUX_INLINE const T &Width() const { return m_width; }

	INFLUX_INLINE const T &Height() const { return m_height; }

	INFLUX_INLINE const T &Depth() const { return m_depth; }

	INFLUX_INLINE void SetX(const T &x) { m_x = x; }

	INFLUX_INLINE void SetY(const T &y) { m_y = y; }

	INFLUX_INLINE void SetZ(const T &z) { m_z = z; }

	INFLUX_INLINE void SetWidth(const T &width) { m_width = width; }

	INFLUX_INLINE void SetHeight(const T &height) { m_height = height; }

	INFLUX_INLINE void SetDepth(const T &depth) { m_depth = depth; }

	INFLUX_INLINE bool Contains(const T &x, const T &y, const T &z) const {
		return x >= m_x && x <= m_x + m_width && y >= m_y && y <= m_y + m_height && z >= m_z && z <= m_z + m_depth;
	}

	INFLUX_INLINE bool Contains(const Rect3 &rect) const {
		return Contains(rect.m_x, rect.m_y, rect.m_z) && Contains(rect.m_x + rect.m_width, rect.m_y + rect.m_height, rect.m_z + rect.m_depth);
	}

	INFLUX_INLINE bool Intersects(const Rect3 &rect) const {
		return m_x < rect.m_x + rect.m_width && m_x + m_width > rect.m_x &&
			m_y < rect.m_y + rect.m_height && m_y + m_height > rect.m_y &&
			m_z < rect.m_z + rect.m_depth && m_z + m_depth > rect.m_z;
	}

	INFLUX_NODISCARD INFLUX_INLINE bool Valid() const
	{
		return m_width >= 0 && m_height >= 0 && m_depth >= 0;
	}

		INFLUX_INLINE Rect3 &Merge(const Rect3 &rect) {
			T x = std::min(m_x, rect.m_x);
			T y = std::min(m_y, rect.m_y);
			T z = std::min(m_z, rect.m_z);
			T width = std::max(m_x + m_width, rect.m_x + rect.m_width) - x;
			T height = std::max(m_y + m_height, rect.m_y + rect.m_height) - y;
			T depth = std::max(m_z + m_depth, rect.m_z + rect.m_depth) - z;

			m_x = x;
			m_y = y;
			m_z = z;
			m_width = width;
			m_height = height;
			m_depth = depth;

			return *this;
		}

		INFLUX_INLINE Rect3 &Expand(const T &amount) {
			m_x -= amount;
			m_y -= amount;
			m_z -= amount;
			m_width += amount * 2;
			m_height += amount * 2;
			m_depth += amount * 2;
			return *this;
		}

		INFLUX_INLINE Rect3 &Expand(const T &xAmount, const T &yAmount, const T &zAmount) {
			m_x -= xAmount;
			m_y -= yAmount;
			m_z -= zAmount;
			m_width += xAmount * 2;
			m_height += yAmount * 2;
			m_depth += zAmount * 2;
			return *this;
		}

		INFLUX_INLINE Rect3 &Expand(const T &xAmount, const T &yAmount) {
			m_x -= xAmount;
			m_y -= yAmount;
			m_width += xAmount * 2;
			m_height += yAmount * 2;
			return *this;
		}

		INFLUX_INLINE Rect3 &Expand(const T &left, const T &top, const T &right, const T &bottom, const T &front, const T &back) {
			m_x -= left;
			m_y -= top;
			m_z -= front;
			m_width += left + right;
			m_height += top + bottom;
			m_depth += front + back;
			return *this;
		}

		INFLUX_INLINE Rect3 &Shrink(const T &amount) {
			m_x += amount;
			m_y += amount;
			m_z += amount;
			m_width -= amount * 2;
			m_height -= amount * 2;
			m_depth -= amount * 2;
			return *this;
		}

		INFLUX_INLINE Rect3 &Shrink(const T &xAmount, const T &yAmount, const T &zAmount) {
			m_x += xAmount;
			m_y += yAmount;
			m_z += zAmount;
			m_width -= xAmount * 2;
			m_height -= yAmount * 2;
			m_depth -= zAmount * 2;
			return *this;
		}

		INFLUX_INLINE Rect3 &Shrink(const T &xAmount, const T &yAmount) {
			m_x += xAmount;
			m_y += yAmount;
			m_width -= xAmount * 2;
			m_height -= yAmount * 2;
			return *this;
		}

		INFLUX_INLINE Rect3 &Shrink(const T &left, const T &top, const T &right, const T &bottom, const T &front, const T &back) {
			m_x += left;
			m_y += top;
			m_z += front;
			m_width -= left + right;
			m_height -= top + bottom;
			m_depth -= front + back;
			return *this;
		}

		INFLUX_INLINE Rect3 &Translate(const T &x, const T &y, const T &z) {
			m_x += x;
			m_y += y;
			m_z += z;
			return *this;
		}

		INFLUX_INLINE Rect3 &Translate(const glm::vec<3, T, glm::defaultp> &translation) {
			m_x += translation.x;
			m_y += translation.y;
			m_z += translation.z;
			return *this;
		}

		INFLUX_INLINE T Volume()
		{
			return m_width * m_height * m_depth;
		}

		INFLUX_INLINE T Area()
		{
			return 2 * (m_width * m_height + m_width * m_depth + m_height * m_depth);
		}

		INFLUX_INLINE glm::vec<3, T, glm::defaultp> Center() const
		{
			return glm::vec<3, T, glm::defaultp>(m_x + m_width / 2, m_y + m_height / 2, m_z + m_depth / 2);
		}

		INFLUX_INLINE glm::vec<3, T, glm::defaultp> Min() const
		{
			return glm::vec<3, T, glm::defaultp>(m_x, m_y, m_z);
		}

		INFLUX_INLINE glm::vec<3, T, glm::defaultp> Max() const
		{
			return glm::vec<3, T, glm::defaultp>(m_x + m_width, m_y + m_height, m_z + m_depth);
		}

	private:
		T m_x{};
		T m_y{};
		T m_z{};
		T m_width{};
		T m_height{};
		T m_depth{};
};

} // influx

#endif //RECT3_HPP
