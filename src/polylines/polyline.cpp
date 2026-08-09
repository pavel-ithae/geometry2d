#include <geometry2d/polylines/polyline.hpp>
#include <stdexcept>
#include <sstream>

using namespace geometry2d;
using namespace geometry2d::polylines;

void Polyline::assertBounds(int index, bool includePastEnd)
{
    if ((index < 0) || (includePastEnd ? (index > Polyline::vertices_.size()) : (index >= Polyline::vertices_.size())))
    {
        std::stringstream stream;

        stream << "Polyline index [" << index << "] is out of range! " << "Size: " << vertices_.size();

        throw std::out_of_range(stream.str());
    }
}

void Polyline::add(Vertex vertex)
{
    vertices_.push_back(vertex);
}

void Polyline::insert(int index, Vertex vertex)
{
    assertBounds(index, true);

    vertices_.insert(vertices_.begin() + index, vertex);
}

void Polyline::remove(int index)
{
    assertBounds(index);

    vertices_.erase(vertices_.begin() + index);
}
