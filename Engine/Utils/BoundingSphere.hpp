//
// Created by liyun on 24-6-27.
//

#ifndef BOUNDINGSPHERE_HPP
#define BOUNDINGSPHERE_HPP

#include <glm/glm.hpp>

#include "Engine/Core/Export.h"
#include "Engine/Utils/Internal/BoundingBoxImpl.hpp"

namespace influx {
	template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>, T> >
	class BoundingSphere : public BoundingBoxImpl<T> {
	public:
		static INFLUX_CONSTEXPR typename BoundingBoxImpl<T>::ValueType MaxValue = std::numeric_limits<T>::max();
		static INFLUX_CONSTEXPR typename BoundingBoxImpl<T>::ValueType MinValue = -std::numeric_limits<T>::max();
		using ElementType = glm::vec<3, T, glm::defaultp>;

		BoundingSphere() = default;

		BoundingSphere(const ElementType &center, const T &radius) : m_center(center), m_radius(radius) {
		}

		INFLUX_INLINE const ElementType &Center() const { return m_center; }

		INFLUX_INLINE const T &Radius() const { return m_radius; }

		void SetCenter(const ElementType &center) { m_center = center; }

		void SetRadius(const T &radius) { m_radius = radius; }

		INFLUX_INLINE bool Contains(const ElementType &point) const {
			return glm::distance(m_center, point) <= m_radius;
		}

		INFLUX_INLINE bool Contains(const BoundingSphere &sphere) const {
			return glm::distance(m_center, sphere.m_center) + sphere.m_radius <= m_radius;
		}

	private:
		ElementType m_center{};
		T m_radius{};
	};

	using BoundingSpheref = BoundingSphere<float>;
	using BoundingSphered = BoundingSphere<double>;
	using BoundingSpherei = BoundingSphere<int>;
} // influx

template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>, T> >
INFLUX_STREAM_OUT_FUNCTION(influx::BoundingSphere<T>,
                           "BoundingSphere: center={" << type.Center().x << "," << type.Center().y << ","<< type.Center(
                           ).z << "}, radius={" <<
                           type.Radius() << "}")

#endif //BOUNDINGSPHERE_HPP
