/*
    Author: Veeupup
    n 的阶乘，使用动态规划

 */
#include <bits/stdc++.h>
using namespace std;

#define N 1000
long long dp[N+1];

void Initial()
{
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        dp[i] = i * dp[i-1];
    }
}

int main()
{
    freopen("data.txt", "r", stdin);
    Initial();
    long n;
    while (scanf("%ld", &n) != EOF)
    {
        printf("%ld\n", dp[n]);
    }
    return 0;

}