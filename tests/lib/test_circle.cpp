#include <catch2/catch_test_macros.hpp>
#include <geometry2d/circle.hpp>
#include <geometry2d/direction.hpp>
#include "test_macros.hpp"

using namespace geometry2d;

Circle circleTemp;

TEST_CASE("Circle Value Constructor", "[circle]")
{
    REQUIRE(Circle(Point(0.0f, 0.0f), 0.0f).center == Point(0.0f, 0.0f));
    REQUIRE(Circle(Point(0.0f, 0.0f), 0.0f).radius == 0.0f);

    REQUIRE(Circle(Point(1.0f, 2.0f), 3.0f).center == Point(1.0f, 2.0f));
    REQUIRE(Circle(Point(1.0f, 2.0f), 3.0f).radius == 3.0f);

    REQUIRE(Circle(0.0f, 0.0f, 0.0f).center == Point(0.0f, 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).radius == 0.0f);

    REQUIRE(Circle(1.0f, 2.0f, 3.0f).center == Point(1.0f, 2.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).radius == 3.0f);
}

TEST_CASE("Circle Equals", "[circle]")
{
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).equals(Circle(0.0f, 0.0f, 0.0f)));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).equals(Circle(1.0f, 2.0f, 3.0f)));

    REQUIRE_FALSE(Circle(1.0f, 2.0f, 3.0f).equals(Circle(-1.0f, 2.0f, 3.0f)));
    REQUIRE_FALSE(Circle(1.0f, 2.0f, 3.0f).equals(Circle(1.0f, -2.0f, 3.0f)));
    REQUIRE_FALSE(Circle(1.0f, 2.0f, 3.0f).equals(Circle(1.0f, 2.0f, -3.0f)));

    REQUIRE_FALSE(Circle(1.0f + FLOAT_EPSILON, 2.0f, 3.0f).equals(Circle(1.0f, 2.0f, 3.0f)));
    REQUIRE_FALSE(Circle(1.0f, 2.0f + FLOAT_EPSILON, 3.0f).equals(Circle(1.0f, 2.0f, 3.0f)));
    REQUIRE_FALSE(Circle(1.0f, 2.0f, 3.0f + FLOAT_EPSILON).equals(Circle(1.0f, 2.0f, 3.0f)));

    REQUIRE_FALSE(Circle(1.0f - FLOAT_EPSILON, 2.0f, 3.0f).equals(Circle(1.0f, 2.0f, 3.0f)));
    REQUIRE_FALSE(Circle(1.0f, 2.0f - FLOAT_EPSILON, 3.0f).equals(Circle(1.0f, 2.0f, 3.0f)));
    REQUIRE_FALSE(Circle(1.0f, 2.0f, 3.0f - FLOAT_EPSILON).equals(Circle(1.0f, 2.0f, 3.0f)));
}

TEST_CASE("Circle Equals Approx", "[circle]")
{
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).equalsApprox(Circle(0.0f, 0.0f, 0.0f)));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).equalsApprox(Circle(1.0f, 2.0f, 3.0f)));

    REQUIRE_FALSE(Circle(1.0f, 2.0f, 3.0f).equalsApprox(Circle(-1.0f, 2.0f, 3.0f)));
    REQUIRE_FALSE(Circle(1.0f, 2.0f, 3.0f).equalsApprox(Circle(1.0f, -2.0f, 3.0f)));
    REQUIRE_FALSE(Circle(1.0f, 2.0f, 3.0f).equalsApprox(Circle(1.0f, 2.0f, -3.0f)));

    REQUIRE(Circle(1.0f + FLOAT_EPSILON, 2.0f, 3.0f).equalsApprox(Circle(1.0f, 2.0f, 3.0f)));
    REQUIRE(Circle(1.0f, 2.0f + FLOAT_EPSILON, 3.0f).equalsApprox(Circle(1.0f, 2.0f, 3.0f)));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f + FLOAT_EPSILON).equalsApprox(Circle(1.0f, 2.0f, 3.0f)));

    REQUIRE(Circle(1.0f - FLOAT_EPSILON, 2.0f, 3.0f).equalsApprox(Circle(1.0f, 2.0f, 3.0f)));
    REQUIRE(Circle(1.0f, 2.0f - FLOAT_EPSILON, 3.0f).equalsApprox(Circle(1.0f, 2.0f, 3.0f)));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f - FLOAT_EPSILON).equalsApprox(Circle(1.0f, 2.0f, 3.0f)));
}

TEST_CASE("Circle Negate", "[circle]")
{
    REQUIRE((-Circle(1.0f, 2.0f, 3.0f)) == Circle(-1.0f, -2.0f, 3.0f));
    REQUIRE((-Circle(-1.0f, -2.0f, 3.0f)) == Circle(1.0f, 2.0f, 3.0f));
}

TEST_CASE("Circle Translate", "[circle]")
{
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).translate(3.0f, 5.0f) == Circle(3.0f, 5.0f, 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).translate(-3.0f, -5.0f) == Circle(-3.0f, -5.0f, 0.0f));

    REQUIRE(Circle(1.0f, 2.0f, 3.0f).translate(4.0f, 5.0f) == Circle(5.0f, 7.0f, 3.0f));
    REQUIRE(Circle(3.0f, 1.0f, 2.0f).translate(-4.0f, -5.0f) == Circle(-1.0f, -4.0f, 2.0f));

    REQUIRE(Circle(1.0f, 2.0f, 3.0f).translate(Point(4.0f, 5.0f)) == Circle(5.0f, 7.0f, 3.0f));
    REQUIRE(Circle(3.0f, 1.0f, 2.0f).translate(Point(-4.0f, -5.0f)) == Circle(-1.0f, -4.0f, 2.0f));
}

TEST_CASE("Circle Translate Offset", "[circle]")
{
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).translate(Point(3.0f, 5.0f)) == Circle(3.0f, 5.0f, 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).translate(Point(-3.0f, -5.0f)) == Circle(-3.0f, -5.0f, 0.0f));

    REQUIRE(Circle(1.0f, 2.0f, 3.0f).translate(Point(4.0f, 5.0f)) == Circle(5.0f, 7.0f, 3.0f));
    REQUIRE(Circle(3.0f, 1.0f, 2.0f).translate(Point(-4.0f, -5.0f)) == Circle(-1.0f, -4.0f, 2.0f));
}

TEST_CASE("Circle Translate Direction", "[circle]")
{
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).translate(Direction(1.0f, 0.0f), 3.0f) == Circle(3.0f, 0.0f, 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).translate(Direction(0.0f, 1.0f), 3.0f) == Circle(0.0f, 3.0f, 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).translate(Direction(-1.0f, 0.0f), 3.0f) == Circle(-3.0f, 0.0f, 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).translate(Direction(0.0f, -1.0f), 3.0f) == Circle(0.0f, -3.0f, 0.0f));

    REQUIRE(Circle(0.0f, 0.0f, 0.0f).translate(Direction(1.0f, 1.0f), 3.0f) == Circle(DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(3.0f), 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).translate(Direction(-1.0f, 1.0f), 3.0f) == Circle(DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(3.0f), 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).translate(Direction(1.0f, -1.0f), 3.0f) == Circle(DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(-3.0f), 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).translate(Direction(-1.0f, -1.0f), 3.0f) == Circle(DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(-3.0f), 0.0f));

    REQUIRE(Circle(1.0f, 2.0f, 3.0f).translate(Direction(1.0f, 0.0f), 3.0f) == Circle(4.0f, 2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).translate(Direction(0.0f, 1.0f), 3.0f) == Circle(1.0f, 5.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).translate(Direction(-1.0f, 0.0f), 3.0f) == Circle(-2.0f, 2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).translate(Direction(0.0f, -1.0f), 3.0f) == Circle(1.0f, -1.0f, 3.0f));

    REQUIRE(Circle(1.0f, 2.0f, 3.0f).translate(Direction(1.0f, 1.0f), 3.0f) == Circle(1.0f + DIAGONAL_DELTA(3.0f), 2.0f + DIAGONAL_DELTA(3.0f), 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).translate(Direction(-1.0f, 1.0f), 3.0f) == Circle(1.0f + DIAGONAL_DELTA(-3.0f), 2.0f + DIAGONAL_DELTA(3.0f), 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).translate(Direction(1.0f, -1.0f), 3.0f) == Circle(1.0f + DIAGONAL_DELTA(3.0f), 2.0f + DIAGONAL_DELTA(-3.0f), 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).translate(Direction(-1.0f, -1.0f), 3.0f) == Circle(1.0f + DIAGONAL_DELTA(-3.0f), 2.0f + DIAGONAL_DELTA(-3.0f), 3.0f));
}

TEST_CASE("Circle Addition Operator", "[circle]")
{
    REQUIRE((Circle(0.0f, 0.0f, 0.0f) + Point(3.0f, 5.0f)) == Circle(3.0f, 5.0f, 0.0f));
    REQUIRE((Circle(0.0f, 0.0f, 0.0f) + Point(-3.0f, -5.0f)) == Circle(-3.0f, -5.0f, 0.0f));

    REQUIRE((Circle(1.0f, 2.0f, 3.0f) + Point(4.0f, 5.0f)) == Circle(5.0f, 7.0f, 3.0f));
    REQUIRE((Circle(3.0f, 1.0f, 2.0f) + Point(-4.0f, -5.0f)) == Circle(-1.0f, -4.0f, 2.0f));

    Circle cTemp(1.0f, 2.0f, 3.0f);
    Point pTemp(4.0f, 5.0f);

    Circle resultTemp = cTemp + pTemp;
    REQUIRE(cTemp == Circle(1.0f, 2.0f, 3.0f));
    REQUIRE(pTemp == Point(4.0f, 5.0f));
}

TEST_CASE("Circle Subtraction Operator", "[circle]")
{
    REQUIRE((Circle(0.0f, 0.0f, 0.0f) - Point(3.0f, 5.0f)) == Circle(-3.0f, -5.0f, 0.0f));
    REQUIRE((Circle(0.0f, 0.0f, 0.0f) - Point(-3.0f, -5.0f)) == Circle(3.0f, 5.0f, 0.0f));

    REQUIRE((Circle(1.0f, 2.0f, 3.0f) - Point(4.0f, 5.0f)) == Circle(-3.0f, -3.0f, 3.0f));
    REQUIRE((Circle(3.0f, 1.0f, 2.0f) - Point(-4.0f, -5.0f)) == Circle(7.0f, 6.0f, 2.0f));

    Circle cTemp(1.0f, 2.0f, 3.0f);
    Point pTemp(4.0f, 5.0f);

    Circle resultTemp = cTemp - pTemp;
    REQUIRE(cTemp == Circle(1.0f, 2.0f, 3.0f));
    REQUIRE(pTemp == Point(4.0f, 5.0f));
}

TEST_CASE("Circle Rotate Radians", "[circle]")
{
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).rotateRadians(0.0f) == Circle(0.0f, 0.0f, 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).rotateRadians(PI_2) == Circle(0.0f, 0.0f, 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).rotateRadians(PI) == Circle(0.0f, 0.0f, 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).rotateRadians(PI + PI_2) == Circle(0.0f, 0.0f, 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).rotateRadians(PI + PI) == Circle(0.0f, 0.0f, 0.0f));

    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateRadians(0.0f) == Circle(1.0f, 2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateRadians(PI_2) == Circle(-2.0f, 1.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateRadians(PI) == Circle(-1.0f, -2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateRadians(PI + PI_2) == Circle(2.0f, -1.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateRadians(PI + PI) == Circle(1.0f, 2.0f, 3.0f));
}

TEST_CASE("Circle Rotate Radians at Pivot", "[circle]")
{
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateRadians({1.0f, 2.0f}, 0.0f) == Circle(1.0f, 2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateRadians({1.0f, 2.0f}, PI_2) == Circle(1.0f, 2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateRadians({1.0f, 2.0f}, PI) == Circle(1.0f, 2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateRadians({1.0f, 2.0f}, PI + PI_2) == Circle(1.0f, 2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateRadians({1.0f, 2.0f}, PI + PI) == Circle(1.0f, 2.0f, 3.0f));

    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateRadians({3.0f, 5.0f}, 0.0f) == Circle(1.0f, 2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateRadians({3.0f, 5.0f}, PI_2) == Circle(6.0f, 3.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateRadians({3.0f, 5.0f}, PI) == Circle(5.0f, 8.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateRadians({3.0f, 5.0f}, PI + PI_2) == Circle(0.0f, 7.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateRadians({3.0f, 5.0f}, PI + PI) == Circle(1.0f, 2.0f, 3.0f));
}

TEST_CASE("Circle Rotate Degrees", "[circle]")
{
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).rotateDegrees(0.0f) == Circle(0.0f, 0.0f, 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).rotateDegrees(90.0f) == Circle(0.0f, 0.0f, 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).rotateDegrees(180.0f) == Circle(0.0f, 0.0f, 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).rotateDegrees(270.0f) == Circle(0.0f, 0.0f, 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).rotateDegrees(360.0f) == Circle(0.0f, 0.0f, 0.0f));

    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateDegrees(0.0f) == Circle(1.0f, 2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateDegrees(90.0f) == Circle(-2.0f, 1.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateDegrees(180.0f) == Circle(-1.0f, -2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateDegrees(270.0f) == Circle(2.0f, -1.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateDegrees(360.0f) == Circle(1.0f, 2.0f, 3.0f));
}

TEST_CASE("Circle Rotate Degrees at Pivot", "[circle]")
{
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateDegrees({1.0f, 2.0f}, 0.0f) == Circle(1.0f, 2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateDegrees({1.0f, 2.0f}, 90.0f) == Circle(1.0f, 2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateDegrees({1.0f, 2.0f}, 180.0f) == Circle(1.0f, 2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateDegrees({1.0f, 2.0f}, 270.0f) == Circle(1.0f, 2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateDegrees({1.0f, 2.0f}, 360.0f) == Circle(1.0f, 2.0f, 3.0f));

    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateDegrees({3.0f, 5.0f}, 0.0f) == Circle(1.0f, 2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateDegrees({3.0f, 5.0f}, 90.0f) == Circle(6.0f, 3.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateDegrees({3.0f, 5.0f}, 180.0f) == Circle(5.0f, 8.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateDegrees({3.0f, 5.0f}, 270.0f) == Circle(0.0f, 7.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).rotateDegrees({3.0f, 5.0f}, 360.0f) == Circle(1.0f, 2.0f, 3.0f));
}

TEST_CASE("Circle Scale", "[circle]")
{
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).scale(0.5f) == Circle(0.5f, 1.0f, 1.5f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).scale(0.1f) == Circle(0.1f, 0.2f, 0.3f));

    REQUIRE(Circle(1.0f, 2.0f, 3.0f).scale({1.0f, 2.0f}, 0.5f) == Circle(1.0f, 2.0f, 1.5f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).scale({1.0f, 2.0f}, 0.1f) == Circle(1.0f, 2.0f, 0.3f));

    REQUIRE(Circle(1.0f, 2.0f, 3.0f).scale({3.0f, 5.0f}, 0.5f) == Circle(2.0f, 3.5f, 1.5f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).scale({3.0f, 5.0f}, 0.1f) == Circle(2.8f, 4.7f, 0.3f));
}

TEST_CASE("Circle Get Translated", "[circle]")
{
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).getTranslated(3.0f, 5.0f) == Circle(3.0f, 5.0f, 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).getTranslated(-3.0f, -5.0f) == Circle(-3.0f, -5.0f, 0.0f));

    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getTranslated(4.0f, 5.0f) == Circle(5.0f, 7.0f, 3.0f));
    REQUIRE(Circle(3.0f, 1.0f, 2.0f).getTranslated(-4.0f, -5.0f) == Circle(-1.0f, -4.0f, 2.0f));

    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getTranslated(Point(4.0f, 5.0f)) == Circle(5.0f, 7.0f, 3.0f));
    REQUIRE(Circle(3.0f, 1.0f, 2.0f).getTranslated(Point(-4.0f, -5.0f)) == Circle(-1.0f, -4.0f, 2.0f));

    Circle temp(1.0f, 2.0f, 3.0f);

    temp.getTranslated(1.0f, 2.0f);
    REQUIRE(temp == Circle(1.0f, 2.0f, 3.0f));
    temp.getTranslated(-1.0f, -2.0f);
    REQUIRE(temp == Circle(1.0f, 2.0f, 3.0f));
}

TEST_CASE("Circle Get Translated Offset", "[circle]")
{
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).getTranslated(Point(3.0f, 5.0f)) == Circle(3.0f, 5.0f, 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).getTranslated(Point(-3.0f, -5.0f)) == Circle(-3.0f, -5.0f, 0.0f));

    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getTranslated(Point(4.0f, 5.0f)) == Circle(5.0f, 7.0f, 3.0f));
    REQUIRE(Circle(3.0f, 1.0f, 2.0f).getTranslated(Point(-4.0f, -5.0f)) == Circle(-1.0f, -4.0f, 2.0f));

    Circle temp(1.0f, 2.0f, 3.0f);

    temp.getTranslated(Point(1.0f, 2.0f));
    REQUIRE(temp == Circle(1.0f, 2.0f, 3.0f));
    temp.getTranslated(Point(-1.0f, -2.0f));
    REQUIRE(temp == Circle(1.0f, 2.0f, 3.0f));
}

TEST_CASE("Circle Get Translated Direction", "[circle]")
{
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).getTranslated(Direction(1.0f, 0.0f), 3.0f) == Circle(3.0f, 0.0f, 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).getTranslated(Direction(0.0f, 1.0f), 3.0f) == Circle(0.0f, 3.0f, 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).getTranslated(Direction(-1.0f, 0.0f), 3.0f) == Circle(-3.0f, 0.0f, 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).getTranslated(Direction(0.0f, -1.0f), 3.0f) == Circle(0.0f, -3.0f, 0.0f));

    REQUIRE(Circle(0.0f, 0.0f, 0.0f).getTranslated(Direction(1.0f, 1.0f), 3.0f) == Circle(DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(3.0f), 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).getTranslated(Direction(-1.0f, 1.0f), 3.0f) == Circle(DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(3.0f), 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).getTranslated(Direction(1.0f, -1.0f), 3.0f) == Circle(DIAGONAL_DELTA(3.0f), DIAGONAL_DELTA(-3.0f), 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).getTranslated(Direction(-1.0f, -1.0f), 3.0f) == Circle(DIAGONAL_DELTA(-3.0f), DIAGONAL_DELTA(-3.0f), 0.0f));

    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getTranslated(Direction(1.0f, 0.0f), 3.0f) == Circle(4.0f, 2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getTranslated(Direction(0.0f, 1.0f), 3.0f) == Circle(1.0f, 5.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getTranslated(Direction(-1.0f, 0.0f), 3.0f) == Circle(-2.0f, 2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getTranslated(Direction(0.0f, -1.0f), 3.0f) == Circle(1.0f, -1.0f, 3.0f));

    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getTranslated(Direction(1.0f, 1.0f), 3.0f) == Circle(1.0f + DIAGONAL_DELTA(3.0f), 2.0f + DIAGONAL_DELTA(3.0f), 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getTranslated(Direction(-1.0f, 1.0f), 3.0f) == Circle(1.0f + DIAGONAL_DELTA(-3.0f), 2.0f + DIAGONAL_DELTA(3.0f), 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getTranslated(Direction(1.0f, -1.0f), 3.0f) == Circle(1.0f + DIAGONAL_DELTA(3.0f), 2.0f + DIAGONAL_DELTA(-3.0f), 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getTranslated(Direction(-1.0f, -1.0f), 3.0f) == Circle(1.0f + DIAGONAL_DELTA(-3.0f), 2.0f + DIAGONAL_DELTA(-3.0f), 3.0f));

    Circle temp(1.0f, 2.0f, 3.0f);

    temp.getTranslated(Direction(1.0f, 1.0f), 3.0f);
    REQUIRE(temp == Circle(1.0f, 2.0f, 3.0f));
    temp.getTranslated(Direction(-1.0f, -1.0f), 3.0f);
    REQUIRE(temp == Circle(1.0f, 2.0f, 3.0f));
}

TEST_CASE("Circle Get Rotated Radians", "[circle]")
{
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).getRotatedRadians(0.0f) == Circle(0.0f, 0.0f, 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).getRotatedRadians(PI_2) == Circle(0.0f, 0.0f, 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).getRotatedRadians(PI) == Circle(0.0f, 0.0f, 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).getRotatedRadians(PI + PI_2) == Circle(0.0f, 0.0f, 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).getRotatedRadians(PI + PI) == Circle(0.0f, 0.0f, 0.0f));

    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedRadians(0.0f) == Circle(1.0f, 2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedRadians(PI_2) == Circle(-2.0f, 1.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedRadians(PI) == Circle(-1.0f, -2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedRadians(PI + PI_2) == Circle(2.0f, -1.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedRadians(PI + PI) == Circle(1.0f, 2.0f, 3.0f));

    Circle temp(1.0f, 2.0f, 3.0f);

    temp.getRotatedRadians(PI_2);
    REQUIRE(temp == Circle(1.0f, 2.0f, 3.0f));
    temp.getRotatedRadians(PI);
    REQUIRE(temp == Circle(1.0f, 2.0f, 3.0f));
}

TEST_CASE("Circle Get Rotated Radians at Pivot", "[circle]")
{
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedRadians({1.0f, 2.0f}, 0.0f) == Circle(1.0f, 2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedRadians({1.0f, 2.0f}, PI_2) == Circle(1.0f, 2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedRadians({1.0f, 2.0f}, PI) == Circle(1.0f, 2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedRadians({1.0f, 2.0f}, PI + PI_2) == Circle(1.0f, 2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedRadians({1.0f, 2.0f}, PI + PI) == Circle(1.0f, 2.0f, 3.0f));

    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedRadians({3.0f, 5.0f}, 0.0f) == Circle(1.0f, 2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedRadians({3.0f, 5.0f}, PI_2) == Circle(6.0f, 3.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedRadians({3.0f, 5.0f}, PI) == Circle(5.0f, 8.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedRadians({3.0f, 5.0f}, PI + PI_2) == Circle(0.0f, 7.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedRadians({3.0f, 5.0f}, PI + PI) == Circle(1.0f, 2.0f, 3.0f));

    Circle temp(1.0f, 2.0f, 3.0f);

    temp.getRotatedRadians({1.0f, 2.0f},PI_2);
    REQUIRE(temp == Circle(1.0f, 2.0f, 3.0f));
    temp.getRotatedRadians({1.0f, 2.0f},PI);
    REQUIRE(temp == Circle(1.0f, 2.0f, 3.0f));
    temp.getRotatedRadians({3.0f, 5.0f},PI_2);
    REQUIRE(temp == Circle(1.0f, 2.0f, 3.0f));
    temp.getRotatedRadians({3.0f, 5.0f},PI);
    REQUIRE(temp == Circle(1.0f, 2.0f, 3.0f));
}

TEST_CASE("Circle Get Rotated Degrees", "[circle]")
{
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).getRotatedDegrees(0.0f) == Circle(0.0f, 0.0f, 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).getRotatedDegrees(90.0f) == Circle(0.0f, 0.0f, 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).getRotatedDegrees(180.0f) == Circle(0.0f, 0.0f, 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).getRotatedDegrees(270.0f) == Circle(0.0f, 0.0f, 0.0f));
    REQUIRE(Circle(0.0f, 0.0f, 0.0f).getRotatedDegrees(360.0f) == Circle(0.0f, 0.0f, 0.0f));

    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedDegrees(0.0f) == Circle(1.0f, 2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedDegrees(90.0f) == Circle(-2.0f, 1.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedDegrees(180.0f) == Circle(-1.0f, -2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedDegrees(270.0f) == Circle(2.0f, -1.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedDegrees(360.0f) == Circle(1.0f, 2.0f, 3.0f));

    Circle temp(1.0f, 2.0f, 3.0f);

    temp.getRotatedDegrees(90.0f);
    REQUIRE(temp == Circle(1.0f, 2.0f, 3.0f));
    temp.getRotatedDegrees(180.0f);
    REQUIRE(temp == Circle(1.0f, 2.0f, 3.0f));
}

TEST_CASE("Circle Get Rotated Degrees at Pivot", "[circle]")
{
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedDegrees({1.0f, 2.0f}, 0.0f) == Circle(1.0f, 2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedDegrees({1.0f, 2.0f}, 90.0f) == Circle(1.0f, 2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedDegrees({1.0f, 2.0f}, 180.0f) == Circle(1.0f, 2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedDegrees({1.0f, 2.0f}, 270.0f) == Circle(1.0f, 2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedDegrees({1.0f, 2.0f}, 360.0f) == Circle(1.0f, 2.0f, 3.0f));

    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedDegrees({3.0f, 5.0f}, 0.0f) == Circle(1.0f, 2.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedDegrees({3.0f, 5.0f}, 90.0f) == Circle(6.0f, 3.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedDegrees({3.0f, 5.0f}, 180.0f) == Circle(5.0f, 8.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedDegrees({3.0f, 5.0f}, 270.0f) == Circle(0.0f, 7.0f, 3.0f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getRotatedDegrees({3.0f, 5.0f}, 360.0f) == Circle(1.0f, 2.0f, 3.0f));

    Circle temp(1.0f, 2.0f, 3.0f);

    temp.getRotatedDegrees({1.0f, 2.0f},180.0f);
    REQUIRE(temp == Circle(1.0f, 2.0f, 3.0f));
    temp.getRotatedDegrees({1.0f, 2.0f},90.0f);
    REQUIRE(temp == Circle(1.0f, 2.0f, 3.0f));
    temp.getRotatedDegrees({3.0f, 5.0f},180.0f);
    REQUIRE(temp == Circle(1.0f, 2.0f, 3.0f));
    temp.getRotatedDegrees({3.0f, 5.0f},90.0f);
    REQUIRE(temp == Circle(1.0f, 2.0f, 3.0f));
}

TEST_CASE("Circle Get Scaled", "[circle]")
{
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getScaled(0.5f) == Circle(0.5f, 1.0f, 1.5f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getScaled(0.1f) == Circle(0.1f, 0.2f, 0.3f));

    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getScaled({1.0f, 2.0f}, 0.5f) == Circle(1.0f, 2.0f, 1.5f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getScaled({1.0f, 2.0f}, 0.1f) == Circle(1.0f, 2.0f, 0.3f));

    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getScaled({3.0f, 5.0f}, 0.5f) == Circle(2.0f, 3.5f, 1.5f));
    REQUIRE(Circle(1.0f, 2.0f, 3.0f).getScaled({3.0f, 5.0f}, 0.1f) == Circle(2.8f, 4.7f, 0.3f));

    Circle temp(1.0f, 2.0f, 3.0f);

    temp.getScaled(0.5f);
    REQUIRE(temp == Circle(1.0f, 2.0f, 3.0f));
    temp.getScaled({1.0f, 2.0f}, 0.5f);
    REQUIRE(temp == Circle(1.0f, 2.0f, 3.0f));
    temp.getScaled({3.0f, 4.0f}, 0.5f);
    REQUIRE(temp == Circle(1.0f, 2.0f, 3.0f));
}