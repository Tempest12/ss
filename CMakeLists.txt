#author Shane del Solar

cmake_minimum_required(VERSION 3.0)

project(ss)
set(CMAKE_CXX_COMPILIER g++)

add_subdirectory(src)

file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*/*.cpp)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -pedantic -O0 -g")

add_executable(ss ${SOURCES})

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/include)

target_link_libraries(ss ${OPENGL_LIBRARIES} ${SDL2_LIBRARIES})