#include <iostream>
using namespace std;
int isRelatedToSeven(int x);
int main() {
    int n;
    cin >> n;

    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (!isRelatedToSeven(i)) {
            sum += 1LL * i * i;
        }
    }

    cout << sum;
    return 0;
}
// 64 位输出请用 printf("%lld")

int isRelatedToSeven(int x)
{
    if (x % 7 == 0) {
        return true;
    }

    while (x > 0) { //
        if (x % 10 == 7) { // 如果当前位是7，返回true 
            return true;
        }
        x /= 10; // 继续检查下一位数字
    }

    return false;
}