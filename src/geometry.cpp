#include <geometry2d/geometry.hpp>
#include <math.h>

using namespace geometry2d;

float geometry2d::pointDistanceSqrd(const Point &a, const Point &b)
{
    Point diff = b - a;

    return (diff.x * diff.x) + (diff.y * diff.y);
}

float geometry2d::pointDistance(const Point &a, const Point &b)
{
    return std::sqrt(pointDistanceSqrd(a, b));
}

Point geometry2d::pointLerp(const Point &a, const Point &b, float interpolant)
{
    return Point(a + ((b - a) * interpolant));
}
