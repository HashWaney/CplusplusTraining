//
// Created by hash on 2020/6/20.
//

// inline: 内联能够提高函数效率，但是并不是所有的函数都定义成内联函数，内联是以代码（复制）为代价
//         仅仅省去了函数调用的开销，从而提高函数的执行效率。
//         - 如果执行函数体内代码的时候相比函数调用开销大，那么效率就低下
//         - 另一方面，每一处内联函数的调用都要复制代码，将使得程序总代码量增大，消耗更多内存空间。

// 不适用内联情况
// - 如果函数体内代码比较长，内联将导致内存消耗代价比较高
// - 如果函数体内出现循环，那么执行函数体内代码的时间要比函数调用的开销大。

// 编译器对inline函数的处理步骤：
//1。 将inline函数体复制到inline函数调用点处；
//2。 为所用inline函数中的局部变量分配内存空间
//3。 将inline函数的输入参数和返回值映射到调用方法的局部变量空间中
//4。 如果inline函数有多个返回点，将起转变为inline函数代码块末尾的分支（使用goto）？？？

// 1. 类中内联

// 2. 虚函数（virtual)
// 虚函数可以是内联函数，内联是可以修饰虚函数的，但是当虚函数表现多态性的时候不能内联
// 内联是在编译器时期内联的，而虚函数的多态性是运行期，编译器无法知道运行的调用哪个代码。因此虚函数表现为多态性时（运行时）不可以进行内联
// inline virtual 唯一可以内联的时候是：编译器知道所调用的对象是哪个类；只有在编译器具有实际对象而不是对象的指针或者引用时才会发生。


#include "iostream"

using namespace std;


class A {

public:
    void f1(int x);

    /**
     * @brief 类中定义了的函数是隐式内联函数,声明要想成为内联函数，必须在实现处(定义处)加inline关键字。
     *
     * @param x
     * @param y
     */
    inline int HaHa(int x, int y) ///< 定义即隐式内联函数！
    {
        return x * y;
    };

};

class VirtualBase {
public:
    VirtualBase() {

    }

    inline virtual void who() { // 虚方法被inline修饰。
        cout << " i am virtual base class\n";
    }

    virtual ~VirtualBase() {

    }
};

// 继承 类比Java中的extends 父类要声明为public 不然子类无法继承
class VirtualSample : public VirtualBase {
public:
    VirtualSample() {

    }

    inline void who() {
        cout << " i am virtual sample class \n";
    }


};


int Foo(int x, int y); // 函数声明

inline int Foo(int x, int y) { // 函数定义
    cout << "inline function start " << endl;
    return x + y; // 内联函数的函数体
}

inline void A::f1(int x) {

}

int main() {
    A a;
    cout << ">>>>>>normal function<<<<<<<<" << endl;
    cout << "执行结果： " << a.HaHa(1, 2) << endl;

    cout << ">>>>>>>inline function<<<<<<<<" << endl;
    cout << "执行结果：" << Foo(3, 5) << endl;

    // 此处的虚函数who() 是通过类(VirtualBase)的具体对象（virtualBase)来调用，编译期间就能确定类型为VirtualBase，
    // 所以它是可以内联的，但最终是否内联取决于编译器

    VirtualBase virtualBase;
    virtualBase.who();

    VirtualBase *p = new VirtualSample();
    // 此处的虚函数是通过指针调用的，呈现多态性，需要在运行期间才能确定，所以不能内联
    p->who();

    // VirtualBase有析构函数，所以delete时，会先调用派生类（VirtualSample）的析构函数，在调用基类的析构函数，防止内存泄漏
    delete p;
    p = nullptr;


    return 0;
}