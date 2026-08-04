#include <catch2/catch_test_macros.hpp>
#include <geometry2d/point.hpp>
#include <geometry2d/direction.hpp>
#include <limits.h>

#if _WIN32  // In Windows, this macro is needed to expose the PI macros.
    #define _USE_MATH_DEFINES
#endif
#include <math.h>

#define FLOAT_EPSILON std::numeric_limits<float>::epsilon()
#define DIAGONAL_DELTA(length) ((1.0f / std::sqrt(2.0f)) * length)

#if _WIN32 // Windows doesn't have f versions.
    #define PI M_PI
    #define PI_2 M_PI_2
    #define PI_4 M_PI_4
#else
    #define PI M_PIf
    #define PI_2 M_PI_2f
    #define PI_4 M_PI_4f
#endif

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

TEST_CASE("Point Rotate Radians", "[point]")
{
    REQUIRE(Point(1.0f, 3.0f).rotateRadians(0.0f) == Point(1.0f, 3.0f));
    REQUIRE(Point(1.0f, 3.0f).rotateRadians(PI_2) == Point(-3.0f, 1.0f));
    REQUIRE(Point(1.0f, 3.0f).rotateRadians(PI) == Point(-1.0f, -3.0f));
    REQUIRE(Point(1.0f, 3.0f).rotateRadians(PI + PI_2) == Point(3.0f, -1.0f));
    REQUIRE(Point(1.0f, 3.0f).rotateRadians(PI + PI) == Point(1.0f, 3.0f));
}

TEST_CASE("Point Rotate Radians at Pivot", "[point]")
{
    REQUIRE(Point(1.0f, 3.0f).rotateRadians({1.0f, 0.0f}, 0.0f) == Point(1.0f, 3.0f));
    REQUIRE(Point(1.0f, 3.0f).rotateRadians({1.0f, 0.0f}, PI_2) == Point(-2.0f, 0.0f));
    REQUIRE(Point(1.0f, 3.0f).rotateRadians({1.0f, 0.0f}, PI) == Point(1.0f, -3.0f));
    REQUIRE(Point(1.0f, 3.0f).rotateRadians({1.0f, 0.0f}, PI + PI_2) == Point(4.0f, 0.0f));
    REQUIRE(Point(1.0f, 3.0f).rotateRadians({1.0f, 0.0f}, PI + PI) == Point(1.0f, 3.0f));

    REQUIRE(Point(1.0f, 3.0f).rotateRadians({0.0f, 3.0f}, 0.0f) == Point(1.0f, 3.0f));
    REQUIRE(Point(1.0f, 3.0f).rotateRadians({0.0f, 3.0f}, PI_2) == Point(0.0f, 4.0f));
    REQUIRE(Point(1.0f, 3.0f).rotateRadians({0.0f, 3.0f}, PI) == Point(-1.0f, 3.0f));
    REQUIRE(Point(1.0f, 3.0f).rotateRadians({0.0f, 3.0f}, PI + PI_2) == Point(0.0f, 2.0f));
    REQUIRE(Point(1.0f, 3.0f).rotateRadians({0.0f, 3.0f}, PI + PI) == Point(1.0f, 3.0f));
}

TEST_CASE("Point Rotate Degrees", "[point]")
{
    REQUIRE(Point(1.0f, 3.0f).rotateDegrees(0.0f) == Point(1.0f, 3.0f));
    REQUIRE(Point(1.0f, 3.0f).rotateDegrees(90.0f) == Point(-3.0f, 1.0f));
    REQUIRE(Point(1.0f, 3.0f).rotateDegrees(180.0f) == Point(-1.0f, -3.0f));
    REQUIRE(Point(1.0f, 3.0f).rotateDegrees(270.0f) == Point(3.0f, -1.0f));
    REQUIRE(Point(1.0f, 3.0f).rotateDegrees(360.0f) == Point(1.0f, 3.0f));
}

TEST_CASE("Point Rotate Degrees at Pivot", "[point]")
{
    REQUIRE(Point(1.0f, 3.0f).rotateDegrees({1.0f, 0.0f}, 0.0f) == Point(1.0f, 3.0f));
    REQUIRE(Point(1.0f, 3.0f).rotateDegrees({1.0f, 0.0f}, 90.0f) == Point(-2.0f, 0.0f));
    REQUIRE(Point(1.0f, 3.0f).rotateDegrees({1.0f, 0.0f}, 180.0f) == Point(1.0f, -3.0f));
    REQUIRE(Point(1.0f, 3.0f).rotateDegrees({1.0f, 0.0f}, 270.0f) == Point(4.0f, 0.0f));
    REQUIRE(Point(1.0f, 3.0f).rotateDegrees({1.0f, 0.0f}, 360.0f) == Point(1.0f, 3.0f));

    REQUIRE(Point(1.0f, 3.0f).rotateDegrees({0.0f, 3.0f}, 0.0f) == Point(1.0f, 3.0f));
    REQUIRE(Point(1.0f, 3.0f).rotateDegrees({0.0f, 3.0f}, 90.0f) == Point(0.0f, 4.0f));
    REQUIRE(Point(1.0f, 3.0f).rotateDegrees({0.0f, 3.0f}, 180.0f) == Point(-1.0f, 3.0f));
    REQUIRE(Point(1.0f, 3.0f).rotateDegrees({0.0f, 3.0f}, 270.0f) == Point(0.0f, 2.0f));
    REQUIRE(Point(1.0f, 3.0f).rotateDegrees({0.0f, 3.0f}, 360.0f) == Point(1.0f, 3.0f));
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

TEST_CASE("Point Get Rotated Radians", "[point]")
{
    REQUIRE(Point(1.0f, 3.0f).getRotatedRadians(0.0f) == Point(1.0f, 3.0f));
    REQUIRE(Point(1.0f, 3.0f).getRotatedRadians(PI_2) == Point(-3.0f, 1.0f));
    REQUIRE(Point(1.0f, 3.0f).getRotatedRadians(PI) == Point(-1.0f, -3.0f));
    REQUIRE(Point(1.0f, 3.0f).getRotatedRadians(PI + PI_2) == Point(3.0f, -1.0f));
    REQUIRE(Point(1.0f, 3.0f).getRotatedRadians(PI + PI) == Point(1.0f, 3.0f));

    pointTemp = Point(1.0f, 3.0f);

    pointTemp.getRotatedRadians(PI);
    REQUIRE(pointTemp == Point(1.0f, 3.0f));
}

TEST_CASE("Point Get Rotated Radians at Pivot", "[point]")
{
    REQUIRE(Point(1.0f, 3.0f).getRotatedRadians({1.0f, 0.0f}, 0.0f) == Point(1.0f, 3.0f));
    REQUIRE(Point(1.0f, 3.0f).getRotatedRadians({1.0f, 0.0f}, PI_2) == Point(-2.0f, 0.0f));
    REQUIRE(Point(1.0f, 3.0f).getRotatedRadians({1.0f, 0.0f}, PI) == Point(1.0f, -3.0f));
    REQUIRE(Point(1.0f, 3.0f).getRotatedRadians({1.0f, 0.0f}, PI + PI_2) == Point(4.0f, 0.0f));
    REQUIRE(Point(1.0f, 3.0f).getRotatedRadians({1.0f, 0.0f}, PI + PI) == Point(1.0f, 3.0f));

    REQUIRE(Point(1.0f, 3.0f).getRotatedRadians({0.0f, 3.0f}, 0.0f) == Point(1.0f, 3.0f));
    REQUIRE(Point(1.0f, 3.0f).getRotatedRadians({0.0f, 3.0f}, PI_2) == Point(0.0f, 4.0f));
    REQUIRE(Point(1.0f, 3.0f).getRotatedRadians({0.0f, 3.0f}, PI) == Point(-1.0f, 3.0f));
    REQUIRE(Point(1.0f, 3.0f).getRotatedRadians({0.0f, 3.0f}, PI + PI_2) == Point(0.0f, 2.0f));
    REQUIRE(Point(1.0f, 3.0f).getRotatedRadians({0.0f, 3.0f}, PI + PI) == Point(1.0f, 3.0f));

    pointTemp = Point(1.0f, 3.0f);

    pointTemp.getRotatedRadians({1.0f, 0.0f}, PI);
    REQUIRE(pointTemp == Point(1.0f, 3.0f));
    pointTemp.getRotatedRadians({0.0f, 3.0f}, PI);
    REQUIRE(pointTemp == Point(1.0f, 3.0f));
}

TEST_CASE("Point Get Rotated Degrees", "[point]")
{
    REQUIRE(Point(1.0f, 3.0f).getRotatedDegrees(0.0f) == Point(1.0f, 3.0f));
    REQUIRE(Point(1.0f, 3.0f).getRotatedDegrees(90.0f) == Point(-3.0f, 1.0f));
    REQUIRE(Point(1.0f, 3.0f).getRotatedDegrees(180.0f) == Point(-1.0f, -3.0f));
    REQUIRE(Point(1.0f, 3.0f).getRotatedDegrees(270.0f) == Point(3.0f, -1.0f));
    REQUIRE(Point(1.0f, 3.0f).getRotatedDegrees(360.0f) == Point(1.0f, 3.0f));

    pointTemp = Point(1.0f, 3.0f);

    pointTemp.getRotatedDegrees(90.0f);
    REQUIRE(pointTemp == Point(1.0f, 3.0f));
}

TEST_CASE("Point Get Rotated Degrees at Pivot", "[point]")
{
    REQUIRE(Point(1.0f, 3.0f).getRotatedDegrees({1.0f, 0.0f}, 0.0f) == Point(1.0f, 3.0f));
    REQUIRE(Point(1.0f, 3.0f).getRotatedDegrees({1.0f, 0.0f}, 90.0f) == Point(-2.0f, 0.0f));
    REQUIRE(Point(1.0f, 3.0f).getRotatedDegrees({1.0f, 0.0f}, 180.0f) == Point(1.0f, -3.0f));
    REQUIRE(Point(1.0f, 3.0f).getRotatedDegrees({1.0f, 0.0f}, 270.0f) == Point(4.0f, 0.0f));
    REQUIRE(Point(1.0f, 3.0f).getRotatedDegrees({1.0f, 0.0f}, 360.0f) == Point(1.0f, 3.0f));

    REQUIRE(Point(1.0f, 3.0f).getRotatedDegrees({0.0f, 3.0f}, 0.0f) == Point(1.0f, 3.0f));
    REQUIRE(Point(1.0f, 3.0f).getRotatedDegrees({0.0f, 3.0f}, 90.0f) == Point(0.0f, 4.0f));
    REQUIRE(Point(1.0f, 3.0f).getRotatedDegrees({0.0f, 3.0f}, 180.0f) == Point(-1.0f, 3.0f));
    REQUIRE(Point(1.0f, 3.0f).getRotatedDegrees({0.0f, 3.0f}, 270.0f) == Point(0.0f, 2.0f));
    REQUIRE(Point(1.0f, 3.0f).getRotatedDegrees({0.0f, 3.0f}, 360.0f) == Point(1.0f, 3.0f));

    pointTemp = Point(1.0f, 3.0f);

    pointTemp.getRotatedDegrees({1.0f, 0.0f}, 90.0f);
    REQUIRE(pointTemp == Point(1.0f, 3.0f));
    pointTemp.getRotatedDegrees({0.0f, 3.0f}, 90.0f);
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
