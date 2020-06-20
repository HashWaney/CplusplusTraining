//
// Created by hash on 2020/6/20.
//
// 静态变量：函数中的变量，类中的变量
//  - 函数中的静态变量：
// 当变量声明为static，空间将在程序的生命周期内分配，即使多次调用该函数，
// 静态变量的空间也只能分配一次，前一次调用中的变量值通过下一次函数调用传递
//  - 类中的静态变量：
//由于声明为static的变量只被初始化，因为它们在单独的静态存储中分配了空间，因此类中的
// 静态变量由对象共享，
// 也就是说该静态变量可以存储先前函数的状态。
// 静态类的成员：类对象和类中的函数
// - 类对象为静态
//   就像变量一样，对象也在声明为static时具有范围，知道程序的生命周期（也即是static声明的变量，生命周期是从被使用的时候到程序结束）
// - 类中的静态函数
//   静态成员函数不依赖与类的对象，允许静态成员函数仅仅能访问静态成员变量或者其他静态成员函数。无法访问非静态成员变量或其他非静态成员函数。





#include "string"
#include "iostream"

using namespace std;

class Color {
public:
    static int i;

    Color() {

    };

};

class TestNonStatic {
public:
    int i = 0;

    TestNonStatic() {
        i = 0;
        cout << " 进入构造中<<<< " << endl;
    };

    ~TestNonStatic() {
        cout << " 进入析构中<<<< " << endl;
    };
};

 class TestStatic {
public:
     TestStatic() {
        cout << " 进入到static构造中<< " << endl;

    };

    ~TestStatic() {
        cout << " 进入到static析构中<< " << endl;
    }
};

void demo() {
    // static variable
    static int count = 0;
    cout << "static variable  before " << count << " " << endl;
    // 循环调用demo这个函数，count的值会从上一次的值进行变换。
    count++;
    cout << "static variable  after " << count << " " << endl;


    cout << " -----------------------------------------------------" << endl;


    int count2 = 0;
    cout << "normal variable  before " << count2 << " " << endl;

    count2++;
    cout << "normal variable  after " << count2 << " " << endl;

    cout << " -----------------------------------------------------" << endl;
    //static variable  before 0
    //static variable  after 1
    // -----------------------------------------------------
    //normal variable  before 0
    //normal variable  after 1
    // -----------------------------------------------------
    //static variable  before 1
    //static variable  after 2
    // -----------------------------------------------------
    //normal variable  before 0
    //normal variable  after 1
    // -----------------------------------------------------
    //static variable  before 2
    //static variable  after 3
    // -----------------------------------------------------
    //normal variable  before 0
    //normal variable  after 1
    // -----------------------------------------------------
    //static variable  before 3
    //static variable  after 4
    // -----------------------------------------------------
    //normal variable  before 0
    //normal variable  after 1
    // -----------------------------------------------------
    //static variable  before 4
    //static variable  after 5
    // -----------------------------------------------------
    //normal variable  before 0
    //normal variable  after 1
    // -----------------------------------------------------

}

int Color::i = 44;

int main() {
    for (int i = 0; i < 5; ++i) {
        demo();
    }

    Color color1;
    Color color2;

    color1.i = 1;
    color2.i = 2;
    // 最后被更新为2 所以并没有生成多个副本 即 44 1 这个两个副本。

    int x = 0;
    if (x == 0) {
        TestNonStatic nonStatic; // 可以看出非静态的对象的生命周期只在if代码块中。
        // 进入构造中<<<<
        // 进入析构中<<<<
    }
    int y = 0;
    if (y == 0) {
       static TestStatic testStatic; // 声明该实例为static的，可以看出打印的结果为
       // 进入到static构造中<<
        // color1.i-> 2 color2.i-> 2
        // 进入到static析构中<<  // 说明了函数执行完之前一步是调用了该实例的析构函数。即生命周期与程序的结束同步。
    }

    cout << " color1.i-> " << color1.i << " color2.i-> " << color2.i << endl;
    // color1.i-> 2 color2.i-> 2
    return 0;
}