#include <geometry2d/line.hpp>
#include <geometry2d/segment.hpp>

using namespace geometry2d;

Line &Line::set(float yMultiplier, float xMultiplier, float constant)
{
    Line::yMultiplier_ = yMultiplier;
    Line::xMultiplier_ = xMultiplier;
    Line::constant_ = constant;

    return *this;
}

Line::Line(const Segment &segment)
{
    setPoints(segment.a, segment.b);
}

Line &Line::setPoints(float ax, float ay, float bx, float by)
{
    Line::yMultiplier_ = ay - by;
    Line::xMultiplier_ = ax - bx;
    Line::constant_ = (ax * by) - (bx * ay);

    return *this;
}

float Line::getX(float y) const
{
    if (Line::yMultiplier_ == 0.0f)
    {
        return 0.0f;
    }

    // Formula: x = (-by - c) / a;
    return ((-(Line::xMultiplier_ * y)) - Line::constant_) / Line::yMultiplier_;
}

float Line::getY(float x) const
{
    if (Line::xMultiplier_ == 0.0f)
    {
        return 0.0f;
    }

    // Formula: y = (-ax - c) / b;
    return ((-(Line::yMultiplier_ * x)) - Line::constant_) / Line::xMultiplier_;
}
