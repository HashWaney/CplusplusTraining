//
// Created by hash on 2020/6/22.
//
//
int add_cpp(int x, int y);
#include "stdio.h"
int main() {

    // 1. 首先将cpp文件编译成一个.o文件 g++ -c haha.cpp
    // 2. 然后编译c文件 输出一个可执行文件 gcc 12_extern_xxx.c haha.o -o main
    // 3. 执行可执行文件main 获取结果 命令行中直接输入可执行文件名称 比如 main 然后回车
   printf("c invoke cpp function result %d\n",add_cpp(2, 4));
    return 0;
}