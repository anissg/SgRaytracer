#include "OrthographicCamera.h"
#include "Sphere.h"

int main()
{
	// resolution
	int Width = 800;
	int Height = 600;

	Camera* camera = new OrthographicCamera(Vector3(0, 0, 0), Vector3(0, 0, 1), Width, Height);

	std::vector<Sphere> spheres;
	
	spheres.push_back(Sphere(Vector3(100, Height / 2.0f, 150), 100));
	spheres.push_back(Sphere(Vector3(0, -Height / 2.0f, 150), 100));

	// rendering
	Image renderImg = camera->Render(spheres);

	// save the rendered image
	renderImg.saveImage("sphere.ppm");

}