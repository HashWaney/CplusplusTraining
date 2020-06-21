//
// Created by hash on 2020/6/21.
//

#include "iostream"

using namespace std;

/**
 * 定义了一个抽象类: 纯虚函数使得一个类变成了抽象类;
 * 构造函数不能是虚函数， 而析构函数可以是虚析构函数
 *
 */
class Abstract {

public:
    Abstract() { cout << " Abstract Construct Begin" << endl; }

   /*virtual*/ ~Abstract() { cout << " Abstract Destruct Begin" << endl; }
   // Abstract Construct Begin
    // Sample Construct Begin
    // Sample Destruct Begin 也就是说当调用虚析构函数，在释放内存的时候，会先走派生类的析构函数（即派生类默认实现了析构函数，
    // 因为如果派生类不是抽象类，又必须实现虚函数）然后走抽象类的系统函数。这样做好处就是不会只会调用基类的析构函数（why，毕竟你声明的是一个基类指针）
    // override调用派生类的析构函数
    // 进行资源的释放，不需要自己手动调用。
    // Abstract Destruct Begin

};


class Sample : public Abstract {
public :
    Sample() { cout << " Sample Construct Begin" << endl; }

    ~Sample() {
        cout << " Sample Destruct Begin" << endl;
    }
};

/**
 * 抽象类 : 包含虚函数的类
 */
class Company {

private:
    char *name = "hash";
    int x;


public:
    virtual void showName() = 0;

    char *getName() {
        return name;
    }

    void setName(char *name) {
        this->name = name;
    }


    // 4. 抽象类可以有构造函数
    Company(int s) {
        this->x = s;
    }

    void printX() {
        cout << " Abstract class construct receive data from the child " << x << endl;
    }

};

// 如果不在派生类中覆盖纯虚函数，那么派生类也会变成抽象类
// 言外之意：就不能直接实例化该对象，即NotImplPureFun instance;// error
class NotImplPureFun : public Company {

};


class NetEasy : public Company {

private:
    int y;
public:

    void setName(char *n) {
        //分配一块内存缓冲区
        name = new char[strlen(n) + 1];
        //调用拷贝函数拷贝字符串
        strcpy(this->name, n);
    }

    void showName() override {
        cout << " company is " << getName() << endl;
    }

    // 将派生类中的i 传递给抽象类中的i
    NetEasy(int i, int y) : Company(i) {
        this->y = y;
    }

    ~NetEasy() {
        delete[] name;
    }


private:
    char *name;
};

int main() {
    // 抽象类的指针和引用 ==== 由抽象类派生出来的
    Company *company = new NetEasy(33, 24);
//    Company * com = new Company(); // error
//    Company c ; //error 不能创建抽象类的对象
    company->setName("net easy");
    company->printX();
    company->showName();

//    NotImplPureFun instance; // 不能创建抽象类对象

    NetEasy netEasy(1, 2);
    netEasy.setName("net easy");
    netEasy.showName();

    // Test for Pure Destruct
    Abstract *var = new Sample();
    delete var; // delete 触发的是析构函数。真正的释放资源是在析构函数中处理，delete只是一种通知行为。
    return 0;
}