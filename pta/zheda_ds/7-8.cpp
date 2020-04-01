/*
    Author: Veeupup
    哈利波特的考试

    仔细读题，这个题需要求全局最短路径，也就是说
    答案需要在到每个点距离最大的所有点中找最小的
    所以我们先通过 Floyd 求得全局最短路径（通过距离可知能否到达）
    
 */
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <climits>
using namespace std;

const int maxn = 110, INF = 1e5;

int n, m;
int dis[maxn][maxn];

// 朴素的 floyd 算法，求全局最短路径
void floyd() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

int main()
{
    freopen("data.txt","r", stdin);    
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {   // 初始化点之间的距离，自己到自己距离为 0
        for (int j = 1; j <= n; j++)
        {
            if(i == j) dis[i][j] = 0;
            else dis[i][j] = INF;
        }
    }
    int v1, v2, weight;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &v1, &v2, &weight);
        dis[v1][v2] = dis[v2][v1] = weight;
    }
    
    floyd();

    int ans = INF;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int Max = 0;
        for (int j = 1; j <= n; j++)
        {
            if(dis[i][j] == INF) 
            {   // 如果有孤立的结点，那么就无法完成变形
                printf("0");
                return 0;
            }
            Max = max(Max, dis[i][j]);
        }
        if(Max < ans) 
        {
            ans = Max;
            cnt = i;
        }
    }
    printf("%d %d", cnt, ans);
    return 0;
}