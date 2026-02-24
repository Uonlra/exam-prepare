#include <iostream>
#include <string>
using namespace std;
using ll = long long;

string reverseSting(string s);
bool isPalindrome(string s);
int main(){
/*     ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s = "hello";
    char c = s[0];
    s += " world";
    string t = s.substr(1,3);
    cout << s << endl;
    cout << t << endl;
    return 0; */
/*     string s = "hello";     // 读入一个单词（遇空格停止）
    int n = s.size();       // 长度
    char c = s[0];          // 下标访问
    s += "world";           // 拼接
    string t = s.substr(1, 3); // 从下标1开始，长度3
    for(int i = 0; i < (int)s.size(); i++){
        cout << s[i] << endl;
    }
    for(char c : s){
        cout << c << endl;
    } */
    string s = "UONLRA SANYE";
    cout << reverseSting(s) << endl;
    bool ispali =   isPalindrome(s);
    cout << (ispali ? "true" : "false") << endl; 
    return 0;
}
// 反转字符串
string reverseSting(string s){
    string res;
    for(int i = (int)s.size() - 1; i >= 0; i--){
        res += s[i];
    }
    return res;

}

bool isPalindrome(string s){
    int n = (int)s.size();
    for(int i = 0; i < n / 2; i++){
        if(s[i] != s[n - 1 - i]){
            return false;
        }
    }
    return true;
}