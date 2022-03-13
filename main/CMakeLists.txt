cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 14)
project(main)

find_package(dependency)

add_executable(main main.cpp)
target_link_libraries(main Dependency::liba Dependency::libb)

install(TARGETS main)