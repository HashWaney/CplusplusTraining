//
// Created by hash on 2020/6/18.
//
using namespace std;
// 1。定义常量
//const int a = 10;

// 2。 类型检查

// 3。 防止修改，起保护作用，增加程序健壮性
//void f(const int i) {
//    //Cannot assign to variable 'i' with const-qualified type 'const int
//    i++; // error
//}

// 4。 可以节省空间，避免不必要的内存分配
// const 定义的常量从汇编的角度来看，只是给出了对应的内存地址，
// #define 给出的是立即数，
// const定义的常量会在程序运行过程中只有一份拷贝，
// #define定义的常量在内存中有若干个拷贝。

//5。const 对象默认 是文件局部变量
// 非const 变量默认为extern 要使得const变量能够在其他文件中被访问，必须在文件中显示的指定为extern

//6。定义常量
const int b = 1;
//b =1; // error 不能在给一个const修饰的变量赋值。因为被修饰的变量初始化之后的值不能在被修改

//const int a,j =0; a为常量，必须进行初始化

// 7。指针与const

//7.1 。 指向常量的指针
void _07_functestconstpointer() {
// const 位于*的左侧，就是const用来修饰指针所指向的变量
// 被const修饰的又是常量，所以指针指向的是常量。即指向常量的指针
    const char *a; // 指向const对象的指针或者说指向常量的指针
    char const *j; // 也就是说被const修饰的指针指向的内容不能随意更改。

// const位于*的右侧，const修饰的变量需要初始化，
    const char *const p = nullptr;

    // pointer 是一个指向int类型const对象的指针，const定义的是int类型，
    // pointer指向的是int对象类型，而不是pointer本身，所以pointer可以不用赋初始化值，但是不能通过
    // pointer去修改这个对象的值
    const int *pointer;
    //*pointer = 10; // 报错
    //pointer = 10; // 报错

    // 与const修饰不同的，是xx是一个普通的int类型指针，指针可以修改变量的值。
    int *xx;
    // 把int类型数据赋值给指针指向的内容
    *xx = 3;
    // 不能把int 类型数据赋值给int*类型
    int aa = 4;
    // xx =aa;// 报错
    //将aa的地址赋值给int*类型
    xx = &aa; // ok

    //也不能用void* 指针来保存const对象的地址，必须用const void* 类型来保存const对象的地址
    const int pa = 10;
    const void *pa_address = &pa;

//    void * pa_adsdress =&pa; // 报错

    //将非const对象的地址赋值给const对象的指针
    const int *ptr;
    int val = 4;
    ptr = &val; //ok

//    *ptr = 3; 不能使用const指针来修改基础对象val，
    // 可以通过指向非const对象的指针来修改以达到修改const指针指向的变量的值
    // 把val 的地址赋值给ptr2
    int *ptr2 = &val;
    // 修改ptr2的值 达到同步修改了 val的值，通过val的地址又赋值了ptr，即ptr、ptr2、val的值同步修改了
    *ptr2 = 34;

    // std::cout<<*ptr<<std::endl;

    // 总结：
    // 1。对于指向常量的指针，不能通过指针来修改对象的值
    // 2。不能使用void* 指针保存const对象的地址，必须使用 const void* 类型的指针保存
    // 3。非const对象的地址可以赋给指向const对象的指针


    // 常指针
    // 1。 const指针必须进行初始化，且const指针的值不能修改
    int num = 0;
    int *const ptr23 = &num; // const指针必须初始化，且const指针的值不能被修改
    int *change = &num;
    *change = 3;

    const int oo = 3;
//    int * const ott = &oo;// 不能将const int * 赋值给 int*
//    const int * ott = & oo;
//    const int * const ott2 =&oo;

    // 指向常量的指针
    const int ooo = 3;
    const int *const ptt = &ooo;
    //整理一下CPP中的赋值和指向的说法。比如ooo的地址赋值给了ptt，ptt就是指向了ooo对象
    // ptt是一个const指针，指向了int类型的const对象


    // 函数使用const
    // 1） const int
    const int func1(); //返回值为const int

    // 2）const int *
    const int *fun2();//指针指向的内容不变

    // 3）int * const
    int *const fun3(); //指针本身不可变


    // const修饰函数参数
    //1）传递过来的参数以及指针本身在函数内不可变
    void func3(const int var);// 传递过来的参数不可变，表明参数在函数体内不能被修改，var本身就是形参，在函数体内不会改变。
    // 包含传入的形参指针也是一样。输入参数采用的是"值传递" 由于函数将自动产生临时变量用于复制该参数，输入参数不需要被保护，
    // 所有不需要加const修饰
    void func4(int *const var3);//指针本身不可变？？？？指针本身不可变。言外之意是指针的地址不可变，内容可不可变呢？答可以经过上述分析，
    // 通过一个指向非const的指针来修改内容。达到指针对应地址的内容同步改变

    //2）参数指针所指的内容为常量不可变
    void mmcpy(char *dst, const char *src);
    //src 为输入参数，dst为输出参数，给src加上const修饰后，如果函数体内的语句试图改动src的内容，编译器抛出异常

    //3）参数为引用，为了增加效率同时防止修改,对于非内部数据类型的参数（也就是A不是基本数据类型）而言，像void func(A a)这样的声明的函数效率比较低下，
    // 因为函数体内将产生A类型的临时对象用于复制参数a（这句话也就是说在调用这个函数的时候，函数体内部会构造一个A类型的临时变量然后将这个临时变量用a来接收。）
    // 临时对象的构造，复制，析构过程都将消耗时间。这也就是为什么要传递引用 ，而不是传递的值的原因了，类似java中传递一个javabean。
    // 然后我们不希望这个引用被改变，因此加上const进行修饰，代表这个引用不能被修改
//    void func5(const A &a)
//  思考🤔？ 是否应该将void fun(int x) 改写为void fun(const int &x)以便提高效率？
// 不必要，因为内部数据类型（int？？ double ？？ float？？？ 基本数据类型吗？？？）不存在构造、析构的过程，而且复制也快。
// 值传递 和 引用传递效率几乎相同。

// 总结： 1、 如果函数传入一个指针，是否需要为指针加上const，把const 加在指针的前面 代表内容不能修改。 加载指针的后面代表指针本身不能被修改（即地址不可变）
//       2、 如果写的函数需要传入的参数是一个复杂类型的实例（即不是基本数据类型）传入的值参数（效率不高，在函数内部创建临时变量，经历构造，复制，析构等过程）
//          引用参数效率高（至少省了值传递的内部实现的一些细节） 为了引用不能被修改，需要加上const

}

// 8.类中使用cosnt
// 在一个类中，任何不会修改数据成员的函数都应该声明为const类型，
// 如果被const修饰的函数调用了非const成员函数，编译器将报错，
// 使用const修饰的成员函数被常成员函数，只有常成员函数才有资格操作常量和常对象，
// 没有使用const修饰的成员函数不能操作常对象，

extern  class Apple {
private:
    int pep[100];
public:
    Apple(int i);

    const int pep_num;

    void take(int num) const;

    int add(int num);

    int add(int num) const;

    int getCount() const;
};


#include<iostream>

extern const int const_ext;
extern int ext;

Apple::Apple(int i):pep_num(100) {

}
int Apple::add(int num) {
    take(num); // add 调用了const修饰的take方法，证明了非const对象可访问任意的成员函数。包括const成员函数。
}
int Apple::add(int num)const {
    take(num);
}

void Apple::take(int num) const{
    cout<<"take num "<<num <<endl;
}

int Apple::getCount() const{
    take(1);
//    add(1); // getCount 为 常成员函数调用了add 非const修饰的。const对象只能访问const成员函数
    return pep_num;
}






int main() {
//    std::cout << (ext + 10) << std::endl; // file.cpp 中的ext的值加上10
//    std::cout << (const_ext + 10) << std::endl; // file.cpp 中的ext的值加上10
    // 字符串拼接，std::cout<<bbb<<aaa<<ccc<<....<<std:endl;
    size_t len; // 8个字节

    // int 4个字节 void *
    // double 8个字节
    // float 4个字节
    // char 1个字节
    // short 2个字节
    // byte 1个字节
    // boolean 1个字节
    // long 8个字节
    char a1[] = {'a', 'c', 'd'};
    char a2[] = {'a', 'c', 'd'};
    int result = memcmp(a1, a2, sizeof(a1));
    if (!result) { // if（非0）0 代表false 非0 true
        cout << "compare: << " << result << endl;
    } else {
        cout << "compare : =" << result << endl;
    }

    int num = 0;
    int *const ptr23 = &num; // const指针必须初始化，且const指针的值不能被修改
    int *change = &num;
    *change = 3;
    cout << " ptr23 " << *ptr23 << endl;
    //未被const修饰的变量不需要extern修饰*查看01_const_extern.cpp文件，
    // 然而const常量就需要被显示声明extern，并且需要初始化，因为常量在定义后就不能被修改，所以定义时必须初始化
    std::cout << "非const修饰->" << ext + 10 << " == " << sizeof(len) << " == " << sizeof(ext) << std::endl;
//    memcmp() // 比较
    std::cout << "const修饰->" << (const_ext + 10) << std::endl;


    cout<<"-------const修饰类-------"<<endl;

    Apple apple(2);
    int count = apple.getCount();
    cout<<"count总数为 "<<count<<endl;

    apple.add(10);

    const Apple b (3);
    b.add(11);
    return 0;

}

