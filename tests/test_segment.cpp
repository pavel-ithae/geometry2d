#include <catch2/catch_test_macros.hpp>
#include <geometry2d/segment.hpp>
#include <geometry2d/direction.hpp>
#include "test_macros.hpp"

using namespace geometry2d;

TEST_CASE("Segment Value Constructors", "[segment]")
{
    REQUIRE(Segment(Point(0.0f, 0.0f), Point(0.0f, 0.0f)).a == Point(0.0f, 0.0f));
    REQUIRE(Segment(Point(0.0f, 0.0f), Point(0.0f, 0.0f)).b == Point(0.0f, 0.0f));

    REQUIRE(Segment(Point(1.0f, 2.0f), Point(3.0f, 4.0f)).a == Point(1.0f, 2.0f));
    REQUIRE(Segment(Point(1.0f, 2.0f), Point(3.0f, 4.0f)).b == Point(3.0f, 4.0f));

    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).a == Point(0.0f, 0.0f));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).b == Point(0.0f, 0.0f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).a == Point(1.0f, 2.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).b == Point(3.0f, 4.0f));
}

TEST_CASE("Segment Equals", "[segment]")
{
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).equals(Segment(0.0f, 0.0f, 0.0f, 0.0f)));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).equals(Segment(1.0f, 2.0f, 3.0f, 4.0f)));
    REQUIRE(Segment(-4.0f, -3.0f, -2.0f, -1.0f).equals(Segment(-4.0f, -3.0f, -2.0f, -1.0f)));

    REQUIRE_FALSE(Segment(1.0f, 2.0f, 3.0f, 4.0f).equals(Segment(0.0f, 2.0f, 3.0f, 4.0f)));
    REQUIRE_FALSE(Segment(1.0f, 2.0f, 3.0f, 4.0f).equals(Segment(1.0f, 0.0f, 3.0f, 4.0f)));
    REQUIRE_FALSE(Segment(1.0f, 2.0f, 3.0f, 4.0f).equals(Segment(1.0f, 2.0f, 0.0f, 4.0f)));
    REQUIRE_FALSE(Segment(1.0f, 2.0f, 3.0f, 4.0f).equals(Segment(1.0f, 2.0f, 3.0f, 0.0f)));

    REQUIRE_FALSE(Segment(1.0f, 2.0f, 3.0f, 4.0f).equals(Segment(1.0f + FLOAT_EPSILON, 2.0f, 3.0f, 4.0f)));
    REQUIRE_FALSE(Segment(1.0f, 2.0f, 3.0f, 4.0f).equals(Segment(1.0f, 2.0f + FLOAT_EPSILON, 3.0f, 4.0f)));
    REQUIRE_FALSE(Segment(1.0f, 2.0f, 3.0f, 4.0f).equals(Segment(1.0f, 2.0f, 3.0f + FLOAT_EPSILON, 4.0f)));
    REQUIRE_FALSE(Segment(1.0f, 2.0f, 3.0f, 4.0f).equals(Segment(1.0f, 2.0f, 3.0f, 4.0f + FLOAT_EPSILON)));

    REQUIRE_FALSE(Segment(1.0f, 2.0f, 3.0f, 4.0f).equals(Segment(1.0f - FLOAT_EPSILON, 2.0f, 3.0f, 4.0f)));
    REQUIRE_FALSE(Segment(1.0f, 2.0f, 3.0f, 4.0f).equals(Segment(1.0f, 2.0f - FLOAT_EPSILON, 3.0f, 4.0f)));
    REQUIRE_FALSE(Segment(1.0f, 2.0f, 3.0f, 4.0f).equals(Segment(1.0f, 2.0f, 3.0f - FLOAT_EPSILON, 4.0f)));
    REQUIRE_FALSE(Segment(1.0f, 2.0f, 3.0f, 4.0f).equals(Segment(1.0f, 2.0f, 3.0f, 4.0f - FLOAT_EPSILON)));
}

TEST_CASE("Segment Equals Approx", "[segment]")
{
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).equalsApprox(Segment(0.0f, 0.0f, 0.0f, 0.0f)));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).equalsApprox(Segment(1.0f, 2.0f, 3.0f, 4.0f)));
    REQUIRE(Segment(-4.0f, -3.0f, -2.0f, -1.0f).equalsApprox(Segment(-4.0f, -3.0f, -2.0f, -1.0f)));

    REQUIRE_FALSE(Segment(1.0f, 2.0f, 3.0f, 4.0f).equalsApprox(Segment(0.0f, 2.0f, 3.0f, 4.0f)));
    REQUIRE_FALSE(Segment(1.0f, 2.0f, 3.0f, 4.0f).equalsApprox(Segment(1.0f, 0.0f, 3.0f, 4.0f)));
    REQUIRE_FALSE(Segment(1.0f, 2.0f, 3.0f, 4.0f).equalsApprox(Segment(1.0f, 2.0f, 0.0f, 4.0f)));
    REQUIRE_FALSE(Segment(1.0f, 2.0f, 3.0f, 4.0f).equalsApprox(Segment(1.0f, 2.0f, 3.0f, 0.0f)));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).equalsApprox(Segment(1.0f + FLOAT_EPSILON, 2.0f, 3.0f, 4.0f)));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).equalsApprox(Segment(1.0f, 2.0f + FLOAT_EPSILON, 3.0f, 4.0f)));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).equalsApprox(Segment(1.0f, 2.0f, 3.0f + FLOAT_EPSILON, 4.0f)));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).equalsApprox(Segment(1.0f, 2.0f, 3.0f, 4.0f + FLOAT_EPSILON)));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).equalsApprox(Segment(1.0f - FLOAT_EPSILON, 2.0f, 3.0f, 4.0f)));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).equalsApprox(Segment(1.0f, 2.0f - FLOAT_EPSILON, 3.0f, 4.0f)));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).equalsApprox(Segment(1.0f, 2.0f, 3.0f - FLOAT_EPSILON, 4.0f)));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).equalsApprox(Segment(1.0f, 2.0f, 3.0f, 4.0f - FLOAT_EPSILON)));
}

TEST_CASE("Segment Equal Operator", "[segment]")
{
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f) == Segment(0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f) == Segment(1.0f, 2.0f, 3.0f, 4.0f));
    REQUIRE(Segment(-4.0f, -3.0f, -2.0f, -1.0f) == Segment(-4.0f, -3.0f, -2.0f, -1.0f));

    REQUIRE_FALSE(Segment(1.0f, 2.0f, 3.0f, 4.0f) == Segment(0.0f, 2.0f, 3.0f, 4.0f));
    REQUIRE_FALSE(Segment(1.0f, 2.0f, 3.0f, 4.0f) == Segment(1.0f, 0.0f, 3.0f, 4.0f));
    REQUIRE_FALSE(Segment(1.0f, 2.0f, 3.0f, 4.0f) == Segment(1.0f, 2.0f, 0.0f, 4.0f));
    REQUIRE_FALSE(Segment(1.0f, 2.0f, 3.0f, 4.0f) == Segment(1.0f, 2.0f, 3.0f, 0.0f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f) == Segment(1.0f + FLOAT_EPSILON, 2.0f, 3.0f, 4.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f) == Segment(1.0f, 2.0f + FLOAT_EPSILON, 3.0f, 4.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f) == Segment(1.0f, 2.0f, 3.0f + FLOAT_EPSILON, 4.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f) == Segment(1.0f, 2.0f, 3.0f, 4.0f + FLOAT_EPSILON));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f) == Segment(1.0f - FLOAT_EPSILON, 2.0f, 3.0f, 4.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f) == Segment(1.0f, 2.0f - FLOAT_EPSILON, 3.0f, 4.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f) == Segment(1.0f, 2.0f, 3.0f - FLOAT_EPSILON, 4.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f) == Segment(1.0f, 2.0f, 3.0f, 4.0f - FLOAT_EPSILON));
}

TEST_CASE("Segment Not Equal Operator", "[segment]")
{
    REQUIRE_FALSE(Segment(0.0f, 0.0f, 0.0f, 0.0f) != Segment(0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE_FALSE(Segment(1.0f, 2.0f, 3.0f, 4.0f) != Segment(1.0f, 2.0f, 3.0f, 4.0f));
    REQUIRE_FALSE(Segment(-4.0f, -3.0f, -2.0f, -1.0f) != Segment(-4.0f, -3.0f, -2.0f, -1.0f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f) != Segment(0.0f, 2.0f, 3.0f, 4.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f) != Segment(1.0f, 0.0f, 3.0f, 4.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f) != Segment(1.0f, 2.0f, 0.0f, 4.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f) != Segment(1.0f, 2.0f, 3.0f, 0.0f));

    REQUIRE_FALSE(Segment(1.0f, 2.0f, 3.0f, 4.0f) != Segment(1.0f + FLOAT_EPSILON, 2.0f, 3.0f, 4.0f));
    REQUIRE_FALSE(Segment(1.0f, 2.0f, 3.0f, 4.0f) != Segment(1.0f, 2.0f + FLOAT_EPSILON, 3.0f, 4.0f));
    REQUIRE_FALSE(Segment(1.0f, 2.0f, 3.0f, 4.0f) != Segment(1.0f, 2.0f, 3.0f + FLOAT_EPSILON, 4.0f));
    REQUIRE_FALSE(Segment(1.0f, 2.0f, 3.0f, 4.0f) != Segment(1.0f, 2.0f, 3.0f, 4.0f + FLOAT_EPSILON));

    REQUIRE_FALSE(Segment(1.0f, 2.0f, 3.0f, 4.0f) != Segment(1.0f - FLOAT_EPSILON, 2.0f, 3.0f, 4.0f));
    REQUIRE_FALSE(Segment(1.0f, 2.0f, 3.0f, 4.0f) != Segment(1.0f, 2.0f - FLOAT_EPSILON, 3.0f, 4.0f));
    REQUIRE_FALSE(Segment(1.0f, 2.0f, 3.0f, 4.0f) != Segment(1.0f, 2.0f, 3.0f - FLOAT_EPSILON, 4.0f));
    REQUIRE_FALSE(Segment(1.0f, 2.0f, 3.0f, 4.0f) != Segment(1.0f, 2.0f, 3.0f, 4.0f - FLOAT_EPSILON));
}

TEST_CASE("Segment Negate", "[segment]")
{
    REQUIRE((-Segment(1.0f, 2.0f, 3.0f, 4.0f)) == Segment(-1.0f, -2.0f, -3.0f, -4.0f));
    REQUIRE((-Segment(-4.0f, -3.0f, -2.0f, -1.0f)) == Segment(4.0f, 3.0f, 2.0f, 1.0f));
}

TEST_CASE("Segment Translate", "[segment]")
{
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).translate(1.0f, 2.0f) == Segment(1.0f, 2.0f, 1.0f, 2.0f));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).translate(-1.0f, -2.0f) == Segment(-1.0f, -2.0f, -1.0f, -2.0f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).translate(1.0f, 2.0f) == Segment(2.0f, 4.0f, 4.0f, 6.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).translate(-1.0f, -2.0f) == Segment(0.0f, 0.0f, 2.0f, 2.0f));

    REQUIRE(Segment(-4.0f, -3.0f, -2.0f, -1.0f).translate(2.0f, 4.0f) == Segment(-2.0f, 1.0f, 0.0f, 3.0f));
    REQUIRE(Segment(-4.0f, -3.0f, -2.0f, -1.0f).translate(-2.0f, -4.0f) == Segment(-6.0f, -7.0f, -4.0f, -5.0f));
}

TEST_CASE("Segment Translate Offset", "[segment]")
{
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).translate(Point(1.0f, 2.0f)) == Segment(1.0f, 2.0f, 1.0f, 2.0f));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).translate(Point(-1.0f, -2.0f)) == Segment(-1.0f, -2.0f, -1.0f, -2.0f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).translate(Point(1.0f, 2.0f)) == Segment(2.0f, 4.0f, 4.0f, 6.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).translate(Point(-1.0f, -2.0f)) == Segment(0.0f, 0.0f, 2.0f, 2.0f));

    REQUIRE(Segment(-4.0f, -3.0f, -2.0f, -1.0f).translate(Point(2.0f, 4.0f)) == Segment(-2.0f, 1.0f, 0.0f, 3.0f));
    REQUIRE(Segment(-4.0f, -3.0f, -2.0f, -1.0f).translate(Point(-2.0f, -4.0f)) == Segment(-6.0f, -7.0f, -4.0f, -5.0f));
}

TEST_CASE("Segment Translate Direction", "[segment]")
{
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).translate(Direction(1.0f, 0.0f), 3.0f) == Segment(3.0f, 0.0f, 3.0f, 0.0f));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).translate(Direction(0.0f, 1.0f), 3.0f) == Segment(0.0f, 3.0f, 0.0f, 3.0f));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).translate(Direction(-1.0f, 0.0f), 3.0f) == Segment(-3.0f, 0.0f, -3.0f, 0.0f));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).translate(Direction(0.0f, -1.0f), 3.0f) == Segment(0.0f, -3.0f, 0.0f, -3.0f));

    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).translate(Direction(1.0f, 1.0f), 3.0f) == Segment(DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(3.0f)));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).translate(Direction(-1.0f, 1.0f), 3.0f) == Segment(DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(3.0f)));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).translate(Direction(1.0f, -1.0f), 3.0f) == Segment(DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(-3.0f)));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).translate(Direction(-1.0f, -1.0f), 3.0f) == Segment(DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(-3.0f)));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).translate(Direction(1.0f, 0.0f), 3.0f) == Segment(4.0f, 2.0f, 6.0f, 4.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).translate(Direction(0.0f, 1.0f), 3.0f) == Segment(1.0f, 5.0f, 3.0f, 7.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).translate(Direction(-1.0f, 0.0f), 3.0f) == Segment(-2.0f, 2.0f, 0.0f, 4.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).translate(Direction(0.0f, -1.0f), 3.0f) == Segment(1.0f, -1.0f, 3.0f, 1.0f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).translate(Direction(1.0f, 1.0f), 3.0f) == Segment(1.0f + DIAGONAL_DELTA(3.0f), 2.0f + DIAGONAL_DELTA(3.0f), 3.0f + DIAGONAL_DELTA(3.0f), 4.0f + DIAGONAL_DELTA(3.0f)));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).translate(Direction(-1.0f, 1.0f), 3.0f) == Segment(1.0f + DIAGONAL_DELTA(-3.0f), 2.0f + DIAGONAL_DELTA(3.0f), 3.0f + DIAGONAL_DELTA(-3.0f), 4.0f + DIAGONAL_DELTA(3.0f)));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).translate(Direction(1.0f, -1.0f), 3.0f) == Segment(1.0f + DIAGONAL_DELTA(3.0f), 2.0f + DIAGONAL_DELTA(-3.0f), 3.0f + DIAGONAL_DELTA(3.0f), 4.0f + DIAGONAL_DELTA(-3.0f)));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).translate(Direction(-1.0f, -1.0f), 3.0f) == Segment(1.0f + DIAGONAL_DELTA(-3.0f), 2.0f + DIAGONAL_DELTA(-3.0f), 3.0f + DIAGONAL_DELTA(-3.0f), 4.0f + DIAGONAL_DELTA(-3.0f)));
}

TEST_CASE("Segment Addition Operator", "[segment]")
{
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f) + Point(1.0f, 2.0f) == Segment(1.0f, 2.0f, 1.0f, 2.0f));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f) + Point(-1.0f, -2.0f) == Segment(-1.0f, -2.0f, -1.0f, -2.0f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f) + Point(1.0f, 2.0f) == Segment(2.0f, 4.0f, 4.0f, 6.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f) + Point(-1.0f, -2.0f) == Segment(0.0f, 0.0f, 2.0f, 2.0f));

    REQUIRE(Segment(-4.0f, -3.0f, -2.0f, -1.0f) + Point(2.0f, 4.0f) == Segment(-2.0f, 1.0f, 0.0f, 3.0f));
    REQUIRE(Segment(-4.0f, -3.0f, -2.0f, -1.0f) + Point(-2.0f, -4.0f) == Segment(-6.0f, -7.0f, -4.0f, -5.0f));
}

TEST_CASE("Segment Substraction Operator", "[segment]")
{
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f) - Point(1.0f, 2.0f) == Segment(-1.0f, -2.0f, -1.0f, -2.0f));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f) - Point(-1.0f, -2.0f) == Segment(1.0f, 2.0f, 1.0f, 2.0f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f) - Point(1.0f, 2.0f) == Segment(0.0f, 0.0f, 2.0f, 2.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f) - Point(-1.0f, -2.0f) == Segment(2.0f, 4.0f, 4.0f, 6.0f));

    REQUIRE(Segment(-4.0f, -3.0f, -2.0f, -1.0f) - Point(2.0f, 4.0f) == Segment(-6.0f, -7.0f, -4.0f, -5.0f));
    REQUIRE(Segment(-4.0f, -3.0f, -2.0f, -1.0f) - Point(-2.0f, -4.0f) == Segment(-2.0f, 1.0f, 0.0f, 3.0f));
}

TEST_CASE("Segment Rotate Radians", "[segment]")
{
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).rotateRadians(0.0f) == Segment(0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).rotateRadians(PI_2) == Segment(0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).rotateRadians(PI) == Segment(0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).rotateRadians(PI + PI_2) == Segment(0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).rotateRadians(PI + PI) == Segment(0.0f, 0.0f, 0.0f, 0.0f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).rotateRadians(0.0f) == Segment(1.0f, 2.0f, 3.0f, 4.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).rotateRadians(PI_2) == Segment(-2.0f, 1.0f, -4.0f, 3.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).rotateRadians(PI) == Segment(-1.0f, -2.0f, -3.0f, -4.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).rotateRadians(PI + PI_2) == Segment(2.0f, -1.0f, 4.0f, -3.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).rotateRadians(PI + PI) == Segment(1.0f, 2.0f, 3.0f, 4.0f));
}

TEST_CASE("Segment Rotate Radians at Pivot", "[segment]")
{
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateRadians({1.0f, 2.0f}, 0.0f) == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateRadians({1.0f, 2.0f}, PI_2) == Segment(1.0f, 2.0f, -2.0f, 4.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateRadians({1.0f, 2.0f}, PI) == Segment(1.0f, 2.0f, -1.0f, -1.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateRadians({1.0f, 2.0f}, PI + PI_2) == Segment(1.0f, 2.0f, 4.0f, 0.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateRadians({1.0f, 2.0f}, PI + PI) == Segment(1.0f, 2.0f, 3.0f, 5.0f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateRadians({3.0f, 5.0f}, 0.0f) == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateRadians({3.0f, 5.0f}, PI_2) == Segment(6.0f, 3.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateRadians({3.0f, 5.0f}, PI) == Segment(5.0f, 8.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateRadians({3.0f, 5.0f}, PI + PI_2) == Segment(0.0f, 7.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateRadians({3.0f, 5.0f}, PI + PI) == Segment(1.0f, 2.0f, 3.0f, 5.0f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateRadiansFromA(0.0f) == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateRadiansFromA(PI_2) == Segment(1.0f, 2.0f, -2.0f, 4.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateRadiansFromA(PI) == Segment(1.0f, 2.0f, -1.0f, -1.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateRadiansFromA(PI + PI_2) == Segment(1.0f, 2.0f, 4.0f, 0.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateRadiansFromA(PI + PI) == Segment(1.0f, 2.0f, 3.0f, 5.0f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateRadiansFromB(0.0f) == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateRadiansFromB(PI_2) == Segment(6.0f, 3.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateRadiansFromB(PI) == Segment(5.0f, 8.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateRadiansFromB(PI + PI_2) == Segment(0.0f, 7.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateRadiansFromB(PI + PI) == Segment(1.0f, 2.0f, 3.0f, 5.0f));
}

TEST_CASE("Segment Rotate Degrees", "[segment]")
{
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).rotateDegrees(0.0f) == Segment(0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).rotateDegrees(90.0f) == Segment(0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).rotateDegrees(180.0f) == Segment(0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).rotateDegrees(270.0f) == Segment(0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).rotateDegrees(360.0f) == Segment(0.0f, 0.0f, 0.0f, 0.0f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).rotateDegrees(0.0f) == Segment(1.0f, 2.0f, 3.0f, 4.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).rotateDegrees(90.0f) == Segment(-2.0f, 1.0f, -4.0f, 3.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).rotateDegrees(180.0f) == Segment(-1.0f, -2.0f, -3.0f, -4.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).rotateDegrees(270.0f) == Segment(2.0f, -1.0f, 4.0f, -3.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).rotateDegrees(360.0f) == Segment(1.0f, 2.0f, 3.0f, 4.0f));
}

TEST_CASE("Segment Rotate Degrees at Pivot", "[segment]")
{
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateDegrees({1.0f, 2.0f}, 0.0f) == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateDegrees({1.0f, 2.0f}, 90.0f) == Segment(1.0f, 2.0f, -2.0f, 4.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateDegrees({1.0f, 2.0f}, 180.0f) == Segment(1.0f, 2.0f, -1.0f, -1.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateDegrees({1.0f, 2.0f}, 270.0f) == Segment(1.0f, 2.0f, 4.0f, 0.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateDegrees({1.0f, 2.0f}, 360.0f) == Segment(1.0f, 2.0f, 3.0f, 5.0f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateDegrees({3.0f, 5.0f}, 0.0f) == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateDegrees({3.0f, 5.0f}, 90.0f) == Segment(6.0f, 3.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateDegrees({3.0f, 5.0f}, 180.0f) == Segment(5.0f, 8.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateDegrees({3.0f, 5.0f}, 270.0f) == Segment(0.0f, 7.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateDegrees({3.0f, 5.0f}, 360.0f) == Segment(1.0f, 2.0f, 3.0f, 5.0f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateDegreesFromA(0.0f) == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateDegreesFromA(90.0f) == Segment(1.0f, 2.0f, -2.0f, 4.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateDegreesFromA(180.0f) == Segment(1.0f, 2.0f, -1.0f, -1.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateDegreesFromA(270.0f) == Segment(1.0f, 2.0f, 4.0f, 0.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateDegreesFromA(360.0f) == Segment(1.0f, 2.0f, 3.0f, 5.0f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateDegreesFromB(0.0f) == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateDegreesFromB(90.0f) == Segment(6.0f, 3.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateDegreesFromB(180.0f) == Segment(5.0f, 8.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateDegreesFromB(270.0f) == Segment(0.0f, 7.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).rotateDegreesFromB(360.0f) == Segment(1.0f, 2.0f, 3.0f, 5.0f));
}

TEST_CASE("Segment Scale", "[segment]")
{
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).scale(0.5f) == Segment(0.5f, 1.0f, 1.5f, 2.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).scale(0.1f) == Segment(0.1f, 0.2f, 0.3f, 0.4f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).scale({1.0f, 2.0f}, 0.5f) == Segment(1.0f, 2.0f, 2.0f, 3.5f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).scale({1.0f, 2.0f}, 0.1f) == Segment(1.0f, 2.0f, 1.2f, 2.3f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).scale({3.0f, 5.0f}, 0.5f) == Segment(2.0f, 3.5f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).scale({3.0f, 5.0f}, 0.1f) == Segment(2.8f, 4.7f, 3.0f, 5.0f));
}

TEST_CASE("Segment Get Translated", "[segment]")
{
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).getTranslated(1.0f, 2.0f) == Segment(1.0f, 2.0f, 1.0f, 2.0f));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).getTranslated(-1.0f, -2.0f) == Segment(-1.0f, -2.0f, -1.0f, -2.0f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).getTranslated(1.0f, 2.0f) == Segment(2.0f, 4.0f, 4.0f, 6.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).getTranslated(-1.0f, -2.0f) == Segment(0.0f, 0.0f, 2.0f, 2.0f));

    REQUIRE(Segment(-4.0f, -3.0f, -2.0f, -1.0f).getTranslated(2.0f, 4.0f) == Segment(-2.0f, 1.0f, 0.0f, 3.0f));
    REQUIRE(Segment(-4.0f, -3.0f, -2.0f, -1.0f).getTranslated(-2.0f, -4.0f) == Segment(-6.0f, -7.0f, -4.0f, -5.0f));

    Segment temp(1.0f, 2.0f, 3.0f, 4.0f);

    temp.getTranslated(1.0f, 2.0f);
    REQUIRE(temp == Segment(1.0f, 2.0f, 3.0f, 4.0f));
    temp.getTranslated(-1.0f, -2.0f);
    REQUIRE(temp == Segment(1.0f, 2.0f, 3.0f, 4.0f));
}

TEST_CASE("Segment Get Translated Offset", "[segment]")
{
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Point(1.0f, 2.0f)) == Segment(1.0f, 2.0f, 1.0f, 2.0f));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Point(-1.0f, -2.0f)) == Segment(-1.0f, -2.0f, -1.0f, -2.0f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).getTranslated(Point(1.0f, 2.0f)) == Segment(2.0f, 4.0f, 4.0f, 6.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).getTranslated(Point(-1.0f, -2.0f)) == Segment(0.0f, 0.0f, 2.0f, 2.0f));

    REQUIRE(Segment(-4.0f, -3.0f, -2.0f, -1.0f).getTranslated(Point(2.0f, 4.0f)) == Segment(-2.0f, 1.0f, 0.0f, 3.0f));
    REQUIRE(Segment(-4.0f, -3.0f, -2.0f, -1.0f).getTranslated(Point(-2.0f, -4.0f)) == Segment(-6.0f, -7.0f, -4.0f, -5.0f));

    Segment temp(1.0f, 2.0f, 3.0f, 4.0f);

    temp.getTranslated(Point(1.0f, 2.0f));
    REQUIRE(temp == Segment(1.0f, 2.0f, 3.0f, 4.0f));
    temp.getTranslated(Point(-1.0f, -2.0f));
    REQUIRE(temp == Segment(1.0f, 2.0f, 3.0f, 4.0f));
}

TEST_CASE("Segment Get Translated Direction", "[segment]")
{
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Direction(1.0f, 0.0f), 3.0f) == Segment(3.0f, 0.0f, 3.0f, 0.0f));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Direction(0.0f, 1.0f), 3.0f) == Segment(0.0f, 3.0f, 0.0f, 3.0f));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Direction(-1.0f, 0.0f), 3.0f) == Segment(-3.0f, 0.0f, -3.0f, 0.0f));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Direction(0.0f, -1.0f), 3.0f) == Segment(0.0f, -3.0f, 0.0f, -3.0f));

    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Direction(1.0f, 1.0f), 3.0f) == Segment(DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(3.0f)));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Direction(-1.0f, 1.0f), 3.0f) == Segment(DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(3.0f)));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Direction(1.0f, -1.0f), 3.0f) == Segment(DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(-3.0f)));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Direction(-1.0f, -1.0f), 3.0f) == Segment(DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(-3.0f)));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).getTranslated(Direction(1.0f, 0.0f), 3.0f) == Segment(4.0f, 2.0f, 6.0f, 4.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).getTranslated(Direction(0.0f, 1.0f), 3.0f) == Segment(1.0f, 5.0f, 3.0f, 7.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).getTranslated(Direction(-1.0f, 0.0f), 3.0f) == Segment(-2.0f, 2.0f, 0.0f, 4.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).getTranslated(Direction(0.0f, -1.0f), 3.0f) == Segment(1.0f, -1.0f, 3.0f, 1.0f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).getTranslated(Direction(1.0f, 1.0f), 3.0f) == Segment(1.0f + DIAGONAL_DELTA(3.0f), 2.0f + DIAGONAL_DELTA(3.0f), 3.0f + DIAGONAL_DELTA(3.0f), 4.0f + DIAGONAL_DELTA(3.0f)));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).getTranslated(Direction(-1.0f, 1.0f), 3.0f) == Segment(1.0f + DIAGONAL_DELTA(-3.0f), 2.0f + DIAGONAL_DELTA(3.0f), 3.0f + DIAGONAL_DELTA(-3.0f), 4.0f + DIAGONAL_DELTA(3.0f)));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).getTranslated(Direction(1.0f, -1.0f), 3.0f) == Segment(1.0f + DIAGONAL_DELTA(3.0f), 2.0f + DIAGONAL_DELTA(-3.0f), 3.0f + DIAGONAL_DELTA(3.0f), 4.0f + DIAGONAL_DELTA(-3.0f)));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).getTranslated(Direction(-1.0f, -1.0f), 3.0f) == Segment(1.0f + DIAGONAL_DELTA(-3.0f), 2.0f + DIAGONAL_DELTA(-3.0f), 3.0f + DIAGONAL_DELTA(-3.0f), 4.0f + DIAGONAL_DELTA(-3.0f)));

    Segment temp(1.0f, 2.0f, 3.0f, 4.0f);

    temp.getTranslated(Direction(1.0f, 1.0f), 3.0f);
    REQUIRE(temp == Segment(1.0f, 2.0f, 3.0f, 4.0f));
    temp.getTranslated(Direction(-1.0f, -1.0f), 3.0f);
    REQUIRE(temp == Segment(1.0f, 2.0f, 3.0f, 4.0f));
}

TEST_CASE("Segment Get Rotated Radians", "[segment]")
{
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).getRotatedRadians(0.0f) == Segment(0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).getRotatedRadians(PI_2) == Segment(0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).getRotatedRadians(PI) == Segment(0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).getRotatedRadians(PI + PI_2) == Segment(0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).getRotatedRadians(PI + PI) == Segment(0.0f, 0.0f, 0.0f, 0.0f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).getRotatedRadians(0.0f) == Segment(1.0f, 2.0f, 3.0f, 4.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).getRotatedRadians(PI_2) == Segment(-2.0f, 1.0f, -4.0f, 3.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).getRotatedRadians(PI) == Segment(-1.0f, -2.0f, -3.0f, -4.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).getRotatedRadians(PI + PI_2) == Segment(2.0f, -1.0f, 4.0f, -3.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).getRotatedRadians(PI + PI) == Segment(1.0f, 2.0f, 3.0f, 4.0f));

    Segment temp(1.0f, 2.0f, 3.0f, 4.0f);

    temp.getRotatedRadians(PI_2);
    REQUIRE(temp == Segment(1.0f, 2.0f, 3.0f, 4.0f));
    temp.getRotatedRadians(PI);
    REQUIRE(temp == Segment(1.0f, 2.0f, 3.0f, 4.0f));
}

TEST_CASE("Segment Get Rotated Radians at Pivot", "[segment]")
{
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedRadians({1.0f, 2.0f}, 0.0f) == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedRadians({1.0f, 2.0f}, PI_2) == Segment(1.0f, 2.0f, -2.0f, 4.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedRadians({1.0f, 2.0f}, PI) == Segment(1.0f, 2.0f, -1.0f, -1.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedRadians({1.0f, 2.0f}, PI + PI_2) == Segment(1.0f, 2.0f, 4.0f, 0.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedRadians({1.0f, 2.0f}, PI + PI) == Segment(1.0f, 2.0f, 3.0f, 5.0f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedRadians({3.0f, 5.0f}, 0.0f) == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedRadians({3.0f, 5.0f}, PI_2) == Segment(6.0f, 3.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedRadians({3.0f, 5.0f}, PI) == Segment(5.0f, 8.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedRadians({3.0f, 5.0f}, PI + PI_2) == Segment(0.0f, 7.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedRadians({3.0f, 5.0f}, PI + PI) == Segment(1.0f, 2.0f, 3.0f, 5.0f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedRadiansFromA(0.0f) == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedRadiansFromA(PI_2) == Segment(1.0f, 2.0f, -2.0f, 4.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedRadiansFromA(PI) == Segment(1.0f, 2.0f, -1.0f, -1.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedRadiansFromA(PI + PI_2) == Segment(1.0f, 2.0f, 4.0f, 0.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedRadiansFromA(PI + PI) == Segment(1.0f, 2.0f, 3.0f, 5.0f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedRadiansFromB(0.0f) == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedRadiansFromB(PI_2) == Segment(6.0f, 3.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedRadiansFromB(PI) == Segment(5.0f, 8.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedRadiansFromB(PI + PI_2) == Segment(0.0f, 7.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedRadiansFromB(PI + PI) == Segment(1.0f, 2.0f, 3.0f, 5.0f));

    Segment temp(1.0f, 2.0f, 3.0f, 5.0f);

    temp.getRotatedRadians({1.0f, 2.0f},PI_2);
    REQUIRE(temp == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    temp.getRotatedRadians({1.0f, 2.0f},PI);
    REQUIRE(temp == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    temp.getRotatedRadians({3.0f, 5.0f},PI_2);
    REQUIRE(temp == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    temp.getRotatedRadians({3.0f, 5.0f},PI);
    REQUIRE(temp == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    temp.getRotatedRadiansFromA(PI_2);
    REQUIRE(temp == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    temp.getRotatedRadiansFromA(PI);
    REQUIRE(temp == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    temp.getRotatedRadiansFromB(PI_2);
    REQUIRE(temp == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    temp.getRotatedRadiansFromB(PI);
    REQUIRE(temp == Segment(1.0f, 2.0f, 3.0f, 5.0f));
}

TEST_CASE("Segment Get Rotated Degrees", "[segment]")
{
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).getRotatedDegrees(0.0f) == Segment(0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).getRotatedDegrees(90.0f) == Segment(0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).getRotatedDegrees(180.0f) == Segment(0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).getRotatedDegrees(270.0f) == Segment(0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Segment(0.0f, 0.0f, 0.0f, 0.0f).getRotatedDegrees(360.0f) == Segment(0.0f, 0.0f, 0.0f, 0.0f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).getRotatedDegrees(0.0f) == Segment(1.0f, 2.0f, 3.0f, 4.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).getRotatedDegrees(90.0f) == Segment(-2.0f, 1.0f, -4.0f, 3.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).getRotatedDegrees(180.0f) == Segment(-1.0f, -2.0f, -3.0f, -4.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).getRotatedDegrees(270.0f) == Segment(2.0f, -1.0f, 4.0f, -3.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).getRotatedDegrees(360.0f) == Segment(1.0f, 2.0f, 3.0f, 4.0f));

    Segment temp(1.0f, 2.0f, 3.0f, 4.0f);

    temp.getRotatedDegrees(90.0f);
    REQUIRE(temp == Segment(1.0f, 2.0f, 3.0f, 4.0f));
    temp.getRotatedDegrees(180.0f);
    REQUIRE(temp == Segment(1.0f, 2.0f, 3.0f, 4.0f));
}

TEST_CASE("Segment Get Rotated Degrees at Pivot", "[segment]")
{
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedDegrees({1.0f, 2.0f}, 0.0f) == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedDegrees({1.0f, 2.0f}, 90.0f) == Segment(1.0f, 2.0f, -2.0f, 4.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedDegrees({1.0f, 2.0f}, 180.0f) == Segment(1.0f, 2.0f, -1.0f, -1.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedDegrees({1.0f, 2.0f}, 270.0f) == Segment(1.0f, 2.0f, 4.0f, 0.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedDegrees({1.0f, 2.0f}, 360.0f) == Segment(1.0f, 2.0f, 3.0f, 5.0f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedDegrees({3.0f, 5.0f}, 0.0f) == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedDegrees({3.0f, 5.0f}, 90.0f) == Segment(6.0f, 3.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedDegrees({3.0f, 5.0f}, 180.0f) == Segment(5.0f, 8.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedDegrees({3.0f, 5.0f}, 270.0f) == Segment(0.0f, 7.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedDegrees({3.0f, 5.0f}, 360.0f) == Segment(1.0f, 2.0f, 3.0f, 5.0f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedDegreesFromA(0.0f) == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedDegreesFromA(90.0f) == Segment(1.0f, 2.0f, -2.0f, 4.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedDegreesFromA(180.0f) == Segment(1.0f, 2.0f, -1.0f, -1.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedDegreesFromA(270.0f) == Segment(1.0f, 2.0f, 4.0f, 0.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedDegreesFromA(360.0f) == Segment(1.0f, 2.0f, 3.0f, 5.0f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedDegreesFromB(0.0f) == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedDegreesFromB(90.0f) == Segment(6.0f, 3.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedDegreesFromB(180.0f) == Segment(5.0f, 8.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedDegreesFromB(270.0f) == Segment(0.0f, 7.0f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getRotatedDegreesFromB(360.0f) == Segment(1.0f, 2.0f, 3.0f, 5.0f));

    Segment temp(1.0f, 2.0f, 3.0f, 5.0f);

    temp.getRotatedDegrees({1.0f, 2.0f},180.0f);
    REQUIRE(temp == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    temp.getRotatedDegrees({1.0f, 2.0f},90.0f);
    REQUIRE(temp == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    temp.getRotatedDegrees({3.0f, 5.0f},180.0f);
    REQUIRE(temp == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    temp.getRotatedDegrees({3.0f, 5.0f},90.0f);
    REQUIRE(temp == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    temp.getRotatedDegreesFromA(180.0f);
    REQUIRE(temp == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    temp.getRotatedDegreesFromA(90.0f);
    REQUIRE(temp == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    temp.getRotatedDegreesFromB(180.0f);
    REQUIRE(temp == Segment(1.0f, 2.0f, 3.0f, 5.0f));
    temp.getRotatedDegreesFromB(90.0f);
    REQUIRE(temp == Segment(1.0f, 2.0f, 3.0f, 5.0f));
}

TEST_CASE("Segment Get Scaled", "[segment]")
{
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).getScaled(0.5f) == Segment(0.5f, 1.0f, 1.5f, 2.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 4.0f).getScaled(0.1f) == Segment(0.1f, 0.2f, 0.3f, 0.4f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getScaled({1.0f, 2.0f}, 0.5f) == Segment(1.0f, 2.0f, 2.0f, 3.5f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getScaled({1.0f, 2.0f}, 0.1f) == Segment(1.0f, 2.0f, 1.2f, 2.3f));

    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getScaled({3.0f, 5.0f}, 0.5f) == Segment(2.0f, 3.5f, 3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getScaled({3.0f, 5.0f}, 0.1f) == Segment(2.8f, 4.7f, 3.0f, 5.0f));

    Segment temp(1.0f, 2.0f, 3.0f, 4.0f);

    temp.getScaled(0.5f);
    REQUIRE(temp == Segment(1.0f, 2.0f, 3.0f, 4.0f));
    temp.getScaled({1.0f, 2.0f}, 0.5f);
    REQUIRE(temp == Segment(1.0f, 2.0f, 3.0f, 4.0f));
    temp.getScaled({3.0f, 4.0f}, 0.5f);
    REQUIRE(temp == Segment(1.0f, 2.0f, 3.0f, 4.0f));
}

TEST_CASE("Segment Get Point", "[segment]")
{
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getPoint(0.0f) == Point(1.0f, 2.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getPoint(1.0f) == Point(3.0f, 5.0f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getPoint(0.5f) == Point(2.0f, 3.5f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getPoint(0.25f) == Point(1.5f, 2.75f));
    REQUIRE(Segment(1.0f, 2.0f, 3.0f, 5.0f).getPoint(0.75f) == Point(2.5f, 4.25f));
}