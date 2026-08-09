#pragma once
#include <geometry2d/api/macros_api.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif
    typedef struct Point_C
    {
        float x;
        float y;
    } Point_C;

    typedef struct Direction_C Direction_C;

    GEOMETRY2D_API void point_translate(Point_C *point, float xTranslation, float yTranslation);
    GEOMETRY2D_API void point_translate_offset(Point_C *point, Point_C offsetTranslation);
    GEOMETRY2D_API void point_translate_direction(Point_C *point, Direction_C direction, float length);

    GEOMETRY2D_API void point_rotate_radians(Point_C *point, float radians);
    GEOMETRY2D_API void point_rotate_radians_pivot(Point_C *point, Point_C pivot, float radians);
    GEOMETRY2D_API void point_rotate_degrees(Point_C *point, float degrees);
    GEOMETRY2D_API void point_rotate_degrees_pivot(Point_C *point, Point_C pivot, float degrees);

    GEOMETRY2D_API void point_scale(Point_C *point, float scale);
    GEOMETRY2D_API void point_scale_pivot(Point_C *point, Point_C pivot, float scale);

    GEOMETRY2D_API bool equals(Point_C a, Point_C b);
    GEOMETRY2D_API bool equalsApprox(Point_C a, Point_C b);
#ifdef __cplusplus
}
#endif