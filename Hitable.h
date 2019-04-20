#pragma once
#include "Ray.h"

struct HitRecord {
	float m_t;
	Vec3 m_point;
	Vec3 m_normal;
};

class Hitable {
public:
	virtual bool hit(const Ray& ray, float t_min, float t_max, HitRecord& record) = 0;
};
