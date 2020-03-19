#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>
#define N 20

int main()
{
    int dp[N];
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    for (int i = 3; i < N; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    int n;
    while(scanf("%d", &n) != EOF) {
        printf("%d\n", dp[n]);
    };
    return 0;
}