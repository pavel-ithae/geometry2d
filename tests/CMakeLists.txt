# Try to include local Catch2 (3.0) package.
find_package(Catch2 3 QUIET)

# If not found locally, fetch Catch2 from github.
if(NOT Catch2_FOUND)
    Include(FetchContent)

    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.8.1
    )

    FetchContent_MakeAvailable(Catch2)
endif()

# Find source files.
file(GLOB GEOMETRY2D_TEST_SOURCE ./*.cpp)

# Prepare executable.
add_executable(tests ${GEOMETRY2D_TEST_SOURCE})

# Output executable to "/bin" directory.
set_target_properties(tests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Link Geometry2D library.
target_link_libraries(tests PRIVATE geometry2d)

# Link Catch2 (with main) library.
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(tests)