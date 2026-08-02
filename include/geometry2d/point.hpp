#pragma once
#include <iostream>

namespace geometry2d
{
    class Direction;

    class Point
    {
    public:
        float x;
        float y;

        Point() {}
        
        Point(float x, float y)
        {
            Point::x = x;
            Point::y = y;
        }

        bool operator==(const Point &other) const { return equalsApprox(other); }
        bool operator!=(const Point &other) const { return !equalsApprox(other); }

        Point operator-() const { return Point(-x, -y); }

        Point operator+(const Point &addend) const { return getTranslated(addend); }
        Point operator-(const Point &subtrahend) const { return getTranslated(-subtrahend); }
        Point operator*(float multiplier) const { return getScaled(multiplier); }

        friend std::ostream &operator<<(std::ostream &os, const Point &p);

        Point &translate(float xTranslation, float yTranslation);
        Point &translate(const Point &offsetTranslation) { return translate(offsetTranslation.x, offsetTranslation.y); }
        Point &translate(const Direction &translationDirection, float translationLength);

        Point &scale(float scale);
        Point &scale(const Point &pivot, float scale);

        bool equals(const Point &other) const;
        bool equalsApprox(const Point &other) const;

        Point getTranslated(float xTranslation, float yTranslation) const { return Point(x, y).translate(xTranslation, yTranslation); }
        Point getTranslated(const Point &offsetTranslation) const { return getTranslated(offsetTranslation.x, offsetTranslation.y); }
        Point getTranslated(const Direction &translationDirection, float translationLength) const { return Point(x, y).translate(translationDirection, translationLength); }

        Point getScaled(float scale) const { return Point(x, y).scale(scale); }
        Point getScaled(const Point &pivot, float scale) const { return Point(x, y).scale(pivot, scale); }
    };

    std::ostream &operator<<(std::ostream &os, const Point &p);
}