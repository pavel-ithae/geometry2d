#include <geometry2d/capsule.hpp>
#include <geometry2d/direction.hpp>
#include <iostream>
#include "macros.hpp"

using namespace geometry2d;

Capsule &Capsule::translate(float xTranslation, float yTranslation)
{
    segment.translate(xTranslation, yTranslation);

    return *this;
}

Capsule &Capsule::translate(const Direction &direction, float length)
{
    return translate(direction.getTranslation(length));
}

Capsule &Capsule::rotateRadians(float radians)
{
    segment.rotateRadians(radians);

    return *this;
}

Capsule &Capsule::rotateRadians(const Point &pivot, float radians)
{
    segment.rotateRadians(pivot, radians);

    return *this;
}

Capsule &Capsule::rotateRadiansFromA(float radians)
{
    segment.rotateRadiansFromA(radians);

    return *this;
}

Capsule &Capsule::rotateRadiansFromB(float radians)
{
    segment.rotateRadiansFromB(radians);

    return *this;
}

Capsule &Capsule::rotateDegrees(float degrees)
{
    segment.rotateDegrees(degrees);

    return *this;
}

Capsule &Capsule::rotateDegrees(const Point &pivot, float degrees)
{
    segment.rotateDegrees(pivot, degrees);

    return *this;
}

Capsule &Capsule::rotateDegreesFromA(float degrees)
{
    segment.rotateDegreesFromA(degrees);

    return *this;
}

Capsule &Capsule::rotateDegreesFromB(float degrees)
{
    segment.rotateDegreesFromB(degrees);

    return *this;
}

Capsule &Capsule::scale(float multiplier)
{
    segment.scale(multiplier);

    radius *= multiplier;

    return *this;
}

Capsule &Capsule::scale(const Point &pivot, float multiplier)
{
    segment.scale(pivot, multiplier);

    radius *= multiplier;

    return *this;
}

Capsule &geometry2d::Capsule::scaleFromA(float multiplier)
{
    segment.scaleFromA(multiplier);

    radius *= multiplier;

    return *this;
}

Capsule &geometry2d::Capsule::scaleFromB(float multiplier)
{
    segment.scaleFromB(multiplier);

    radius *= multiplier;

    return *this;
}

bool geometry2d::Capsule::equals(const Capsule &other) const
{
    return segment.equals(other.segment) && (radius == other.radius);
}

bool geometry2d::Capsule::equalsApprox(const Capsule &other) const
{
    return segment.equalsApprox(other.segment) && (std::abs(radius - other.radius) < EQUALS_APROX_EPSILON);
}

Point Capsule::getPoint(float interpolant) const
{
    return segment.getPoint(interpolant);
}

std::ostream &geometry2d::operator<<(std::ostream &os, const Capsule &capsule)
{
    os << "{" << capsule.segment << ", " << capsule.radius << "}";

    return os;
}