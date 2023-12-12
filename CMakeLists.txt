cmake_minimum_required(VERSION 3.26)
project(dsa-fun)

set(CMAKE_CXX_STANDARD 17)
set(CL_GNU_DEBUG_FLAGS "-static-libstdc++ -ggdb -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion")
set(CL_GNU_RELEASE_FLAGS "-static-libstdc++ -O2 -s -DNDEBUG")

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if ($ENV{CL_BUILD_MODE} STREQUAL "RELEASE")
        set(CMAKE_CXX_FLAGS ${CL_GNU_RELEASE_FLAGS})
    else()
        set(CMAKE_CXX_FLAGS ${CL_GNU_DEBUG_FLAGS})
    endif()
endif()

message(GNU_FLAGS="${CMAKE_CXX_FLAGS}")

file(GLOB_RECURSE PROJECT_SOURCES RELATIVE ${CMAKE_SOURCE_DIR} src/*.cpp)

add_executable(dsa-fun ${PROJECT_SOURCES} )
