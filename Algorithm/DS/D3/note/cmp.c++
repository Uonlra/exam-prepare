#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

using ll = long long;

// 函数声明
bool cmp(const vector<int> & a, const vector <int> & b);

int main(){
    vector<vector<int>> arr = {{3, 4}, {1, 2}, {2, 3}, {1, 1}};
    sort(arr.begin(), arr.end(), cmp);
    // 现在 arr 已经按照 cmp 定义的规则排序了
    
    return 0;
}

// 函数实现
bool cmp(const vector<int> & a, const vector <int> & b){
    // 这里的比较逻辑可以根据具体需求进行调整
    // 例如，比较第一个元素，如果相等则比较第二个元素
    if (a[0] != b[0]) {
        return a[0] < b[0]; // 按照第一个元素升序排序
    } else {
        return a[1] < b[1]; // 如果第一个元素相同，按照第二个元素升序排序
    }
}
