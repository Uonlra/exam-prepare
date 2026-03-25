#include <iostream>
using namespace std;
using ll = long long;

ll mul_method1(ll a, ll b,  ll p);
ll mul_method2(ll a, ll b, ll p);

int main(){
    ll ans = mul_method1(12, 20, 10); // 计算 (12 * 20) % 10 = 0
    cout << "Method 1 Result: " << ans << endl; // 输出结果
    
    // Test with different values to verify
    ans = mul_method1(3, 6, 7); // 计算 (3 * 6) % 7 = 4
    cout << "Method 1 Result: " << ans << endl;

    ans = mul_method2(5, 2, 9); // 计算 (5 * 2) % 9 = 1
    cout << "Method 2 Result: " << ans << endl;
    return 0;
}
// 计算(a * b) % p，a, b, p均为64位整数
long long mul_method1(ll a, ll b, ll p){
    long long res = 0;
    for(; b; b >>= 1){  //
        if(b & 1) res = (res + a) % p;// 如果b的最低位为1，则将a加到结果中
        a = a * 2 % p; // 将a乘以2，相当于左移一位
    }
    return res;
}

long long mul_method2(ll a, ll b, ll p){
    a %= p; // 确保a在模p范围内
    b %= p; // 确保b在模p范围内
    ll c = (long double)a * b / p; // 计算a*b/p的近似值，使用double避免溢出
    ll res = a * b - c * p; // 计算a*b - (a*b/p)*p的结果，理论上应该等于(a*b) % p

    if (res < 0) res += p; // 确保结果为非负数
    else if (res >= p) res -= p; // 如果结果大于等于p，减去p以保持在范围内

    return res;
}
