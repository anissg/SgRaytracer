#pragma once

#include <vector>
#include <string>

#include "Vector3.h"

class Image
{
private:
	int width;
	int height;
	std::vector<Vector3> pixels;
public:
	static const float RGBScale;
	static const float RGBMax;

	Image(int width, int height);
	void setPixels(const std::vector<Vector3>& pixels);
	std::vector<Vector3> getPixels();
	void setPixel(int x, int y, Vector3 color);
	Vector3 getPixel(int x, int y);
	bool saveImage(const std::string& fileName);
};
