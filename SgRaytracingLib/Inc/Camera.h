#pragma once

#include <vector>

#include "Vector3.h"
#include "Sphere.h"
#include "Image.h"
#include "Ray.h"

class Camera
{
protected:
	Vector3 origin;
	Vector3 direction;

	int Width;
	int Height;

public:
	Camera(Vector3& origin, Vector3& direction);

	virtual Image Render(const std::vector<Sphere>& spheres) = 0;
};