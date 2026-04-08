#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// 函数声明


int main(){
    int n;
    cin >> n;

    vector<pair<string, int>> info(n + 1); // 声明一个大小为 n + 1 的 vector，元素类型为 pair<string, int>，用于存储考生信息，info为一个向量，索引为试验座位号，值为一个 pair，包含考生 ID 和考试座位号
    for (int i = 0; i < n; ++i) {
        string id;
        int trialSeat, examSeat;
        cin >> id >> trialSeat >> examSeat; // 从输入中读取考生的 ID、试验座位号和考试座位号
        info[trialSeat] = {id, examSeat}; // 将考生信息存储在 info 向量中，索引为试验座位号，值为一个 pair，包含考生 ID 和考试座位号
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int querySeat;
        cin >> querySeat;
        cout << info[querySeat].first << ' ' << info[querySeat].second << '\n';
    }

    return 0;
}

// 函数实现