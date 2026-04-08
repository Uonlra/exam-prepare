#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> odd;
    vector<int> even;

    for (int i = 0; i < 10; ++i) {
        int x;
        cin >> x;
        if (x % 2 != 0) {
            odd.push_back(x);// 奇数放在odd数组中
        } else {
            even.push_back(x);
        }
    }

    sort(odd.begin(), odd.end(), greater<int>());//greatr<int>()是一个比较函数对象，用于指定排序的顺序，这里表示降序排序
    sort(even.begin(), even.end());

    bool first = true;
    for (int x : odd) {// 输出奇数数组
        if (!first) {
            cout << " ";
        }
        cout << x;
        first = false;
    }
    for (int x : even) {
        if (!first) {
            cout << " ";
        }
        cout << x;
        first = false;
    }

    return 0;
}
