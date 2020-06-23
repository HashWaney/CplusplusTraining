//
// Created by hash on 2020/6/23.
//
// 联合（union）是一种节省空间的特殊的类，一个union可以有多个数据成员，
// 但是在任意时刻只有一个数据成员可以有值，
#include "iostream"

using namespace std;

typedef int (*Function)(int, int); // 定义一个函数指针

union {
    typedef int *fun(int x, int y);   // 定义一个指针函数

    typedef void(*Func)();

    int add(int x, int y) {
        return x + y;
    }


    class A {
    public:
        A() {

        }

        ~A() {

        }

        virtual void fun() {

        }
    };


    int x;


//    A& a; 不能含有引用类型的成员
//    virtual void x()=0; 不能有虚函数
} haha;

int adda(int x, int y) {
    return x + y;
}
void print()
{
    cout<<"test union function pointer"<<endl;
}

Function fp = &adda; // fp是一个函数指针 指向一个函数的地址，&adda就是取出adda对应的函数地址。
int main() {


    haha.x = 1;
//    haha.A  //error
//    haha.fun(2,3);//error
//    haha.function = ff(11, 22);
//    cout << *haha.function << endl;
    // Cannot create a non-constant pointer to member function//无法创建指向成员函数的非恒定指针
//    fp = &haha.add;//    Cannot take the address of an rvalue of type 'int'

    int a = (*fp)(1, 4444); // 函数指针的使用

    cout << "aaaaa === " << a << endl;

    return 0;
}
