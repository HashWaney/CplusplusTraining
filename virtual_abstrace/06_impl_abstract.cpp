//
// Created by hash on 2020/6/21.
//
//

#include "iostream"

using namespace std;

class A {
public:
    virtual void print() = 0;

    // 成员函数
    void impl() {
        cout << "A invoke print pure function start" << endl;
        this->print();
        cout << "A invoke print pure function end" << endl;
    }

    A() {
        //libc++abi.dylib: Pure virtual function called! 构造函数内部不能使用==>析构函数内部同样不能使用虚函数
        print();
    }
};

class B : public A {
    //派生类B 由 抽象类A 派生而来，必须要实现基类中的所有虚函数，才能成为非抽象类。
public:
    void print() override {
        cout << "B invoke print function" << endl;
    }


};


int main() {
    B b; // 实例化了一个B对象
    b.impl();
    return 0;
}
