/*
    Author: Veeupup
    点菜问题，01 背包

    input:
        90 4
        20 25
        30 20
        40 50
        10 18
        40 2
        25 30
        10 8

    output:
        95
        38

 */
#include <iostream>
#include <cstdio>
#include <cstdint>
using namespace std;

const int maxn = 1010;

int C, N;   // 最大报销钱数，菜品数量
int V[maxn], P[maxn];   // 菜的评价分数，菜的价格
int dp[maxn];   // dp数组

int max(int a, int b) {
    return a > b ? a : b;
}

int main()
{
    freopen("data.txt","r", stdin);
    while (scanf("%d%d", &C, &N) != EOF)
    {
        for (int i = 0; i < N; i++)
        {   // 菜的价格，菜的评价
            scanf("%d%d", &P[i], &V[i]);    
        }
        fill(dp, dp + maxn, 0); // 初始化为 0
        for (int i = 0; i < N; i++)
        {   // 枚举菜品
            for (int v = C; v >= P[i]; v--)
            {
                dp[v] = max(dp[v], dp[v-P[i]] + V[i]);
            } 
        }
        printf("%d\n", dp[C]);
    }
    return 0;
}