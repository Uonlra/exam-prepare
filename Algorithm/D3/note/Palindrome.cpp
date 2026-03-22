#include<bits/stdc++.h>
#include<stdio.h>
#include<string>
#include<ctype.h>
using namespace std;

const char* rev = "A 3 HIL JM O 2TUVWXY51SE Z 8 ";
const char* msg[] = {"not a palindrome", "a regular palindrome", "a mirrored string", "a mirrored palindrome"};
char r(char ch) {
if(isalpha(ch)) return rev[ch - 'A'];
return rev[ch - '0' + 25];
}

int main() {
    char s[30];
    while(scanf("%s", s) == 1) {
        int len = strlen(s);
        bool palin = true, mirro = true;
        for(int i = 0; i < len / 2; i++) {
            if(s[i] != s[len - 1 - i]) palin = false; // 判断是否是回文字符串
            if(r(s[i]) != s[len - 1 - i]) mirro = false; // 判断是否是镜像字符串
        }
        if(len & 1) {
            if(r(s[len / 2]) != s[len / 2]) mirro = false;
        }
        printf("%s -- is %s.\n\n", s, msg[palin + mirro * 2]);
    }
    return 0;
}