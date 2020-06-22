//
// Created by hash on 2020/6/22.
//
// 1. C++ 与 C编译区别：
//  extern "C" ：用于C++链接在C语言模块中定义的函数
//  C++中文件函数编译后生成的符号与C语言生成的不同
//  比如int add(int a, int b) 函数经过C++编译器生成.o文件后，add会变成
//  add_int_int之类的，C的话会生成的_add，也就是说编译后，C与C++生成的符号不同
//  这就是导致一个问题：如果C++中使用了C语言实现的函数，在编译连接的时候，会出错，提示找不到对应的符号
//  此时extern "C"就起作用了，告诉连接器去寻找_add这类的C语言符号，而不是经过C++修饰的符号。

// 2.C++调用C函数
// C++调用C函数的例子：
#include "iostream"

using namespace std;
extern "C" {
#include "add.h"
}


int main() {
    int y = add(2, 3);
    cout << ">>>>>extern c <<<<<<" << y << endl;//>>>>>extern c <<<<<<5


    // 1. gcc -c add.c === > add.o gcc 编译工具 -c compile 编译.c文件 ==》 生成一个.o文件的
    // 2. g++ 12_extern.cpp add.o -o main ===> g++  将add.o 链接到12_extern.cpp文件中参与编译，-o output输出文件 main 可执行文件名称
    // 3. 命令行中直接运行这个可执行文件main 得到结果

    return 0;
}