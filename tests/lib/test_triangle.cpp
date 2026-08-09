#include <catch2/catch_test_macros.hpp>
#include <geometry2d/triangle.hpp>
#include <geometry2d/direction.hpp>
#include "test_macros.hpp"

using namespace geometry2d;

TEST_CASE("Triangle Value Constructors", "[triangle]")
{
    REQUIRE(Triangle(Point(0.0f, 0.0f), Point(0.0f, 0.0f), Point(0.0f, 0.0f)).a == Point(0.0f, 0.0f));
    REQUIRE(Triangle(Point(0.0f, 0.0f), Point(0.0f, 0.0f), Point(0.0f, 0.0f)).b == Point(0.0f, 0.0f));
    REQUIRE(Triangle(Point(0.0f, 0.0f), Point(0.0f, 0.0f), Point(0.0f, 0.0f)).c == Point(0.0f, 0.0f));

    REQUIRE(Triangle(Point(1.0f, 2.0f), Point(3.0f, 4.0f), Point(-1.0f, 3.0f)).a == Point(1.0f, 2.0f));
    REQUIRE(Triangle(Point(1.0f, 2.0f), Point(3.0f, 4.0f), Point(-1.0f, 3.0f)).b == Point(3.0f, 4.0f));
    REQUIRE(Triangle(Point(1.0f, 2.0f), Point(3.0f, 4.0f), Point(-1.0f, 3.0f)).c == Point(-1.0f, 3.0f));

    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).a == Point(0.0f, 0.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).b == Point(0.0f, 0.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).c == Point(0.0f, 0.0f));

    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).a == Point(1.0f, 2.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).b == Point(3.0f, 4.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).c == Point(-1.0f, 3.0f));
}

TEST_CASE("Triangle Equals", "[triangle]")
{
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).equals(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equals(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f)));
    REQUIRE(Triangle(-4.0f, -3.0f, -2.0f, -1.0f, 1.0f, -3.0f).equals(Triangle(-4.0f, -3.0f, -2.0f, -1.0f, 1.0f, -3.0f)));

    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equals(Triangle(0.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f)));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equals(Triangle(1.0f, 0.0f, 3.0f, 4.0f, -1.0f, 3.0f)));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equals(Triangle(1.0f, 2.0f, 0.0f, 4.0f, -1.0f, 3.0f)));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equals(Triangle(1.0f, 2.0f, 3.0f, 0.0f, -1.0f, 3.0f)));

    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equals(Triangle(1.0f + FLOAT_EPSILON, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f)));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equals(Triangle(1.0f, 2.0f + FLOAT_EPSILON, 3.0f, 4.0f, -1.0f, 3.0f)));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equals(Triangle(1.0f, 2.0f, 3.0f + FLOAT_EPSILON, 4.0f, -1.0f, 3.0f)));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equals(Triangle(1.0f, 2.0f, 3.0f, 4.0f + FLOAT_EPSILON, -1.0f, 3.0f)));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equals(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f + FLOAT_EPSILON, 3.0f)));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equals(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f + FLOAT_EPSILON)));

    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equals(Triangle(1.0f - FLOAT_EPSILON, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f)));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equals(Triangle(1.0f, 2.0f - FLOAT_EPSILON, 3.0f, 4.0f, -1.0f, 3.0f)));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equals(Triangle(1.0f, 2.0f, 3.0f - FLOAT_EPSILON, 4.0f, -1.0f, 3.0f)));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equals(Triangle(1.0f, 2.0f, 3.0f, 4.0f - FLOAT_EPSILON, -1.0f, 3.0f)));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equals(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f - FLOAT_EPSILON, 3.0f)));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equals(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f - FLOAT_EPSILON)));
}

TEST_CASE("Triangle Equals Approx", "[triangle]")
{
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).equalsApprox(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equalsApprox(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f)));
    REQUIRE(Triangle(-4.0f, -3.0f, -2.0f, -1.0f, 1.0f, -3.0f).equalsApprox(Triangle(-4.0f, -3.0f, -2.0f, -1.0f, 1.0f, -3.0f)));

    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equalsApprox(Triangle(0.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f)));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equalsApprox(Triangle(1.0f, 0.0f, 3.0f, 4.0f, -1.0f, 3.0f)));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equalsApprox(Triangle(1.0f, 2.0f, 0.0f, 4.0f, -1.0f, 3.0f)));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equalsApprox(Triangle(1.0f, 2.0f, 3.0f, 0.0f, -1.0f, 3.0f)));

    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equalsApprox(Triangle(1.0f + FLOAT_EPSILON, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f)));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equalsApprox(Triangle(1.0f, 2.0f + FLOAT_EPSILON, 3.0f, 4.0f, -1.0f, 3.0f)));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equalsApprox(Triangle(1.0f, 2.0f, 3.0f + FLOAT_EPSILON, 4.0f, -1.0f, 3.0f)));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equalsApprox(Triangle(1.0f, 2.0f, 3.0f, 4.0f + FLOAT_EPSILON, -1.0f, 3.0f)));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equalsApprox(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f + FLOAT_EPSILON, 3.0f)));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equalsApprox(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f + FLOAT_EPSILON)));

    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equalsApprox(Triangle(1.0f - FLOAT_EPSILON, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f)));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equalsApprox(Triangle(1.0f, 2.0f - FLOAT_EPSILON, 3.0f, 4.0f, -1.0f, 3.0f)));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equalsApprox(Triangle(1.0f, 2.0f, 3.0f - FLOAT_EPSILON, 4.0f, -1.0f, 3.0f)));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equalsApprox(Triangle(1.0f, 2.0f, 3.0f, 4.0f - FLOAT_EPSILON, -1.0f, 3.0f)));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equalsApprox(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f - FLOAT_EPSILON, 3.0f)));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).equalsApprox(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f - FLOAT_EPSILON)));
}

TEST_CASE("Triangle Equal Operator", "[triangle]")
{
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f) == (Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) == Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f));
    REQUIRE(Triangle(-4.0f, -3.0f, -2.0f, -1.0f, 1.0f, -3.0f) == Triangle(-4.0f, -3.0f, -2.0f, -1.0f, 1.0f, -3.0f));

    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) == Triangle(0.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) == Triangle(1.0f, 0.0f, 3.0f, 4.0f, -1.0f, 3.0f));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) == Triangle(1.0f, 2.0f, 0.0f, 4.0f, -1.0f, 3.0f));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) == Triangle(1.0f, 2.0f, 3.0f, 0.0f, -1.0f, 3.0f));

    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) == Triangle(1.0f + FLOAT_EPSILON, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) == Triangle(1.0f, 2.0f + FLOAT_EPSILON, 3.0f, 4.0f, -1.0f, 3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) == Triangle(1.0f, 2.0f, 3.0f + FLOAT_EPSILON, 4.0f, -1.0f, 3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) == Triangle(1.0f, 2.0f, 3.0f, 4.0f + FLOAT_EPSILON, -1.0f, 3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) == Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f + FLOAT_EPSILON, 3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) == Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f + FLOAT_EPSILON));

    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) == Triangle(1.0f - FLOAT_EPSILON, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) == Triangle(1.0f, 2.0f - FLOAT_EPSILON, 3.0f, 4.0f, -1.0f, 3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) == Triangle(1.0f, 2.0f, 3.0f - FLOAT_EPSILON, 4.0f, -1.0f, 3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) == Triangle(1.0f, 2.0f, 3.0f, 4.0f - FLOAT_EPSILON, -1.0f, 3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) == Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f - FLOAT_EPSILON, 3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) == Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f - FLOAT_EPSILON));
}

TEST_CASE("Triangle Not Equal Operator", "[triangle]")
{
    REQUIRE_FALSE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f) != (Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) != Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f));
    REQUIRE_FALSE(Triangle(-4.0f, -3.0f, -2.0f, -1.0f, 1.0f, -3.0f) != Triangle(-4.0f, -3.0f, -2.0f, -1.0f, 1.0f, -3.0f));

    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) != Triangle(0.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) != Triangle(1.0f, 0.0f, 3.0f, 4.0f, -1.0f, 3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) != Triangle(1.0f, 2.0f, 0.0f, 4.0f, -1.0f, 3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) != Triangle(1.0f, 2.0f, 3.0f, 0.0f, -1.0f, 3.0f));

    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) != Triangle(1.0f + FLOAT_EPSILON, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) != Triangle(1.0f, 2.0f + FLOAT_EPSILON, 3.0f, 4.0f, -1.0f, 3.0f));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) != Triangle(1.0f, 2.0f, 3.0f + FLOAT_EPSILON, 4.0f, -1.0f, 3.0f));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) != Triangle(1.0f, 2.0f, 3.0f, 4.0f + FLOAT_EPSILON, -1.0f, 3.0f));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) != Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f + FLOAT_EPSILON, 3.0f));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) != Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f + FLOAT_EPSILON));

    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) != Triangle(1.0f - FLOAT_EPSILON, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) != Triangle(1.0f, 2.0f - FLOAT_EPSILON, 3.0f, 4.0f, -1.0f, 3.0f));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) != Triangle(1.0f, 2.0f, 3.0f - FLOAT_EPSILON, 4.0f, -1.0f, 3.0f));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) != Triangle(1.0f, 2.0f, 3.0f, 4.0f - FLOAT_EPSILON, -1.0f, 3.0f));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) != Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f - FLOAT_EPSILON, 3.0f));
    REQUIRE_FALSE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) != Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f - FLOAT_EPSILON));
}

TEST_CASE("Triangle Negate", "[triangle]")
{
    REQUIRE((-Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f)) == Triangle(-1.0f, -2.0f, -3.0f, -4.0f, 1.0f, -3.0f));
    REQUIRE((-Triangle(-4.0f, -3.0f, -2.0f, -1.0f, 1.0f, -3.0f)) == Triangle(4.0f, 3.0f, 2.0f, 1.0f, -1.0f, 3.0f));
}

TEST_CASE("Triangle Translate", "[triangle]")
{
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).translate(1.0f, 2.0f) == Triangle(1.0f, 2.0f, 1.0f, 2.0f, 1.0f, 2.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).translate(-1.0f, -2.0f) == Triangle(-1.0f, -2.0f, -1.0f, -2.0f, -1.0f, -2.0f));

    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).translate(1.0f, 2.0f) == Triangle(2.0f, 4.0f, 4.0f, 6.0f, 0.0f, 5.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).translate(-1.0f, -2.0f) == Triangle(0.0f, 0.0f, 2.0f, 2.0f, -2.0f, 1.0f));

    REQUIRE(Triangle(-4.0f, -3.0f, -2.0f, -1.0f, 1.0f, -3.0f).translate(2.0f, 4.0f) == Triangle(-2.0f, 1.0f, 0.0f, 3.0f, 3.0f, 1.0f));
    REQUIRE(Triangle(-4.0f, -3.0f, -2.0f, -1.0f, 1.0f, -3.0f).translate(-2.0f, -4.0f) == Triangle(-6.0f, -7.0f, -4.0f, -5.0f, -1.0f, -7.0f));
}

TEST_CASE("Triangle Translate Offset", "[triangle]")
{
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).translate(Point(1.0f, 2.0f)) == Triangle(1.0f, 2.0f, 1.0f, 2.0f, 1.0f, 2.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).translate(Point(-1.0f, -2.0f)) == Triangle(-1.0f, -2.0f, -1.0f, -2.0f, -1.0f, -2.0f));

    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).translate(Point(1.0f, 2.0f)) == Triangle(2.0f, 4.0f, 4.0f, 6.0f, 0.0f, 5.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).translate(Point(-1.0f, -2.0f)) == Triangle(0.0f, 0.0f, 2.0f, 2.0f, -2.0f, 1.0f));

    REQUIRE(Triangle(-4.0f, -3.0f, -2.0f, -1.0f, 1.0f, -3.0f).translate(Point(2.0f, 4.0f)) == Triangle(-2.0f, 1.0f, 0.0f, 3.0f, 3.0f, 1.0f));
    REQUIRE(Triangle(-4.0f, -3.0f, -2.0f, -1.0f, 1.0f, -3.0f).translate(Point(-2.0f, -4.0f)) == Triangle(-6.0f, -7.0f, -4.0f, -5.0f, -1.0f, -7.0f));
}

TEST_CASE("Triangle Translate Direction", "[triangle]")
{
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).translate(Direction(1.0f, 0.0f), 3.0f) == Triangle(3.0f, 0.0f, 3.0f, 0.0f, 3.0f, 0.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).translate(Direction(0.0f, 1.0f), 3.0f) == Triangle(0.0f, 3.0f, 0.0f, 3.0f, 0.0f, 3.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).translate(Direction(-1.0f, 0.0f), 3.0f) == Triangle(-3.0f, 0.0f, -3.0f, 0.0f, -3.0f, 0.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).translate(Direction(0.0f, -1.0f), 3.0f) == Triangle(0.0f, -3.0f, 0.0f, -3.0f, 0.0f, -3.0f));

    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).translate(Direction(1.0f, 1.0f), 3.0f) == Triangle(DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(3.0f)));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).translate(Direction(-1.0f, 1.0f), 3.0f) == Triangle(DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(3.0f)));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).translate(Direction(1.0f, -1.0f), 3.0f) == Triangle(DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(-3.0f)));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).translate(Direction(-1.0f, -1.0f), 3.0f) == Triangle(DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(-3.0f)));

    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).translate(Direction(1.0f, 0.0f), 3.0f) == Triangle(4.0f, 2.0f, 6.0f, 4.0f, 2.0f, 3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).translate(Direction(0.0f, 1.0f), 3.0f) == Triangle(1.0f, 5.0f, 3.0f, 7.0f, -1.0f, 6.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).translate(Direction(-1.0f, 0.0f), 3.0f) == Triangle(-2.0f, 2.0f, 0.0f, 4.0f, -4.0f, 3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).translate(Direction(0.0f, -1.0f), 3.0f) == Triangle(1.0f, -1.0f, 3.0f, 1.0f, -1.0f, 0.0f));

    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).translate(Direction(1.0f, 1.0f), 3.0f) == Triangle(1.0f + DIAGONAL_DELTA(3.0f), 2.0f + DIAGONAL_DELTA(3.0f), 3.0f + DIAGONAL_DELTA(3.0f), 4.0f + DIAGONAL_DELTA(3.0f), -1.0f + DIAGONAL_DELTA(3.0f), 3.0f + DIAGONAL_DELTA(3.0f)));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).translate(Direction(-1.0f, 1.0f), 3.0f) == Triangle(1.0f + DIAGONAL_DELTA(-3.0f), 2.0f + DIAGONAL_DELTA(3.0f), 3.0f + DIAGONAL_DELTA(-3.0f), 4.0f + DIAGONAL_DELTA(3.0f), -1.0f + DIAGONAL_DELTA(-3.0f), 3.0f + DIAGONAL_DELTA(3.0f)));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).translate(Direction(1.0f, -1.0f), 3.0f) == Triangle(1.0f + DIAGONAL_DELTA(3.0f), 2.0f + DIAGONAL_DELTA(-3.0f), 3.0f + DIAGONAL_DELTA(3.0f), 4.0f + DIAGONAL_DELTA(-3.0f), -1.0f + DIAGONAL_DELTA(3.0f), 3.0f + DIAGONAL_DELTA(-3.0f)));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).translate(Direction(-1.0f, -1.0f), 3.0f) == Triangle(1.0f + DIAGONAL_DELTA(-3.0f), 2.0f + DIAGONAL_DELTA(-3.0f), 3.0f + DIAGONAL_DELTA(-3.0f), 4.0f + DIAGONAL_DELTA(-3.0f), -1.0f + DIAGONAL_DELTA(-3.0f), 3.0f + DIAGONAL_DELTA(-3.0f)));
}

TEST_CASE("Triangle Addition Operator", "[triangle]")
{
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f) + Point(1.0f, 2.0f) == Triangle(1.0f, 2.0f, 1.0f, 2.0f, 1.0f, 2.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f) + Point(-1.0f, -2.0f) == Triangle(-1.0f, -2.0f, -1.0f, -2.0f, -1.0f, -2.0f));

    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) + Point(1.0f, 2.0f) == Triangle(2.0f, 4.0f, 4.0f, 6.0f, 0.0f, 5.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) + Point(-1.0f, -2.0f) == Triangle(0.0f, 0.0f, 2.0f, 2.0f, -2.0f, 1.0f));

    REQUIRE(Triangle(-4.0f, -3.0f, -2.0f, -1.0f, 1.0f, -3.0f) + Point(2.0f, 4.0f) == Triangle(-2.0f, 1.0f, 0.0f, 3.0f, 3.0f, 1.0f));
    REQUIRE(Triangle(-4.0f, -3.0f, -2.0f, -1.0f, 1.0f, -3.0f) + Point(-2.0f, -4.0f) == Triangle(-6.0f, -7.0f, -4.0f, -5.0f, -1.0f, -7.0f));
}

TEST_CASE("Triangle Substraction Operator", "[triangle]")
{
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f) - Point(1.0f, 2.0f) == Triangle(-1.0f, -2.0f, -1.0f, -2.0f, -1.0f, -2.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f) - Point(-1.0f, -2.0f) == Triangle(1.0f, 2.0f, 1.0f, 2.0f, 1.0f, 2.0f));

    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) - Point(1.0f, 2.0f) == Triangle(0.0f, 0.0f, 2.0f, 2.0f, -2.0f, 1.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f) - Point(-1.0f, -2.0f) == Triangle(2.0f, 4.0f, 4.0f, 6.0f, 0.0f, 5.0f));

    REQUIRE(Triangle(-4.0f, -3.0f, -2.0f, -1.0f, 1.0f, -3.0f) - Point(2.0f, 4.0f) == Triangle(-6.0f, -7.0f, -4.0f, -5.0f, -1.0f, -7.0f));
    REQUIRE(Triangle(-4.0f, -3.0f, -2.0f, -1.0f, 1.0f, -3.0f) - Point(-2.0f, -4.0f) == Triangle(-2.0f, 1.0f, 0.0f, 3.0f, 3.0f, 1.0f));
}

TEST_CASE("Triangle Rotate Radians", "[triangle]")
{
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).rotateRadians(0.0f) == Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).rotateRadians(PI_2) == Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).rotateRadians(PI) == Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).rotateRadians(PI + PI_2) == Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).rotateRadians(PI + PI) == Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));

    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).rotateRadians(0.0f) == Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).rotateRadians(PI_2) == Triangle(-2.0f, 1.0f, -4.0f, 3.0f, -3.0f, -1.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).rotateRadians(PI) == Triangle(-1.0f, -2.0f, -3.0f, -4.0f, 1.0f, -3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).rotateRadians(PI + PI_2) == Triangle(2.0f, -1.0f, 4.0f, -3.0f, 3.0f, 1.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).rotateRadians(PI + PI) == Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f));
}

TEST_CASE("Triangle Rotate Radians at Pivot", "[triangle]")
{
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).rotateRadians({1.0f, 2.0f}, 0.0f) == Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).rotateRadians({1.0f, 2.0f}, PI_2) == Triangle(1.0f, 2.0f, -2.0f, 4.0f, 0.0f, 0.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).rotateRadians({1.0f, 2.0f}, PI) == Triangle(1.0f, 2.0f, -1.0f, -1.0f, 3.0f, 1.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).rotateRadians({1.0f, 2.0f}, PI + PI_2) == Triangle(1.0f, 2.0f, 4.0f, 0.0f, 2.0f, 4.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).rotateRadians({1.0f, 2.0f}, PI + PI) == Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f));

    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).rotateRadians({3.0f, 5.0f}, 0.0f) == Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).rotateRadians({3.0f, 5.0f}, PI_2) == Triangle(6.0f, 3.0f, 3.0f, 5.0f, 5.0f, 1.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).rotateRadians({3.0f, 5.0f}, PI) == Triangle(5.0f, 8.0f, 3.0f, 5.0f, 7.0f, 7.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).rotateRadians({3.0f, 5.0f}, PI + PI_2) == Triangle(0.0f, 7.0f, 3.0f, 5.0f, 1.0f, 9.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).rotateRadians({3.0f, 5.0f}, PI + PI) == Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f));
}

TEST_CASE("Triangle Rotate Degrees", "[triangle]")
{
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).rotateDegrees(0.0f) == Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).rotateDegrees(90.0f) == Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).rotateDegrees(180.0f) == Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).rotateDegrees(270.0f) == Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).rotateDegrees(360.0f) == Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));

    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).rotateDegrees(0.0f) == Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).rotateDegrees(90.0f) == Triangle(-2.0f, 1.0f, -4.0f, 3.0f, -3.0f, -1.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).rotateDegrees(180.0f) == Triangle(-1.0f, -2.0f, -3.0f, -4.0f, 1.0f, -3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).rotateDegrees(270.0f) == Triangle(2.0f, -1.0f, 4.0f, -3.0f, 3.0f, 1.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).rotateDegrees(360.0f) == Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f));
}

TEST_CASE("Triangle Rotate Degrees at Pivot", "[triangle]")
{
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).rotateDegrees({1.0f, 2.0f}, 0.0f) == Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).rotateDegrees({1.0f, 2.0f}, 90.0f) == Triangle(1.0f, 2.0f, -2.0f, 4.0f, 0.0f, 0.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).rotateDegrees({1.0f, 2.0f}, 180.0f) == Triangle(1.0f, 2.0f, -1.0f, -1.0f, 3.0f, 1.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).rotateDegrees({1.0f, 2.0f}, 270.0f) == Triangle(1.0f, 2.0f, 4.0f, 0.0f, 2.0f, 4.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).rotateDegrees({1.0f, 2.0f}, 360.0f) == Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f));

    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).rotateDegrees({3.0f, 5.0f}, 0.0f) == Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).rotateDegrees({3.0f, 5.0f}, 90.0f) == Triangle(6.0f, 3.0f, 3.0f, 5.0f, 5.0f, 1.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).rotateDegrees({3.0f, 5.0f}, 180.0f) == Triangle(5.0f, 8.0f, 3.0f, 5.0f, 7.0f, 7.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).rotateDegrees({3.0f, 5.0f}, 270.0f) == Triangle(0.0f, 7.0f, 3.0f, 5.0f, 1.0f, 9.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).rotateDegrees({3.0f, 5.0f}, 360.0f) == Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f));
}

TEST_CASE("Triangle Scale", "[triangle]")
{
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).scale(0.5f) == Triangle(0.5f, 1.0f, 1.5f, 2.0f, -0.5f, 1.5f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).scale(0.1f) == Triangle(0.1f, 0.2f, 0.3f, 0.4f, -0.1f, 0.3f));

    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).scale({1.0f, 2.0f}, 0.5f) == Triangle(1.0f, 2.0f, 2.0f, 3.5f, 0.0f, 2.5f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).scale({1.0f, 2.0f}, 0.1f) == Triangle(1.0f, 2.0f, 1.2f, 2.3f, 0.8f, 2.1f));

    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).scale({3.0f, 5.0f}, 0.5f) == Triangle(2.0f, 3.5f, 3.0f, 5.0f, 1.0f, 4.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).scale({3.0f, 5.0f}, 0.1f) == Triangle(2.8f, 4.7f, 3.0f, 5.0f, 2.6f, 4.8f));
}

TEST_CASE("Triangle Get Translated", "[triangle]")
{
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getTranslated(1.0f, 2.0f) == Triangle(1.0f, 2.0f, 1.0f, 2.0f, 1.0f, 2.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getTranslated(-1.0f, -2.0f) == Triangle(-1.0f, -2.0f, -1.0f, -2.0f, -1.0f, -2.0f));

    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).getTranslated(1.0f, 2.0f) == Triangle(2.0f, 4.0f, 4.0f, 6.0f, 0.0f, 5.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).getTranslated(-1.0f, -2.0f) == Triangle(0.0f, 0.0f, 2.0f, 2.0f, -2.0f, 1.0f));

    REQUIRE(Triangle(-4.0f, -3.0f, -2.0f, -1.0f, 1.0f, -3.0f).getTranslated(2.0f, 4.0f) == Triangle(-2.0f, 1.0f, 0.0f, 3.0f, 3.0f, 1.0f));
    REQUIRE(Triangle(-4.0f, -3.0f, -2.0f, -1.0f, 1.0f, -3.0f).getTranslated(-2.0f, -4.0f) == Triangle(-6.0f, -7.0f, -4.0f, -5.0f, -1.0f, -7.0f));

    Triangle temp(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f);

    temp.getTranslated(1.0f, 2.0f);
    REQUIRE(temp == Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f));
    temp.getTranslated(-1.0f, -2.0f);
    REQUIRE(temp == Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f));
}

TEST_CASE("Triangle Get Translated Offset", "[triangle]")
{
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Point(1.0f, 2.0f)) == Triangle(1.0f, 2.0f, 1.0f, 2.0f, 1.0f, 2.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Point(-1.0f, -2.0f)) == Triangle(-1.0f, -2.0f, -1.0f, -2.0f, -1.0f, -2.0f));

    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).getTranslated(Point(1.0f, 2.0f)) == Triangle(2.0f, 4.0f, 4.0f, 6.0f, 0.0f, 5.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).getTranslated(Point(-1.0f, -2.0f)) == Triangle(0.0f, 0.0f, 2.0f, 2.0f, -2.0f, 1.0f));

    REQUIRE(Triangle(-4.0f, -3.0f, -2.0f, -1.0f, 1.0f, -3.0f).getTranslated(Point(2.0f, 4.0f)) == Triangle(-2.0f, 1.0f, 0.0f, 3.0f, 3.0f, 1.0f));
    REQUIRE(Triangle(-4.0f, -3.0f, -2.0f, -1.0f, 1.0f, -3.0f).getTranslated(Point(-2.0f, -4.0f)) == Triangle(-6.0f, -7.0f, -4.0f, -5.0f, -1.0f, -7.0f));

    Triangle temp(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f);

    temp.getTranslated(Point(1.0f, 2.0f));
    REQUIRE(temp == Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f));
    temp.getTranslated(Point(-1.0f, -2.0f));
    REQUIRE(temp == Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f));
}

TEST_CASE("Triangle Get Translated Direction", "[triangle]")
{
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Direction(1.0f, 0.0f), 3.0f) == Triangle(3.0f, 0.0f, 3.0f, 0.0f, 3.0f, 0.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Direction(0.0f, 1.0f), 3.0f) == Triangle(0.0f, 3.0f, 0.0f, 3.0f, 0.0f, 3.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Direction(-1.0f, 0.0f), 3.0f) == Triangle(-3.0f, 0.0f, -3.0f, 0.0f, -3.0f, 0.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Direction(0.0f, -1.0f), 3.0f) == Triangle(0.0f, -3.0f, 0.0f, -3.0f, 0.0f, -3.0f));

    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Direction(1.0f, 1.0f), 3.0f) == Triangle(DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(3.0f)));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Direction(-1.0f, 1.0f), 3.0f) == Triangle(DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(3.0f)));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Direction(1.0f, -1.0f), 3.0f) == Triangle(DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(-3.0f)));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getTranslated(Direction(-1.0f, -1.0f), 3.0f) == Triangle(DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(-3.0f)));

    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).getTranslated(Direction(1.0f, 0.0f), 3.0f) == Triangle(4.0f, 2.0f, 6.0f, 4.0f, 2.0f, 3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).getTranslated(Direction(0.0f, 1.0f), 3.0f) == Triangle(1.0f, 5.0f, 3.0f, 7.0f, -1.0f, 6.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).getTranslated(Direction(-1.0f, 0.0f), 3.0f) == Triangle(-2.0f, 2.0f, 0.0f, 4.0f, -4.0f, 3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).getTranslated(Direction(0.0f, -1.0f), 3.0f) == Triangle(1.0f, -1.0f, 3.0f, 1.0f, -1.0f, 0.0f));

    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).getTranslated(Direction(1.0f, 1.0f), 3.0f) == Triangle(1.0f + DIAGONAL_DELTA(3.0f), 2.0f + DIAGONAL_DELTA(3.0f), 3.0f + DIAGONAL_DELTA(3.0f), 4.0f + DIAGONAL_DELTA(3.0f), -1.0f + DIAGONAL_DELTA(3.0f), 3.0f + DIAGONAL_DELTA(3.0f)));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).getTranslated(Direction(-1.0f, 1.0f), 3.0f) == Triangle(1.0f + DIAGONAL_DELTA(-3.0f), 2.0f + DIAGONAL_DELTA(3.0f), 3.0f + DIAGONAL_DELTA(-3.0f), 4.0f + DIAGONAL_DELTA(3.0f), -1.0f + DIAGONAL_DELTA(-3.0f), 3.0f + DIAGONAL_DELTA(3.0f)));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).getTranslated(Direction(1.0f, -1.0f), 3.0f) == Triangle(1.0f + DIAGONAL_DELTA(3.0f), 2.0f + DIAGONAL_DELTA(-3.0f), 3.0f + DIAGONAL_DELTA(3.0f), 4.0f + DIAGONAL_DELTA(-3.0f), -1.0f + DIAGONAL_DELTA(3.0f), 3.0f + DIAGONAL_DELTA(-3.0f)));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).getTranslated(Direction(-1.0f, -1.0f), 3.0f) == Triangle(1.0f + DIAGONAL_DELTA(-3.0f), 2.0f + DIAGONAL_DELTA(-3.0f), 3.0f + DIAGONAL_DELTA(-3.0f), 4.0f + DIAGONAL_DELTA(-3.0f), -1.0f + DIAGONAL_DELTA(-3.0f), 3.0f + DIAGONAL_DELTA(-3.0f)));

    Triangle temp(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f);

    temp.getTranslated(Direction(1.0f, 1.0f), 3.0f);
    REQUIRE(temp == Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f));
    temp.getTranslated(Direction(-1.0f, -1.0f), 3.0f);
    REQUIRE(temp == Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f));
}

TEST_CASE("Triangle Get Rotated Radians", "[triangle]")
{
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getRotatedRadians(0.0f) == Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getRotatedRadians(PI_2) == Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getRotatedRadians(PI) == Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getRotatedRadians(PI + PI_2) == Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getRotatedRadians(PI + PI) == Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));

    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).getRotatedRadians(0.0f) == Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).getRotatedRadians(PI_2) == Triangle(-2.0f, 1.0f, -4.0f, 3.0f, -3.0f, -1.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).getRotatedRadians(PI) == Triangle(-1.0f, -2.0f, -3.0f, -4.0f, 1.0f, -3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).getRotatedRadians(PI + PI_2) == Triangle(2.0f, -1.0f, 4.0f, -3.0f, 3.0f, 1.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).getRotatedRadians(PI + PI) == Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f));

    Triangle temp(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f);

    temp.getRotatedRadians(PI_2);
    REQUIRE(temp == Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f));
    temp.getRotatedRadians(PI);
    REQUIRE(temp == Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f));
}

TEST_CASE("Triangle Get Rotated Radians at Pivot", "[triangle]")
{
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).getRotatedRadians({1.0f, 2.0f}, 0.0f) == Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).getRotatedRadians({1.0f, 2.0f}, PI_2) == Triangle(1.0f, 2.0f, -2.0f, 4.0f, 0.0f, 0.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).getRotatedRadians({1.0f, 2.0f}, PI) == Triangle(1.0f, 2.0f, -1.0f, -1.0f, 3.0f, 1.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).getRotatedRadians({1.0f, 2.0f}, PI + PI_2) == Triangle(1.0f, 2.0f, 4.0f, 0.0f, 2.0f, 4.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).getRotatedRadians({1.0f, 2.0f}, PI + PI) == Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f));

    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).getRotatedRadians({3.0f, 5.0f}, 0.0f) == Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).getRotatedRadians({3.0f, 5.0f}, PI_2) == Triangle(6.0f, 3.0f, 3.0f, 5.0f, 5.0f, 1.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).getRotatedRadians({3.0f, 5.0f}, PI) == Triangle(5.0f, 8.0f, 3.0f, 5.0f, 7.0f, 7.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).getRotatedRadians({3.0f, 5.0f}, PI + PI_2) == Triangle(0.0f, 7.0f, 3.0f, 5.0f, 1.0f, 9.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).getRotatedRadians({3.0f, 5.0f}, PI + PI) == Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f));

    Triangle temp(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f);

    temp.getRotatedRadians({1.0f, 2.0f},PI_2);
    REQUIRE(temp == Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f));
    temp.getRotatedRadians({1.0f, 2.0f},PI);
    REQUIRE(temp == Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f));
    temp.getRotatedRadians({3.0f, 5.0f},PI_2);
    REQUIRE(temp == Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f));
    temp.getRotatedRadians({3.0f, 5.0f},PI);
    REQUIRE(temp == Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f));
}

TEST_CASE("Triangle Get Rotated Degrees", "[triangle]")
{
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getRotatedDegrees(0.0f) == Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getRotatedDegrees(90.0f) == Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getRotatedDegrees(180.0f) == Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getRotatedDegrees(270.0f) == Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
    REQUIRE(Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f).getRotatedDegrees(360.0f) == Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));

    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).getRotatedDegrees(0.0f) == Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).getRotatedDegrees(90.0f) == Triangle(-2.0f, 1.0f, -4.0f, 3.0f, -3.0f, -1.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).getRotatedDegrees(180.0f) == Triangle(-1.0f, -2.0f, -3.0f, -4.0f, 1.0f, -3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).getRotatedDegrees(270.0f) == Triangle(2.0f, -1.0f, 4.0f, -3.0f, 3.0f, 1.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).getRotatedDegrees(360.0f) == Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f));

    Triangle temp(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f);

    temp.getRotatedDegrees(90.0f);
    REQUIRE(temp == Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f));
    temp.getRotatedDegrees(180.0f);
    REQUIRE(temp == Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f));
}

TEST_CASE("Triangle Get Rotated Degrees at Pivot", "[triangle]")
{
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).getRotatedDegrees({1.0f, 2.0f}, 0.0f) == Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).getRotatedDegrees({1.0f, 2.0f}, 90.0f) == Triangle(1.0f, 2.0f, -2.0f, 4.0f, 0.0f, 0.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).getRotatedDegrees({1.0f, 2.0f}, 180.0f) == Triangle(1.0f, 2.0f, -1.0f, -1.0f, 3.0f, 1.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).getRotatedDegrees({1.0f, 2.0f}, 270.0f) == Triangle(1.0f, 2.0f, 4.0f, 0.0f, 2.0f, 4.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).getRotatedDegrees({1.0f, 2.0f}, 360.0f) == Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f));

    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).getRotatedDegrees({3.0f, 5.0f}, 0.0f) == Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).getRotatedDegrees({3.0f, 5.0f}, 90.0f) == Triangle(6.0f, 3.0f, 3.0f, 5.0f, 5.0f, 1.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).getRotatedDegrees({3.0f, 5.0f}, 180.0f) == Triangle(5.0f, 8.0f, 3.0f, 5.0f, 7.0f, 7.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).getRotatedDegrees({3.0f, 5.0f}, 270.0f) == Triangle(0.0f, 7.0f, 3.0f, 5.0f, 1.0f, 9.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).getRotatedDegrees({3.0f, 5.0f}, 360.0f) == Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f));

    Triangle temp(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f);

    temp.getRotatedDegrees({1.0f, 2.0f},180.0f);
    REQUIRE(temp == Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f));
    temp.getRotatedDegrees({1.0f, 2.0f},90.0f);
    REQUIRE(temp == Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f));
    temp.getRotatedDegrees({3.0f, 5.0f},180.0f);
    REQUIRE(temp == Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f));
    temp.getRotatedDegrees({3.0f, 5.0f},90.0f);
    REQUIRE(temp == Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f));
}

TEST_CASE("Triangle Get Scaled", "[triangle]")
{
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).getScaled(0.5f) == Triangle(0.5f, 1.0f, 1.5f, 2.0f, -0.5f, 1.5f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f).getScaled(0.1f) == Triangle(0.1f, 0.2f, 0.3f, 0.4f, -0.1f, 0.3f));

    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).getScaled({1.0f, 2.0f}, 0.5f) == Triangle(1.0f, 2.0f, 2.0f, 3.5f, 0.0f, 2.5f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).getScaled({1.0f, 2.0f}, 0.1f) == Triangle(1.0f, 2.0f, 1.2f, 2.3f, 0.8f, 2.1f));

    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).getScaled({3.0f, 5.0f}, 0.5f) == Triangle(2.0f, 3.5f, 3.0f, 5.0f, 1.0f, 4.0f));
    REQUIRE(Triangle(1.0f, 2.0f, 3.0f, 5.0f, -1.0f, 3.0f).getScaled({3.0f, 5.0f}, 0.1f) == Triangle(2.8f, 4.7f, 3.0f, 5.0f, 2.6f, 4.8f));

    Triangle temp(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f);

    temp.getScaled(0.5f);
    REQUIRE(temp == Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f));
    temp.getScaled({1.0f, 2.0f}, 0.5f);
    REQUIRE(temp == Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f));
    temp.getScaled({3.0f, 4.0f}, 0.5f);
    REQUIRE(temp == Triangle(1.0f, 2.0f, 3.0f, 4.0f, -1.0f, 3.0f));
}