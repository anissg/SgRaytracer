#pragma once

#include <math.h>

struct Vector3
{
public:
	float x;
	float y;
	float z;

	// Constructors
	Vector3();
	Vector3(float x, float y, float z);
	Vector3(float x, float y);
	Vector3(const Vector3& o);

	// Operators
	Vector3 operator+(const Vector3& o);
	Vector3& operator+=(const Vector3& o);
	Vector3 operator-()const;
	Vector3 operator-(const Vector3& o)const;
	Vector3& operator-=(const Vector3& o);
	Vector3 operator*(const float&)const;
	Vector3& operator*=(const float& s);
	Vector3 operator/(const float& s);
	Vector3& operator/=(const float& s);
	float operator*(const Vector3& o)const;		// Dot product
	Vector3 operator^(const Vector3& o);		// Cross product
	Vector3& operator^=(const Vector3& o);		// Cross product

	// Other functions
	float magnitude();
	float magnitude_sqr();
	Vector3 normalised();
	void normalise();
};

