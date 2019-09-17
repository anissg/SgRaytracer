#include "Ray.h"
#include <cmath>

Ray::Ray(Vector3 origin, Vector3 direction)
{
	this->origin = origin;
	this->direction = direction;
}

std::optional<float> Ray::Intersect(Sphere sphere)
{
	float R = sphere.GetRaduis();
	Vector3 oc = origin - sphere.GetCenter();

	float b = direction * oc;
	float c = (oc * oc) - (R * R);
	float delta = b * b - c;

	if (delta < 0)
		return {};

	float sqrtDelta = sqrt(delta);

	float distance = fmin(-b - sqrtDelta, -b + sqrtDelta);

	if (distance < 0)
		return {};

	return distance;
}

std::optional<float> Ray::Intersect(std::vector<Sphere> sList)
{
	float minDist = FLT_MAX;
	
	for (Sphere sphere : sList)
	{
		float dist = Intersect(sphere).value_or(FLT_MAX);
		minDist = fmin(dist, FLT_MAX);
	}

	if (minDist < FLT_MAX)
		return minDist;

	return {};
}
