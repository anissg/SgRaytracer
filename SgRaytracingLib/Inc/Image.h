#pragma once

#include <vector>
#include <string>

#include "Color.h"

class Image
{
private:
	int width;
	int height;
	std::vector<Color> pixels;
public:
	static const float RGBScale;
	static const float RGBMax;

	Image(int width, int height);
	void setPixels(const std::vector<Color>& pixels);
	std::vector<Color> getPixels();
	void setPixel(int x, int y, Color color);
	Vector3 getPixel(int x, int y);
	bool saveImage(const std::string& fileName);
};
