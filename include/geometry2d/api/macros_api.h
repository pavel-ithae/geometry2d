#pragma once

#if defined(_WIN32)
#if GEOMETRY2D_API_BUILD
#define GEOMETRY2D_API __declspec(dllexport)
#else
#define GEOMETRY2D_API __declspec(dllimport)
#endif
#elif defined(__GNUC__) || defined(__clang__)
#define GEOMETRY2D_API __attribute__((visibility("default")))
#else
#define GEOMETRY2D_API 
#endif

