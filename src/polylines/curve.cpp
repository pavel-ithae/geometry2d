#include <geometry2d/polylines/curve.hpp>
#include <stdexcept>
#include <string>
#include <sstream>

using namespace geometry2d;
using namespace geometry2d::polylines;

std::ostream &geometry2d::polylines::operator<<(std::ostream &os, BezierType type)
{
    switch (type)
    {
    case BezierType::Linear:
        os << "Linear";
        break;
    
    case BezierType::Quadratic:
        os << "Quadratic";
        break;

    case BezierType::Cubic:
        os << "Cubic";
        break;
    }

    return os;
}

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

void CurveDynamic::assertBezierType(BezierType expectedType) const
{
    if (CurveDynamic::bezierType_ != expectedType)
    {
        std::stringstream stream;

        stream << "Expected beizer of type \"" << expectedType << "\" but is \"" << CurveDynamic::bezierType_ << "\".";

        throw std::logic_error(stream.str());
    }
}

void CurveDynamic::setLinear()
{
    bezierType_ = BezierType::Linear;
}

void CurveDynamic::setQuadratic(const Point &centerControlOffset)
{
    bezierType_ = BezierType::Quadratic;

    aControlOffset_ = centerControlOffset;
}

void CurveDynamic::setCubic(const Point &startControlOffset, const Point &endControlOffset)
{
    bezierType_ = BezierType::Quadratic;

    aControlOffset_ = startControlOffset;
    bControlOffset_ = endControlOffset;
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

CurveLinear CurveDynamic::getAsLinear() const
{
    CurveDynamic::assertBezierType(BezierType::Linear);
    
    return CurveLinear();
}

void CurveDynamic::getAsLinear(CurveLinear *buffer) const
{
    CurveDynamic::assertBezierType(BezierType::Linear);
}

CurveQuadratic CurveDynamic::getAsQuadratic() const
{
    CurveDynamic::assertBezierType(BezierType::Quadratic);

    return CurveQuadratic(CurveDynamic::aControlOffset_);
}

void CurveDynamic::getAsQuadratic(CurveQuadratic *buffer) const
{
    CurveDynamic::assertBezierType(BezierType::Quadratic);

    buffer->centerControlOffset = CurveDynamic::aControlOffset_;
}

CurveCubic CurveDynamic::getAsCubic() const
{
    CurveDynamic::assertBezierType(BezierType::Cubic);

    return CurveCubic(CurveDynamic::aControlOffset_, CurveDynamic::bControlOffset_);
}

void geometry2d::polylines::CurveDynamic::getAsCubic(CurveCubic *buffer) const
{
    CurveDynamic::assertBezierType(BezierType::Cubic);

    buffer->startControlOffset = CurveDynamic::aControlOffset_;
    buffer->endControlOffset = CurveDynamic::bControlOffset_;
}
