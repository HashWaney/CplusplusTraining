//
// Created by hash on 2020/6/23.
//

#include "iostream"

using namespace std;
//using namespace Color; //error

// 作用域不受限
enum TYPE {
    RED = 15,
    YELLOW,
    BLUE
};
//namespace： 限制你的作用域，解决作用域不受限
namespace Color {
    enum TYPE {
        RED = 15,
        YELLOW,
        BLUE
    };
}
/**
 * 如果上述的using namespace Color
 */
struct Color2 {
    enum TYPE {
        RED = 20,
        YELLOW,
        BLUE
    };

    void print() {
        cout << "Color2 print" << endl;
    }
};

// C++11的枚举类
// 等价于enum class Color4:int
enum class Color4 {
    RED = 3,
    YELLOW,
    BLUE
};

enum class Color6 : char;// 前向声明

//定义
enum class Color6 : char {
    RED = 'r',
    BLUE
};


//2 类中的枚举类型：
//  1。希望某些常量只在类中有效（作用域在类的内部，常量=== 不变）----》const修饰数据成员来实现。
//     const数据成员只在某个对象生存期内是常量，类实例化之后的对象是一个生存期的，对于整个类来说是可变的
//     因为类可以创建多个对象，不同的对象其const数据成员的值可以是不同的
// 2。不能在类声明中初始化const数据成员，因为类的对象未被创建时，编译器不知道SIZE的值是多少，
//    如果说const前面加上一个static，静态变量，编译器是可以知道SIZE的值。如果说不能加（不让加）
class A {
//     const int SIZE = 100;   // 错误，企图在类声明中初始化 const 数据成员

    //如果说加上了static ，这个const修饰的成员就是类成员了，那么随着类的生命周期而进行最终的销毁。
    static const int SIZE = 100;
    int array[SIZE];  // 错误，未知的 SIZE
};

// 3。在类的构造函数的初始化列表中进行
class V {

public:
    V(int size);

    const int SIZE;


};

// 构造函数的定义
V::V(int size) : SIZE(size) {
    cout << "V construct param size " << size << endl;
}

// 用类中的枚举常量来实现类中的恒定的常量
class Person {
public:
    typedef enum {
        BOY = 0,
        GIRL
    } SEX_TYPE;
};

// 枚举常量不会占用对象的存储空间，在编译时被全部求值
// 枚举常量的缺点：隐含数据类型是整数，其最大值有限，且不能表示浮点数。

int main() {

    // 定义新的枚举变量
    Color::TYPE color = Color::RED;
    cout << "namespace Color " << color << endl;

    // 结构体
    Color2 color2;
    color2.print();
    cout << "struct Color " << color2.RED << endl;


    //enum class  int C11
    Color4 color4 = Color4::RED;

//    cout << "enum class c11 Color " << color4 << endl; //error 不能隐式转换成其他类型
    cout << "enum class c11 Color " << static_cast<int>(color4) << endl; // 必须强制转换为定义的int类型


    // enum class char C11 可以指定特定类型来存储enum。enum 也是用基本类型数据来存储的，char int float 来代表枚举
    char c = static_cast<char>(Color6::RED);
    cout << "enum class c11 Color get char '" << c << "'" << endl;
    // V::V(int size):SIZE(size){}
    V v(199);
    Person p;
    cout << "Person Sex:" << Person::BOY << endl;
    return 0;

}