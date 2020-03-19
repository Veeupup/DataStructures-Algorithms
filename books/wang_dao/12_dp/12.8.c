#include<stdio.h>
#include<stdint.h>
#include<limits.h>


/* 
    完全背包问题

    dp[i][j] = max( dp[i][j], dp[i][j-w[i]] + v[i] )
    由于只和上一行有关系，所以退化成一维数组求解
    dp[j] = max( dp[j], dp[j-w[i]] + v[i] )

    input:
        3
        10 110
        2
        1 1
        30 50
        10 110
        2
        1 1
        50 30
        1 6
        2
        10 3
        20 4
    output:
        60
        100
        impossible

 */
#define MAXN 10000

int INF = INT_MAX / 10;

int dp[MAXN];
int v[MAXN];
int w[MAXN];


int main()
{
    freopen("data.txt","r", stdin);
    int caseNumber;
    scanf("%d", &caseNumber);
    while (caseNumber--)
    {
        int e, f;
        scanf("%d%d", &e, &f);
        int m = f - e;  // 背包容量
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &v[i], &w[i]);
        }
        dp[0] = 0;
        for (int i = 1; i <= m; i++)
        {
            dp[i] = INF;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = w[i]; j <= m; j++)
            {
                dp[j] = ( dp[j] < dp[j-w[i]] + v[i] ) ? dp[j] : dp[j-w[i]] + v[i];
            }
        }
        if(dp[m] == INF) {
            printf("impossible\n");
        }else {
            printf("%d\n", dp[m]);
        }

    }
    


    return 0;
}