//
// Created by hash on 2020/6/23.
//

//1.引用与指针
//  int &r; 不合法，没有初始化引用
//  int* p; 合法，但p为野指针，需要注意
// 即 引用必须初始化，不能为空，不能更换目标，是哪个类的引用就是哪个类的
//    指针可以不初始化，可以为空，可更换目标（因此在使用的时候需要进行判空处理）
void test_ptr(int *p) {
    if (p != nullptr) {
        *p = 4; //更换指针p的内容

    }
}

void test_ref(int &r) {
    r = 43;
    return;
}

// 引用不能更换目标
// 指针可以随时改变指向，但是引用只能指向初始化时指向的对象，无法改变

/**
 * @author HashWaney
 * @time 2020.6.23 18:04
 * @desc pointer and reference
 */
void feature_life() {
    int child = 1;
    int adult = 2;
    // child live a happy life
    int &child_life = child;
    //then, As time flows, child become a adult, adapter to the adult_life。
    int *adult_life = &child;
    //child ->grew up -->become adult，live the adult_life.
    adult_life = &adult;
    //In fact ,child still the boy，but he become an adult,he always miss the child_life.
    child_life = adult;
    //so，who are u? be a child or adult? are u happy？
}

// 2.引用
// 左值： 常规引用；一般表示对象的身份，

#include "iostream"

using namespace std;

class Copyable {
public:
    Copyable() {}

    Copyable(const Copyable &o) {
        cout << "Copied" << endl;
    }
};

Copyable ReturnValue() {
    cout << "return instance" << endl;
    return Copyable(); // 返回一个临时对象
}

void AcceptVal(Copyable a) {
    cout << "AcceptVal" << endl;
}


void AcceptRef(const Copyable &a) {
    cout << "AcceptRef" << endl;
}

int main() {
    cout << "pass by value:" << endl;
    AcceptVal(ReturnValue());
    cout << "pass by reference:" << endl;
    AcceptRef(ReturnValue());
    return 0;
}