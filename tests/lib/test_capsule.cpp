#include <catch2/catch_test_macros.hpp>
#include <geometry2d/capsule.hpp>
#include <geometry2d/direction.hpp>
#include "test_macros.hpp"

using namespace geometry2d;

TEST_CASE("Capsule Value Constructors", "[capsule]")
{
    REQUIRE(Capsule(Segment(0.0f, 0.0f, 0.0f, 0.0f), 0.0f).segment == Segment(0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Capsule(Segment(0.0f, 0.0f, 0.0f, 0.0f), 0.0f).radius == 0.0f);

    REQUIRE(Capsule(Segment(Point(1.0f, 2.0f), Point(3.0f, 4.0f)), 5.0f).segment == Segment(1.0f, 2.0f, 3.0f, 4.0f));
    REQUIRE(Capsule(Segment(Point(1.0f, 2.0f), Point(3.0f, 4.0f)), 5.0f).radius == 5.0f);

    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).segment == Segment(0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).radius == 0.0f);

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).segment == Segment(1.0f, 2.0f, 3.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).radius == 5.0f);
}

TEST_CASE("Capsule Equals", "[capsule]")
{
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).equals(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f)));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equals(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f)));
    REQUIRE(Capsule(-4.0f, -3.0f, -2.0f, -1.0f, 0.0f).equals(Capsule(-4.0f, -3.0f, -2.0f, -1.0f, 0.0f)));

    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equals(Capsule(0.0f, 2.0f, 3.0f, 4.0f, 5.0f)));
    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equals(Capsule(1.0f, 0.0f, 3.0f, 4.0f, 5.0f)));
    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equals(Capsule(1.0f, 2.0f, 0.0f, 4.0f, 5.0f)));
    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equals(Capsule(1.0f, 2.0f, 3.0f, 0.0f, 5.0f)));
    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equals(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 0.0f)));

    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equals(Capsule(1.0f + FLOAT_EPSILON, 2.0f, 3.0f, 4.0f, 5.0f)));
    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equals(Capsule(1.0f, 2.0f + FLOAT_EPSILON, 3.0f, 4.0f, 5.0f)));
    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equals(Capsule(1.0f, 2.0f, 3.0f + FLOAT_EPSILON, 4.0f, 5.0f)));
    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equals(Capsule(1.0f, 2.0f, 3.0f, 4.0f + FLOAT_EPSILON, 5.0f)));
    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equals(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f + FLOAT_EPSILON)));

    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equals(Capsule(1.0f - FLOAT_EPSILON, 2.0f, 3.0f, 4.0f, 5.0f)));
    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equals(Capsule(1.0f, 2.0f - FLOAT_EPSILON, 3.0f, 4.0f, 5.0f)));
    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equals(Capsule(1.0f, 2.0f, 3.0f - FLOAT_EPSILON, 4.0f, 5.0f)));
    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equals(Capsule(1.0f, 2.0f, 3.0f, 4.0f - FLOAT_EPSILON, 5.0f)));
    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equals(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f - FLOAT_EPSILON)));
}

TEST_CASE("Capsule Equals Approx", "[capsule]")
{
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).equalsApprox(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f)));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equalsApprox(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f)));
    REQUIRE(Capsule(-4.0f, -3.0f, -2.0f, -1.0f, 0.0f).equalsApprox(Capsule(-4.0f, -3.0f, -2.0f, -1.0f, 0.0f)));

    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equalsApprox(Capsule(0.0f, 2.0f, 3.0f, 4.0f, 5.0f)));
    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equalsApprox(Capsule(1.0f, 0.0f, 3.0f, 4.0f, 5.0f)));
    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equalsApprox(Capsule(1.0f, 2.0f, 0.0f, 4.0f, 5.0f)));
    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equalsApprox(Capsule(1.0f, 2.0f, 3.0f, 0.0f, 5.0f)));
    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equalsApprox(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 0.0f)));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equalsApprox(Capsule(1.0f + FLOAT_EPSILON, 2.0f, 3.0f, 4.0f, 5.0f)));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equalsApprox(Capsule(1.0f, 2.0f + FLOAT_EPSILON, 3.0f, 4.0f, 5.0f)));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equalsApprox(Capsule(1.0f, 2.0f, 3.0f + FLOAT_EPSILON, 4.0f, 5.0f)));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equalsApprox(Capsule(1.0f, 2.0f, 3.0f, 4.0f + FLOAT_EPSILON, 5.0f)));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equalsApprox(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f + FLOAT_EPSILON)));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equalsApprox(Capsule(1.0f - FLOAT_EPSILON, 2.0f, 3.0f, 4.0f, 5.0f)));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equalsApprox(Capsule(1.0f, 2.0f - FLOAT_EPSILON, 3.0f, 4.0f, 5.0f)));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equalsApprox(Capsule(1.0f, 2.0f, 3.0f - FLOAT_EPSILON, 4.0f, 5.0f)));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equalsApprox(Capsule(1.0f, 2.0f, 3.0f, 4.0f - FLOAT_EPSILON, 5.0f)));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).equalsApprox(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f - FLOAT_EPSILON)));
}

TEST_CASE("Capsule Equal Operator", "[capsule]")
{
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f) == Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) == Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f));
    REQUIRE(Capsule(-4.0f, -3.0f, -2.0f, -1.0f, 0.0f) == Capsule(-4.0f, -3.0f, -2.0f, -1.0f, 0.0f));

    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) == Capsule(0.0f, 2.0f, 3.0f, 4.0f, 5.0f));
    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) == Capsule(1.0f, 0.0f, 3.0f, 4.0f, 5.0f));
    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) == Capsule(1.0f, 2.0f, 0.0f, 4.0f, 5.0f));
    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) == Capsule(1.0f, 2.0f, 3.0f, 0.0f, 5.0f));
    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) == Capsule(1.0f, 2.0f, 3.0f, 4.0f, 0.0f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) == Capsule(1.0f + FLOAT_EPSILON, 2.0f, 3.0f, 4.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) == Capsule(1.0f, 2.0f + FLOAT_EPSILON, 3.0f, 4.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) == Capsule(1.0f, 2.0f, 3.0f + FLOAT_EPSILON, 4.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) == Capsule(1.0f, 2.0f, 3.0f, 4.0f + FLOAT_EPSILON, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) == Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f + FLOAT_EPSILON));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) == Capsule(1.0f - FLOAT_EPSILON, 2.0f, 3.0f, 4.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) == Capsule(1.0f, 2.0f - FLOAT_EPSILON, 3.0f, 4.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) == Capsule(1.0f, 2.0f, 3.0f - FLOAT_EPSILON, 4.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) == Capsule(1.0f, 2.0f, 3.0f, 4.0f - FLOAT_EPSILON, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) == Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f - FLOAT_EPSILON));
}

TEST_CASE("Capsule Not Equal Operator", "[capsule]")
{
    REQUIRE_FALSE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f) != Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) != Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f));
    REQUIRE_FALSE(Capsule(-4.0f, -3.0f, -2.0f, -1.0f, 0.0f) != Capsule(-4.0f, -3.0f, -2.0f, -1.0f, 0.0f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) != Capsule(0.0f, 2.0f, 3.0f, 4.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) != Capsule(1.0f, 0.0f, 3.0f, 4.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) != Capsule(1.0f, 2.0f, 0.0f, 4.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) != Capsule(1.0f, 2.0f, 3.0f, 0.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) != Capsule(1.0f, 2.0f, 3.0f, 4.0f, 0.0f));

    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) != Capsule(1.0f + FLOAT_EPSILON, 2.0f, 3.0f, 4.0f, 5.0f));
    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) != Capsule(1.0f, 2.0f + FLOAT_EPSILON, 3.0f, 4.0f, 5.0f));
    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) != Capsule(1.0f, 2.0f, 3.0f + FLOAT_EPSILON, 4.0f, 5.0f));
    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) != Capsule(1.0f, 2.0f, 3.0f, 4.0f + FLOAT_EPSILON, 5.0f));
    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) != Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f + FLOAT_EPSILON));

    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) != Capsule(1.0f - FLOAT_EPSILON, 2.0f, 3.0f, 4.0f, 5.0f));
    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) != Capsule(1.0f, 2.0f - FLOAT_EPSILON, 3.0f, 4.0f, 5.0f));
    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) != Capsule(1.0f, 2.0f, 3.0f - FLOAT_EPSILON, 4.0f, 5.0f));
    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) != Capsule(1.0f, 2.0f, 3.0f, 4.0f - FLOAT_EPSILON, 5.0f));
    REQUIRE_FALSE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) != Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f - FLOAT_EPSILON));

}

TEST_CASE("Capsule Negate", "[capsule]")
{
    REQUIRE((-Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f)) == Capsule(-1.0f, -2.0f, -3.0f, -4.0f, 5.0f));
    REQUIRE((-Capsule(-4.0f, -3.0f, -2.0f, -1.0f, 5.0f)) == Capsule(4.0f, 3.0f, 2.0f, 1.0f, 5.0f));
}

TEST_CASE("Capsule Translate", "[capsule]")
{
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 5.0f).translate(1.0f, 2.0f) == Capsule(1.0f, 2.0f, 1.0f, 2.0f, 5.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 5.0f).translate(-1.0f, -2.0f) == Capsule(-1.0f, -2.0f, -1.0f, -2.0f, 5.0f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).translate(1.0f, 2.0f) == Capsule(2.0f, 4.0f, 4.0f, 6.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).translate(-1.0f, -2.0f) == Capsule(0.0f, 0.0f, 2.0f, 2.0f, 5.0f));

    REQUIRE(Capsule(-4.0f, -3.0f, -2.0f, -1.0f, 5.0f).translate(2.0f, 4.0f) == Capsule(-2.0f, 1.0f, 0.0f, 3.0f, 5.0f));
    REQUIRE(Capsule(-4.0f, -3.0f, -2.0f, -1.0f, 5.0f).translate(-2.0f, -4.0f) == Capsule(-6.0f, -7.0f, -4.0f, -5.0f, 5.0f));
}

TEST_CASE("Capsule Translate Offset", "[capsule]")
{
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 5.0f).translate(Point(1.0f, 2.0f)) == Capsule(1.0f, 2.0f, 1.0f, 2.0f, 5.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 5.0f).translate(Point(-1.0f, -2.0f)) == Capsule(-1.0f, -2.0f, -1.0f, -2.0f, 5.0f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).translate(Point(1.0f, 2.0f)) == Capsule(2.0f, 4.0f, 4.0f, 6.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).translate(Point(-1.0f, -2.0f)) == Capsule(0.0f, 0.0f, 2.0f, 2.0f, 5.0f));

    REQUIRE(Capsule(-4.0f, -3.0f, -2.0f, -1.0f, 5.0f).translate(Point(2.0f, 4.0f)) == Capsule(-2.0f, 1.0f, 0.0f, 3.0f, 5.0f));
    REQUIRE(Capsule(-4.0f, -3.0f, -2.0f, -1.0f, 5.0f).translate(Point(-2.0f, -4.0f)) == Capsule(-6.0f, -7.0f, -4.0f, -5.0f, 5.0f));
}

TEST_CASE("Capsule Translate Direction", "[capsule]")
{
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 5.0f).translate(Direction(1.0f, 0.0f), 3.0f) == Capsule(3.0f, 0.0f, 3.0f, 0.0f, 5.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 5.0f).translate(Direction(0.0f, 1.0f), 3.0f) == Capsule(0.0f, 3.0f, 0.0f, 3.0f, 5.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 5.0f).translate(Direction(-1.0f, 0.0f), 3.0f) == Capsule(-3.0f, 0.0f, -3.0f, 0.0f, 5.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 5.0f).translate(Direction(0.0f, -1.0f), 3.0f) == Capsule(0.0f, -3.0f, 0.0f, -3.0f, 5.0f));

    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 5.0f).translate(Direction(1.0f, 1.0f), 3.0f) == Capsule(DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(3.0f), 5.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 5.0f).translate(Direction(-1.0f, 1.0f), 3.0f) == Capsule(DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(3.0f), 5.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 5.0f).translate(Direction(1.0f, -1.0f), 3.0f) == Capsule(DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(-3.0f), 5.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 5.0f).translate(Direction(-1.0f, -1.0f), 3.0f) == Capsule(DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(-3.0f), 5.0f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).translate(Direction(1.0f, 0.0f), 3.0f) == Capsule(4.0f, 2.0f, 6.0f, 4.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).translate(Direction(0.0f, 1.0f), 3.0f) == Capsule(1.0f, 5.0f, 3.0f, 7.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).translate(Direction(-1.0f, 0.0f), 3.0f) == Capsule(-2.0f, 2.0f, 0.0f, 4.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).translate(Direction(0.0f, -1.0f), 3.0f) == Capsule(1.0f, -1.0f, 3.0f, 1.0f, 5.0f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).translate(Direction(1.0f, 1.0f), 3.0f) == Capsule(1.0f + DIAGONAL_DELTA(3.0f), 2.0f + DIAGONAL_DELTA(3.0f), 3.0f + DIAGONAL_DELTA(3.0f), 4.0f + DIAGONAL_DELTA(3.0f), 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).translate(Direction(-1.0f, 1.0f), 3.0f) == Capsule(1.0f + DIAGONAL_DELTA(-3.0f), 2.0f + DIAGONAL_DELTA(3.0f), 3.0f + DIAGONAL_DELTA(-3.0f), 4.0f + DIAGONAL_DELTA(3.0f), 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).translate(Direction(1.0f, -1.0f), 3.0f) == Capsule(1.0f + DIAGONAL_DELTA(3.0f), 2.0f + DIAGONAL_DELTA(-3.0f), 3.0f + DIAGONAL_DELTA(3.0f), 4.0f + DIAGONAL_DELTA(-3.0f), 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).translate(Direction(-1.0f, -1.0f), 3.0f) == Capsule(1.0f + DIAGONAL_DELTA(-3.0f), 2.0f + DIAGONAL_DELTA(-3.0f), 3.0f + DIAGONAL_DELTA(-3.0f), 4.0f + DIAGONAL_DELTA(-3.0f), 5.0f));
}

TEST_CASE("Capsule Addition Operator", "[capsule]")
{
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 5.0f) + Point(1.0f, 2.0f) == Capsule(1.0f, 2.0f, 1.0f, 2.0f, 5.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 5.0f) + Point(-1.0f, -2.0f) == Capsule(-1.0f, -2.0f, -1.0f, -2.0f, 5.0f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) + Point(1.0f, 2.0f) == Capsule(2.0f, 4.0f, 4.0f, 6.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) + Point(-1.0f, -2.0f) == Capsule(0.0f, 0.0f, 2.0f, 2.0f, 5.0f));

    REQUIRE(Capsule(-4.0f, -3.0f, -2.0f, -1.0f, 5.0f) + Point(2.0f, 4.0f) == Capsule(-2.0f, 1.0f, 0.0f, 3.0f, 5.0f));
    REQUIRE(Capsule(-4.0f, -3.0f, -2.0f, -1.0f, 5.0f) + Point(-2.0f, -4.0f) == Capsule(-6.0f, -7.0f, -4.0f, -5.0f, 5.0f));
}

TEST_CASE("Capsule Substraction Operator", "[capsule]")
{
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 5.0f) - Point(1.0f, 2.0f) == Capsule(-1.0f, -2.0f, -1.0f, -2.0f, 5.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 5.0f) - Point(-1.0f, -2.0f) == Capsule(1.0f, 2.0f, 1.0f, 2.0f, 5.0f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) - Point(1.0f, 2.0f) == Capsule(0.0f, 0.0f, 2.0f, 2.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f) - Point(-1.0f, -2.0f) == Capsule(2.0f, 4.0f, 4.0f, 6.0f, 5.0f));

    REQUIRE(Capsule(-4.0f, -3.0f, -2.0f, -1.0f, 5.0f) - Point(2.0f, 4.0f) == Capsule(-6.0f, -7.0f, -4.0f, -5.0f, 5.0f));
    REQUIRE(Capsule(-4.0f, -3.0f, -2.0f, -1.0f, 5.0f) - Point(-2.0f, -4.0f) == Capsule(-2.0f, 1.0f, 0.0f, 3.0f, 5.0f));
}

TEST_CASE("Capsule Rotate Radians", "[capsule]")
{
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).rotateRadians(0.0f) == Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).rotateRadians(PI_2) == Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).rotateRadians(PI) == Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).rotateRadians(PI + PI_2) == Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).rotateRadians(PI + PI) == Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).rotateRadians(0.0f) == Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).rotateRadians(PI_2) == Capsule(-2.0f, 1.0f, -4.0f, 3.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).rotateRadians(PI) == Capsule(-1.0f, -2.0f, -3.0f, -4.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).rotateRadians(PI + PI_2) == Capsule(2.0f, -1.0f, 4.0f, -3.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).rotateRadians(PI + PI) == Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f));
}

TEST_CASE("Capsule Rotate Radians at Pivot", "[capsule]")
{
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateRadians({1.0f, 2.0f}, 0.0f) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateRadians({1.0f, 2.0f}, PI_2) == Capsule(1.0f, 2.0f, -2.0f, 4.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateRadians({1.0f, 2.0f}, PI) == Capsule(1.0f, 2.0f, -1.0f, -1.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateRadians({1.0f, 2.0f}, PI + PI_2) == Capsule(1.0f, 2.0f, 4.0f, 0.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateRadians({1.0f, 2.0f}, PI + PI) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateRadians({3.0f, 5.0f}, 0.0f) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateRadians({3.0f, 5.0f}, PI_2) == Capsule(6.0f, 3.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateRadians({3.0f, 5.0f}, PI) == Capsule(5.0f, 8.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateRadians({3.0f, 5.0f}, PI + PI_2) == Capsule(0.0f, 7.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateRadians({3.0f, 5.0f}, PI + PI) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateRadiansFromA(0.0f) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateRadiansFromA(PI_2) == Capsule(1.0f, 2.0f, -2.0f, 4.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateRadiansFromA(PI) == Capsule(1.0f, 2.0f, -1.0f, -1.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateRadiansFromA(PI + PI_2) == Capsule(1.0f, 2.0f, 4.0f, 0.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateRadiansFromA(PI + PI) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateRadiansFromB(0.0f) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateRadiansFromB(PI_2) == Capsule(6.0f, 3.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateRadiansFromB(PI) == Capsule(5.0f, 8.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateRadiansFromB(PI + PI_2) == Capsule(0.0f, 7.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateRadiansFromB(PI + PI) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
}

TEST_CASE("Capsule Rotate Degrees", "[capsule]")
{
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).rotateDegrees(0.0f) == Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).rotateDegrees(90.0f) == Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).rotateDegrees(180.0f) == Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).rotateDegrees(270.0f) == Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).rotateDegrees(360.0f) == Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).rotateDegrees(0.0f) == Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).rotateDegrees(90.0f) == Capsule(-2.0f, 1.0f, -4.0f, 3.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).rotateDegrees(180.0f) == Capsule(-1.0f, -2.0f, -3.0f, -4.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).rotateDegrees(270.0f) == Capsule(2.0f, -1.0f, 4.0f, -3.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).rotateDegrees(360.0f) == Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f));
}

TEST_CASE("Capsule Rotate Degrees at Pivot", "[capsule]")
{
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateDegrees({1.0f, 2.0f}, 0.0f) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateDegrees({1.0f, 2.0f}, 90.0f) == Capsule(1.0f, 2.0f, -2.0f, 4.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateDegrees({1.0f, 2.0f}, 180.0f) == Capsule(1.0f, 2.0f, -1.0f, -1.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateDegrees({1.0f, 2.0f}, 270.0f) == Capsule(1.0f, 2.0f, 4.0f, 0.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateDegrees({1.0f, 2.0f}, 360.0f) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateDegrees({3.0f, 5.0f}, 0.0f) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateDegrees({3.0f, 5.0f}, 90.0f) == Capsule(6.0f, 3.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateDegrees({3.0f, 5.0f}, 180.0f) == Capsule(5.0f, 8.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateDegrees({3.0f, 5.0f}, 270.0f) == Capsule(0.0f, 7.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateDegrees({3.0f, 5.0f}, 360.0f) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateDegreesFromA(0.0f) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateDegreesFromA(90.0f) == Capsule(1.0f, 2.0f, -2.0f, 4.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateDegreesFromA(180.0f) == Capsule(1.0f, 2.0f, -1.0f, -1.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateDegreesFromA(270.0f) == Capsule(1.0f, 2.0f, 4.0f, 0.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateDegreesFromA(360.0f) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateDegreesFromB(0.0f) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateDegreesFromB(90.0f) == Capsule(6.0f, 3.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateDegreesFromB(180.0f) == Capsule(5.0f, 8.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateDegreesFromB(270.0f) == Capsule(0.0f, 7.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).rotateDegreesFromB(360.0f) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
}

TEST_CASE("Capsule Scale", "[capsule]")
{
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).scale(0.5f) == Capsule(0.5f, 1.0f, 1.5f, 2.0f, 2.5f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).scale(0.1f) == Capsule(0.1f, 0.2f, 0.3f, 0.4f, 0.5f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).scale({1.0f, 2.0f}, 0.5f) == Capsule(1.0f, 2.0f, 2.0f, 3.5f, 2.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).scale({1.0f, 2.0f}, 0.1f) == Capsule(1.0f, 2.0f, 1.2f, 2.3f, 0.4f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).scale({3.0f, 5.0f}, 0.5f) == Capsule(2.0f, 3.5f, 3.0f, 5.0f, 2.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).scale({3.0f, 5.0f}, 0.1f) == Capsule(2.8f, 4.7f, 3.0f, 5.0f, 0.4f));
}

TEST_CASE("Capsule Get Translated", "[capsule]")
{
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getTranslated(1.0f, 2.0f) == Capsule(1.0f, 2.0f, 1.0f, 2.0f, 0.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getTranslated(-1.0f, -2.0f) == Capsule(-1.0f, -2.0f, -1.0f, -2.0f, 0.0f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).getTranslated(1.0f, 2.0f) == Capsule(2.0f, 4.0f, 4.0f, 6.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).getTranslated(-1.0f, -2.0f) == Capsule(0.0f, 0.0f, 2.0f, 2.0f, 5.0f));

    REQUIRE(Capsule(-4.0f, -3.0f, -2.0f, -1.0f, 5.0f).getTranslated(2.0f, 4.0f) == Capsule(-2.0f, 1.0f, 0.0f, 3.0f, 5.0f));
    REQUIRE(Capsule(-4.0f, -3.0f, -2.0f, -1.0f, 5.0f).getTranslated(-2.0f, -4.0f) == Capsule(-6.0f, -7.0f, -4.0f, -5.0f, 5.0f));

    Capsule temp(1.0f, 2.0f, 3.0f, 4.0f, 5.0f);

    temp.getTranslated(1.0f, 2.0f);
    REQUIRE(temp == Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f));
    temp.getTranslated(-1.0f, -2.0f);
    REQUIRE(temp == Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f));
}

TEST_CASE("Capsule Get Translated Offset", "[capsule]")
{
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Point(1.0f, 2.0f)) == Capsule(1.0f, 2.0f, 1.0f, 2.0f, 0.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Point(-1.0f, -2.0f)) == Capsule(-1.0f, -2.0f, -1.0f, -2.0f, 0.0f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).getTranslated(Point(1.0f, 2.0f)) == Capsule(2.0f, 4.0f, 4.0f, 6.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).getTranslated(Point(-1.0f, -2.0f)) == Capsule(0.0f, 0.0f, 2.0f, 2.0f, 5.0f));

    REQUIRE(Capsule(-4.0f, -3.0f, -2.0f, -1.0f, 5.0f).getTranslated(Point(2.0f, 4.0f)) == Capsule(-2.0f, 1.0f, 0.0f, 3.0f, 5.0f));
    REQUIRE(Capsule(-4.0f, -3.0f, -2.0f, -1.0f, 5.0f).getTranslated(Point(-2.0f, -4.0f)) == Capsule(-6.0f, -7.0f, -4.0f, -5.0f, 5.0f));

    Capsule temp(1.0f, 2.0f, 3.0f, 4.0f, 5.0f);

    temp.getTranslated(Point(1.0f, 2.0f));
    REQUIRE(temp == Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f));
    temp.getTranslated(Point(-1.0f, -2.0f));
    REQUIRE(temp == Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f));
}

TEST_CASE("Capsule Get Translated Direction", "[capsule]")
{
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Direction(1.0f, 0.0f), 3.0f) == Capsule(3.0f, 0.0f, 3.0f, 0.0f, 0.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Direction(0.0f, 1.0f), 3.0f) == Capsule(0.0f, 3.0f, 0.0f, 3.0f, 0.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Direction(-1.0f, 0.0f), 3.0f) == Capsule(-3.0f, 0.0f, -3.0f, 0.0f, 0.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Direction(0.0f, -1.0f), 3.0f) == Capsule(0.0f, -3.0f, 0.0f, -3.0f, 0.0f));

    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Direction(1.0f, 1.0f), 3.0f) == Capsule(DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(3.0f), 0.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Direction(-1.0f, 1.0f), 3.0f) == Capsule(DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(3.0f), 0.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Direction(1.0f, -1.0f), 3.0f) == Capsule(DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(-3.0f), 0.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Direction(-1.0f, -1.0f), 3.0f) == Capsule(DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(-3.0f), 0.0f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).getTranslated(Direction(1.0f, 0.0f), 3.0f) == Capsule(4.0f, 2.0f, 6.0f, 4.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).getTranslated(Direction(0.0f, 1.0f), 3.0f) == Capsule(1.0f, 5.0f, 3.0f, 7.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).getTranslated(Direction(-1.0f, 0.0f), 3.0f) == Capsule(-2.0f, 2.0f, 0.0f, 4.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).getTranslated(Direction(0.0f, -1.0f), 3.0f) == Capsule(1.0f, -1.0f, 3.0f, 1.0f, 5.0f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).getTranslated(Direction(1.0f, 1.0f), 3.0f) == Capsule(1.0f + DIAGONAL_DELTA(3.0f), 2.0f + DIAGONAL_DELTA(3.0f), 3.0f + DIAGONAL_DELTA(3.0f), 4.0f + DIAGONAL_DELTA(3.0f), 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).getTranslated(Direction(-1.0f, 1.0f), 3.0f) == Capsule(1.0f + DIAGONAL_DELTA(-3.0f), 2.0f + DIAGONAL_DELTA(3.0f), 3.0f + DIAGONAL_DELTA(-3.0f), 4.0f + DIAGONAL_DELTA(3.0f), 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).getTranslated(Direction(1.0f, -1.0f), 3.0f) == Capsule(1.0f + DIAGONAL_DELTA(3.0f), 2.0f + DIAGONAL_DELTA(-3.0f), 3.0f + DIAGONAL_DELTA(3.0f), 4.0f + DIAGONAL_DELTA(-3.0f), 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).getTranslated(Direction(-1.0f, -1.0f), 3.0f) == Capsule(1.0f + DIAGONAL_DELTA(-3.0f), 2.0f + DIAGONAL_DELTA(-3.0f), 3.0f + DIAGONAL_DELTA(-3.0f), 4.0f + DIAGONAL_DELTA(-3.0f), 5.0f));

    Capsule temp(1.0f, 2.0f, 3.0f, 4.0f, 5.0f);

    temp.getTranslated(Direction(1.0f, 1.0f), 3.0f);
    REQUIRE(temp == Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f));
    temp.getTranslated(Direction(-1.0f, -1.0f), 3.0f);
    REQUIRE(temp == Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f));
}

TEST_CASE("Capsule Get Rotated Radians", "[capsule]")
{
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getRotatedRadians(0.0f) == Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getRotatedRadians(PI_2) == Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getRotatedRadians(PI) == Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getRotatedRadians(PI + PI_2) == Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getRotatedRadians(PI + PI) == Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).getRotatedRadians(0.0f) == Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).getRotatedRadians(PI_2) == Capsule(-2.0f, 1.0f, -4.0f, 3.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).getRotatedRadians(PI) == Capsule(-1.0f, -2.0f, -3.0f, -4.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).getRotatedRadians(PI + PI_2) == Capsule(2.0f, -1.0f, 4.0f, -3.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).getRotatedRadians(PI + PI) == Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f));

    Capsule temp(1.0f, 2.0f, 3.0f, 4.0f, 5.0f);

    temp.getRotatedRadians(PI_2);
    REQUIRE(temp == Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f));
    temp.getRotatedRadians(PI);
    REQUIRE(temp == Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f));
}

TEST_CASE("Capsule Get Rotated Radians at Pivot", "[capsule]")
{
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedRadians({1.0f, 2.0f}, 0.0f) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedRadians({1.0f, 2.0f}, PI_2) == Capsule(1.0f, 2.0f, -2.0f, 4.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedRadians({1.0f, 2.0f}, PI) == Capsule(1.0f, 2.0f, -1.0f, -1.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedRadians({1.0f, 2.0f}, PI + PI_2) == Capsule(1.0f, 2.0f, 4.0f, 0.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedRadians({1.0f, 2.0f}, PI + PI) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedRadians({3.0f, 5.0f}, 0.0f) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedRadians({3.0f, 5.0f}, PI_2) == Capsule(6.0f, 3.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedRadians({3.0f, 5.0f}, PI) == Capsule(5.0f, 8.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedRadians({3.0f, 5.0f}, PI + PI_2) == Capsule(0.0f, 7.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedRadians({3.0f, 5.0f}, PI + PI) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedRadiansFromA(0.0f) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedRadiansFromA(PI_2) == Capsule(1.0f, 2.0f, -2.0f, 4.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedRadiansFromA(PI) == Capsule(1.0f, 2.0f, -1.0f, -1.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedRadiansFromA(PI + PI_2) == Capsule(1.0f, 2.0f, 4.0f, 0.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedRadiansFromA(PI + PI) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedRadiansFromB(0.0f) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedRadiansFromB(PI_2) == Capsule(6.0f, 3.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedRadiansFromB(PI) == Capsule(5.0f, 8.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedRadiansFromB(PI + PI_2) == Capsule(0.0f, 7.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedRadiansFromB(PI + PI) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));

    Capsule temp(1.0f, 2.0f, 3.0f, 5.0f, 4.0f);

    temp.getRotatedRadians({1.0f, 2.0f},PI_2);
    REQUIRE(temp == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    temp.getRotatedRadians({1.0f, 2.0f},PI);
    REQUIRE(temp == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    temp.getRotatedRadians({3.0f, 5.0f},PI_2);
    REQUIRE(temp == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    temp.getRotatedRadians({3.0f, 5.0f},PI);
    REQUIRE(temp == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    temp.getRotatedRadiansFromA(PI_2);
    REQUIRE(temp == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    temp.getRotatedRadiansFromA(PI);
    REQUIRE(temp == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    temp.getRotatedRadiansFromB(PI_2);
    REQUIRE(temp == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    temp.getRotatedRadiansFromB(PI);
    REQUIRE(temp == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
}

TEST_CASE("Capsule Get Rotated Degrees", "[capsule]")
{
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getRotatedDegrees(0.0f) == Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getRotatedDegrees(90.0f) == Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getRotatedDegrees(180.0f) == Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getRotatedDegrees(270.0f) == Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getRotatedDegrees(360.0f) == Capsule(0.0f, 0.0f, 0.0f, 0.0f, 0.0f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).getRotatedDegrees(0.0f) == Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).getRotatedDegrees(90.0f) == Capsule(-2.0f, 1.0f, -4.0f, 3.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).getRotatedDegrees(180.0f) == Capsule(-1.0f, -2.0f, -3.0f, -4.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).getRotatedDegrees(270.0f) == Capsule(2.0f, -1.0f, 4.0f, -3.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).getRotatedDegrees(360.0f) == Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f));

    Capsule temp(1.0f, 2.0f, 3.0f, 4.0f, 5.0f);

    temp.getRotatedDegrees(90.0f);
    REQUIRE(temp == Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f));
    temp.getRotatedDegrees(180.0f);
    REQUIRE(temp == Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f));
}

TEST_CASE("Capsule Get Rotated Degrees at Pivot", "[capsule]")
{
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedDegrees({1.0f, 2.0f}, 0.0f) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedDegrees({1.0f, 2.0f}, 90.0f) == Capsule(1.0f, 2.0f, -2.0f, 4.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedDegrees({1.0f, 2.0f}, 180.0f) == Capsule(1.0f, 2.0f, -1.0f, -1.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedDegrees({1.0f, 2.0f}, 270.0f) == Capsule(1.0f, 2.0f, 4.0f, 0.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedDegrees({1.0f, 2.0f}, 360.0f) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedDegrees({3.0f, 5.0f}, 0.0f) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedDegrees({3.0f, 5.0f}, 90.0f) == Capsule(6.0f, 3.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedDegrees({3.0f, 5.0f}, 180.0f) == Capsule(5.0f, 8.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedDegrees({3.0f, 5.0f}, 270.0f) == Capsule(0.0f, 7.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedDegrees({3.0f, 5.0f}, 360.0f) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedDegreesFromA(0.0f) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedDegreesFromA(90.0f) == Capsule(1.0f, 2.0f, -2.0f, 4.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedDegreesFromA(180.0f) == Capsule(1.0f, 2.0f, -1.0f, -1.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedDegreesFromA(270.0f) == Capsule(1.0f, 2.0f, 4.0f, 0.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedDegreesFromA(360.0f) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedDegreesFromB(0.0f) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedDegreesFromB(90.0f) == Capsule(6.0f, 3.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedDegreesFromB(180.0f) == Capsule(5.0f, 8.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedDegreesFromB(270.0f) == Capsule(0.0f, 7.0f, 3.0f, 5.0f, 4.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getRotatedDegreesFromB(360.0f) == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));

    Capsule temp(1.0f, 2.0f, 3.0f, 5.0f, 4.0f);

    temp.getRotatedDegrees({1.0f, 2.0f},180.0f);
    REQUIRE(temp == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    temp.getRotatedDegrees({1.0f, 2.0f},90.0f);
    REQUIRE(temp == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    temp.getRotatedDegrees({3.0f, 5.0f},180.0f);
    REQUIRE(temp == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    temp.getRotatedDegrees({3.0f, 5.0f},90.0f);
    REQUIRE(temp == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    temp.getRotatedDegreesFromA(180.0f);
    REQUIRE(temp == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    temp.getRotatedDegreesFromA(90.0f);
    REQUIRE(temp == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    temp.getRotatedDegreesFromB(180.0f);
    REQUIRE(temp == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
    temp.getRotatedDegreesFromB(90.0f);
    REQUIRE(temp == Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f));
}

TEST_CASE("Capsule Get Scaled", "[capsule]")
{
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).getScaled(0.5f) == Capsule(0.5f, 1.0f, 1.5f, 2.0f, 2.5f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f).getScaled(0.1f) == Capsule(0.1f, 0.2f, 0.3f, 0.4f, 0.5f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getScaled({1.0f, 2.0f}, 0.5f) == Capsule(1.0f, 2.0f, 2.0f, 3.5f, 2.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getScaled({1.0f, 2.0f}, 0.1f) == Capsule(1.0f, 2.0f, 1.2f, 2.3f, 0.4f));

    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getScaled({3.0f, 5.0f}, 0.5f) == Capsule(2.0f, 3.5f, 3.0f, 5.0f, 2.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getScaled({3.0f, 5.0f}, 0.1f) == Capsule(2.8f, 4.7f, 3.0f, 5.0f, 0.4f));

    Capsule temp(1.0f, 2.0f, 3.0f, 4.0f, 5.0f);

    temp.getScaled(0.5f);
    REQUIRE(temp == Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f));
    temp.getScaled({1.0f, 2.0f}, 0.5f);
    REQUIRE(temp == Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f));
    temp.getScaled({3.0f, 4.0f}, 0.5f);
    REQUIRE(temp == Capsule(1.0f, 2.0f, 3.0f, 4.0f, 5.0f));
}

TEST_CASE("Capsule Get Point", "[capsule]")
{
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getPoint(0.0f) == Point(1.0f, 2.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getPoint(1.0f) == Point(3.0f, 5.0f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getPoint(0.5f) == Point(2.0f, 3.5f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getPoint(0.25f) == Point(1.5f, 2.75f));
    REQUIRE(Capsule(1.0f, 2.0f, 3.0f, 5.0f, 4.0f).getPoint(0.75f) == Point(2.5f, 4.25f));
}