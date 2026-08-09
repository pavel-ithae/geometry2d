#include <geometry2d/api/point_api.h>
#include <geometry2d/api/direction_api.h>
#include <geometry2d/point.hpp>
#include <geometry2d/direction.hpp>
#include "api_cast.hpp"

using namespace geometry2d;

void point_translate(Point_C *point, float xTranslation, float yTranslation)
{
    reinterpret_cast<Point *>(point)->translate(xTranslation, yTranslation);
}

void point_translate_offset(Point_C *point, Point_C offsetTranslation)
{
    reinterpret_cast<Point *>(point)->translate(POINT_2_LIB(offsetTranslation));
}

void point_translate_direction(Point_C *point, Direction_C direction, float length)
{
    reinterpret_cast<Point *>(point)->translate(DIRECTION_2_LIB(direction), length);
}

void point_rotate_radians(Point_C *point, float radians)
{
    reinterpret_cast<Point *>(point)->rotateRadians(radians);
}

void point_rotate_radians_pivot(Point_C *point, Point_C pivot, float radians)
{
    reinterpret_cast<Point *>(point)->rotateRadians(POINT_2_LIB(pivot), radians);
}

void point_rotate_degrees(Point_C *point, float degrees)
{
    reinterpret_cast<Point *>(point)->rotateDegrees(degrees);
}

void point_rotate_degrees_pivot(Point_C *point, Point_C pivot, float degrees)
{
    reinterpret_cast<Point *>(point)->rotateDegrees(POINT_2_LIB(pivot), degrees);
}

void point_scale(Point_C *point, float scale)
{
    reinterpret_cast<Point *>(point)->scale(scale);
}

void point_scale_pivot(Point_C *point, Point_C pivot, float scale)
{
    reinterpret_cast<Point *>(point)->scale(POINT_2_LIB(pivot), scale);
}

bool equals(Point_C a, Point_C b)
{
    return POINT_2_LIB(a).equals(POINT_2_LIB(b));
}

bool equalsApprox(Point_C a, Point_C b)
{
    return POINT_2_LIB(a).equalsApprox(POINT_2_LIB(b));
}