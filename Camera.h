#pragma once
#include "Ray.h"

class Camera {
public:
	Camera() 
		: m_lower_left_corner(-2.0f, -1.0f, -1.0f)
		, m_horizontal(4.0f, 0.0f, 0.0f)
		, m_vertical(0.0f, 2.0f, 0.0f)
		, m_origin(0.0f, 0.0f, 0.0f)
	{}

	Ray get_ray(float u, float v) { return Ray(m_origin, m_lower_left_corner + u * m_horizontal + v * m_vertical); }

	Vec3 m_origin;
	Vec3 m_lower_left_corner;
	Vec3 m_horizontal;
	Vec3 m_vertical;
};