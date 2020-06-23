//
// Created by hash on 2020/6/23.
//

// 友元函数：普通函数想访问某个类的私有或者是保护成员变量
// 友元类：类A中的成员函数访问类B中的私有或者保护成员

// 优点：提高了程序的运行效率

// 缺点：破坏了封装性，如果你都可以访问我私有成员，那我们封装的意义呢。但是
//      有时候不得不去破坏


//总结：能够访问私有成员-》破坏封装性-友元关系不可传递-友元关系的单向性。

// 友元定义在类（需要被友元的类）的外部，声明在类的内部
#include "iostream"

using namespace std;


class A {
private:
    int a;
public:
    friend int getData(A &a); //  声明 友元函数
    A(int a) : a(a) {

    }
};

//定义一个友元函数
int getData(A &c) {// 只能传引用，如果传递指针的话，私有的指针是无法访问(访问域是public)
    return c.a; // 这样就访问到了被友元类A的私有成员a
}



//2.友元类的声明在该类的声明中，而实现在该类外
// friend class <友元类名>;
// 比如类B是类A的友元，那么类B可以直接访问类A的私有成员.

//3.注意"
//1。友元关系没有继承性，假如类B是类A的友元，类C继承于类A，那么友元类B是无法直接访问类C的私有或保护成员
//2。友元关系没有传递性，假如类B是类A的友元，类C是类B的友元，那么友元C是无法直接访问类A的私有或保护成员 不存在友元的友元的这种关系。


class C {
public:
    C(int a) : aa(a) { // :aa == >私有成员 aa （a)方便给这个私有成员进行赋值操作
    }

    C() {}

    friend class E; ///如果不指定的话，在E中的return 函数会报错

private:
    int aa; // 私有成员
};

class E {
public :
    int getAa(C &c) {
        return c.aa;
    }
};

class F : public C {

public:
    F(int ff) : f(ff) {

    }

    F() {

    }

private:
    int f;
};


class H {

public :

    H(int hh) : h(hh) {}

    H() {}

    friend class I;

private:
    int h;
};

class I {

public:

    I(int ii) : i(ii) {
    }

    I() {}

    int getH(H &hh) {
        return hh.h;
    }

    friend class J;

private :
    int i;
};

class J {
public:
    int getI(I &ii) {
        return ii.i;
    }

    int getH(H &hh) {
//        return hh.h; 直接报错了，无法访问到类H的私有成员

    }

private:
    int j;
};

int main() {
    A a(12);
    cout << "访问友元类的私有成员 ：" << getData(a) << endl;

    C aa(222);
    E e;
    F f(22);
    cout << "友元类E 访问 类C的私有成员：" << e.getAa(aa) << endl;//友元类E 访问 类C的私有成员：222
    cout << "友元类E F是继承自C的访问 类F的私有成员 ：" << e.getAa(f) << endl;//友元类E 访问 类F的私有成员：0

    // 测试友元的传递性
    H h(33);
    I i(35);
    J j;
    cout << "友元类I 访问类H的私有成员:" << i.getH(h) << endl;

    cout << "友元类J 访问类I的私有成员:" << j.getI(i) << endl;
    cout << "友元类J 访问类H的私有成员：" << j.getH(h) << endl; // 32767


    return 0;

}

