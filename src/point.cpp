#include <geometry2d/point.hpp>
#include <geometry2d/direction.hpp>
#include <geometry2d/macros.hpp>
#include <math.h>
#include <iostream>

using namespace geometry2d;

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

Point &Point::rotateRadians(float radians)
{
    Point temp(Point::x, Point::y);

    float cos = std::cos(radians);
    float sin = std::sin(radians);

    Point::x = (temp.x * cos) - (temp.y * sin);
    Point::y = (temp.x * sin) + (temp.y * cos);

    return *this;
}

Point &Point::rotateRadians(const Point &pivot, float radians)
{
    Point temp(Point::x - pivot.x, Point::y - pivot.y);

    float cos = std::cos(radians);
    float sin = std::sin(radians);

    Point::x = pivot.x + ((temp.x * cos) - (temp.y * sin));
    Point::y = pivot.y + ((temp.x * sin) + (temp.y * cos));

    return *this;
}

Point &Point::rotateDegrees(float degrees)
{
    return rotateRadians(DEGREES_TO_RADIANS(degrees));
}

Point &Point::rotateDegrees(const Point &pivot, float degrees)
{
    return rotateRadians(pivot, DEGREES_TO_RADIANS(degrees));
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