//
// Created by hash on 2020/6/22.
//

// 1.volatile ：
//  - 防止编译器自作主张，进行编译优化，防止指令重排
//  - 对于修改的变量能够被外界所知（修改是对于外界是可察觉的）
//  - 多线程应用中被多个任务共享的变量，当多个线程共享某一个变量，该变量的值被某一个线程更改
//    应用volatile声明，防止编译器优化把变量从内存装入CPU寄存器中，当一个线程变更变量后，未及时同步到其他线程中
//    导致程序出错，volatile是让编译器每次操作该变量一定要从内存中真正取出，而不是使用已经存在寄存器中的值。


// 2.常见问题
// - 一个参数既可以是const还可以是volatile吗？ 可以，只读的状态寄存器，volatile的使用是因为它可能被意想不到的修饰
//   const保证程序不能试图去修改它
// -  一个指针可以是volatile吗？ 可以，中断服务子程序修改一个指向一个buffer的指针
// - 程序有什么错误
//  int square(volatile int * ptr){
//      return *ptr * *ptr; // ptr指向值的平方，
//  }
// ptr 指向一个volatile类型的参数，编译器将会优化为如下代码：
// int square(volatile int *ptr){
//  int a,b;
//  a= *ptr; // 可能会被改变，因此 a 和 b 的值可能不同
//  b= *ptr;
//  return a*b;
// }
// 修改如下：
// int square(volatile int *ptr){
//  int a =*ptr;
//  return a*a;
// }

// 3.volatile的使用
// -  是一种类型修饰符，用它声明的类型变量表示被某些编译器未知的因素更改，使用volatile告诉编译器不应该对这样的对象进行优化
// - volatile声明的变量，每次访问时都必须从内存中取出值（没有经过volatile修饰的变量，可能由于编译器的优化，从CPU寄存器中取值——
// - const可以是volatile（只读的状态寄存器）
// - 指针可以是volatile

#include "stdio.h"

int main() {
    const  int local = 10;
    const volatile int volatileLocal = 10;
    int *ptr = (int *) &local;
    int *volatilePtr = (int *) &volatileLocal;

    printf("Initial value of local= %d\n", local);//10
    printf("Initial value of volatileLocal= %d\n", local);//10


    *ptr = 100;
    *volatilePtr = 100;

    //const 修饰的变量不能被更改，即内容也不能被更改，const修饰的值直接从cpu寄存器中去取的

    printf("const  modify value of local =%d\n", local); // 10

    printf("const + volatile modify value of volatileLocal =%d\n", volatileLocal);//100






    return 0;

}