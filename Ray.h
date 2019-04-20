#pragma once
#include "Vec3.h"

class Ray
{
public:
	Ray() {}
	Ray(const Vec3& a, const Vec3& b) { mA = a; mB = b;	}

	Vec3 origin() const { return mA; }
	Vec3 direction() const { return mB; }
	Vec3 point_at_parameter(float t) const { return mA + t * mB; }

	Vec3 mA;
	Vec3 mB;
};
