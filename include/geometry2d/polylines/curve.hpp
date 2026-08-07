#pragma once
#include <geometry2d/point.hpp>
#include <geometry2d/segment.hpp>

namespace geometry2d::polylines
{
    enum class BezierType
    {
        Linear,

        Quadratic,

        Cubic
    };

    class Curve
    {
    public:
        virtual BezierType getBezierType() const = 0;

        virtual Point getPoint(const Point &a, const Point &b, float t) const = 0;
        virtual Point getPoint(const Segment &s, float t) const { return getPoint(s.a, s.b, t); }

        static Point getPointInBezierLinear(const Point &a, const Point &b, float t);
        static Point getPointInBezierQuadratic(const Point &a, const Point &b, float t, const Point &control);
        static Point getPointInBezierCubic(const Point &a, const Point &b, float t, const Point &aControl, const Point &bControl);
    };

    class CurveLinear : Curve
    {
    public:
        BezierType getBezierType() const override { return BezierType::Linear; }

        Point getPoint(const Point &a, const Point &b, float t) const;
    };

    class CurveQuadratic : Curve
    {
    public:
        Point centerControlOffset;

        CurveQuadratic() {}

        CurveQuadratic(const Point &centerControlOffset)
        {
            CurveQuadratic::centerControlOffset = centerControlOffset;
        }

        CurveQuadratic(float xControlOffset, float yControlOffset)
        {
            centerControlOffset = Point(xControlOffset, yControlOffset);
        }

        BezierType getBezierType() const override { return BezierType::Quadratic; }

        Point getPoint(const Point &a, const Point &b, float t) const;
    };

    class CurveCubic : Curve
    {
    public:
        Point startControlOffset;
        Point endControlOffset;

        CurveCubic() {}

        CurveCubic(const Point &startControlOffset, const Point &endControlOffset)
        {
            CurveCubic::startControlOffset = startControlOffset;
            CurveCubic::endControlOffset = endControlOffset;
        }

        CurveCubic(float xStartControlOffset, float yStartControlOffset, float xEndControlOffset, float yEndControlOffset)
        {
            startControlOffset = Point(xStartControlOffset, yStartControlOffset);
            endControlOffset = Point(xEndControlOffset, yEndControlOffset);
        }

        BezierType getBezierType() const override { return BezierType::Cubic; }

        Point getPoint(const Point &a, const Point &b, float t) const;
    };

    class CurveDynamic : Curve
    {
    private:
        BezierType bezierType_;
        Point aControlOffset_;
        Point bControlOffset_;

    public:
        CurveDynamic()
        {  
            bezierType_ = BezierType::Linear;
        }

        CurveDynamic(const Point &centerControlOffset)
        {  
            bezierType_ = BezierType::Quadratic;

            aControlOffset_ = centerControlOffset;
        }

        CurveDynamic(const Point &startControlOffset, const Point &endControlOffset)
        {  
            bezierType_ = BezierType::Quadratic;

            aControlOffset_ = startControlOffset;
            bControlOffset_ = endControlOffset;
        }

        BezierType getBezierType() const override { return bezierType_; }

        Point getPoint(const Point &a, const Point &b, float t) const;
    };
}