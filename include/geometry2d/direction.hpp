#pragma once
#include <geometry2d/point.hpp>
#include <iosfwd>

namespace geometry2d
{
    struct Radians
    {
    };

    struct Degrees
    {
    };

    class Direction
    {
        float x_;
        float y_;
        float radians_;
        float degrees_;

        Direction &set(float x, float y, float radians, float degrees);

    public:
        Direction() {}
        
        Direction(float x, float y)
        {
            setPoint(x, y);
        }

        Direction(const Point &point)
        {
            setPoint(point.x, point.y);
        }

        Direction(float xFrom, float yFrom, float xTo, float yTo)
        {
            setPoint(xFrom, yFrom, xTo, yTo);
        }

        Direction(const Point &from, const Point &to)
        {
            setPoint(from, to);
        }

        Direction(float angleRadians, Radians)
        {
            setAngleRadians(angleRadians);
        }

        Direction(float angleDegrees, Degrees)
        {
            setAngleDegrees(angleDegrees);
        }

        float x() const { return x_; }
        float y() const { return y_; }
        Point point() const { return Point(x_, y_); }

        float radians() const { return radians_; }
        float degrees() const { return degrees_; };

        bool isZero() const { return (x_ == 0.0f) && (y_ == 0.0f); }

        friend std::ostream &operator<<(std::ostream &os, const Direction &direction);

        static Direction right();
        static Direction left();
        static Direction up();
        static Direction down();

        static float getAngleDifferenceRadians(const Direction &from, const Direction &to);
        static float getAngleDifferenceDegrees(const Direction &from, const Direction &to);

        static Direction getClosestNormalDirection(const Direction &a, const Direction &b);
        static Direction getFurthestNormalDirection(const Direction &a, const Direction &b);

        Direction &setZero() { return set(0.0f, 0.0f, 0.0f, 0.0f); }
        Direction &setPoint(float x, float y);
        Direction &setPoint(float xFrom, float yFrom, float xTo, float yTo) { return setPoint(xTo - xFrom, yTo - yFrom); }
        Direction &setPoint(const Point &point) { return setPoint(point.x, point.y); }
        Direction &setPoint(const Point &from, const Point &to) { return setPoint(to - from); }

        Direction &setAngleRadians(float radians);
        Direction &setAngleDegrees(float degrees);

        Direction &rotateRadians(float radians);
        Direction &rotateDegrees(float degrees);

        Direction &invert();

        Point getTranslation(float length) const;
        Point getTranslation(float length, const Point &source) const { return source + getTranslation(length); }

        Direction getRotatedRadians(float radians) const
        {
            Direction copy = *this;
            return copy.rotateRadians(radians);
        }
        Direction getRotatedDegrees(float degrees) const
        {
            Direction copy = *this;
            return copy.rotateRadians(degrees);
        }

        Direction getInverse() const
        {
            Direction copy = *this;
            return copy.invert();
        }
    };

    std::ostream &operator<<(std::ostream &os, const Direction &direction);
}