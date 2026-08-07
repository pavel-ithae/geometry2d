#include <geometry2d/triangle.hpp>
#include <geometry2d/direction.hpp>
#include <iostream>

using namespace geometry2d;

Triangle &Triangle::translate(float xTranslation, float yTranslation)
{
    Triangle::a.x += xTranslation;
    Triangle::a.y += yTranslation;

    Triangle::b.x += xTranslation;
    Triangle::b.y += yTranslation;

    Triangle::c.x += xTranslation;
    Triangle::c.y += yTranslation;

    return *this;
}

Triangle &Triangle::translate(const Direction &direction, float length)
{
    return translate(direction.getTranslation(length));
}

Triangle &Triangle::rotateRadians(float radians)
{
    a.rotateRadians(radians);
    b.rotateRadians(radians);
    c.rotateRadians(radians);

    return *this;
}

Triangle &Triangle::rotateRadians(const Point &pivot, float radians)
{
    a.rotateRadians(pivot, radians);
    b.rotateRadians(pivot, radians);
    c.rotateRadians(pivot, radians);

    return *this;
}

Triangle &Triangle::rotateDegrees(float degrees)
{
    a.rotateDegrees(degrees);
    b.rotateDegrees(degrees);
    c.rotateDegrees(degrees);

    return *this;
}

Triangle &Triangle::rotateDegrees(const Point &pivot, float degrees)
{
    a.rotateDegrees(pivot, degrees);
    b.rotateDegrees(pivot, degrees);
    c.rotateDegrees(pivot, degrees);

    return *this;
}

Triangle &Triangle::scale(float multiplier)
{
    a.scale(multiplier);
    b.scale(multiplier);
    c.scale(multiplier);

    return *this;
}

Triangle &Triangle::scale(const Point &pivot, float multiplier)
{
    a.scale(pivot, multiplier);
    b.scale(pivot, multiplier);
    c.scale(pivot, multiplier);

    return *this;
}

bool geometry2d::Triangle::equals(const Triangle &other) const
{
    return a.equals(other.a) && b.equals(other.b) && c.equals(other.c);
}

bool geometry2d::Triangle::equalsApprox(const Triangle &other) const
{
    return a.equalsApprox(other.a) && b.equalsApprox(other.b) && c.equalsApprox(other.c);
}

std::ostream &geometry2d::operator<<(std::ostream &os, const Triangle &segment)
{
    os << "{" << segment.a << ", " << segment.b << ", " << segment.c << "}";

    return os;
}