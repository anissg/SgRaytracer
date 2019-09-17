#include "OrthographicCamera.h"
#include "Sphere.h"

int main()
{
	// resolution
	int Width = 800;
	int Height = 600;

	Camera* camera = new OrthographicCamera(Vector3(0, 0, 0), Vector3(0, 0, 1), Width, Height);

	std::vector<Sphere> spheres;
	Sphere* sphere = nullptr;

	sphere = new Sphere(Vector3(100, 0, 150), 100);
	spheres.push_back(*sphere);

	sphere = new Sphere(Vector3(200, 0, 200), 120);
	spheres.push_back(*sphere);

	// rendering
	Image renderImg = camera->Render(spheres);

	// save the rendered image
	renderImg.saveImage("sphere.ppm");

}