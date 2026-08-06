#pragma once
#include <geometry2d/point.hpp>
#include <iosfwd>

namespace geometry2d
{
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

        bool operator==(const Segment &other) const { return equalsApprox(other); }
        bool operator!=(const Segment &other) const { return !equalsApprox(other); }

        Segment operator+(const Point &addend) const { return getTranslated(addend); }
        Segment operator-(const Point &subtrahend) const { return getTranslated(-subtrahend); }
        Segment operator*(float multiplier) const { return getScaled(multiplier); }

        Segment operator-() const { return Segment(-a, -b); }

        friend std::ostream &operator<<(std::ostream &os, const Segment &segment);

        Segment &translate(float xTranslation, float yTranslation);
        Segment &translate(const Point &translationOffset) { return translate(translationOffset.x, translationOffset.y); }
        Segment &translate(const Direction &direction, float length);

        Segment &rotateRadians(float radians);
        Segment &rotateRadians(const Point &pivot, float radians);
        Segment &rotateRadiansFromA(float radians);
        Segment &rotateRadiansFromB(float radians);

        Segment &rotateDegrees(float degrees);
        Segment &rotateDegrees(const Point &pivot, float degrees);
        Segment &rotateDegreesFromA(float degrees);
        Segment &rotateDegreesFromB(float degrees);

        Segment &scale(float multiplier);
        Segment &scale(const Point &pivot, float multiplier);
        Segment &scaleFromA(float multiplier);
        Segment &scaleFromB(float multiplier);

        bool equals(const Segment &other) const;
        bool equalsApprox(const Segment &other) const;

        Segment getTranslated(float xTranslation, float yTranslation) const { return Segment(a, b).translate(xTranslation, yTranslation); }
        Segment getTranslated(const Point &translationOffset) const { return Segment(a, b).translate(translationOffset); }
        Segment getTranslated(const Direction &direction, float length) const { return Segment(a, b).translate(direction, length); }

        Segment getRotatedRadians(float radians) const { return Segment(a, b).rotateRadians(radians); };
        Segment getRotatedRadians(const Point &pivot, float radians) const { return Segment(a, b).rotateRadians(pivot, radians); };
        Segment getRotatedRadiansFromA(float radians) const { return Segment(a, b).rotateRadiansFromA(radians); };
        Segment getRotatedRadiansFromB(float radians) const { return Segment(a, b).rotateRadiansFromB(radians); };

        Segment getRotatedDegrees(float degrees) const { return Segment(a, b).rotateDegrees(degrees); };
        Segment getRotatedDegrees(const Point &pivot, float degrees) const { return Segment(a, b).rotateDegrees(pivot, degrees); };
        Segment getRotatedDegreesFromA(float degrees) const { return Segment(a, b).rotateDegreesFromA(degrees); };
        Segment getRotatedDegreesFromB(float degrees) const { return Segment(a, b).rotateDegreesFromB(degrees); };

        Segment getScaled(float multiplier) const { return Segment(a, b).scale(multiplier); };
        Segment getScaled(const Point &pivot, float multiplier) const { return Segment(a, b).scale(pivot, multiplier); };
        Segment getScaledFromA(float multiplier) const { return Segment(a, b).scaleFromA(multiplier); };
        Segment getScaledFromB(float multiplier) const { return Segment(a, b).scaleFromB(multiplier); };

        Point getPoint(float interpolant) const;
    };

    std::ostream &operator<<(std::ostream &os, const Segment &segment);
}