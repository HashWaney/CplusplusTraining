//
// Created by hash on 2020/6/22.
//

// 1。 基础理论：
//  虚函数表：为了解决一个动态后期绑定方式的函数调用而提供的一种查找方式
// 1。1 理论前提：每一个使用了虚函数的类（从使用虚函数的派生类）都有自己的虚函数表，该表包含了由类的
//              对象调用的每一个虚函数，也就是说表中的每一个条目都是一个函数指针，对应着每一个虚函数

//1。2 编译器还会添加一个指向基类的指针（vptr) 这个指针会在创建类时候自动设置。用来指向该类的虚函数表

#include "iostream"
#include <stdio.h>

using namespace std;

/**
 *  函数指针：由上面分析可得：其实就是虚函数表中的每一个条目，该条目是一个函数指针，指向该类中的每一个使用的虚函数
 */
typedef void(*Func)();

/**
 * 基类：抽象类：因为定义了纯虚函数》》 如果没有定义纯虚函数而是只定义了虚函数，那么是不是不是抽象类，好比java中，它其实抽象方法是没有函数实体的，
 * 也就是这个虚函数到底是个啥？到底怎么定义呢？没有函数实体好比我们Java中的抽象方法，那么必然这个类是一个抽象类，同理，有函数实体的虚方法，是不是意味着
 * 该类不是一个抽象类呢？那纯虚函数也是虚函数的一种，对不对，只不过对应着纯虚函数没有函数实体，好比Java中该函数被abstract修饰，其他方法没有被abstract修饰
 * 解答：没有定义纯虚函数的类不是一个抽象类，也即是只用定义了纯虚函数的类才是一个抽象类。
 *
 */
class Base {
public:
    Base() {}

     ~Base() {}

    virtual void fun0() {
        cout << ">>>>>base : func0()<<<<<" << endl;
    }

    virtual void fun1() {
        cout << ">>>>>base : func1()<<<<<" << endl;
    }

    virtual void fun2() {
        cout << ">>>>>base : func2()<<<<<" << endl;
    }

//    virtual void fun3() = 0; // 纯虚函数，那么该类就是一个抽象类。 那么思考，如果不定义纯虚函数或者只定义虚函数，那么该类是否还是抽象类呢？

};

class Sample : public Base {

public:
    Sample() {};

    void fun0() {
        cout << ">>>>>Sample : fun0()<<<<<<" << endl;
    }
    void fun1() {
        cout << ">>>>>Sample : fun1()<<<<<<" << endl;
    }

    void fun2() {
        cout << ">>>>>>Sample :fun2()<<<<<<<" << endl;
    }
    ~Sample(){};




};

/**
 * 获取虚函数表中的虚函数地址
 * @param clazz
 * @param offset
 * @return
 */
Func getVirtualFunAddressInVTable(void *clazz, int offset) {
    cout << ">>>>>find the virtual func address in the vTable<<<<<" << endl;
    // 1. 要取出clazz中的vptr的地址值
    void *vptr_address = (void *) *(unsigned long *) clazz;
    // 2.vptr 是指向这个虚函数表的，通过offset就是这个虚函数在虚函数表中对应的位置，通过首地址+偏移量查找这个虚函数的地址
    void *fun_address = (void *) *((unsigned long *) vptr_address + offset);
    //3. 赋值给定义的函数指针
    printf("fun_address %p:\n", fun_address);
    return (Func) fun_address;
}

int main() {

    Base ptr; //
    Sample s;
    Base *pt = new Sample();// 基类指针指向派生类对象
    Base &p = ptr;//基类引用指向基类实例
    Base &pp = s;// 基类引用指向派生类实例
    cout << ">>>>>>基类对象直接调用<<<<<<<" << endl;
    ptr.fun1();
    cout << ">>>>>>基类对象调用基类实例(即基类引用指向基类实例)<<<<<" << endl;
    p.fun1();
    cout << ">>>>>>基类对象调用派生类实例并调用虚函数(即基类引用指向派生类实例)<<<<<" << endl;
    pp.fun1();
    cout << ">>>>>>基类指针指向派生类实例并调用虚函数<<<<<<<" << endl;
    pt->fun1();


    cout << "<<<<手动查找vPtr 和 vTable>>>>>" << endl;
    // offset = 0 第一个函数 pt其实就是这个类的指针
    Func fun1 = getVirtualFunAddressInVTable(pt, 0);
    // func 是一个函数指针，*指针 其实就是取指针中内容，由于func是一个函数的指针，取内容也就是取这个函数。
    (*fun1)();// 其实就是调用这个函数
    Func fun2 = getVirtualFunAddressInVTable(pt, 2);
    (*fun2)();
//    delete pt;
    return 0;
}