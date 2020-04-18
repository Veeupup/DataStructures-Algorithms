#include <iostream>
#include <algorithm>
#define LOCAL
using namespace std;

const int maxn = 5000;

int N;  // 村庄数
int father[105];    // 并查集的父亲结点
struct edge
{
    int u, v, cost, isHas;  // 两个端点，成本，是否有路
}edges[maxn];

int findFather(int x)
{
    while (x != father[x])
    {
        x = father[x];
    }
    return x;
}

void Union(int x, int y)
{
    x = findFather(x);
    y = findFather(y);
    if(x != y)
        father[x] = y;
}

bool cmp(edge a, edge b)
{
    return a.cost < b.cost;
}

void Prim(int m)
{
    sort(edges, edges + m, cmp);    // 所有的边从小到达排序
    int ans = 0;    // 记录修建路程需要的成本
    for (int i = 0; i < m; i++)
    {   // 如果这条边的两个边不在同一个集合中，那么就加入到集合中
        if(findFather(edges[i].u) != findFather(edges[i].v))
        {
            ans += edges[i].cost;
            Union(edges[i].u, edges[i].v);
        }
    }
    printf("%d", ans);
}

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {   // 初始化并查集
        father[i] = i;
    }
    int m = N * (N - 1) / 2;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d%d", &edges[i].u, &edges[i].v, &edges[i].cost, &edges[i].isHas);
        if(edges[i].isHas == 1)
            Union(edges[i].u, edges[i].v);
    }
    Prim(m);

    return 0;
}