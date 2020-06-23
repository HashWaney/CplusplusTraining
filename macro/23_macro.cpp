//
// Created by hash on 2020/6/23.
//
//1.宏中包含特殊符号
// 分为#，## \
// # 是"字符串化"的意思，出现在宏定义的#把后面的参数转换成一个字符串
// 只能用于传入参数的宏定义中，且必须置于宏定义体中的参数名之前

#include <iostream>
#include "string"
#include "stdio.h"

#define exp(s) printf("test s is %s\n",s)
#define exp1(s) printf("test s is %s\n",#s)
#define exp2(s) #s


// 2.符号连接操作符（##）
// ## 是一种分隔连接方式，作用是先分隔，然后进行强制连接，将宏定义的多个形参转换成一个实际参数名（拼接）
#define expA(s) printf("前缀加上后的字符串为:%s\n",gc_##s)  //gc_s必须存在
#define expB(s) printf("前缀加上后的字符串为:%s\n",gc_  ##  s)  //gc_s必须存在
// 注意事项1
#define gc_hello1 "I am gc_hello1"

// 3. 续行操作符(\) 当定义的宏不能用一行表达完整时候，可用"\"表示下一行继续此宏的定义
//    注意\前留空格
#define MAX(a, b)((a)>(b)?(a)\
:(b))


using namespace std;

int main() {
    exp("hello");
    exp1(helloworld);
    string str = exp2(abc aad); // 空格被忽略
    //当传入参数之间的有空格，只会保留一个，
    cout << str << " " << str.size() << endl;
    // 定义一个gc_xx格式的字符。
    const char *gc_xx = "I am la_la";
    // gc_##s s代表xx
    // 定义宏将xx传入到宏定义的参数中
    expA(xx);
    expB(hello1);

    int max_val = MAX(3, 5);
    cout << "max val = " << max_val << endl;

    return 0;
}