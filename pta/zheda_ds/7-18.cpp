/*
    Author: Veeupup
    银行业务队列简单模拟

    A 的速度是 B 的两倍，根据处理顺序输出
    分别计算出 每个人结束的事件，归并到一起

 */
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <vector>
#define LOCAL
using namespace std;

const int maxn = 1010;

struct Person
{
    int id, endTime;
} lineA[maxn], lineB[maxn];

int timeA = 0, timeB = 0; // A 和 B 当前结束的时间
int numA = 0, numB = 0;

int main()
{
    #ifdef LOCAL
    freopen("data.txt", "r", stdin);
    #endif
    int n, tempId; // 总人数
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tempId);
        if (tempId % 2 == 1)
        {
            timeA++;
            lineA[numA].id = tempId;
            lineA[numA++].endTime = timeA;
        }
        else
        {
            timeB += 2;
            lineB[numB].id = tempId;
            lineB[numB++].endTime = timeB;
        }
    }
    // 开始归并
    int i = 0, j = 0;  // i 代表 A 的编号，j 代表 B 的编号
    bool flag = false; // 控制输出格式
    int nowTimeA, nowTimeB, nowId;
    while (i < numA && j < numB)
    {
        int nowTimeA = lineA[i].endTime;
        int nowTimeB = lineB[j].endTime;
        if (lineA[i].endTime <= lineB[j].endTime)
        {
            nowId = lineA[i++].id;
        }
        else
        {
            nowId = lineB[j++].id;
        }
        if (flag)
        {
            printf(" %d", nowId);
        }
        else
        {
            printf("%d", nowId);
            flag = true;
        }
    }
    while (i < numA)
    {
        if (flag)
        {
            printf(" %d", lineA[i++].id);
        }
        else
        {
            printf("%d", lineA[i++].id);
        }
    }
    while (j < numB)
    {
        if (flag)
        {
            printf(" %d", lineB[j++].id);
        }
        else
        {
            printf("%d", lineB[j++].id);
        }
    }
    return 0;
}