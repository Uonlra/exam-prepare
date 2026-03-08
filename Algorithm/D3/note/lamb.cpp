#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
    void solve(vector<vector<int>>& arr) {
        // 验证输入数据有效性
        if (arr.empty()) return;
        
        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
            // 确保访问索引 1 是安全的
            if (a.size() < 2 || b.size() < 2) return false;
            // 降序排序:按第二个元素从大到小
            return a[1] > b[1];
        });
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 本地调试区
    // Solution s;
    // cout << s.solve(...) << '\n';

    return 0;
}