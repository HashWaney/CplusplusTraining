//
// Created by hash on 2020/6/23.
//

#include "iostream"

using namespace std;


string addBinary(string a, string b);

int lengthOfLongSetSubString(string s);

int main() {
    string a = addBinary("10110011111111000001111111111111111", "10001011111100");
    cout << "binary sum :" << a << endl;
    lengthOfLongSetSubString("abcabcbb ");
    return 0;
}

// 二进制求和。满二进一
// 1。首先让两个字符串等长，不等长，在短的字符串前补零，否则之后的操作会超出索引
// 2。然后从后遍历所有的位数，同位相加，字符相加，利用ASCII码，字符内部都用数字表示，不需要知道具体值，但'0'-'0'=0 '0'+1='1'
// 3。判断相加后的字符，若大于等于字符'2' 下一位需要进一
// 4。最后判断第0位是否有进位，如果有，拼接一个'1'
string addBinary(string a, string b) {
    int asize = a.size();
    int bsize = b.size();

    while (asize < bsize) {
        a = '0' + a;
        ++asize;
    }

    while (asize > bsize) {
        b = '0' + b;
        ++bsize;
    }


    int carry = 0; //add carry
    for (int i = asize - 1; i >= 0; i--) {
        int sum = a[i] - '0' + b[i] - '0' + carry;
        a[i] = sum % 2 + '0'; // 给a中的每一个元素进行相加之后重新赋值，就得到了相加之后的数据
        carry = sum / 2;
    }
    if (carry > 0) { // 说明还是有进位的，在a的前面在加上1
        a = '1' + a;
    }

    return a;

}

int lengthOfLongSetSubString(string s) {

    int start(0), end(0), length(0), result(0);
    int size = s.size();
    while (end < size) {
        char temp = s[end];
        //[start,end);
        for (int index = start; index < end; index++) {
            if (temp == s[index]) {
                start = index + 1;
                length = end - start;
                cout<<"end "<<end<<" start "<<start<<" length "<<length<<endl;
                break;
            }
        }
        end++;
        length++;
        result = max(result, length);
    }
    return result;
}

