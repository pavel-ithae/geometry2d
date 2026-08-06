#pragma once
#include <geometry2d/point.hpp>
#include <iosfwd>

namespace geometry2d
{
    class Direction;

    class Circle
    {
    public:
        Point center;
        float radius;

        Circle() {}
        
        Circle(const Point &center, float radius)
        {
            Circle::center = center;
            Circle::radius = radius;
        }

        Circle(float x, float y, float radius)
        {
            center.x = x;
            center.y = y;

            Circle::radius = radius;
        }

        bool operator==(const Circle &other) const { return equalsApprox(other); }
        bool operator!=(const Circle &other) const { return !equalsApprox(other); }

        Circle operator+(const Point &addend) const { return getTranslated(addend); }
        Circle operator-(const Point &subtrahend) const { return getTranslated(-subtrahend); }
        Circle operator*(float multiplier) const { return getScaled(multiplier); }

        Circle operator-() const { return Circle(-center, radius); }

        friend std::ostream &operator<<(std::ostream &os, const Circle &circle);

        Circle &translate(float xTranslation, float yTranslation);
        Circle &translate(const Point &offsetTranslation) { return translate(offsetTranslation.x, offsetTranslation.y); }
        Circle &translate(const Direction &translationDirection, float translationLength);

        Circle &rotateRadians(float radians);
        Circle &rotateRadians(const Point &pivot, float radians);
        Circle &rotateDegrees(float degrees);
        Circle &rotateDegrees(const Point &pivot, float degrees);

        Circle &scale(float scale);
        Circle &scale(const Point &pivot, float scale);

        bool equals(const Circle &other) const;
        bool equalsApprox(const Circle &other) const;

        Circle getTranslated(float xTranslation, float yTranslation) const { return Circle(*this).translate(xTranslation, yTranslation); }
        Circle getTranslated(const Point &offsetTranslation) const { return getTranslated(offsetTranslation.x, offsetTranslation.y); }
        Circle getTranslated(const Direction &translationDirection, float translationLength) const { return Circle(*this).translate(translationDirection, translationLength); }

        Circle getRotatedRadians(float radians) const { return Circle(*this).rotateRadians(radians); }
        Circle getRotatedRadians(const Point &pivot, float radians) const { return Circle(*this).rotateRadians(pivot, radians); }
        Circle getRotatedDegrees(float degrees) const { return Circle(*this).rotateDegrees(degrees); }
        Circle getRotatedDegrees(const Point &pivot, float degrees) const { return Circle(*this).rotateDegrees(pivot, degrees); }

        Circle getScaled(float scale) const { return Circle(*this).scale(scale); }
        Circle getScaled(const Point &pivot, float scale) const { return Circle(*this).scale(pivot, scale); }
    };

    std::ostream &operator<<(std::ostream &os, const Circle &circle);
}