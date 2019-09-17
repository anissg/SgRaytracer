#include "Sphere.h"
#include "Vector3.h"

Sphere::Sphere(Vector3 center, float radius)
{
	this->center = center;
	this->radius = radius;
}

Vector3 Sphere::GetCenter()const
{
	return center;
}

float Sphere::GetRaduis()const
{
	return radius;
}