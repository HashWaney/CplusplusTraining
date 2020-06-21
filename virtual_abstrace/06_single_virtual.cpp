//
// Created by hash on 2020/6/21.
//

//1.纯虚函数与抽象类：C++中的纯虚函数(或抽象函数）
// 纯虚函数： 没有函数体的虚函数 ：通过赋值0来声明纯虚函数
// 抽象类： 包含纯虚函数的类
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
    ~VirtualImpl(){

    }
    void show() override {
        cout << " 派生类 实现 纯虚函数 " << endl;
    }
};

int main() {
//    VirtualImpl aVirtual;
//    aVirtual.show();
    cout<<">>>>>>>>>>派生类指针实现纯虚函数调用<<<<<<<<<<<<<"<<endl;
    VirtualClass*  pVirtual = new VirtualImpl();
    pVirtual->show();
    cout<<">>>>>>>>>>派生类实例实现纯虚函数调用<<<<<<<<<<<<<"<<endl;
    VirtualImpl aVirtual;
    aVirtual.show();
    return 0;
}
