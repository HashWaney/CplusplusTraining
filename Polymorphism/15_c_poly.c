//
// Created by hash on 2020/6/23.
//

//C语言中没有class类这个概念，但是有结构体struct，使用struct模拟：使用函数指针把属性与方法封装到结构体

// 1。 继承 ：结构体嵌套
// 2。 多态 ：类和子类的函数指针不同。
//          在C语言的结构体内部是没有成员函数的，如果要实现这个父结构体和子结构体共有的函数？
//          考虑使用函数指针来模拟，缺陷：父子各自的函数指针，不是类似C++中维护的虚函数表而是一块
//          物理内存，如果模拟的函数过多，不易维护
// 注意：模拟多态。必须保持函数指针变量对齐（在内容上完全一致，而且变量对齐也完全一致）否则父类指针指向子类对象，崩溃

#include "stdio.h"

typedef void (*print)();

// parent
typedef struct A_ {
    print p;

} A;

// child
typedef struct B_ {
    A _b; //在子类中定义一个基类的对象即可实现对父类的继承
} B;


void FuncA() {
    printf("%s\n", "Base A :: fun");

}

void FuncB() {
    printf("%s\n", "Sample B :: fun");
}

int main() {
    A a;
    B b;
    a.p = FuncA;
    b._b.p = FuncB; // 将函数地址赋给给函数指针

    A *pa = &a;
    pa->p();

    pa = (A *) &b;//父类指针指向子类对象，类型不匹配，向上强转

    pa->p();
    return 0;
}