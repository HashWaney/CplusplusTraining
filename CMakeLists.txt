cmake_minimum_required(VERSION 3.16)
project(Review)

set(CMAKE_CXX_STANDARD 11)

add_executable(Review main.cpp)
add_executable(const  01_const.cpp
                      01_const_extern.cpp)
