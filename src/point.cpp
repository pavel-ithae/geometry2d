#include <geometry2d/point.hpp>
#include <geometry2d/direction.hpp>
#include <math.h>
#include <iostream>
using namespace geometry2d;

#define EQUALS_APROX_EPSILON 0.001f

Point &Point::translate(float xTranslation, float yTranslation)
{
    Point::x += xTranslation;
    Point::y += yTranslation;

    return *this;
}

Point &Point::translate(const Direction &translationDirection, float translationLength)
{
    return translate(translationDirection.getTranslation(translationLength));
}

Point &Point::scale(float scale)
{
    Point::x *= scale;
    Point::y *= scale;

    return *this;
}

Point &Point::scale(const Point &pivot, float scale)
{
    Point delta((Point::x - pivot.x) * scale, (Point::y - pivot.y) * scale);

    Point::x = pivot.x + delta.x;
    Point::y = pivot.y + delta.y;

    return *this;
}

bool Point::equals(const Point &other) const
{
    return (Point::x == other.x) && (Point::y == other.y);
}

bool Point::equalsApprox(const Point &other) const
{
    return (std::abs(Point::x - other.x) < EQUALS_APROX_EPSILON) && (std::abs(Point::y - other.y) < EQUALS_APROX_EPSILON);
}

std::ostream &geometry2d::operator<<(std::ostream &os, const Point &point)
{
    os << "{" << point.x << ", " << point.y << "}";

    return os;
}

#undef EQUALS_APROX_EPSILON