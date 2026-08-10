# CMake version.
cmake_minimum_required(VERSION 3.10)

# Project.
project(geometry2dLibrary)

# Gather & group files.
file(GLOB_RECURSE GEOMETRY2D_SOURCE "./src/*.cpp")
file(GLOB_RECURSE GEOMETRY2D_HEADERS "./include/*.hpp" "./include/*.h")

if(NOT BUILD_GEOMETRY2D_API)
    list(FILTER GEOMETRY2D_SOURCE EXCLUDE REGEX ".*/api/.*")
    list(FILTER GEOMETRY2D_HEADERS EXCLUDE REGEX ".*/api/.*")
endif()

if(NOT BUILD_GEOMETRY2D_API)
    add_library(geometry2d)
else()
    add_library(geometry2d SHARED)
endif()

set_target_properties(geometry2d PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

target_sources(geometry2d
    PRIVATE
        ${GEOMETRY2D_SOURCE}
        
    PUBLIC
        FILE_SET geometry2dHeaders
        TYPE HEADERS
        BASE_DIRS
            include
        FILES
            ${GEOMETRY2D_HEADERS}
)

# if(NOT BUILD_GEOMETRY2D_API)
#     target_sources(geometry2d
#         PUBLIC
#             FILE_SET geometry2dHeaders
#             TYPE HEADERS
#             BASE_DIRS
#                 include
#             FILES
#                 ${GEOMETRY2D_HEADERS}
#     )
# else()
# endif()

if(BUILD_TESTING)
    enable_testing()

    add_subdirectory(./tests)
endif()