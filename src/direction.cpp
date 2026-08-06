#include <geometry2d/direction.hpp>
#include <geometry2d/point.hpp>
#include <iostream>
#include "macros.hpp"

using namespace geometry2d;

Direction &Direction::set(float x, float y, float radians, float degrees)
{
    Direction::x_ = x;
    Direction::y_ = y;
    Direction::radians_ = radians;
    Direction::degrees_ = degrees;

    return *this;
}

Direction Direction::right()
{
    return Direction().set(1.0f, 0.0f, 0.0f, 0.0f);
}

Direction Direction::left()
{
    return Direction().set(-1.0f, 0.0f, PI, 180.0f);
}

Direction Direction::up()
{
    return Direction().set(0.0f, 1.0f, PI_2, 90.0f);
}

Direction Direction::down()
{
    return Direction().set(0.0f, -1.0f, PI + PI_2, 270.0f);
}

float Direction::getAngleDifferenceRadians(const Direction &from, const Direction &to)
{
    float rawDifference = to.radians_ - from.radians_;

    if (rawDifference >= 0.0f)
    {
        if (rawDifference > PI)
        {
            return -(PI - (rawDifference - PI));
        }
        else
        {
            return rawDifference;
        }
    }
    else
    {
        if (rawDifference <= (-PI))
        {
            return PI + (rawDifference + PI);
        }
        else
        {
            return rawDifference;
        }
    }
}

float Direction::getAngleDifferenceDegrees(const Direction &from, const Direction &to)
{
    float rawDifference = to.degrees_ - from.degrees_;

    if (rawDifference >= 0.0f)
    {
        if (rawDifference > 180.0f)
        {
            return -(180.0f - (rawDifference - 180.0f));
        }
        else
        {
            return rawDifference;
        }
    }
    else
    {
        if (rawDifference <= (-180.0f))
        {
            return 180.0f + (rawDifference + 180.0f);
        }
        else
        {
            return rawDifference;
        }
    }
}

Direction Direction::getClosestNormalDirection(const Direction &a, const Direction &b)
{
    return a.getRotatedRadians(getAngleDifferenceRadians(a, b) * 0.5f);
}

Direction Direction::getFurthestNormalDirection(const Direction &a, const Direction &b)
{
    Direction direction = getClosestNormalDirection(a, b);
    direction.invert();

    return direction;
}

Direction &Direction::setPoint(float x, float y)
{
    float distance = sqrt((x * x) + (y * y));

    if (distance <= 0.0f)
    {
        Direction::x_ = 0.0f;
        Direction::y_ = 0.0f;

        radians_ = 0.0f;
        degrees_ = 0.0f;

        return *this;
    }

    Direction::x_ = x / distance;
    Direction::y_ = y / distance;

    Direction::radians_ = atan2(Direction::y_, Direction::x_);
    Direction::degrees_ = RADIANS_TO_DEGREES(Direction::radians_);

    return *this;
}

Direction &Direction::setAngleRadians(float radians)
{
    if (radians >= (PI * 2.0f))
    {
        Direction::radians_ = fmod(radians, (PI * 2.0f));
    }
    else
    {
        Direction::radians_ = radians;
    }

    Direction::x_ = cos(Direction::radians_);
    Direction::y_ = sin(Direction::radians_);
    Direction::degrees_ = RADIANS_TO_DEGREES(radians_);

    return *this;
}

Direction &Direction::setAngleDegrees(float degrees)
{
    if (degrees >= 360.0f)
    {
        Direction::degrees_ = fmod(degrees, 360.0f);
    }
    else
    {
        Direction::degrees_ = degrees;
    }

    Direction::radians_ = DEGREES_TO_RADIANS(degrees);
    Direction::x_ = cos(Direction::radians_);
    Direction::y_ = sin(Direction::radians_);

    return *this;
}

Direction &Direction::rotateRadians(float radians)
{
    if (Direction::isZero())
    {
        return *this;
    }

    setAngleRadians(fmod((Direction::radians_ + radians), (M_PI * 2.0f)));

    return *this;
}

Direction &Direction::rotateDegrees(float degrees)
{
    if (Direction::isZero())
    {
        return *this;
    }

    setAngleDegrees(fmod((Direction::degrees_ + degrees), 360.0f));

    return *this;
}

Direction &Direction::invert()
{
    float inverseRadians = (Direction::radians_ < PI) ? (Direction::radians_ + PI) : (Direction::radians_ - PI);

    set(-Direction::x_, -Direction::y_, inverseRadians, RADIANS_TO_DEGREES(inverseRadians));

    return *this;
}

Point Direction::getTranslation(float length) const
{
    return Point(Direction::x_ * length, Direction::y_ * length);
}

std::ostream &geometry2d::operator<<(std::ostream &os, const Direction &direction)
{
    os << "{" << direction.x_ << ", " << direction.y_ << ", " << direction.radians_ << ", " << direction.degrees_ << "}";

    return os;
}
