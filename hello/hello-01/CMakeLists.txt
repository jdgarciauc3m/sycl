cmake_minimum_required(VERSION 3.21)
project(hello_01)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors)

set(CMAKE_CXX_COMPILER dpcpp)
SET(CMAKE_CXX_FLAGS "-fsycl -fsycl-unnamed-lambda")

add_executable(hello_01 main.cpp)
target_link_libraries(hello_01 OpenCL sycl)
