#pragma once
#include "point/test_point.hpp"

namespace galla::tests
{
    class TestGeometry2D
    {
        static void test_point()
        {
            TestPoint::run();
        }

    public:
        static void run()
        {
            test_point();
        }
    };
}

#undef FLOAT_EPSILON