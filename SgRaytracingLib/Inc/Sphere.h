#pragma once
#include "Vector3.h"

class Sphere
{
private:
	Vector3 center;
	float radius;

public:
	Sphere(Vector3 center, float radius);

	Vector3 GetCenter()const;
	float GetRaduis()const;
};

