#pragma once
#include "Camera.h"

class OrthographicCamera :
	public Camera
{

public:
	OrthographicCamera(Vector3 origin, Vector3 direction, int Width, int Height);
	
	Image Render(const std::vector<Sphere>& spheres);
};

