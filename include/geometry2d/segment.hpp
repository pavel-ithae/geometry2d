#pragma once
#include <geometry2d/point.hpp>

namespace geometry2d
{
    class Direction;

    class Segment
    {
    public:
        Point a;
        Point b;

        Segment() {}

        Segment(float ax, float ay, float bx, float by)
        {
            a.x = ax;
            a.y = ay;

            b.x = bx;
            b.y = by;
        }

        Segment(const Point &a, const Point &b)
        {
            Segment::a = a;
            Segment::b = b;
        }

        Segment operator+(const Point &addend) const { return getTranslated(addend); }
        Segment operator-(const Point &subtrahend) const { return getTranslated(-subtrahend); }

        Segment &translate(float xTranslation, float yTranslation);
        Segment &translate(const Point &translationOffset) { return translate(translationOffset.x, translationOffset.y); }
        Segment &translate(const Direction &direction, float length);

        Segment getTranslated(float xTranslation, float yTranslation) const { return Segment(a, b).translate(xTranslation, yTranslation); }
        Segment getTranslated(const Point &translationOffset) const { return Segment(a, b).translate(translationOffset); }
        Segment getTranslated(const Direction &direction, float length) const { return Segment(a, b).translate(direction, length); }

        Point getPoint(float interpolant) const;

        Direction getDirectionAB() const;
        Direction getDirectionBA() const;
    };
}