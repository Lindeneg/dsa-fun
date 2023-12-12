cmake_minimum_required(VERSION 3.26)
project(dsa-fun)

set(CMAKE_CXX_STANDARD 17)
set(CL_CLANG_DEBUG_FLAGS "-ggdb -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion")
set(CL_CLANG_RELEASE_FLAGS "-O2 -DNDEBUG")
set(CL_GNU_DEBUG_FLAGS "-static-libstdc++ ${CL_CLANG_DEBUG_FLAGS}")
set(CL_GNU_RELEASE_FLAGS "-static-libstdc++ -s ${CL_CLANG_RELEASE_FLAGS}")

function(set_flags mode debug_flags release_flags)
    if ("${mode}" STREQUAL "RELEASE")
        set(CMAKE_CXX_FLAGS ${release_flags} PARENT_SCOPE)
    else()
        set(CMAKE_CXX_FLAGS ${debug_flags} PARENT_SCOPE)
    endif()
endfunction()


if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set_flags("$ENV{CL_BUILD_MODE}" "${CL_GNU_DEBUG_FLAGS}" "${CL_GNU_RELEASE_FLAGS}")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set_flags("$ENV{CL_BUILD_MODE}" ${CL_CLANG_DEBUG_FLAGS} ${CL_CLANG_RELEASE_FLAGS})
endif()

message(COMPILER_FLAGS="${CMAKE_CXX_FLAGS}")

file(GLOB_RECURSE PROJECT_SOURCES RELATIVE ${CMAKE_SOURCE_DIR} src/*.cpp)

add_executable(dsa-fun ${PROJECT_SOURCES} )
