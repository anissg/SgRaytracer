#include "Vector3.h"

const float epsilon = .000001f;

Vector3::Vector3() 
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3(float x, float y) 
{
	this->x = x;
	this->y = y;
	z = 0;
}

Vector3::Vector3(const Vector3& o) 
{
	x = o.x;
	y = o.y;
	z = o.z;
}

bool Vector3::operator==(const Vector3& o)const
{
	return (x == o.x && y == o.y && z == o.z);
}

Vector3 Vector3::operator+(const Vector3& o) 
{
	return Vector3(x + o.x, y + o.y, z + o.z);
}

Vector3& Vector3::operator+=(const Vector3& o) 
{
	x += o.x;
	y += o.y;
	z += o.z;
	return *this;
}

Vector3 Vector3::operator-()const 
{
	return Vector3(-x, -y, -z);
}

Vector3 Vector3::operator-(const Vector3& o)const 
{
	return Vector3(x - o.x, y - o.y, z - o.z);
}

Vector3& Vector3::operator-=(const Vector3& o) 
{
	x -= o.x;
	y -= o.y;
	z -= o.z;
	return *this;
}

Vector3 Vector3::operator*(const float& s)const 
{
	return Vector3(x * s, y * s, z * s);
}

Vector3& Vector3::operator*=(const float& s) 
{
	x *= s;
	y *= s;
	z *= s;
	return *this;
}

Vector3 Vector3::operator/(const float& s) 
{
	return Vector3(x / s, y / s, z / s);
}

Vector3& Vector3::operator/=(const float& s) 
{
	x /= s;
	y /= s;
	z /= s;
	return *this;
}

float Vector3::operator*(const Vector3& o)const 
{
	return (x * o.x) + (y * o.y) + (z * o.z);
}

Vector3 Vector3::operator^(const Vector3& o) 
{
	float nx = y * o.z - o.y * z;
	float ny = z * o.x - o.z * x;
	float nz = x * o.y - o.x * y;
	return Vector3(nx, ny, nz);
}

Vector3& Vector3::operator^=(const Vector3& o) 
{
	float nx = y * o.z - o.y * z;
	float ny = z * o.x - o.z * x;
	float nz = x * o.y - o.x * y;
	x = nx;
	y = ny;
	z = nz;
	return *this;
}

float Vector3::magnitude()
{
	return sqrtf(magnitude_sqr());
}

float Vector3::magnitude_sqr() 
{
	return (x * x) + (y * y) + (z * z);
}

Vector3 Vector3::normalised() 
{
	return Vector3(*this) / magnitude();
}

void Vector3::normalise() 
{
	(*this) /= magnitude();
}