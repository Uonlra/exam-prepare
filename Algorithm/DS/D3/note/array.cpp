#include<bits/stdc++.h>
#include<stdio.h>
#include<iostream>
using namespace std;

void arry();
void wertyu();
#define maxn 1010
int ans[maxn];
void masterMindHints();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int id;
    cin >> id;
    switch(id) {
        case 1: arry(); break;
        case 2: wertyu(); break;
        case 3: masterMindHints(); break;
    }
}

void arry() {
    int c, q = 1;
    while((c = getchar()) != EOF) {
    if(c == '"') { printf("%s", q ? "``" : "''"); q = !q; }
    else printf("%c", c);
    }
    return ;
}

void wertyu(){
    char s[] = "1234567890- = QWERTYUIOP[]\\ ASDFGHJKL;' ZXCVBNM,./";
    int c, i;
    while((c = getchar()) != EOF) { //不断读取标准输入，直到文件结束
        for(i = 0; s[i] && s[i] != c; i++); // 找错位之后的字符在常量表中的位置
        if(s[i]) printf("%c", s[i - 1]);// 输出错位之后的字符的前一个字符
        else printf("%c", c);
    }
}

void masterMindHints() {    
    int T,n;
    memset(ans, 0, sizeof(ans));
    for(int m = 1; m < maxn; m++){
        int x = m, y = m ;
        while (x > 0)
        {
            y += x % 10; x /= 10;
        }
        if (ans[y] == 0 || ans[y] > m) ans[y] = m;
    }
    cin >> T;
    while(T--){
        cin >> n;
        if(ans[n]) cout << ans[n] << endl;
        else cout << 0 << endl;
    }
    return ;
}