//
// Created by hash on 2020/6/21.
//

//1.纯虚函数与抽象类：C++中的纯虚函数(或抽象函数）
// 纯虚函数： 没有函数体的虚函数 ：通过赋值0来声明纯虚函数
// 抽象类： 包含纯虚函数的类

// 抽象类只能作为基类来派生新类使用，不能创建抽象类的对象（也就是说抽象类不能直接实例化）
// 抽象类的指针和引用由抽象类派生出来的派生类的对象实例生成。
// Virtual * base =new VirtualImpl();

// 2.实现抽象类 查看 {@link 06_impl_abstract.cpp}
// 在成员函数内可以调用纯虚函数，在构造函数/析构函数内部不能使用纯虚函数
// 如果一个类从抽象类派生而来，必须实现基类中的所有纯虚函数，才能成为非抽象类

#include "iostream"

using namespace std;


class VirtualClass { // 抽象类
public: // 访问域 为 共有的
    virtual void show() = 0; // 纯虚函数
    // 其他成员
private: // 访问域 为 私有的
    int a;
protected: // 访问域 为 受保护的
    short s;
};

class VirtualImpl : public VirtualClass {

public:
    VirtualImpl() {}

    ~VirtualImpl() {

    }

    void show() override {
        cout << " 派生类 实现 纯虚函数 " << endl;
    }
};

int main() {
//    VirtualImpl aVirtual; === 等同于 aVirtual = new VirtualImpl()  Java中的 A a = new A();
//    aVirtual.show();
/**
 * 1. 抽象类只能作为基类来派生新类来使用
 * 2. 抽象类的指针和引用-> 由抽象类派生出来的类的对象？？？也就是这些抽象类的指针和引用是指向抽象类派生出来的派生类，不能指向抽象类
 */
    cout << ">>>>>>>>>>派生类指针实现纯虚函数调用<<<<<<<<<<<<<" << endl;
    VirtualClass*  pVirtual = new VirtualImpl();
//    VirtualClass virtualClass; ❌错误，抽象类，不能创建对象

//    VirtualClass aClass =new VirtualClass(); ❌ 错误，VirtualClass 是抽象类，不能创建对象。
//    VirtualClass *pVirtual; 这种方式不行 然后调用show方法直接挂掉了，不向下执行
    cout << ">>>>>>>>>>>>抽象类调用纯虚函数开始<<<<<<<<<<<" << endl;
    // 直接挂掉了？？？？
    pVirtual->show();
    cout << ">>>>>>>>>>>>抽象类调用纯虚函数结束<<<<<<<<<<<" << endl;
    cout << ">>>>>>>>>>派生类实例实现纯虚函数调用<<<<<<<<<<<<<" << endl;
    VirtualImpl aVirtual;
    aVirtual.show();
    return 0;
}
