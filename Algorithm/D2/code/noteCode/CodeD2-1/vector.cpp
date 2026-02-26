#include <bits/stdc++.h>
using namespace std;
using ll = long long;

double average(vector<int> &v);
int max_value(vector<int> &v);
int min_value(vector<int> &v);
void addOne(vector<int> &v);

int main(){
    vector<int> v; // 定义一个空的vector
    vector<int> v2(5); // 定义一个大小为5的vector，元素默认初始化为0
    vector<int> v3(5, 10); // 定义一个大小为5的vector，元素初始化为10
    vector<int> v4 = {1, 2, 3, 4, 5}; // 定义一个vector，并使用列表初始化

    v.push_back(1); // 在末尾添加元素1
    v.push_back(2); // 在末尾添加元素2
    v.push_back(3); // 在末尾添加元素3
    v.pop_back(); // 删除末尾的元素（3）

    int x = v[0]; // 通过下标访问元素（1）
    cout << "Vector size: " << v.size() << endl; // 输出vector的大小
    cout << "Vector elements: ";
    for(int i = 0; i < (int)v.size(); i++){
        cout << v[i] << " "; // 通过下标访问元素
    }
    cout << endl;

    double avg = average(v);
    cout << "Average: " << avg << endl;
    int maxVal = max_value(v);
    int minVal = min_value(v);
    cout << "Max: " << maxVal << endl;
    cout << "Min: " << minVal << endl;

    addOne(v); // 给vector中的每个元素加1
    cout << "After adding one: ";
    for(int i = 0; i < (int)v.size(); i++){
        cout << v[i] << " "; // 通过下标访问元素
    }
    cout << endl;

    v.clear(); // 清空vector中的所有元素
    return 0;

    
}

double average(vector<int> &v){
    ll sum = 0;
    for (int x : v){
        sum += x;
    }
    return (double)sum / v.size();
}

int max_value(vector<int> &v){
    int result = v[0];
    for (int x : v){
        if (x > result){
            result = x;
        }
    }
    return result;
}

int min_value(vector<int> &v){
    int result = v[0];
    for (int x : v){
        if (x < result){
            result = x;
        }
    }
    return result;
}

void addOne(vector<int> &v){
    for (auto &x : v){
        x += 1;
    }
    for (size_t i = 0; i < v.size(); ++i){
        v[i] += 1;
    }
}