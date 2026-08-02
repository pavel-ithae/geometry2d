#pragma once
#include "../test.hpp"
#include <geometry2d/point.hpp>
#include <geometry2d/direction.hpp>
#include <math.h>
#include <limits>

using namespace geometry2d;

#define FLOAT_EPSILON std::numeric_limits<float>::epsilon()

namespace galla::tests
{
    class TestPoint
    {
        static void test_valueConstructor()
        {
            TEST_CASE("Point Value Constructor",
                      {
                          TEST_UNIT_EQUALS(Point(0.0f, 0.0f).x, 0.0f);
                          TEST_UNIT_EQUALS(Point(0.0f, 0.0f).y, 0.0f);
                          TEST_UNIT_EQUALS(Point(1.0f, 3.0f).x, 1.0f);
                          TEST_UNIT_EQUALS(Point(1.0f, 3.0f).y, 3.0f);
                      });
        }

        static void test_equals()
        {
            TEST_CASE("Point Equals",
                      {
                          TEST_UNIT_EQUALS(Point(2.0f, -5.0f).equals(Point(2.0f, -5.0f)), true);

                          TEST_UNIT_EQUALS(Point(2.0f, -5.0f).equals(Point(1.0f, -5.0f)), false);
                          TEST_UNIT_EQUALS(Point(2.0f, -5.0f).equals(Point(2.0f, 5.0f)), false);
                          TEST_UNIT_EQUALS(Point(2.0f, -5.0f).equals(Point(1.0f, 5.0f)), false);

                          TEST_UNIT_EQUALS(Point(-1.0f + FLOAT_EPSILON, 4.0f - FLOAT_EPSILON).equals(Point(-1.0f, 4.0f)), false);
                      });
        }

        static void test_equalsApprox()
        {
            TEST_CASE("Point Equals Approx",
                      {
                          TEST_UNIT_EQUALS(Point(2.0f, -5.0f).equalsApprox(Point(2.0f, -5.0f)), true);

                          TEST_UNIT_EQUALS(Point(2.0f, -5.0f).equalsApprox(Point(1.0f, -5.0f)), false);
                          TEST_UNIT_EQUALS(Point(2.0f, -5.0f).equalsApprox(Point(2.0f, 5.0f)), false);
                          TEST_UNIT_EQUALS(Point(2.0f, -5.0f).equalsApprox(Point(1.0f, 5.0f)), false);

                          TEST_UNIT_EQUALS(Point(-1.0f + FLOAT_EPSILON, 4.0f - FLOAT_EPSILON).equalsApprox(Point(-1.0f, 4.0f)), true);
                          TEST_UNIT_EQUALS(Point(2.0f, -5.0f).equalsApprox(Point(1.0f, 5.0f)), false);

                          TEST_UNIT_EQUALS(Point(-1.0f + FLOAT_EPSILON, 4.0f - FLOAT_EPSILON) == Point(-1.0f, 4.0f), true);
                          TEST_UNIT_EQUALS(Point(-1.0f + FLOAT_EPSILON, 4.0f - FLOAT_EPSILON) != Point(-1.0f, 4.0f), false);
                          TEST_UNIT_EQUALS(Point(2.0f, -5.0f) == (Point(1.0f, 5.0f)), false);
                          TEST_UNIT_EQUALS(Point(2.0f, -5.0f) != (Point(1.0f, 5.0f)), true);
                      });
        }

        static void test_negate()
        {
            TEST_CASE("Point Negate",
                      {
                          TEST_UNIT_EQUALS(-Point(3.0f, -1.5f), Point(-3.0f, 1.5f));
                          TEST_UNIT_EQUALS(-Point(-3.0f, 1.5f), Point(3.0f, -1.5f));
                      });
        }

        static void test_translate()
        {
            TEST_CASE("Point Translate",
                      {
                          TEST_UNIT_EQUALS(Point(1.0f, 3.0f).translate(2.5f, 1.25f), Point(3.5f, 4.25f));
                          TEST_UNIT_EQUALS(Point(1.0f, 3.0f).translate(-2.5f, -1.25f), Point(-1.5f, 1.75f));

                          TEST_UNIT_EQUALS(Point(1.0f, 3.0f).translate(Point(2.5f, 1.25f)), Point(3.5f, 4.25f));
                          TEST_UNIT_EQUALS(Point(1.0f, 3.0f).translate(Point(-2.5f, -1.25f)), Point(-1.5f, 1.75f));

                          TEST_UNIT_EQUALS(Point(1.0f, 3.0f) + (Point(2.5f, 1.25f)), Point(3.5f, 4.25f));
                          TEST_UNIT_EQUALS(Point(1.0f, 3.0f) - (Point(2.5f, 1.25f)), Point(-1.5f, 1.75f));

                          TEST_UNIT_EQUALS(Point(1.0f, 3.0f).getTranslated(Point(2.5f, 1.25f)), Point(3.5f, 4.25f));
                          TEST_UNIT_EQUALS(Point(1.0f, 3.0f).getTranslated(Point(-2.5f, -1.25f)), Point(-1.5f, 1.75f));
                      });
        }

        static void test_translate_direction()
        {
#define DIAGONAL_DELTA(length) ((1.0f / std::sqrt(2.0f)) * length)

            TEST_CASE("Point Translate Direction",
                      {
                          TEST_UNIT_EQUALS(Point(1.0f, 3.0f).translate(Direction(1.0f, 0.0f), 2.5f), Point(3.5f, 3.0f));
                          TEST_UNIT_EQUALS(Point(1.0f, 3.0f).translate(Direction(-1.0f, 0.0f), 2.5f), Point(-1.5f, 3.0f));
                          TEST_UNIT_EQUALS(Point(1.0f, 3.0f).translate(Direction(0.0f, 1.0f), 2.5f), Point(1.0f, 5.5f));
                          TEST_UNIT_EQUALS(Point(1.0f, 3.0f).translate(Direction(0.0f, -1.0f), 2.5f), Point(1.0f, 0.5f));

                          TEST_UNIT_EQUALS(Point(1.0f, 3.0f).translate(Direction(1.0f, 1.0f), 2.0f), Point(1.0f + DIAGONAL_DELTA(2.0f), 3.0f + DIAGONAL_DELTA(2.0f)));
                          TEST_UNIT_EQUALS(Point(1.0f, 3.0f).translate(Direction(-1.0f, 1.0f), 2.5f), Point(1.0f - DIAGONAL_DELTA(2.5f), 3.0f + DIAGONAL_DELTA(2.5f)));
                          TEST_UNIT_EQUALS(Point(1.0f, 3.0f).translate(Direction(1.0f, -1.0f), 1.0f), Point(1.0f + DIAGONAL_DELTA(1.0f), 3.0f - DIAGONAL_DELTA(1.0f)));
                          TEST_UNIT_EQUALS(Point(1.0f, 3.0f).translate(Direction(-1.0f, -1.0f), 4.25f), Point(1.0f - DIAGONAL_DELTA(4.25f), 3.0f - DIAGONAL_DELTA(4.25f)));
                      });

#undef DIAGONAL_DELTA
        }

        static void test_scale()
        {
            TEST_CASE("Point Scale",
                      {
                          TEST_UNIT_EQUALS(Point(1.0f, 3.0f).scale(0.5f), Point(0.5f, 1.5f));
                          TEST_UNIT_EQUALS(Point(-2.5f, -1.25f).scale(0.1f), Point(-0.25f, -0.125f));

                          TEST_UNIT_EQUALS(Point(1.0f, 3.0f) * 0.5f, Point(0.5f, 1.5f));
                          TEST_UNIT_EQUALS(Point(-2.5f, -1.25f) * 0.1f, Point(-0.25f, -0.125f));

                          TEST_UNIT_EQUALS(Point(1.0f, 3.0f).scale(Point(-0.5f, 1.0f), 0.5f), Point(0.25f, 2.0f));
                          TEST_UNIT_EQUALS(Point(-2.5f, -1.25f).scale(Point(1.5f, -1.0f), 0.1f), Point(1.1f, -1.025f));

                          TEST_UNIT_EQUALS(Point(1.0f, 3.0f).getScaled(0.5f), Point(0.5f, 1.5f));
                          TEST_UNIT_EQUALS(Point(-2.5f, -1.25f).getScaled(0.1f), Point(-0.25f, -0.125f));

                          TEST_UNIT_EQUALS(Point(1.0f, 3.0f).getScaled(Point(-0.5f, 1.0f), 0.5f), Point(0.25f, 2.0f));
                          TEST_UNIT_EQUALS(Point(-2.5f, -1.25f).getScaled(Point(1.5f, -1.0f), 0.1f), Point(1.1f, -1.025f));
                      });
        }

        static void test_getImmutable()
        {
            TEST_CASE("Point Get Immutable",
                      {
                          TEST_UNIT_IMMUTABLE(Point(1.0f, 3.0f), getTranslated(2.5f, 1.25f));
                          TEST_UNIT_IMMUTABLE(Point(1.0f, 3.0f), getTranslated(Point(2.5f, 1.25f)));
                          TEST_UNIT_IMMUTABLE(Point(1.0f, 3.0f), getTranslated(Direction(1.0f, 0.0f), 2.5f));

                          TEST_UNIT_IMMUTABLE(Point(1.0f, 3.0f), getScaled(0.5f));
                          TEST_UNIT_IMMUTABLE(Point(1.0f, 3.0f), getScaled(Point(-0.25f, 0.5f), 0.5f));
                      });
        }

    public:
        static void run()
        {
            test_valueConstructor();
            test_equals();
            test_equalsApprox();
            test_negate();
            test_translate();
            test_translate_direction();
            test_scale();
            test_getImmutable();
        }
    };
}

#undef FLOAT_EPSILON