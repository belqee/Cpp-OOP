cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)

project(Life)

set(exe_name ${PROJECT_NAME})

set(test_name test)

add_library(corelib OBJECT GameLife.cpp )

add_executable(${exe_name} main.cpp)
target_link_libraries(${exe_name} corelib)