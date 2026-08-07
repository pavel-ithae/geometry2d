#pragma once
#include<geometry2d/point.hpp>

namespace geometry2d
{
    float pointDistanceSqrd(const Point &a, const Point &b);
    float pointDistance(const Point &a, const Point &b);
    Point pointLerp(const Point &a, const Point &b, float interpolant);
}