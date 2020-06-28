//
// Created by hash on 2020/6/23.
//
#include "iostream"

using namespace std;

// 关闭注释
#if 0
asd
#endif
//打开注释
//条件编译指令
#if 0
asData
#endif
#define DEBUG 0


// union 学习
// 具有相同的内存地址
union mdd {
    struct {
        float x;
        int y;
        int z;
    } var;
    int k;
} vx;

int main(int argc, char const *argv[]) {
    int i, j, k, f;
    for (i = 1; i <= 4; i++) {
        for (j = 1; j <= 30; j++) {
            cout << " ";
        }
        for (k = 1; k <= 8 - 2 * i; k++) {
            cout << " ";
        }
        for (f = 1; f <= 2 * i; f++) {
            cout << '*';
        }
        cout << endl;
    }
    for (i = 1; i < 4; i++) {
        for (j = 1; j <= 30; j++) {
            cout << " ";
        }
        for (f = 1; f <= 8 - 2 * i; f++) {
            cout << '*';
        }
        cout << endl;

    }
    //                                    **
    //                                  ****
    //                                ******
    //                              ********
    //                              ******
    //                              ****
    //                              **
    /**
     * asData:
     */
    cout << "union联合体相关信息" << endl;

    vx.var.x = 33.33f;
    vx.var.y = 2;
    vx.var.z = 3;
    if (DEBUG) {
        vx.k = 34; // 覆盖了第一个元素空间值：如何理解，如果不赋值，那么vx.k的值为地址空间的第一元素的值,
        // 也就是说vx.var.x =vx.k 那么vx.var.x =34 赋值给float类型精度丢失因此vx.var.x = 0f
        // 打印保留小数点后两位 因此打印了 0.00 2 3 34
        printf("%.2lf %d %d %d\n", vx.var.x, vx.var.y, vx.var.z, vx.k);
    } else {
        printf("%.2lf %d %d \n", vx.var.x, vx.var.y, vx.var.z);//33.33 2 3
    }
    // 打印闰年
    // 规则：四年一闰；百年不闰，四百年再闰

    int year;
    bool isLeapYear;
    cout << "enter the year:";
    cin >> year;
    isLeapYear = (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    if (isLeapYear) {
        cout << year << " is a leap year"
             << endl;
    } else {
        cout << year << " is not a lear year" << endl;
    }


    return 0;
}
