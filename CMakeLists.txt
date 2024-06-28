cmake_minimum_required(VERSION 3.28)
project(raytracing)

set(CMAKE_CXX_STANDARD 20)

add_executable(raytracing
        #main.cpp
        math/vec3.cpp
        math/vec3.h
        math/ray.h
        test/test_vec3.cpp
        test/test_ray.cpp
)

find_package(fmt)
find_package(GTest)

target_link_libraries(raytracing fmt::fmt)
target_link_libraries(raytracing gtest::gtest)
target_link_libraries(raytracing d3dcompiler d3d12 dxgi gdi32)