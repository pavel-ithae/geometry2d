#pragma once
#include <geometry2d/point.hpp>
#include <geometry2d/segment.hpp>
#include <iosfwd>

namespace geometry2d::polylines
{
    enum class BezierType
    {
        Linear,

        Quadratic,

        Cubic
    };

    std::ostream &operator<<(std::ostream &os, BezierType type);

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

        void assertBezierType(BezierType expectedType) const;

    public:
        CurveDynamic() { setLinear(); }
        CurveDynamic(const Point &centerControlOffset) { setQuadratic(centerControlOffset); }
        CurveDynamic(const Point &startControlOffset, const Point &endControlOffset) { setCubic(startControlOffset, endControlOffset); }

        void setLinear();
        void setQuadratic(const Point &centerControlOffset);
        void setCubic(const Point &startControlOffset, const Point &endControlOffset);

        void set(const CurveLinear &curve) { setLinear(); }
        void set(const CurveQuadratic &curve) { setQuadratic(curve.centerControlOffset); }
        void set(const CurveCubic &curve) { setCubic(curve.startControlOffset, curve.endControlOffset); }

        BezierType getBezierType() const override { return bezierType_; }

        Point getPoint(const Point &a, const Point &b, float t) const;

        CurveLinear getAsLinear() const;
        void getAsLinear(CurveLinear *buffer) const;

        CurveQuadratic getAsQuadratic() const;
        void getAsQuadratic(CurveQuadratic *buffer) const;

        CurveCubic getAsCubic() const;
        void getAsCubic(CurveCubic *buffer) const;
    };
}