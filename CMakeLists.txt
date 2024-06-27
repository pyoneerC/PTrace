cmake_minimum_required(VERSION 3.28)
project(raytracing)

set(CMAKE_CXX_STANDARD 20)

add_executable(raytracing
        vec3.cpp
        vec3.h
        ray.h
        test_vec3.cpp
)

find_package(fmt)
find_package(GTest)

target_link_libraries(raytracing fmt::fmt)
target_link_libraries(raytracing gtest::gtest)