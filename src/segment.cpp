#include <geometry2d/segment.hpp>
#include <geometry2d/direction.hpp>
#include <iostream>

using namespace geometry2d;

Segment &Segment::translate(float xTranslation, float yTranslation)
{
    Segment::a.x += xTranslation;
    Segment::a.y += yTranslation;

    Segment::b.x += xTranslation;
    Segment::b.y += yTranslation;

    return *this;
}

Segment &Segment::translate(const Direction &direction, float length)
{
    return translate(direction.getTranslation(length));
}

Segment &Segment::rotateRadians(float radians)
{
    a.rotateRadians(radians);
    b.rotateRadians(radians);

    return *this;
}

Segment &Segment::rotateRadians(const Point &pivot, float radians)
{
    a.rotateRadians(pivot, radians);
    b.rotateRadians(pivot, radians);

    return *this;
}

Segment &Segment::rotateRadiansFromA(float radians)
{
    b.rotateRadians(a, radians);

    return *this;
}

Segment &Segment::rotateRadiansFromB(float radians)
{
    a.rotateRadians(b, radians);

    return *this;
}

Segment &Segment::rotateDegrees(float degrees)
{
    a.rotateDegrees(degrees);
    b.rotateDegrees(degrees);

    return *this;
}

Segment &Segment::rotateDegrees(const Point &pivot, float degrees)
{
    a.rotateDegrees(pivot, degrees);
    b.rotateDegrees(pivot, degrees);

    return *this;
}

Segment &Segment::rotateDegreesFromA(float degrees)
{
    b.rotateDegrees(a, degrees);

    return *this;
}

Segment &Segment::rotateDegreesFromB(float degrees)
{
    a.rotateDegrees(b, degrees);

    return *this;
}

Segment &Segment::scale(float multiplier)
{
    a.scale(multiplier);
    b.scale(multiplier);

    return *this;
}

Segment &Segment::scale(const Point &pivot, float multiplier)
{
    a.scale(pivot, multiplier);
    b.scale(pivot, multiplier);

    return *this;
}

Segment &geometry2d::Segment::scaleFromA(float multiplier)
{
    b.scale(a, multiplier);

    return *this;
}

Segment &geometry2d::Segment::scaleFromB(float multiplier)
{
    a.scale(b, multiplier);

    return *this;
}

bool geometry2d::Segment::equals(const Segment &other) const
{
    return a.equals(other.a) && b.equals(other.b);
}

bool geometry2d::Segment::equalsApprox(const Segment &other) const
{
    return a.equalsApprox(other.a) && b.equalsApprox(other.b);
}

Point Segment::getPoint(float interpolant) const
{
    return Point(
        Segment::a.x + ((Segment::b.x - Segment::a.x) * interpolant),
        Segment::a.y + ((Segment::b.y - Segment::a.y) * interpolant)
    );
}

std::ostream &geometry2d::operator<<(std::ostream &os, const Segment &segment)
{
    os << "{" << segment.a << ", " << segment.b << "}";

    return os;
}