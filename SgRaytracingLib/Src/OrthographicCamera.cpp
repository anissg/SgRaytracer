#include "OrthographicCamera.h"

OrthographicCamera::OrthographicCamera(Vector3 origin, Vector3 direction, int Width, int Height)
	:Camera(origin, direction)
{
	this->Width = Width;
	this->Height = Height;
}

Image OrthographicCamera::Render(const std::vector<Sphere>& spheres)
{
	Image img = Image(Width, Height);
	Vector3 color;
	Vector3 pixel;

	for (int x = 0; x < Width; x++)
	{
		for (int y = 0; y < Height; y++)
		{
			Vector3 rayOrigin = Vector3(origin.x - Width / 2 + x, origin.y - Height / 2 + y, origin.z);
			Ray ray = Ray(rayOrigin, direction);

			std::optional<float> distance = ray.Intersect(spheres);
			if (distance.has_value())
				pixel = Vector3(1, 1, 1)/* * (distance.value() / 300)*/;
			else
				pixel = Vector3(0, 0, 0);

			img.setPixel(x, y, pixel);
		}
	}

	return img;
}
