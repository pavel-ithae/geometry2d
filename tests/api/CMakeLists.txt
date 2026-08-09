# Find source files.
file(GLOB GEOMETRY2D_TEST_API_SOURCE ./*.c)

# Prepare executable.
add_executable(tests_api ${GEOMETRY2D_TEST_API_SOURCE})

# Output executable to "/bin" directory.
set_target_properties(tests_api PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Link Geometry2D library.
target_link_libraries(tests_api PRIVATE geometry2d)

# Include Unity test framework.
add_subdirectory(${CMAKE_SOURCE_DIR}/third_party/unity ${CMAKE_SOURCE_DIR}/build/third_party/unity)

set_target_properties(unity PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

target_link_libraries(tests_api PRIVATE unity)