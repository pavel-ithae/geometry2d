#include <catch2/catch_test_macros.hpp>
#include <geometry2d/point.hpp>
#include <geometry2d/direction.hpp>
#include <limits.h>

#define FLOAT_EPSILON std::numeric_limits<float>::epsilon()
#define DIAGONAL_DELTA(length) ((1.0f / std::sqrt(2.0f)) * length)

using namespace geometry2d;

Point pointTemp;

TEST_CASE("Point Value Constructor", "[point]")
{
    REQUIRE(Point(0.0f, 0.0f).x == 0.0f);
    REQUIRE(Point(0.0f, 0.0f).y == 0.0f);

    REQUIRE(Point(1.0f, 3.0f).x == 1.0f);
    REQUIRE(Point(1.0f, 3.0f).y == 3.0f);
}

TEST_CASE("Point Equals", "[point]")
{
    REQUIRE(Point(2.0f, -5.0f).equals(Point(2.0f, -5.0f)));

    REQUIRE_FALSE(Point(2.0f, -5.0f).equals(Point(1.0f, -5.0f)));
    REQUIRE_FALSE(Point(2.0f, -5.0f).equals(Point(2.0f, 5.0f)));
    REQUIRE_FALSE(Point(2.0f, -5.0f).equals(Point(1.0f, 5.0f)));

    REQUIRE_FALSE(Point(-1.0f + FLOAT_EPSILON, 4.0f - FLOAT_EPSILON).equals(Point(-1.0f, 4.0f)));
}

TEST_CASE("Point Equals Approx", "[point]")
{
    REQUIRE(Point(2.0f, -5.0f).equalsApprox(Point(2.0f, -5.0f)));

    REQUIRE_FALSE(Point(2.0f, -5.0f).equalsApprox(Point(1.0f, -5.0f)));
    REQUIRE_FALSE(Point(2.0f, -5.0f).equalsApprox(Point(2.0f, 5.0f)));
    REQUIRE_FALSE(Point(2.0f, -5.0f).equalsApprox(Point(1.0f, 5.0f)));

    REQUIRE(Point(-1.0f + FLOAT_EPSILON, 4.0f - FLOAT_EPSILON).equalsApprox(Point(-1.0f, 4.0f)));
    REQUIRE_FALSE(Point(2.0f, -5.0f).equalsApprox(Point(1.0f, 5.0f)));

    REQUIRE(Point(-1.0f + FLOAT_EPSILON, 4.0f - FLOAT_EPSILON) == Point(-1.0f, 4.0f));
    REQUIRE_FALSE(Point(2.0f, -5.0f) == (Point(1.0f, 5.0f)));

    REQUIRE_FALSE(Point(-1.0f + FLOAT_EPSILON, 4.0f - FLOAT_EPSILON) != Point(-1.0f, 4.0f));
    REQUIRE(Point(2.0f, -5.0f) != (Point(1.0f, 5.0f)));
}

TEST_CASE("Point Negate", "[point]")
{
    REQUIRE(-Point(3.0f, -1.5f) == Point(-3.0f, 1.5f));
    REQUIRE(-Point(-3.0f, 1.5f) == Point(3.0f, -1.5f));
}

TEST_CASE("Point Translate", "[point]")
{
    REQUIRE(Point(1.0f, 3.0f).translate(2.5f, 1.25f) == Point(3.5f, 4.25f));
    REQUIRE(Point(1.0f, 3.0f).translate(-2.5f, -1.25f) == Point(-1.5f, 1.75f));

    REQUIRE(Point(1.0f, 3.0f).translate(Point(2.5f, 1.25f)) == Point(3.5f, 4.25f));
    REQUIRE(Point(1.0f, 3.0f).translate(Point(-2.5f, -1.25f)) == Point(-1.5f, 1.75f));

    REQUIRE((Point(1.0f, 3.0f) + (Point(2.5f, 1.25f))) == Point(3.5f, 4.25f));
    REQUIRE((Point(1.0f, 3.0f) - (Point(2.5f, 1.25f))) == Point(-1.5f, 1.75f));
}

TEST_CASE("Point Translate Direction", "[point]")
{
    REQUIRE(Point(1.0f, 3.0f).translate(Direction(1.0f, 0.0f), 2.5f) == Point(3.5f, 3.0f));
    REQUIRE(Point(1.0f, 3.0f).translate(Direction(-1.0f, 0.0f), 2.5f) == Point(-1.5f, 3.0f));
    REQUIRE(Point(1.0f, 3.0f).translate(Direction(0.0f, 1.0f), 2.5f) == Point(1.0f, 5.5f));
    REQUIRE(Point(1.0f, 3.0f).translate(Direction(0.0f, -1.0f), 2.5f) == Point(1.0f, 0.5f));

    REQUIRE(Point(1.0f, 3.0f).translate(Direction(1.0f, 1.0f), 2.0f) == Point(1.0f + DIAGONAL_DELTA(2.0f), 3.0f + DIAGONAL_DELTA(2.0f)));
    REQUIRE(Point(1.0f, 3.0f).translate(Direction(-1.0f, 1.0f), 2.5f) == Point(1.0f - DIAGONAL_DELTA(2.5f), 3.0f + DIAGONAL_DELTA(2.5f)));
    REQUIRE(Point(1.0f, 3.0f).translate(Direction(1.0f, -1.0f), 1.0f) == Point(1.0f + DIAGONAL_DELTA(1.0f), 3.0f - DIAGONAL_DELTA(1.0f)));
    REQUIRE(Point(1.0f, 3.0f).translate(Direction(-1.0f, -1.0f), 4.25f) == Point(1.0f - DIAGONAL_DELTA(4.25f), 3.0f - DIAGONAL_DELTA(4.25f)));
}

TEST_CASE("Point Scale", "[point]")
{
    REQUIRE(Point(1.0f, 3.0f).scale(0.5f) == Point(0.5f, 1.5f));
    REQUIRE(Point(-2.5f, -1.25f).scale(0.1f) == Point(-0.25f, -0.125f));

    REQUIRE((Point(1.0f, 3.0f) * 0.5f) == Point(0.5f, 1.5f));
    REQUIRE((Point(-2.5f, -1.25f) * 0.1f) == Point(-0.25f, -0.125f));

    REQUIRE(Point(1.0f, 3.0f).scale(Point(-0.5f, 1.0f), 0.5f) == Point(0.25f, 2.0f));
    REQUIRE(Point(-2.5f, -1.25f).scale(Point(1.5f, -1.0f), 0.1f) == Point(1.1f, -1.025f));
}

TEST_CASE("Point Get Translated", "[point]")
{
    REQUIRE(Point(1.0f, 3.0f).getTranslated(Point(2.5f, 1.25f)) == Point(3.5f, 4.25f));
    REQUIRE(Point(1.0f, 3.0f).getTranslated(Point(-2.5f, -1.25f)) == Point(-1.5f, 1.75f));

    pointTemp = Point(1.0f, 3.0f);

    pointTemp.getTranslated(2.5f, 1.25f);
    REQUIRE(pointTemp == Point(1.0f, 3.0f));
    pointTemp.getTranslated(Point(2.5f, 1.25f));
    REQUIRE(pointTemp == Point(1.0f, 3.0f));
    pointTemp.getTranslated(Direction(1.0f, 1.0f), 2.5f);
    REQUIRE(pointTemp == Point(1.0f, 3.0f));
}

TEST_CASE("Point Get Scaled", "[point]")
{
    REQUIRE(Point(1.0f, 3.0f).getScaled(0.5f) == Point(0.5f, 1.5f));
    REQUIRE(Point(-2.5f, -1.25f).getScaled(0.1f) == Point(-0.25f, -0.125f));

    pointTemp = Point(1.0f, 3.0f);

    pointTemp.getScaled(0.5f);
    REQUIRE(pointTemp == Point(1.0f, 3.0f));
    pointTemp.getScaled(Point(-0.25f, 0.5f), 0.5f);
    REQUIRE(pointTemp == Point(1.0f, 3.0f));
}
