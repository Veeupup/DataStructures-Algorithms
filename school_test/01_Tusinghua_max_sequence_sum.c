/*
    Author: Veeupup
    最大子序列和
    动态规划，设 dp[i] 表示 以 A[i] 为结尾的前方最大子序列的和
    dp[i] = max( A[i], dp[i-1] + A[i] )

    输入
        5
        1 5 -3 2 4

        6
        1 -2 3 4 -10 6

        4
        -3 -1 -2 -5
    输出
        9
        7
        -1

 */
#include <stdio.h>
#include <stdint.h>
#define N 1000010

int A[N];
int dp[N];

int maxNum(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    freopen("data.txt", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &A[i]);
        }
        dp[0] = A[0];
        int max = dp[0];
        for (int i = 1; i < n; i++)
        {
            dp[i] = maxNum(A[i], A[i] + dp[i - 1]);
            if (dp[i] > max)
                max = dp[i];
        }
        printf("%d\n", max);
    }
    return 0;
}