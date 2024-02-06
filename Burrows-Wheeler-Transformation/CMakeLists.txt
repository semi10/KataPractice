cmake_minimum_required(VERSION 3.8)

set(This Burrows-Wheeler-Transformation)

set(Headers 
    Burrows-Wheeler-Transformation.hpp
)

set(Sources
    Burrows-Wheeler-Transformation.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
)

add_test(
    NAME ${This}
    COMMAND ${This}
)