#pragma once

#if _WIN32  // In Windows, this macro is needed to expose the PI macros.
    #define _USE_MATH_DEFINES
#endif
#include <math.h>

#define EQUALS_APROX_EPSILON 0.001f // Margin of error for approx equality operators.

#if _WIN32 // Windows doesn't have f versions.
    #define PI M_PI
    #define PI_2 M_PI_2
#else
    #define PI M_PIf
    #define PI_2 M_PI_2f
#endif

#define RADIANS_TO_DEGREES(radians) (radians * (180.0f / PI))
#define DEGREES_TO_RADIANS(degrees) (degrees * (PI / 180.0f))