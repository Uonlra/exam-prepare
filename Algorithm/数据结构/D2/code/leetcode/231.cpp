#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;
const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    return 0;
}

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // 1. 首先，n 必须大于 0（负数和 0 肯定不是 2 的幂）
        // 2. 利用 n & (n - 1) 消除唯一的 1，如果结果为 0，说明它是 2 的幂
        return n > 0 && (n & (long long)n - 1) == 0;
    }
};