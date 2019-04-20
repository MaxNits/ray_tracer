#include <iostream>
#include <fstream>
#include <float.h>

#include "Camera.h"
#include "HitableList.h"
#include "Ray.h"
#include "Sphere.h"
#include "Vec3.h"

Vec3 color(const Ray& ray, Hitable* world) {
	HitRecord rec;
	if (world->hit(ray, 0.0f, FLT_MAX, rec)) {
		return 0.5f * Vec3(rec.m_normal.x() + 1, rec.m_normal.y() + 1, rec.m_normal.z() + 1);
	}
	else {
		Vec3 unit_direction = unit_vector(ray.direction());
		float t = 0.5f * (unit_direction.y() + 1.0f);
		return (1.0f - t) * Vec3(1.0f, 1.0f, 1.0f) + t * Vec3(0.5f, 0.7f, 1.0f);
	}
}

int main() {
	std::ofstream out_file;
	out_file.open("colors.ppm");

	int nx = 200;
	int ny = 100;

	out_file << "P3\n" << nx << " " << ny << "\n255\n";

	Vec3 lower_left_corner(-2.0f, -1.0f, -1.0f);
	Vec3 horizontal(4.0f, 0.0f, 0.0f);
	Vec3 vertical(0.0f, 2.0f, 0.0f);
	Vec3 origin(0.0f, 0.0f, 0.0f);

	Hitable* list[2];
	list[0] = new Sphere(Vec3(0.0f, 0.0f, -1.0f), 0.5f);
	list[1] = new Sphere(Vec3(0.0f, -100.5f, -1.0f), 100.f);

	Hitable* world = new HitableList(list, 2);

	for (int j = ny - 1; j >= 0; j--) {
		for (int i = 0; i < nx; i++) {
			float u = float(i) / float(nx);
			float v = float(j) / float(ny);
			Ray r(origin, lower_left_corner + u * horizontal + v * vertical);

			Vec3 col = color(r, world);

			int ir = int(255.99 * col[0]);
			int ig = int(255.99 * col[1]);
			int ib = int(255.99 * col[2]);

			out_file << ir << " " << ig << " " << ib << "\n";
		}
	}
}