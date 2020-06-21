//
// Created by hash on 2020/6/21.
//

#include "iostream"

using namespace std;

class A {
public:
    virtual void print() = 0;

    void impl() {
        cout << "A invoke print pure function start" << endl;
        this->print();
        cout << "A invoke print pure function end" << endl;
    }

    A() {

    }
};

class B : public A {
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
