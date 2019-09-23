#pragma once

#include "Vector3.h"

class Color
{
public:
    float r;
    float g;
    float b;

    //colors
    const Color White(1.0f, 1.0f, 1.0f);
    const Color Black(0.0f, 0.0f, 0.0f);
    const Color Red(1.0f, 0.0f, 0.0f);
    const Color Green(0.0f, 1.0f, 0.0f);
    const Color Blue(0.0f, 0.0f, 1.0f);

    // Constructors
    Color();
    Color(float x, float y, float z);
    Color(float x, float y);
    Color(const Color& o);
    Color(const Vector3& o);

    Color operator+(const Color& o);
    Color& operator+=(const Color& o);
    Color operator-(const Color& o)const;
    Color& operator-=(const Color& o);
    Color operator*(const float&)const;
    Color& operator*=(const float& s);
    Color operator/(const float& s);
    Color& operator/=(const float& s);


};

