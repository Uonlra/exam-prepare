#include <utility>   // 包含 pair
#include <vector>
#include <iostream>
#include <algorithm> // sort
using namespace std;

int main() {
    pair<int, int> p = {1, 2};  // C++11 简写
    cout << p.first << " " << p.second << endl; // 访问

    vector<pair<int, int>> vec;
    vec.push_back({3, 4});

    // pair 默认排序：先 first 升序，再 second 升序
    sort(vec.begin(), vec.end());

    return 0;
}