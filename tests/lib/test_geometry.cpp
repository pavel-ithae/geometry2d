#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <geometry2d/geometry.hpp>
#include "test_macros.hpp"

using namespace geometry2d;
using namespace Catch::Matchers;

TEST_CASE("Point Distance Squared", "[geometry][point]")
{
    REQUIRE_THAT(geometry2d::pointDistanceSqrd(Point(0.0f, 0.0f), Point(0.0f, 0.0f)), WithinAbs(0.0f, FLOAT_EPSILON));
    REQUIRE_THAT(geometry2d::pointDistanceSqrd(Point(1.0f, 2.0f), Point(1.0f, 2.0f)), WithinAbs(0.0f, FLOAT_EPSILON));

    REQUIRE_THAT(geometry2d::pointDistanceSqrd(Point(0.0f, 0.0f), Point(2.0f, 0.0f)), WithinAbs(4.0f, FLOAT_EPSILON));
    REQUIRE_THAT(geometry2d::pointDistanceSqrd(Point(0.0f, 0.0f), Point(0.0f, 3.0f)), WithinAbs(9.0f, FLOAT_EPSILON));
    REQUIRE_THAT(geometry2d::pointDistanceSqrd(Point(0.0f, 0.0f), Point(1.0f, 2.0f)), WithinAbs(5.0f, FLOAT_EPSILON));

    REQUIRE_THAT(geometry2d::pointDistanceSqrd(Point(2.0f, 0.0f), Point(0.0f, 0.0f)), WithinAbs(4.0f, FLOAT_EPSILON));
    REQUIRE_THAT(geometry2d::pointDistanceSqrd(Point(0.0f, 3.0f), Point(0.0f, 0.0f)), WithinAbs(9.0f, FLOAT_EPSILON));
    REQUIRE_THAT(geometry2d::pointDistanceSqrd(Point(1.0f, 2.0f), Point(0.0f, 0.0f)), WithinAbs(5.0f, FLOAT_EPSILON));

    REQUIRE_THAT(geometry2d::pointDistanceSqrd(Point(1.0f, 0.0f), Point(0.0f, 2.0f)), WithinAbs(5.0f, FLOAT_EPSILON));
    REQUIRE_THAT(geometry2d::pointDistanceSqrd(Point(0.0f, 1.0f), Point(2.0f, 0.0f)), WithinAbs(5.0f, FLOAT_EPSILON));

    REQUIRE_THAT(geometry2d::pointDistanceSqrd(Point(0.0f, 0.0f), Point(-2.0f, 0.0f)), WithinAbs(4.0f, FLOAT_EPSILON));
    REQUIRE_THAT(geometry2d::pointDistanceSqrd(Point(0.0f, 0.0f), Point(0.0f, -3.0f)), WithinAbs(9.0f, FLOAT_EPSILON));
    REQUIRE_THAT(geometry2d::pointDistanceSqrd(Point(0.0f, 0.0f), Point(-1.0f, -2.0f)), WithinAbs(5.0f, FLOAT_EPSILON));

    REQUIRE_THAT(geometry2d::pointDistanceSqrd(Point(-2.0f, 0.0f), Point(0.0f, 0.0f)), WithinAbs(4.0f, FLOAT_EPSILON));
    REQUIRE_THAT(geometry2d::pointDistanceSqrd(Point(0.0f, -3.0f), Point(0.0f, 0.0f)), WithinAbs(9.0f, FLOAT_EPSILON));
    REQUIRE_THAT(geometry2d::pointDistanceSqrd(Point(-1.0f, -2.0f), Point(0.0f, 0.0f)), WithinAbs(5.0f, FLOAT_EPSILON));

    REQUIRE_THAT(geometry2d::pointDistanceSqrd(Point(-1.0f, 0.0f), Point(0.0f, -2.0f)), WithinAbs(5.0f, FLOAT_EPSILON));
    REQUIRE_THAT(geometry2d::pointDistanceSqrd(Point(0.0f, -1.0f), Point(-2.0f, 0.0f)), WithinAbs(5.0f, FLOAT_EPSILON));

    REQUIRE_THAT(geometry2d::pointDistanceSqrd(Point(1.0f, 2.0f), Point(-3.0f, -4.0f)), WithinAbs(52.0f, FLOAT_EPSILON));
    REQUIRE_THAT(geometry2d::pointDistanceSqrd(Point(-1.0f, -2.0f), Point(3.0f, 4.0f)), WithinAbs(52.0f, FLOAT_EPSILON));
    REQUIRE_THAT(geometry2d::pointDistanceSqrd(Point(1.0f, 2.0f), Point(3.0f, 5.0f)), WithinAbs(13.0f, FLOAT_EPSILON));
    REQUIRE_THAT(geometry2d::pointDistanceSqrd(Point(-1.0f, -2.0f), Point(-3.0f, -5.0f)), WithinAbs(13.0f, FLOAT_EPSILON));
}

TEST_CASE("Point Distance", "[geometry][point]")
{
    REQUIRE_THAT(geometry2d::pointDistance(Point(0.0f, 0.0f), Point(0.0f, 0.0f)), WithinAbs(0.0f, FLOAT_EPSILON));
    REQUIRE_THAT(geometry2d::pointDistance(Point(1.0f, 2.0f), Point(1.0f, 2.0f)), WithinAbs(0.0f, FLOAT_EPSILON));

    REQUIRE_THAT(geometry2d::pointDistance(Point(0.0f, 0.0f), Point(2.0f, 0.0f)), WithinAbs(2.0f, FLOAT_EPSILON));
    REQUIRE_THAT(geometry2d::pointDistance(Point(0.0f, 0.0f), Point(0.0f, 3.0f)), WithinAbs(3.0f, FLOAT_EPSILON));
    REQUIRE_THAT(geometry2d::pointDistance(Point(0.0f, 0.0f), Point(1.0f, 2.0f)), WithinAbs(std::sqrt(5.0f), FLOAT_EPSILON));

    REQUIRE_THAT(geometry2d::pointDistance(Point(2.0f, 0.0f), Point(0.0f, 0.0f)), WithinAbs(2.0f, FLOAT_EPSILON));
    REQUIRE_THAT(geometry2d::pointDistance(Point(0.0f, 3.0f), Point(0.0f, 0.0f)), WithinAbs(3.0f, FLOAT_EPSILON));
    REQUIRE_THAT(geometry2d::pointDistance(Point(1.0f, 2.0f), Point(0.0f, 0.0f)), WithinAbs(std::sqrt(5.0f), FLOAT_EPSILON));

    REQUIRE_THAT(geometry2d::pointDistance(Point(1.0f, 0.0f), Point(0.0f, 2.0f)), WithinAbs(std::sqrt(5.0f), FLOAT_EPSILON));
    REQUIRE_THAT(geometry2d::pointDistance(Point(0.0f, 1.0f), Point(2.0f, 0.0f)), WithinAbs(std::sqrt(5.0f), FLOAT_EPSILON));

    REQUIRE_THAT(geometry2d::pointDistance(Point(0.0f, 0.0f), Point(-2.0f, 0.0f)), WithinAbs(2.0f, FLOAT_EPSILON));
    REQUIRE_THAT(geometry2d::pointDistance(Point(0.0f, 0.0f), Point(0.0f, -3.0f)), WithinAbs(3.0f, FLOAT_EPSILON));
    REQUIRE_THAT(geometry2d::pointDistance(Point(0.0f, 0.0f), Point(-1.0f, -2.0f)), WithinAbs(std::sqrt(5.0f), FLOAT_EPSILON));

    REQUIRE_THAT(geometry2d::pointDistance(Point(-2.0f, 0.0f), Point(0.0f, 0.0f)), WithinAbs(2.0f, FLOAT_EPSILON));
    REQUIRE_THAT(geometry2d::pointDistance(Point(0.0f, -3.0f), Point(0.0f, 0.0f)), WithinAbs(3.0f, FLOAT_EPSILON));
    REQUIRE_THAT(geometry2d::pointDistance(Point(-1.0f, -2.0f), Point(0.0f, 0.0f)), WithinAbs(std::sqrt(5.0f), FLOAT_EPSILON));

    REQUIRE_THAT(geometry2d::pointDistance(Point(-1.0f, 0.0f), Point(0.0f, -2.0f)), WithinAbs(std::sqrt(5.0f), FLOAT_EPSILON));
    REQUIRE_THAT(geometry2d::pointDistance(Point(0.0f, -1.0f), Point(-2.0f, 0.0f)), WithinAbs(std::sqrt(5.0f), FLOAT_EPSILON));

    REQUIRE_THAT(geometry2d::pointDistance(Point(1.0f, 2.0f), Point(-3.0f, -4.0f)), WithinAbs(std::sqrt(52.0f), FLOAT_EPSILON));
    REQUIRE_THAT(geometry2d::pointDistance(Point(-1.0f, -2.0f), Point(3.0f, 4.0f)), WithinAbs(std::sqrt(52.0f), FLOAT_EPSILON));
    REQUIRE_THAT(geometry2d::pointDistance(Point(1.0f, 2.0f), Point(3.0f, 5.0f)), WithinAbs(std::sqrt(13.0f), FLOAT_EPSILON));
    REQUIRE_THAT(geometry2d::pointDistance(Point(-1.0f, -2.0f), Point(-3.0f, -5.0f)), WithinAbs(std::sqrt(13.0f), FLOAT_EPSILON));
}

TEST_CASE("Point Lerp", "[geometry][point]")
{
    REQUIRE(geometry2d::pointLerp(Point(0.0f, 0.0f), Point(0.0f, 0.0f), 0.0f) == Point(0.0f, 0.0f));
    REQUIRE(geometry2d::pointLerp(Point(0.0f, 0.0f), Point(0.0f, 0.0f), 1.0f) == Point(0.0f, 0.0f));
    REQUIRE(geometry2d::pointLerp(Point(0.0f, 0.0f), Point(0.0f, 0.0f), 0.5f) == Point(0.0f, 0.0f));

    REQUIRE(geometry2d::pointLerp(Point(1.0f, 2.0f), Point(3.0f, 5.0f), 0.0f) == Point(1.0f, 2.0f));
    REQUIRE(geometry2d::pointLerp(Point(1.0f, 2.0f), Point(3.0f, 5.0f), 1.0f) == Point(3.0f, 5.0f));
    REQUIRE(geometry2d::pointLerp(Point(1.0f, 2.0f), Point(3.0f, 5.0f), 0.5f) == Point(2.0f, 3.5f));
    REQUIRE(geometry2d::pointLerp(Point(1.0f, 2.0f), Point(3.0f, 5.0f), 0.2f) == Point(1.4f, 2.6f));
    REQUIRE(geometry2d::pointLerp(Point(1.0f, 2.0f), Point(3.0f, 5.0f), 0.8f) == Point(2.6f, 4.4f));

    REQUIRE(geometry2d::pointLerp(Point(-1.0f, -2.0f), Point(-3.0f, -5.0f), 0.0f) == Point(-1.0f, -2.0f));
    REQUIRE(geometry2d::pointLerp(Point(-1.0f, -2.0f), Point(-3.0f, -5.0f), 1.0f) == Point(-3.0f, -5.0f));
    REQUIRE(geometry2d::pointLerp(Point(-1.0f, -2.0f), Point(-3.0f, -5.0f), 0.5f) == Point(-2.0f, -3.5f));
    REQUIRE(geometry2d::pointLerp(Point(-1.0f, -2.0f), Point(-3.0f, -5.0f), 0.2f) == Point(-1.4f, -2.6f));
    REQUIRE(geometry2d::pointLerp(Point(-1.0f, -2.0f), Point(-3.0f, -5.0f), 0.8f) == Point(-2.6f, -4.4f));

    REQUIRE(geometry2d::pointLerp(Point(1.0f, 2.0f), Point(-3.0f, -5.0f), 0.0f) == Point(1.0f, 2.0f));
    REQUIRE(geometry2d::pointLerp(Point(1.0f, 2.0f), Point(-3.0f, -5.0f), 1.0f) == Point(-3.0f, -5.0f));
    REQUIRE(geometry2d::pointLerp(Point(1.0f, 2.0f), Point(-3.0f, -5.0f), 0.5f) == Point(-1.0f, -1.5f));
    REQUIRE(geometry2d::pointLerp(Point(1.0f, 2.0f), Point(-3.0f, -5.0f), 0.2f) == Point(0.2f, 0.6f));
    REQUIRE(geometry2d::pointLerp(Point(1.0f, 2.0f), Point(-3.0f, -5.0f), 0.8f) == Point(-2.2f, -3.6f));

    REQUIRE(geometry2d::pointLerp(Point(-1.0f, -2.0f), Point(3.0f, 5.0f), 0.0f) == Point(-1.0f, -2.0f));
    REQUIRE(geometry2d::pointLerp(Point(-1.0f, -2.0f), Point(3.0f, 5.0f), 1.0f) == Point(3.0f, 5.0f));
    REQUIRE(geometry2d::pointLerp(Point(-1.0f, -2.0f), Point(3.0f, 5.0f), 0.5f) == Point(1.0f, 1.5f));
    REQUIRE(geometry2d::pointLerp(Point(-1.0f, -2.0f), Point(3.0f, 5.0f), 0.2f) == Point(-0.2f, -0.6f));
    REQUIRE(geometry2d::pointLerp(Point(-1.0f, -2.0f), Point(3.0f, 5.0f), 0.8f) == Point(2.2f, 3.6f));
}