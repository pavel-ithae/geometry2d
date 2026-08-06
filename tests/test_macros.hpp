#include <limits.h>

#if _WIN32  // In Windows, this macro is needed to expose the PI macros.
    #define _USE_MATH_DEFINES
#endif
#include <math.h>

#define FLOAT_EPSILON 0.0001f
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