cmake_minimum_required(VERSION 3.8)

set(This Example)

project(${This} C CXX)

set(CMAKE_C_STANDART 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_EXTENSIONS ON)

enable_testing()

add_subdirectory(GoogleTest)

# add_subdirectory(SubarrayWithGivenSum)
add_subdirectory(Burrows-Wheeler-Transformation)