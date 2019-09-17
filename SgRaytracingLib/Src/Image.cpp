#include <fstream>
#include <iostream>

#include "Image.h"
#include "Clamp.h"

Image::Image(int width, int height)
{
	this->width = width;
	this->height = height;

	std::vector<Vector3> pixels;

	for (int i = 0; i < width * height; ++i)
		pixels.push_back(Vector3(0, 0, 0));

	this->pixels = pixels;
}

void Image::setPixels(const std::vector<Vector3>& pixels)
{
	this->pixels = pixels;
}

std::vector<Vector3> Image::getPixels()
{
	return pixels;
}

void Image::setPixel(int x, int y, Vector3 color)
{
	pixels[y * width + x] = color;
}

Vector3 Image::getPixel(int x, int y)
{
	return pixels[y * width + x];
}

bool Image::saveImage(const std::string& fileName)
{
	std::ofstream file;
	int r, g, b;
	Vector3 pixColor;

	file.open(fileName);
	file << "P3\n";
	file << width << " " << height << "\n";
	file << 255 << "\n";  //rgb max

	for (int i = 0; i < width * height; i++)
	{
		pixColor = pixels.at(i);
		r = (int)clamp<float>(pixColor.x * 255.f, 255, 0);
		g = (int)clamp<float>(pixColor.y * 255.f, 255, 0);
		b = (int)clamp<float>(pixColor.z * 255.f, 255, 0);
		file << r << " " << g << " " << b << "\n";
	}
	file.close();

	return true;
}