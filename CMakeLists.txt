#author Shane del Solar

cmake_minimum_required(VERSION 3.0)

project(ss)
set(CMAKE_CXX_COMPILIER g++)

add_subdirectory(src)

file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*/*.cpp)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -pedantic -O0 -g")

add_executable(ss ${SOURCES})

find_package(OpenGL REQUIRED)
find_package(GLEW   REQUIRED)
find_package(GLUT   REQUIRED)

include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)

include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/include)

set_target_properties(ss PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

target_link_libraries(ss ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${GLUT_LIBRARIES} ${SDL2_LIBRARIES})