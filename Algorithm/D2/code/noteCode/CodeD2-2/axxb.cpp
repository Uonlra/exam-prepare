#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int power(int a,int b,int c);

int main(){
    int a, b, c;
    cout << "输入 a, b, c 的值：" << endl;
    cin >> a >> b >> c;
    cout << "计算 a^b % c 的结果：" << endl;
    int result = power(a,b,c);
    cout << "最终结果: " << result << endl;
    return 0;
}

int power(int a, int b, int p){
    int ans = 1 % p; // 处理 p = 1 的情况
    cout << "初始: a=" << a << ", b=" << b << ", p=" << p << ", ans=" << ans << endl;
    
    int iteration = 0;
    for(; b; b >>= 1){ // b 右移一位，相当于除以 2
        cout << "迭代 " << iteration << ": ";
        if(b & 1) {
            ans = (ll)ans * a % p; // 如果 b 的当前最低位是 1，则将 a 的当前值乘到 ans 上
            cout << "b的最低位是1，ans = " << ans;
        }
        a = (ll)a * a % p; // 将 a 平方，准备下一轮迭代
        cout << ", 更新 a=" << a << ", b=" << b << endl;
        iteration++;
    }
    return ans;
}