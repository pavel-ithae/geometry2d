#pragma once

namespace geometry2d
{
    class Point;
    class Direction;
}

struct Point_C;
struct Direction_C;

#define POINT_2_API(point) (*reinterpret_cast<Point_C *>(&point))
#define POINT_2_LIB(point) (*reinterpret_cast<geometry2d::Point *>(&point))

#define DIRECTION_2_API(direction) (*reinterpret_cast<Direction_C *>(&direction))
#define DIRECTION_2_LIB(direction) (*reinterpret_cast<geometry2d::Direction *>(&direction))