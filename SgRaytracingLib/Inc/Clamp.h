#pragma once
#include <math.h>

template<class T>
static double clamp(T x, T upper, T lower)
{
	return fmin(upper, fmax(x, lower));
}