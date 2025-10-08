cmake_minimum_required(VERSION 3.14)
project(SixProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(six_main src/six.cpp main.cpp)


enable_testing()
add_subdirectory(test)