#pragma once
#include <math.h>
#include <stdlib.h>
#include <iostream>

class Vec3 {
public:
	Vec3() {}
	Vec3(float p0, float p1, float p2) { p[0] = p0; p[1] = p1; p[2] = p2; }

	inline float x() const { return p[0]; }
	inline float y() const { return p[1]; }
	inline float z() const { return p[2]; }

	inline float r() const { return p[0]; }
	inline float g() const { return p[1]; }
	inline float b() const { return p[2]; }

	inline const Vec3& operator+() const { return *this; }
	inline Vec3 operator-() const { return Vec3(-p[0], -p[1], -p[2]); }
	inline float operator[](int i) const { return p[i]; }
	inline float& operator[](int i) { return p[i]; }

	inline Vec3& operator+=(const Vec3& rhs);
	inline Vec3& operator-=(const Vec3& rhs);
	inline Vec3& operator*=(const Vec3& rhs);
	inline Vec3& operator/=(const Vec3& rhs);

	inline Vec3& operator*=(float rhs);
	inline Vec3& operator/=(float rhs);

	inline float length() const {
		return sqrt(p[0] * p[0] + p[1] * p[1] + p[2] * p[2]);
	}
	inline float squared_length() const {
		return p[0] * p[0] + p[1] * p[1] + p[2] * p[2];
	}
	
	inline void make_unit_vector();

	float p[3];
};

inline Vec3& Vec3::operator+=(const Vec3& rhs) {
	p[0] += rhs.p[0];
	p[1] += rhs.p[1];
	p[2] += rhs.p[2];

	return *this;
}

inline Vec3& Vec3::operator-=(const Vec3& rhs) {
	p[0] -= rhs.p[0];
	p[1] -= rhs.p[1];
	p[2] -= rhs.p[2];

	return *this;
}

inline Vec3& Vec3::operator*=(const Vec3& rhs) {
	p[0] *= rhs.p[0];
	p[1] *= rhs.p[1];
	p[2] *= rhs.p[2];

	return *this;
}

inline Vec3& Vec3::operator/=(const Vec3& rhs) {
	p[0] /= rhs.p[0];
	p[1] /= rhs.p[1];
	p[2] /= rhs.p[2];

	return *this;
}

inline Vec3& Vec3::operator*=(float rhs) {
	p[0] *= rhs;
	p[1] *= rhs;
	p[2] *= rhs;

	return *this;
}
inline Vec3& Vec3::operator/=(float rhs) {
	float k = 1.0f / rhs;

	p[0] *= k;
	p[1] *= k;
	p[2] *= k;

	return *this;
}

inline void Vec3::make_unit_vector() {
	float k = 1 / this->length();
	p[0] *= k;
	p[1] *= k;
	p[2] *= k;
}

inline std::istream& operator>>(std::istream& is, Vec3& vec) {
	is >> vec.p[0] >> vec.p[1] >> vec.p[2];
	return is;
}

inline std::ostream& operator<<(std::ostream& os, const Vec3& vec) {
	os << vec.p[0] << " " << vec.p[1] << " " << vec.p[2];
	return os;
}

inline Vec3 operator+(const Vec3& v1, const Vec3& v2) {
	return Vec3(v1.p[0] + v2.p[0], v1.p[1] + v2.p[1], v1.p[2] + v2.p[2]);
}

inline Vec3 operator-(const Vec3& v1, const Vec3& v2) {
	return Vec3(v1.p[0] - v2.p[0], v1.p[1] - v2.p[1], v1.p[2] - v2.p[2]);
}

inline Vec3 operator*(const Vec3& v1, const Vec3& v2) {
	return Vec3(v1.p[0] * v2.p[0], v1.p[1] * v2.p[1], v1.p[2] * v2.p[2]);
}

inline Vec3 operator/(const Vec3& v1, const Vec3& v2) {
	return Vec3(v1.p[0] / v2.p[0], v1.p[1] / v2.p[1], v1.p[2] / v2.p[2]);
}


inline Vec3 operator*(float t, const Vec3& vec) {
	return Vec3(t * vec.p[0], t * vec.p[1], t* vec.p[2]);
}

inline Vec3 operator*(const Vec3& vec, float t) {
	return Vec3(t * vec.p[0], t * vec.p[1], t* vec.p[2]);
}


inline Vec3 operator/(Vec3 vec, float t) {
	return Vec3(vec.p[0] / t, vec.p[1] / t, vec.p[2] / t);
}


inline float dot(const Vec3& v1, const Vec3& v2) {
	return v1.p[0] * v2.p[0] + v1.p[1] * v2.p[1] + v1.p[2] * v2.p[2];
}

inline Vec3 cross(const Vec3& v1, const Vec3& v2) {
	return Vec3((v1.p[1] * v2.p[2] - v1.p[2] * v2.p[1]), (-v1.p[0] * v2.p[2] - v1.p[2] * v2.p[0]), (v1.p[0] * v2.p[1] - v1.p[1] * v2.p[0]));
}

inline Vec3 unit_vector(Vec3 vec) {
	return vec / vec.length();
}