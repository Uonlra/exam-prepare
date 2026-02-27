#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int f[1 << 20][20]; // f[i][j]表示状态i，最后一个访问的点是j的最短路径长度
// 函数声明
int hamilton(int n, int weight[20][20]);

int main(){
    int n; // 点的数量
    return 0;
}

// 函数实现
int hamilton (int n, int weight[20][20]){ // n是点的数量，weight是点之间的权重矩阵
    memset(f, 0x3f, sizeof(f)); // 初始化f数组为一个很大的数，表示不可达
    f[1][0] = 0; // 从第一个点开始，状态为1（只访问了第一个点），最后一个访问的点是0，路径长度为0

    for (int i = 1; i < (1 << n); i++) // 枚举所有状态，从1到2^n-1
    {
        for (int j = 0; j < n; j++) // 枚举最后一个访问的点j
        {
            if ((i & (1 << j)) == 0) continue; // 如果状态i中没有访问点j，跳过
            for (int k = 0; k < n; k++) // 枚举倒数第二个访问的点k
            {
                if ((i & (1 << k)) == 0) continue; // 如果状态i中没有访问点k，跳过
                if (j == k) continue; // 最后一个访问的点不能是自己
                f[i][j] = min(f[i][j], f[i ^ (1 << j)][k] + weight[k][j]); // 状态转移
            }
        }
    }
    int res = 0x3f3f3f3f; 
    for(int j = 1; j < n; j++) // 枚举最后一个访问的点j，计算回到起点的路径长度
    {
        res = min(res, f[(1 << n) - 1][j] + weight[j][0]); // 从状态2^n-1（所有点都访问了）回到起点0
    }
    return res; // 返回最短路径长度
}