#include <geometry2d/api/point_api.h>
#include <stdio.h>
#include <unity.h>

#define FLOAT_EPSILON 0.0001f

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_point_translate(void)
{
    Point_C point = {0.0f, 0.0f};

    point_translate(&point, 1.0f, 2.0f);

    TEST_ASSERT_FLOAT_WITHIN(FLOAT_EPSILON, 1.0f, point.x);
    TEST_ASSERT_FLOAT_WITHIN(FLOAT_EPSILON, 2.0f, point.y);

    point_translate(&point, 1.0f, 2.0f);
}

int main()
{
    UNITY_BEGIN();

    printf("Hello world!\n");

    RUN_TEST(test_point_translate);

    
    // point_rotate_degrees(&point, 90.0f);

    // printf("Point {%.2f,%.2f}\n", point.x, point.y);

    return UNITY_END();
}