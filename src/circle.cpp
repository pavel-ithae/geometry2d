#include <geometry2d/circle.hpp>
#include <iostream>
#include "macros.hpp"

using namespace geometry2d;

Circle &Circle::translate(float xTranslation, float yTranslation)
{
    Circle::center.translate(xTranslation, yTranslation);

    return *this;
}

Circle &Circle::translate(const Direction &translationDirection, float translationLength)
{
    Circle::center.translate(translationDirection, translationLength);

    return *this;
}

Circle &Circle::rotateRadians(float radians)
{
    Circle::center.rotateRadians(radians);

    return *this;
}

Circle &Circle::rotateRadians(const Point &pivot, float radians)
{
    Circle::center.rotateRadians(pivot, radians);

    return *this;
}

Circle &Circle::rotateDegrees(float degrees)
{
    Circle::center.rotateDegrees(degrees);

    return *this;
}

Circle &Circle::rotateDegrees(const Point &pivot, float degrees)
{
    Circle::center.rotateDegrees(pivot, degrees);

    return *this;
}

Circle &Circle::scale(float scale)
{
    Circle::center.scale(scale);
    Circle::radius *= scale;

    return *this;
}

Circle &Circle::scale(const Point &pivot, float scale)
{
    Circle::center.scale(pivot, scale);
    Circle::radius *= scale;

    return *this;
}

bool Circle::equals(const Circle &other) const
{
    return (Circle::center.equals(other.center)) && (Circle::radius == other.radius);
}

bool Circle::equalsApprox(const Circle &other) const
{
    return (Circle::center.equalsApprox(other.center)) && (std::abs(Circle::radius - other.radius) < EQUALS_APROX_EPSILON);
}

std::ostream &geometry2d::operator<<(std::ostream &os, const Circle &circle)
{
    os << "{" << circle.center << ", " << circle.radius << "}";

    return os;
}
