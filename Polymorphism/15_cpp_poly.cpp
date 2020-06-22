//
// Created by hash on 2020/6/23.
//
//1.C++中的多态：在C++中会维护一张虚函数表，父类指针或者引用是可以指向子类对象
// 如果一个父类的指针或引用调用了父类的虚函数则该父类的指针会在自己的虚函数表中查找自己的函数地址
// 如果该父类对象的指针或者引用指向了子类的对象，并且子类已经重写了父类的虚函数，则该指针会调用子类的已经重写的虚函数
#include "iostream"

using namespace std;

class A {
public:
    virtual void f() {
        cout << "Base A::f()" << endl;
    }
};


class B : public A { // 必须是共有继承，否则后面调用不到，class默认为私有继承

    void f() override { // 虚函数实现，子类中的virtual关键字木有
        cout << "Sample B::f()" << endl;
    }
};

int main() {
    A a; // 基类对象
    B b; // 派生类对象

    A *aa = &a;//父类指针指向父类对象
    aa->f();

    aa = &b;// 父类指针指向子类对象，多态实现
    aa->f();// 调用派生类同名函数

    return 0;
}


