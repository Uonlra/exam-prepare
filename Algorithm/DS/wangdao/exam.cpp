#include <bits/stdc++.h>

using namespace std;
struct Student
{
    int number;
    // 学号
    int score;
    // 成绩
};
const int MAXN = 100;
Student arr[MAXN]; // 学生数组,存储学生的学号和成绩
bool Compare(Student x, Student y)
{
    // 比较函数
    if (x.score == y.score)
    {
        // 成绩相等比较学号
        return x.number < y.number;
    }
    else
    {
        // 成绩不等比较成绩
        return x.score < y.score;
    }
}
int main()
{
    int n;
    scanf("%d", &n);// 输入学生人数
    for (int i = 0; i < n; ++i) // 输入学生的学号和成绩
    {
        scanf("%d%d", &arr[i].number, &arr[i].score);
    }
    sort(arr, arr + n, Compare); // 按照成绩从小到大排序,如果成绩相同则按照学号从小到大排序
    for (int i = 0; i < n; ++i)
    {
        printf("%d %d\n", arr[i].number, arr[i].score);
    }
    return 0;
}