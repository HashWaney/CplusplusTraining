cmake_minimum_required(VERSION 3.16)
project(Review)

set(CMAKE_CXX_STANDARD 11)

add_executable(Review main.cpp)
add_executable(const
        const/01_const.cpp const/01_const_extern.cpp)
add_executable(static
        static/02_static.cpp)

add_executable(this
        this/03_this.cpp)

add_executable(inline
        inline/04_inline.cpp)

add_executable(sizeof
        sizeof/05_sizeof.cpp)