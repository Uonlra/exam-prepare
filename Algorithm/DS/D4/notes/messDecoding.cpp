#include <stdio.h>
#include <string.h> //使用memset
int readchar();
int readint(int c); // 从输入中读取c位二进制数，返回它的整数值
int code[8][1 << 8];
int readcodes(); // 读取编码表，返回1表示成功，0表示没有更多编码头了
int main()
{
    while (readcodes())
    { // 无法读取更多编码头时退出
        // printcodes();
        for (;;)
        {
            int len = readint(3);
            if (len == 0)
                break;
            // printf("len=%d\n", len);
            for (;;)
            {
                int v = readint(len);
                // printf("v=%d\n", v);
                if (v == (1 << len) - 1)
                    break;
                putchar(code[len][v]);
            }
        }
        putchar('\n');
    }
    return 0;
}

int readchar(){
    for(;;){
        int c = getchar();
        if(c != '\n' && c != '\r')
            return c;
    }
}

int readint(int ch){
    int v = 0;
    while (ch--)
    {
        v = (v << 1) + (readchar() - '0'); // 读入一个二进制位，更新v的值
    }
    return v;
}

int readcodes(){
    memset(code, 0, sizeof(code)); // 初始化编码表
    for (int len = 2; len <= 7; len++)
    {
        for (int i = 0; i < (1 << len) - 1; i++)
        {
            int ch = getchar();
            code[len][i] = ch; // 保存编码表
            if (ch == EOF) return 0; // 没有更多编码头了，返回0
            if (ch == '\n' || ch == '\r')
                return 1; // 编码头结束，返回1    
        }
    }
    return 1; // 成功读取编码头
}