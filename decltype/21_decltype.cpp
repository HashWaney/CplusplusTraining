//
// Created by hash on 2020/6/23.
//
// decltype:编译时进行了类型推导=== 为了泛型编程，RTTI机制无法满足这样的需求，在非泛型编程中，类型是确定的，不需要进行推导
// 1. decltype的作用：查询表达式的类型
//    decltype(expression): 返回expression表达式的类型。并不会对表达式进行"求值"
int i = 4;
decltype(i) a; // 推导结果为int，a的类型为int

// 2.与using/typedef合用，用于定义类型
using size_t = decltype(sizeof(0)); // sizeof(a)返回值为size_t类型
using ptrdiff_t = decltype((int *) 1 - (int *) 0);//指针偏移量
using nullptr_r = decltype(nullptr);// 定义一个空指针
//vector<int> vec;

//typedef decltype(vec.begin()) vectype;
//for(vectype i = vec.begin;i!=vec.end;i++){
//
//}
// 这样和auto一样，提高了代码的可读性

//3。重用匿名类型
struct {
    int s;
    double d;
} aa;
decltype(aa) as;// declare type 定义一个上面的匿名的结构体
// 即你使用的时候直接as来访问其中定义好的成员，相当于是重用了这个结构体。



// 4.泛型编程中结合auto，用于追踪函数的返回值类型
template<typename T>
auto multiply(T x, T y) -> decltype(x * y) {
    return x * y;
}

#include "iostream"
#include "vector"

using namespace std;

int main() {
    as.s = 332;
    aa.s = 1;
    int nums[] = {2, 3, 4};
    vector<int> vec(nums, nums + 4);
    vector<int>::iterator it;
    for (it = vec.begin(); it != vec.end(); it++) {
        cout << "iterator element :" << *it << "\n";
    }
    cout << endl;

    using nullptr_t = decltype(nullptr);
    nullptr_t nu;
    int *p = NULL;
    if (p == nu) {
        cout << "null pointer bingo\n" << endl;
    }
    typedef decltype(vec.begin()) vectype;
    //这样做的好处就是我不需要知道vector中存储的是什么类型，直接获取其类型
    // vec.begin()获取第一个元素，通过typedef 和 decltype 来定义类型，
    // 最后完成遍历，不需要知道具体的类型，通过类型推导就可以得出vector中的类型
    for (vectype i = vec.begin(); i != vec.end(); i++) {
        cout << "vect type " << *i << "\n";
    }
    cout << endl;

    cout << "直接使用aa===" << aa.s << endl;

    cout << "直接使用as===" << as.s << endl;

    int x = multiply(4, 2);

    int i = 3;
    cout << "multiply =" << x << endl;

};