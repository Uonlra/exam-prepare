#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        vector<int> a(n); // 输入数组
        // int a[n]; //
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int mx = *max_element(a.begin(), a.end());
        cout << mx << "\n";

        bool removed = false;
        vector<int> rest;
        rest.reserve(max(0, n - 1));// 预分配空间，避免多次扩容

        for (int v : a) {// 遍历数组，找到最大值并移除它
            if (!removed && v == mx) {
                removed = true;
                continue;
            }
            rest.push_back(v);
        }

        if (rest.empty()) {
            cout << -1;
        } else {
            sort(rest.begin(), rest.end());
            for (int i = 0; i < (int)rest.size(); ++i) {
                if (i) {
                    cout << " ";
                }
                cout << rest[i];
            }
        }

        if (!cin.eof()) {// 如果不是输入结束，输出换行 
            cout << "\n";
        }
    }

    return 0;
}
