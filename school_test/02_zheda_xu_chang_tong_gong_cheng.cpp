/*
    Author: Veeupup
    继续畅通工程
    求最短路径
    
    Dijkstra 算法 


 */
#include <iostream>
#include <cstdint>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100;

struct Edge
{
    int from;
    int to;
    int length;
};

Edge edges[N * N];
int father[N];
int height[N];

void Initial(int n) {
    for(int i=0;i<=n;i++) {
        father[i] = i;
        height[i] = 0;
    }
}

int Find(int x)
{
    if (x != father[x])
    {
        father[x] = Find(father[x]);
    }
    return father[x];
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x != y)
    {
        if (height[x] < height[y])
        {
            father[x] = y;
        }
        else if (height[y] < height[x])
        {
            father[y] = x;
        }
        else
        {
            father[y] = x;
            height[x]++;
        }
    }
}

bool Compare(Edge x, Edge y)
{ // 根据边的长度从小到大
    return x.length < y.length;
}

int Kruskal(int n, int edgeNumber)
{
    Initial(n);
    sort(edges, edges + edgeNumber, Compare);
    int sum = 0;
    for (int i = 0; i < edgeNumber; i++)
    {
        if (Find(edges[i].from) != Find(edges[i].to))
        {   // 如果不是在一个集合中，那么并
            Union(edges[i].from, edges[i].to);
            sum += edges[i].length;
        }
    }
    return sum;
}

int main()
{
    // freopen("data.txt", "r", stdin);
    int n; // 乡村数目
    while (scanf("%d", &n) != EOF)
    {
        if(n == 0) break;
        int edgeNumber = (n * (n - 1)) / 2; // 边的数目
        for (int i = 0; i < edgeNumber; i++)
        {
            scanf("%d %d", &edges[i].from, &edges[i].to);
            int length, isHas;
            scanf("%d %d", &length, &isHas);
            if(isHas == 1)
                length = 0;
            edges[i].length = length;
        }
        int sum = Kruskal(n, edgeNumber);
        printf("%d\n", sum);
    }
    return 0;
}