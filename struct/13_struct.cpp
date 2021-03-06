//
// Created by hash on 2020/6/22.
//
// 1. C中的Struct
// 在C中struct 单纯的用作数据的复合类型，在结构体中声明的只能将不同的数据成员放入而不能将函数放入
// 在C结构体中不能使用C++访问修饰符，public ， protected，private 在C++中可以使用
// C中定义结构体变量，必须加struct
// 如果结构体名字与函数名称相同，可以正常运行且正常调用，即struct Base void Base(){}
// 2. C++中的Struct
// C++结构体中不仅可以定义数据，还可以定义函数
// C++结构体中使用访问修饰：private 、public 、protected
// C++结构体中可以直接使用不同struct，但是由同名的函数，或者其他，就需要带上struct

//3. Strcut 与 class 区别
// struct更适合看成一个数据结构的实现体，class 更适合看成一个对象的实现体
// 最本质的一个区别：默认的访问控制，默认的继承访问权限
// struct是public， class 是private
// struct作为数据结构的实现体，它默认的数据访问控制是public，而class作为对象的实现体，默认的成员变量访问控制是private的


#include "stdio.h"

struct Base {
public:
    int v;
    long a;
    void fnc3() {
        printf("%s\n", "struct invoke fnc3 : hello world");
    };

//    private int nb;
private:
    int aa;

    void fnc() {
        printf("%s\n", "hello world");
    };
};

void Base() {
    printf("$$$function Base %s\n", "hello Base");
};

int main() {
    struct Base base;
    base.v = 1;
    base.fnc3();
    printf("$$$struct Base %d\n", base.v);
    Base();
    return 0;
}