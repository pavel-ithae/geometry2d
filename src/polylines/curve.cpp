#include <geometry2d/polylines/curve.hpp>
#include <stdexcept>
#include <string>

using namespace geometry2d;
using namespace geometry2d::polylines;

Point Curve::getPointInBezierLinear(const Point &a, const Point &b, float t)
{
    return a + ((b - a) * t);
}

Point Curve::getPointInBezierQuadratic(const Point &a, const Point &b, float t, const Point &control)
{
    float tReciprocal = 1.0f - t;

    return (a * tReciprocal * tReciprocal) + (control * 2.0f * tReciprocal * t) + (b * t * t);
}

Point Curve::getPointInBezierCubic(const Point &a, const Point &b, float t, const Point &aControl, const Point &bControl)
{
    float tReciprocal = 1.0f - t;

    return (a * tReciprocal * tReciprocal * tReciprocal) + (aControl * 3.0f * tReciprocal * tReciprocal * t) + (bControl * 3.0f * tReciprocal * t * t) + (b * t * t * t);
}

Point CurveLinear::getPoint(const Point &a, const Point &b, float t) const
{
    return getPointInBezierLinear(a, b, t);
}

Point CurveQuadratic::getPoint(const Point &a, const Point &b, float t) const
{
    return getPointInBezierQuadratic(a, b, t, CurveQuadratic::centerControlOffset + getPointInBezierLinear(a, b, 0.5f));
}

Point CurveCubic::getPoint(const Point &a, const Point &b, float t) const
{
    return getPointInBezierCubic(a, b, t, CurveCubic::startControlOffset + a, CurveCubic::endControlOffset + b);
}

Point CurveDynamic::getPoint(const Point &a, const Point &b, float t) const
{
    switch (CurveDynamic::bezierType_)
    {
    case BezierType::Linear:
        return getPointInBezierLinear(a, b, t);

    case BezierType::Quadratic:
        return getPointInBezierQuadratic(a, b, t, CurveDynamic::aControlOffset_ + getPointInBezierLinear(a, b, 0.5f));

    case BezierType::Cubic:
        return getPointInBezierCubic(a, b, t, CurveDynamic::aControlOffset_ + a, CurveDynamic::bControlOffset_ + b);
    
    default:
        throw std::logic_error(std::string("Undefined curve bezier type."));
    }
}
