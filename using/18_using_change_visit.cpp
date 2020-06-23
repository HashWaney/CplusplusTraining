//
// Created by hash on 2020/6/23.
//
#include "iostream"

using namespace std;

class Base {
public :
    Base() : value(11) {}

    virtual ~Base() {}

    void baseTest() {
        cout << "Base test" << endl;
    }

protected:
    int value; // 受保护的
};


// 默认为私有继承，
class Sample : Base {

public :
    void sampleTest() {
        cout << "Base value protected can be visit by Sample = " << value << endl;
    }

    using Base::value;
};

class Base1 {
public:
    Base1() : values(29) {

    }

    virtual ~Base1() {

    }

    void baseTest1() {
        cout << "Base1 test" << endl;
    }

private:
    int values;//私有
};

class Sample1 : private Base1 {
public :
//    using Base1::values;骗子。无法使用
};

class Base2 {
public:
    Base2() : value(20) {}

    virtual ~Base2() {}

    void test1() { cout << "Base test1..." << endl; }

private:  //私有
    int value;
};

/**
 * 子类对父类成员的访问权限跟如何继承没有任何关系，
 * “子类可以访问父类的public和protected成员，不可以访问父类的private成员”——这句话对任何一种继承都是成立的。
 *
 */
class Derived : Base2 {
public:
//    using Base2::value;// 无法访问父类的私有成员
    void test2() {
//        cout << "value is " << value << endl;
    }
};

int main() {
    Derived d;
//    d.test2();// error

    Sample s;
    s.sampleTest();


    return 0;
}