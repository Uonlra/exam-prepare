#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// 函数声明


int main(){
    
    return 0;
}

// 函数实现
class Solution {
public:
    int reverseBits(int n) {
        unsigned int un = (unsigned int)n;  // 将 n 转换为无符号整数    
        unsigned int result = 0;

        for (int i = 0; i < 32; ++i) {
            result <<= 1;           // 将结果左移一位
            result |= (un & 1);     // 将 un 的最低位添加到结果中
            un >>= 1;              // 将 un 右移一位
        }
        return int(result); // 将结果转换回有符号整数
    }
};