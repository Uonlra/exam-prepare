#include <stdio.h>
#define maxn 25
int n, k, m, a[maxn];
// 逆时针走t步，步长是d（-1表示顺时针走），返回新位置
int go(int p, int d, int t);
int main()
{
    while (scanf("%d%d%d", &n, &k, &m) == 3 && n)
    {
        for (int i = 1; i <= n; i++)
            a[i] = i;
        int left = n; // 还剩下的人数
        int p1 = n, p2 = 1;
        while (left)
        {
            p1 = go(p1, 1, k);
            p2 = go(p2, -1, m);
            printf("%3d", p1);
            left--;
            if (p2 != p1)
            {
                printf("%3d", p2);
                left--;
            }
            a[p1] = a[p2] = 0;
            if (left)
                printf(",");
        }
        printf("\n");
    }
    return 0;
}

int go(int p, int d, int t)
{
    // while (t)
    // {
    //     p += d;
    //     if (p == 0)
    //         p = n;
    //     else if (p == n + 1)
    //         p = 1;
    //     if (a[p]) // 这个位置有人
    //         t--;
    // }
    // return p;

    while(t--){
        do{
            p = (p + d + n - 1) % n + 1; // 循环移动位置
        }
        while(!a[p]); // 找到下一个有人的位置
    }
    return p;
}