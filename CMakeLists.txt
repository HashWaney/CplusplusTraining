cmake_minimum_required(VERSION 3.16)
project(Review)

set(CMAKE_CXX_STANDARD 11)


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
add_executable(pure_abstrace
        pure_abstrace/06_single_virtual.cpp
        )
add_executable(virtual_impl pure_abstrace/06_impl_abstract.cpp)

add_executable(virtual_become_abstract pure_abstrace/06_virtual_become_abstract.cpp)

add_executable(vptr_vtable vptr_vtable/07_vtable.cpp)

add_executable(virtual virtual/08_virtual.cpp)
add_executable(cast typecast/09_type_cast.cpp)
add_executable(volatile volatile/10_volatile.cpp)
add_executable(assert assert/11_assert.cpp)
#add_executable(extern extern/12_extern_cpp_invoke_c.cpp
#        extern/add.c)
#
#add_executable(extern c_extern/12_extern_c_invoke_cpp.c
#        c_extern/haha.cpp)

add_executable(struct struct/13_struct.cpp)
add_executable(union union/14_union.cpp)
add_executable(poly Polymorphism/15_c_poly.c)
add_executable(cpppoly Polymorphism/15_cpp_poly.cpp)
add_executable(explicit explicit/16_explicit.cpp)
add_executable(friend friend/17_friend.cpp)
add_executable(using using/18_using_global.cpp)
add_executable(using2 using/18_using_change_visit.cpp)
add_executable(double_colon double_colon/19_double_colon.cpp)
add_executable(enum enum/20_enum.cpp)
add_executable(decltype decltype/21_decltype.cpp)
add_executable(referptr referptr/22_referptr.cpp)
add_executable(macro macro/23_macro.cpp)
add_executable(DailyPractice_print DailyPractice/day1/打印练习.cpp)
add_executable(DailyPractice_algorithm DailyPractice/day2/二进制求和.cpp)
