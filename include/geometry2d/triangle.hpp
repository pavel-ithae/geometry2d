#pragma once
#include <geometry2d/point.hpp>
#include <geometry2d/segment.hpp>

namespace geometry2d
{
    class Triangle
    {
    public:
        Point a;
        Point b;
        Point c;

        Triangle() {}

        Triangle(const Point &a, const Point &b, const Point &c)
        {
            Triangle::a = a;
            Triangle::b = b;
            Triangle::c = c;
        }

        Triangle(float ax, float ay, float bx, float by, float cx, float cy)
        {
            a.x = ax;
            a.y = ay;

            b.x = bx;
            b.y = by;

            c.x = cx;
            c.y = cy;
        }

        bool operator==(const Triangle &other) const { return equalsApprox(other); }
        bool operator!=(const Triangle &other) const { return !equalsApprox(other); }

        Triangle operator+(const Point &addend) const { return getTranslated(addend); }
        Triangle operator-(const Point &subtrahend) const { return getTranslated(-subtrahend); }
        Triangle operator*(float multiplier) const { return getScaled(multiplier); }

        Triangle operator-() const { return Triangle(-a, -b, -c); }

        friend std::ostream &operator<<(std::ostream &os, const Triangle &triangle);

        Segment ab() const { return Segment(a, b); }
        Segment bc() const { return Segment(b, c); }
        Segment ca() const { return Segment(c, a); }
        Segment ac() const { return Segment(a, c); }
        Segment cb() const { return Segment(c, b); }
        Segment ba() const { return Segment(b, a); }

        Triangle &translate(float xTranslation, float yTranslation);
        Triangle &translate(const Point &translationOffset) { return translate(translationOffset.x, translationOffset.y); }
        Triangle &translate(const Direction &direction, float length);

        Triangle &rotateRadians(float radians);
        Triangle &rotateRadians(const Point &pivot, float radians);
        Triangle &rotateDegrees(float degrees);
        Triangle &rotateDegrees(const Point &pivot, float degrees);

        Triangle &scale(float multiplier);
        Triangle &scale(const Point &pivot, float multiplier);

        bool equals(const Triangle &other) const;
        bool equalsApprox(const Triangle &other) const;

        Triangle getTranslated(float xTranslation, float yTranslation) const { return Triangle(*this).translate(xTranslation, yTranslation); }
        Triangle getTranslated(const Point &translationOffset) const { return Triangle(*this).translate(translationOffset); }
        Triangle getTranslated(const Direction &direction, float length) const { return Triangle(*this).translate(direction, length); }

        Triangle getRotatedRadians(float radians) const { return Triangle(*this).rotateRadians(radians); };
        Triangle getRotatedRadians(const Point &pivot, float radians) const { return Triangle(*this).rotateRadians(pivot, radians); };
        Triangle getRotatedDegrees(float degrees) const { return Triangle(*this).rotateDegrees(degrees); };
        Triangle getRotatedDegrees(const Point &pivot, float degrees) const { return Triangle(*this).rotateDegrees(pivot, degrees); };

        Triangle getScaled(float multiplier) const { return Triangle(*this).scale(multiplier); };
        Triangle getScaled(const Point &pivot, float multiplier) const { return Triangle(*this).scale(pivot, multiplier); };
    };

    std::ostream &operator<<(std::ostream &os, const Triangle &triangle);
}