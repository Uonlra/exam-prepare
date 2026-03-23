#include <stdio.h>
#include <string.h>
#define maxn 100
int left, chance;       // 还需要猜left个位置,错chance次之后就会输
char s[maxn], s2[maxn]; // 答案是字符串s,玩家猜的字母序列是s2
int win, lose;          // win=1表示已经赢了;lose=1表示已经输了
void guess(char ch) {
    int i;
    for (i = 0; i < strlen(s); i++)
        if (s[i] == ch)
            break; // 看s中有没有ch
    if (i == strlen(s))
        chance--; // 没有ch,机会-1
    else
    {
        s[i] = 0; // 有ch,把它从s中去掉
        left--;   // 还需要猜的字母数-1
    }
    if (left == 0)
        win = 1; // 没有了,赢了
    else if (chance == 0)
        lose = 1; // 没机会了,输了
 }
int main()
{
    int rnd;
    while (scanf("%d%s%s", &rnd, s, s2) == 3 && rnd != -1)
    {
        printf("Round %d\n", rnd);
        win = lose = 0; // 求解一组新数据之前要初始化
        left = strlen(s);
        chance = 7;
        for (int i = 0; i < strlen(s2); i++)
        {
            guess(s2[i]); // 猜一个字母
            if (win || lose)
                break; // 检查状态
        }
        // 根据结果进行输出
        if (win)
            printf("You win.\n");
        else if (lose)
            printf("You lose.\n");
        else
            printf("You chickened out.\n");
    }
    return 0;
}