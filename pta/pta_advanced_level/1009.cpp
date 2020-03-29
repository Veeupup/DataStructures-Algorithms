/*
    Author: Veeupup
    多项式的乘法

    模拟多项式乘法

 */
#include <iostream>
#include <cstdio>
#include <cstdint>
using namespace std;

int main()
{
    freopen("data.txt","r", stdin);
    int n1, n2, a, cnt = 0;
    scanf("%d", &n1);
    double b, arr[1001] = {0.0}, ans[2001] = {0.0};
    for (int i = 0; i < n1; i++)
    {   // 读入第一个多项式，保存在 arr 数组中
        scanf("%d %lf", &a, &b);
        arr[a] = b;
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        scanf("%d %lf", &a, &b);
        for (int j = 0; j < 1001; j++)
        {   // 多项式模拟计算，后面多项式中的每一个都要和之前多项式的所有位置相乘
            ans[j+a] += arr[j] * b; // 两个位置相乘，指数相加，底数相乘
        }
    }
    for (int i = 2000; i >= 0; i--)
    {   // 计算不为 0 的位置的个数
        if(ans[i] != 0.0)
            cnt++;
    }
    printf("%d", cnt);
    for (int i = 2000; i >= 0; i--)
    {   // 从高位一直向低位计算
        if(ans[i] != 0.0) {
            printf(" %d %.1f", i, ans[i]);
        }
    }
    return 0;
}