# Geometry2d
A C++ library with various utility functions and classes for 2D math for game development.

## Requirements
To build the library, you'll need:
- A C++ compiler (gcc / msvc).
- [CMake](https://cmake.org/) (version 3.31 minimum). (Recommended)

If you want to run tests, you'll also need:
- [CMake](https://cmake.org/) (version 3.31 minimum). (Required)
- [Catch2](https://github.com/catchorg/Catch2) library installed. (Recommended)

## Building with CMake (Recommended)
To compile the static library in CLI, go to the project's root and run the following command:
```
cmake --preset library && cmake --build --preset library
```

To build and run the test, use the following command:
```
cmake --preset test && cmake --build --preset test
```