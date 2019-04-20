#pragma once
#include "Hitable.h"

class HitableList : public Hitable {
public:
	HitableList() {}
	HitableList(Hitable** list, int size) { m_list = list; m_list_size = size; }

	virtual bool hit(const Ray& ray, float t_min, float t_max, HitRecord& record);

	Hitable** m_list;
	int m_list_size;
};

bool HitableList::hit(const Ray& ray, float t_min, float t_max, HitRecord& record) {
	HitRecord temp_rec;
	bool hit_anything = false;
	double closest_so_far = t_max;

	for (int i = 0; i < m_list_size; i++) {
		if (m_list[i]->hit(ray, t_min, closest_so_far, temp_rec)) {
			hit_anything = true;
			closest_so_far = temp_rec.m_t;
			record = temp_rec;
		}
	}

	return hit_anything;
}
