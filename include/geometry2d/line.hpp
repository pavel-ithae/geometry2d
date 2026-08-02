#pragma once
#include <geometry2d/point.hpp>

namespace geometry2d
{
    class Segment;

    class Line
    {
        float yMultiplier_;
        float xMultiplier_;
        float constant_;

        Line &set(float yMultiplier, float xMultiplier, float constant);

    public:
        Line()
        {
            set(0.0f, 0.0f, 0.0f);
        }

        Line(float ax, float ay, float bx, float by)
        {
            setPoints(ax, ay, bx, by);
        }

        Line(const Point& a, const Point& b)
        {
            setPoints(a, b);
        }

        Line(const Segment& segment);

        Line &setPoints(float ax, float ay, float bx, float by);
        Line &setPoints(const Point& a, const Point& b) { return setPoints(a.x, a.y, b.x, b.y); }

        float getX(float y) const;
        float getY(float x) const;
        Point getPointAtX(float x) const { return Point(x, getY(x)); }
        Point getPointAtY(float y) const { return Point(getX(y), y); }
    };
}