#pragma once
#include "Hitable.h"

class Sphere : public Hitable {
public:
	Sphere() {}
	Sphere(Vec3 center, float radius) : m_center(center), m_radius(radius) {}

	virtual bool hit(const Ray& ray, float t_min, float t_max, HitRecord& record) override;
	
	Vec3 m_center;
	float m_radius;
};

bool Sphere::hit(const Ray& ray, float t_min, float t_max, HitRecord& record) {
	Vec3 oc = ray.origin() - m_center;
	float a = dot(ray.direction(), ray.direction());
	float b = dot(oc, ray.direction());
	float c = dot(oc, oc) - m_radius * m_radius;
	float discriminant = b * b - a * c;

	if (discriminant > 0) {
		float temp = (-b - sqrt(b * b - a * c)) / a;
		if (temp < t_max && temp > t_min) {
			record.m_t = temp;
			record.m_point = ray.point_at_parameter(record.m_t);
			record.m_normal = (record.m_point - m_center) / m_radius;
			
			return true;
		}

		temp = (-b + sqrt(b * b - a * c)) / a;
		if (temp < t_max && temp > t_min) {
			record.m_t = temp;
			record.m_point = ray.point_at_parameter(record.m_t);
			record.m_normal = (record.m_point - m_center) / m_radius;

			return true;
		}
	}

	return false;
}