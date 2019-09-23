#pragma once
#include <vector>
#include <optional>
#include "Vector3.h"
#include "Sphere.h"

class Ray
{
	Vector3 origin;
	Vector3 direction;

public:
	Ray(Vector3 origin, Vector3 direction);

	std::optional<float> Intersect(Sphere s) const;
	std::optional<float> Intersect(std::vector<Sphere> sList) const;

};

