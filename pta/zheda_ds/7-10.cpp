/*
    Author: Veeupup
    公路村村通

    最小生成树算法：
    Prim（类似Dijkstra） + Krusktal（边贪心）

    这里选择使用 Krusktal 算法来实现
    算法思想很简单

 */
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <algorithm>
using namespace std;

const int maxn = 1010, INF = INT32_MAX;

int N, M;
struct edge
{
    int u, v;
    int cost; // 边权
} E[maxn * 3];

bool cmp(edge a, edge b)
{
    return a.cost < b.cost;
}

// 使用并查集
int father[maxn];
int findFather(int x)
{
    while (x != father[x])
    {
        x = father[x];
    }
    return x;
}

// n 为顶点个数， m 为图的边数
int kruskal(int n, int m)
{
    // ans 为所求边权之和
    int ans = 0, Num_edge = 0;
    for (int i = 1; i <= n; i++)
    {
        father[i] = i;
    } // 并查集初始化
    sort(E, E + m, cmp);
    for (int i = 0; i < m; i++)
    {
        int faU = findFather(E[i].u);
        int faV = findFather(E[i].v);
        if (faU != faV)
        {
            father[faU] = faV;
            ans += E[i].cost;
            Num_edge++;
            if (Num_edge == n - 1)
                break;
        }
    }
    if (Num_edge != n - 1)
        return -1;
    return ans;
}

int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d%d", &N, &M);
    int u, v, w;
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].cost);
    }
    int ans = kruskal(N, M);
    printf("%d", ans);
    return 0;
}