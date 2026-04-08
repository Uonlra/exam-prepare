#include<bits/stdc++.h>
#include <string>
using namespace std;

int number[128];

int main(){
    string str1,str2;
    while(getline(cin,str1)){
        if (str1 == "#") {
            break;
        }
        getline(cin, str2);
        memset(number,0,sizeof(number));
        for(int i = 0; i < str2.size(); ++i){
            number[str2[i]]++; // 统计每个字符在str2中出现的次数
        }
        for(int i = 0; i < str1.size(); ++i){
            cout << str1[i] << number[str2[i]];// 输出字符和对应的数量
        }
    }
    return 0;
}