//
// Created by hash on 2020/6/23.
//


#include <iostream>

//#define global 3
using namespace std;

void func1() {
    cout << "global::func" << endl;
}

namespace part1 {
    void func1() {
        cout << "part1::func" << endl;
    }
}

namespace part2 {
#ifdef  isPart
    using part1::func1;
#elif global
    using ::func1;

#else
    void func1()
    {
        cout<<"other::func"<<endl;
    }
#endif

}

int main() {
    /**
     * 这就是为什么在c++中使用了cmath而不是math.h头文件
     */
    part2::func1(); // 会根据当前环境定义宏的不同来调用不同命名空间下的func()函数
    return 0;
}