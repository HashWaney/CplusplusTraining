//
// Created by hash on 2020/6/22.
//
// 1.断言 是宏，不是函数，原型定义在C、C++中，其作用是如果它的条件返回错误，终止程序执行。

#include "stdio.h"
#define NDEBUG // 加载assert.h 的include之前，忽略assert断言作用
#include "assert.h"

int main() {

    int  x =9;

    x =1;
    assert(x==9);//Assertion failed: (x==9), function main, file /Users/wangqing/Desktop/JNI/CPP/Review/assert/11_assert.cpp, line 14.



    return 0;
}