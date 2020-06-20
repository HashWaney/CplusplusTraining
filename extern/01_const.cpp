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
    char const *j; //

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
    int aa =4;
   // xx =aa;// 报错
    //将aa的地址赋值给int*类型
    xx =&aa; // ok

    //也不能用void* 指针来保存const对象的地址，必须用const void* 类型来保存const对象的地址
    const int pa =10;
    const void *pa_address = &pa;

//    void * pa_adsdress =&pa; // 报错

    //将非const对象的地址赋值给const对象的指针
    const int *ptr;
    int  val =4;
    ptr = &val; //ok

//    *ptr = 3; 不能使用const指针来修改基础对象val，
    // 可以通过指向非const对象的指针来修改以达到修改const指针指向的变量的值
    // 把val 的地址赋值给ptr2
    int *ptr2 = &val;
    // 修改ptr2的值 达到同步修改了 val的值，通过val的地址又赋值了ptr，即ptr、ptr2、val的值同步修改了
    *ptr2=34;

  // std::cout<<*ptr<<std::endl;

    // 总结：
    // 1。对于指向常量的指针，不能通过指针来修改对象的值
    // 2。不能使用void* 指针保存const对象的地址，必须使用 const void* 类型的指针保存
    // 3。非const对象的地址可以赋给指向const对象的指针


    // 常指针
    // 1。 const指针必须进行初始化，且const指针的值不能修改
    int num =0;
    int * const  ptr23 = &num; // const指针必须初始化，且const指针的值不能被修改
    int * change = &num;
    *change =3;

    const int oo = 3;
//    int * const ott = &oo;// 不能将const int * 赋值给 int*
//    const int * ott = & oo;
//    const int * const ott2 =&oo;

    // 指向常量的指针
    const int ooo = 3;
    const int * const ptt=&ooo;
    //整理一下CPP中的赋值和指向的说法。比如ooo的地址赋值给了ptt，ptt就是指向了ooo对象
    // ptt是一个const指针，指向了int类型的const对象


    // 函数使用const
    // 1） const int
    const int func1(); //返回值为const int

    // 2）const int *
    const int * fun2();//指针指向的内容不变

    // 3）int * const
    int * const fun3(); //指针本身不可变





}




// 解释： pointer 是一个指向int类型的const对象的指针
// const 定义的是int类型，pointer所指向的对象类型，而不是pointer本身



// file.cpp
// int ext;

// file2.cpp
#include<iostream>

extern const int const_ext;
extern int ext;


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

    int num =0;
    int * const  ptr23 = &num; // const指针必须初始化，且const指针的值不能被修改
    int * change = &num;
    *change =3;
    cout<<" ptr23 "<< *ptr23<<endl;
    //未被const修饰的变量不需要extern修饰*查看01_const_extern.cpp文件，
    // 然而const常量就需要被显示声明extern，并且需要初始化，因为常量在定义后就不能被修改，所以定义时必须初始化
    std::cout << "非const修饰->" << ext + 10 << " == " << sizeof(len) << " == " << sizeof(ext) << std::endl;
//    memcmp() // 比较
    std::cout << "const修饰->" << (const_ext + 10) << std::endl;

}

