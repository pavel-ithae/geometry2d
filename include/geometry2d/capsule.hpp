#pragma once
#include <geometry2d/segment.hpp>
#include <iosfwd>

namespace geometry2d
{
    class Capsule
    {
    public:
        Segment segment;
        float radius;

        Capsule() {}

        Capsule(const Segment &segment, float radius)
        {
            Capsule::segment = segment;
            Capsule::radius = radius;
        }

        Capsule(const Point &a, const Point &b, float radius)
        {
            Capsule::segment.a = a;
            Capsule::segment.b = b;

            Capsule::radius = radius;
        }

        Capsule(float ax, float ay, float bx, float by, float radius)
        {
            Capsule::segment.a.x = ax;
            Capsule::segment.a.y = ay;

            Capsule::segment.b.x = bx;
            Capsule::segment.b.y = by;

            Capsule::radius = radius;
        }

        bool operator==(const Capsule &other) const { return equalsApprox(other); }
        bool operator!=(const Capsule &other) const { return !equalsApprox(other); }

        Capsule operator+(const Point &addend) const { return getTranslated(addend); }
        Capsule operator-(const Point &subtrahend) const { return getTranslated(-subtrahend); }
        Capsule operator*(float multiplier) const { return getScaled(multiplier); }

        Capsule operator-() const { return Capsule(-segment, radius); }

        friend std::ostream &operator<<(std::ostream &os, const Capsule &segment);

        Capsule &translate(float xTranslation, float yTranslation);
        Capsule &translate(const Point &translationOffset) { return translate(translationOffset.x, translationOffset.y); }
        Capsule &translate(const Direction &direction, float length);

        Capsule &rotateRadians(float radians);
        Capsule &rotateRadians(const Point &pivot, float radians);
        Capsule &rotateRadiansFromA(float radians);
        Capsule &rotateRadiansFromB(float radians);

        Capsule &rotateDegrees(float degrees);
        Capsule &rotateDegrees(const Point &pivot, float degrees);
        Capsule &rotateDegreesFromA(float degrees);
        Capsule &rotateDegreesFromB(float degrees);

        Capsule &scale(float multiplier);
        Capsule &scale(const Point &pivot, float multiplier);
        Capsule &scaleFromA(float multiplier);
        Capsule &scaleFromB(float multiplier);

        bool equals(const Capsule &other) const;
        bool equalsApprox(const Capsule &other) const;

        Capsule getTranslated(float xTranslation, float yTranslation) const { return Capsule(*this).translate(xTranslation, yTranslation); }
        Capsule getTranslated(const Point &translationOffset) const { return Capsule(*this).translate(translationOffset); }
        Capsule getTranslated(const Direction &direction, float length) const { return Capsule(*this).translate(direction, length); }

        Capsule getRotatedRadians(float radians) const { return Capsule(*this).rotateRadians(radians); };
        Capsule getRotatedRadians(const Point &pivot, float radians) const { return Capsule(*this).rotateRadians(pivot, radians); };
        Capsule getRotatedRadiansFromA(float radians) const { return Capsule(*this).rotateRadiansFromA(radians); };
        Capsule getRotatedRadiansFromB(float radians) const { return Capsule(*this).rotateRadiansFromB(radians); };

        Capsule getRotatedDegrees(float degrees) const { return Capsule(*this).rotateDegrees(degrees); };
        Capsule getRotatedDegrees(const Point &pivot, float degrees) const { return Capsule(*this).rotateDegrees(pivot, degrees); };
        Capsule getRotatedDegreesFromA(float degrees) const { return Capsule(*this).rotateDegreesFromA(degrees); };
        Capsule getRotatedDegreesFromB(float degrees) const { return Capsule(*this).rotateDegreesFromB(degrees); };

        Capsule getScaled(float multiplier) const { return Capsule(*this).scale(multiplier); };
        Capsule getScaled(const Point &pivot, float multiplier) const { return Capsule(*this).scale(pivot, multiplier); };
        Capsule getScaledFromA(float multiplier) const { return Capsule(*this).scaleFromA(multiplier); };
        Capsule getScaledFromB(float multiplier) const { return Capsule(*this).scaleFromB(multiplier); };

        Point getPoint(float interpolant) const;
    };

    std::ostream &operator<<(std::ostream &os, const Capsule &segment);
}