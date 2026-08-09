#include <geometry2d/api/direction_api.h>
#include <geometry2d/direction.hpp>
#include "api_cast.hpp"

using namespace geometry2d;

void direction_set_xy(Direction_C *direction, float x, float y)
{
    reinterpret_cast<Direction *>(direction)->setPoint(x, y);
}

void direction_set_xy_2(Direction_C *direction, float xFrom, float yFrom, float xTo, float yTo)
{
    reinterpret_cast<Direction *>(direction)->setPoint(xFrom, yFrom, xTo, yTo);
}

void direction_set_point(Direction_C *direction, Point_C point)
{
    reinterpret_cast<Direction *>(direction)->setPoint(POINT_2_LIB(point));
}

void direction_set_point_2(Direction_C *direction, Point_C from, Point_C to)
{
    reinterpret_cast<Direction *>(direction)->setPoint(POINT_2_LIB(from), POINT_2_LIB(to));
}

void direction_set_angle_radians(Direction_C *direction, float radians)
{
    reinterpret_cast<Direction *>(direction)->setAngleRadians(radians);
}

void direction_set_angle_degrees(Direction_C *direction, float degrees)
{
    reinterpret_cast<Direction *>(direction)->setAngleDegrees(degrees);
}

void direction_rotate_radians(Direction_C *direction, float radians)
{
    reinterpret_cast<Direction *>(direction)->rotateRadians(radians);
}

void direction_rotate_degrees(Direction_C *direction, float degrees)
{
    reinterpret_cast<Direction *>(direction)->rotateDegrees(degrees);
}

float direction_get_angle_difference_radians(Direction_C *from, Direction_C *to)
{
    return Direction::getAngleDifferenceRadians(*reinterpret_cast<Direction *>(from), *reinterpret_cast<Direction *>(to));
}

float direction_get_angle_difference_degrees(Direction_C *from, Direction_C *to)
{
    return Direction::getAngleDifferenceDegrees(*reinterpret_cast<Direction *>(from), *reinterpret_cast<Direction *>(to));
}

Direction_C direction_get_closest_normal(Direction_C *from, Direction_C *to)
{
    Direction result = Direction::getClosestNormalDirection(*reinterpret_cast<Direction *>(from), *reinterpret_cast<Direction *>(to));

    return DIRECTION_2_API(result);
}

Direction_C direction_get_furthest_normal(Direction_C *from, Direction_C *to)
{
    Direction result = Direction::getFurthestNormalDirection(*reinterpret_cast<Direction *>(from), *reinterpret_cast<Direction *>(to));

    return DIRECTION_2_API(result);
}
