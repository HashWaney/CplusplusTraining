//
// Created by hash on 2020/6/23.
//

//explicit显示关键字
// explicit修饰构造函数，可以防止隐式转换和复制初始化
// explicit修饰转换函数，可以防止隐式转换，语境转换除外

#include "iostream"

using namespace std;

struct A {
    A(int) {}

    operator bool() const {
        return true;
    }
};


class D {
public:
    explicit D() {

    }

    virtual void print() {
        cout << "D: print" << endl;
    }
};

class E : public D {
public:
    E() {

    }

    void print() {
        cout << "E:print" << endl;
    }
};

struct B {
    explicit B(int) {}

    explicit operator bool() const {
        return true;
    }
};

void doA(A a) {

}

void doB(B a) {

}

void doD(D d) {

}

int main() {

    D d;
    E e;
    D *d3 = &e;
    doD(e); // e instanceof d 肯定是可以的
    D d2; // 初始化一个实例
    d.print(); //对象调用函数
    d3->print(); //指针调用函数 其实还是调用基类的方法 除非是虚函数，那么指针就会


    A a1(1); // 直接初始化
    A a2 = 1;// 复制初始化
    A a3{1}; // 直接列表初始化
    A a4 = {1};//复制列表初始化
    A a5 = (A) 1;//允许static_cast显示转换
    doA(2.0f);//允许从float到A的隐式转换
    if (a1) { // 使用的是A的operator bool() 将A到bool的隐式转换，（过程肯定进行了A的判空处理 不然你的返回值到底是是真还是假呢）
        cout << "a1 is not null" << endl;
    }
    bool a6(a1);// 使用了operator bool 将A 隐士转换为bool
    bool a7 = a1;//使用了operator bool 将A 隐士转换为bool
    bool a8 = static_cast<bool>(a1);//使用static_cast进行直接初始化
    if (a8) {
        cout << "static cast A to bool" << endl;
    }
    bool a9 = dynamic_cast<A &>( a1);// dynamic_cast可以将(指针或引用）进行直接初始化，将A的引用复制给一个bool类型吗
    if (a9) {
        cout << "dynamic cast A reference to bool " << endl;
    }
    B b1(1); // 直接初始化
    if (b1) {
        cout << "b1 is not null " << endl;
    }

    //B b2 = 1; 错；被explicit修饰构造函数的对象不能被复制初始化

    B b3{1}; // 直接列表初始化
    // B b4 = {1}; // error 被explicit修饰的构造函数不能复制列表初始化
    B b5 = (B) 1; // 允许static_cast的显示转换

    doB(b1); // 因为b1 就是 B
//   doB(1); 1 不能隐式从int转换为B
    if (b1);// 按语境转换 B 转换为bool
    bool b6(b1);//按照语境将B转换为bool

    //bool b7 = b1;//不能将被explicit修饰的函数operator bool() 的对象b1隐式转换bool
    bool b8 = static_cast<bool >(b1);// 使用static_cast进行直接强转初始化
    if (b8) {
        cout << "static cast B to bool" << endl;
    }

    return 0;
}