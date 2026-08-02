#include <geometry2d/segment.hpp>
#include <geometry2d/direction.hpp>

using namespace geometry2d;

Segment &Segment::translate(float xTranslation, float yTranslation)
{
    Segment::a.x += xTranslation;
    Segment::a.y += yTranslation;

    Segment::b.x += xTranslation;
    Segment::b.y += yTranslation;

    return *this;
}

Segment &Segment::translate(const Direction &direction, float length)
{
    return translate(direction.getTranslation(length));
}

Point Segment::getPoint(float interpolant) const
{
    return Point(
        Segment::a.x + ((Segment::b.x - Segment::a.x) * interpolant),
        Segment::a.y + ((Segment::b.y - Segment::a.y) * interpolant)
    );
}

Direction Segment::getDirectionAB() const
{
    return Direction(a, b);
}

Direction Segment::getDirectionBA() const
{
    return Direction(b, a);
}
