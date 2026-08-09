#pragma once
#include <geometry2d/api/point_api.h>

#ifdef __cplusplus
extern "C"
{
#endif
    typedef struct Direction_C
    {
        float x;
        float y;
        float radians;
        float degrees;
    } Direction_C;

    GEOMETRY2D_API void direction_set_xy(Direction_C *direction, float x, float y);
    GEOMETRY2D_API void direction_set_xy_2(Direction_C *direction, float xFrom, float yFrom, float xTo, float yTo);
    GEOMETRY2D_API void direction_set_point(Direction_C *direction, Point_C point);
    GEOMETRY2D_API void direction_set_point_2(Direction_C *direction, Point_C from, Point_C to);

    GEOMETRY2D_API void direction_set_angle_radians(Direction_C *direction, float radians);
    GEOMETRY2D_API void direction_set_angle_degrees(Direction_C *direction, float degrees);

    GEOMETRY2D_API void direction_rotate_radians(Direction_C *direction, float radians);
    GEOMETRY2D_API void direction_rotate_degrees(Direction_C *direction, float degrees);

    GEOMETRY2D_API float direction_get_angle_difference_radians(Direction_C *from, Direction_C *to);
    GEOMETRY2D_API float direction_get_angle_difference_degrees(Direction_C *from, Direction_C *to);

    GEOMETRY2D_API Direction_C direction_get_closest_normal(Direction_C *from, Direction_C *to);
    GEOMETRY2D_API Direction_C direction_get_furthest_normal(Direction_C *from, Direction_C *to);
#ifdef __cplusplus
}
#endif