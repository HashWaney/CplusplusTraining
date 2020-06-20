//
// Created by hash on 2020/6/20.
//

// this指针的作用：
//1。 一个对象的this指针并不是对象本身的一部分，不会影响sizeof(对象)的结果；
//2。 this作用域是在类内部，当在类的非静态成员函数中访问类的非静态成员的时候，编译器会自动将对象本身的地址

// this指针的使用
// 1。 在类的非静态成员中返回类的本身的时候，直接使用return *this；
// 2。 在参数与成员变量名相同的时候，this->n=n (不能使用n=n 不然出现指向不明）

#include "iostream"
#include "cstring"

using namespace std;

class Person {
    // 类型定义 枚举

public:
    typedef enum {
        BOY = 0,
        GIRL = 1
    } SEX_TYPE;

    Person(char *n, int age, SEX_TYPE sexType) {
        //分配一块内存缓冲区
        this->name = new char[strlen(n) + 1];
        //调用拷贝函数拷贝字符串
        strcpy(this->name, n);
        this->age = age;
        this->sexType = sexType;
    }

    // 用const修饰说明这个变量不能被修改
    int getAge() const {
        return this->age;
    }

    Person &setAge(int age) {
        this->age += age;
        return *this;
    }

    ~Person() {
        // 构造中分配一个数组，因此在析构函数中手动释放数组
        delete[] name;
    }


private:
    char *name;
    int age;
    SEX_TYPE sexType;

};

int main() {
    Person p("zhangSan", 24, Person::BOY);
    cout << p.getAge() << endl;
    cout << p.setAge(10).getAge() << endl;
    return 0;
}