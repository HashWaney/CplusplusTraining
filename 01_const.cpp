//
// Created by hash on 2020/6/18.
//

// 1。定义常量
//const int a = 10;

// 2。 类型检查

// 3。 防止修改，起保护作用，增加程序健壮性
//void f(const int i) {
//    //Cannot assign to variable 'i' with const-qualified type 'const int
//    i++; // error
//}

// 4。 可以节省空间，避免不必要的内存分配
// const 定义的常量从汇编的角度来看，只是给出了对应的内存地址，
// #define 给出的是立即数，
// const定义的常量会在程序运行过程中只有一份拷贝，
// #define定义的常量在内存中有若干个拷贝。

//5。const 对象默认 是文件局部变量
// 非const 变量默认为extern 要使得const变量能够在其他文件中被访问，必须在文件中显示的指定为extern

//6。定义常量
const int b = 1;
//b =1; // error 不能在给一个const修饰的变量赋值。因为被修饰的变量初始化之后的值不能在被修改

//const int a,j =0; a为常量，必须进行初始化

// 7。指针与const

// const 位于*的左侧，就是const用来修饰指针所指向的变量
// 被const修饰的又是常量，所以指针指向的是常量。即指向常量的指针
const char *a; // 指向const对象的指针或者说指向常量的指针
char const *j; //

// const位于*的右侧，const修饰的变量需要初始化，
const char * const p= nullptr;




// file.cpp
// int ext;

// file2.cpp
#include<iostream>

extern const int const_ext;
extern int ext;

int main() {
//    std::cout << (ext + 10) << std::endl; // file.cpp 中的ext的值加上10
//    std::cout << (const_ext + 10) << std::endl; // file.cpp 中的ext的值加上10
    // 字符串拼接，std::cout<<bbb<<aaa<<ccc<<....<<std:endl;

    //未被const修饰的变量不需要extern修饰*查看01_const_extern.cpp文件，
    // 然而const常量就需要被显示声明extern，并且需要初始化，因为常量在定义后就不能被修改，所以定义时必须初始化
    std::cout << "非const修饰->" << ext + 10 << std::endl;
    std::cout << "const修饰->" << (const_ext + 10) << std::endl;
}

