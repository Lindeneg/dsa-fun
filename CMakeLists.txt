cmake_minimum_required(VERSION 3.26)
project(dsa-fun)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "-static-libstdc++ -ggdb -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion")

file(GLOB_RECURSE PROJECT_SOURCES RELATIVE ${CMAKE_SOURCE_DIR} src/*.cpp)

add_executable(dsa-fun ${PROJECT_SOURCES} )
