#pragma once
#include <geometry2d/polylines/vertex.hpp>
#include <vector>

namespace geometry2d::polylines
{
    class Polyline
    {
        std::vector<Vertex> vertices_;

        void assertBounds(int index, bool includePastEnd = false);

    public:
        Polyline() { }
        Polyline(int initialCapacity) { vertices_.reserve(initialCapacity); }

        Vertex& operator[](int index) { return vertices_.at(index); };

        int size() { return vertices_.size(); }

        void add(Vertex vertex);
        void add(Point point) { add(Vertex(point)); }

        void insert(int index, Vertex vertex);
        void insert(int index, Point point) { insert(index, Vertex(point)); }

        void remove(int index);

        const Vertex* begin() const { return vertices_.begin().base(); }
        const Vertex* end() const { return vertices_.end().base(); }
    };
}