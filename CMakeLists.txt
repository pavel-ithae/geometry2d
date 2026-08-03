cmake_minimum_required(VERSION 3.31)

project(geometry2dLibrary)

enable_testing()

file(GLOB GEOMETRY2D_SOURCE "./src/*.cpp")
file(GLOB GEOMETRY2D_HEADERS "./include/*.hpp")

add_library(geometry2d)

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

if(BUILD_TESTING)
    add_subdirectory(./tests)
endif()