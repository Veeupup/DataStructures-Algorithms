#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>

/* 
    N阶楼梯
 */
#define N 91
int dp[N];

int main()
{
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < N; i++)
    {
        dp[i] = dp[i-1]+dp[i-2];
    }
    int n;
    while (scanf("%d", &n) != EOF)
    {
        printf("%d\n", dp[n]);
    }
    return 0;
}