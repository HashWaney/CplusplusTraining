//
// Created by hash on 2020/6/22.
//
#include <iostream>
#include <typeinfo>

using namespace std;

//RTTI：（Runtime Type Identification）：运行时类型信息程序能够使用基类的指针或引用来检验这些指针或者引用
//      所指的对象的实际派生类型。
// 在面向对象程序设计中，如果在运行时查询一个对象是否能作为某种多态类型使用
// 好比Java中的instanceof
// C++提供了dynamic_cast函数用于动态转型，相比C风格的强制类型转换
// 以及C++的reinterpret_cast
// dynamic_cast提供了类型安全检查，是一种基于能力查询的转换，所以在多态类型间提倡。

class B {
    virtual void fun() {}
};

class C : public B {

};

// 在使用时需要注意：被转换的对象obj的类型T必须是多态类型，即T必须公有继承自其他类，或者T拥有虚函数（继承或者自定义——
// 若T为非多态类型，使用dynamic_cast会报错

// T1 为非多态类型
class T1 {

};

//T2 为非多态类型
class T2 : public T1 {

};

// T3 为多态类型
class T3 {
public:
    virtual void fun() = 0;
};

class T4 : public T3 { // 公有继承
    void fun() override {
        cout << "hello T4" << endl;
    }
};

class T5 : private T3 {
    void fun() override {

    }
};

int main() {
    B *b = new C;// 向上转型
    B &bb = *b;
    // 将B类型向下转型为C
    C *c = dynamic_cast<C *>(b);//向下转型
    if (c) {
        cout << "dynamic cast b to c is success" << endl;
    } else {
        cout << "sorry it's not work to dynamic cast" << endl;
    }
    try {

        C &cc = dynamic_cast<C &>(bb);
        cout << "Is ok to dynamic to C&" << endl;
    } catch (bad_cast badCast) {
        cout << "error cast :" << badCast.what() << endl;
    }

    T1 *t1 = new T2;

//    T2* t2 = dynamic_cast<T2*>(t1); //error 报错
    T3 *t3 = new T4;
    T4 *t4 = dynamic_cast<T4 *>(t3);

    //T3 *t32 = new T5; //error 私有继承 一定是要公有继承


    return 0;
}