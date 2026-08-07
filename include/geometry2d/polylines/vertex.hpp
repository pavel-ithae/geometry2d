#pragma once
#include <geometry2d/point.hpp>
#include <geometry2d/polylines/curve.hpp>

namespace geometry2d::polylines
{
    class Vertex
    {
    public:
        Point point;
        CurveDynamic curve;

        Vertex();

        Vertex(const Point &point) 
        {  
            Vertex::point = point;
        }

        Vertex(const Point &point, const CurveDynamic &curve)
        {
            Vertex::point = point;
            Vertex::curve = curve;
        }

        Vertex(float x, float y)
        {
            Vertex::point.x = x;
            Vertex::point.y = y;
        }

        Vertex(float x, float y, const CurveDynamic &curve)
        {
            Vertex::point.x = x;
            Vertex::point.y = y;

            Vertex::curve = curve;
        }
    };


}