/*
    Author: Veeupup
    还是畅通工程
    最小生成树

    https://www.nowcoder.com/practice/d6bd75dbb36e410995f8673a6a2e2229?tpId=40&tqId=21479&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking

 */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define N 100

struct Edge
{
    int from;
    int to;
    int length;
} edges[10010];

int father[N]; // 记录父亲结点
int height[N]; // 记录结点深度

void Initial(int n)
{
    for (int i = 0; i < n; i++)
    {
        father[i] = i;
        height[i] = 0;
    }
}

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
    if (x != y)
    {
        if (height[x] < height[y])
            father[x] = y;
        else if (height[y] < height[x])
            father[y] = x;
        else
        {
            father[x] = y;
            height[y]++;
        }
    }
}

// 将边按照边来排序
// 为了简单直接冒泡排序
void sortEdges(int edgeNumber)
{
    for (int i = 0; i < edgeNumber; i++)
    {
        for (int j = i + 1; j < edgeNumber; j++)
        {
            if (edges[i].length > edges[j].length)
            {
                int tempFrom = edges[i].from;
                int tempTo = edges[i].to;
                int tempLength = edges[i].length;
                edges[i].from = edges[j].from;
                edges[i].to = edges[j].to;
                edges[i].length = edges[j].length;
                edges[j].from = tempFrom;
                edges[j].to = tempTo;
                edges[j].length = tempLength;
            }
        }
    }
};

int Kruskal(int n, int edgeNumber)
{
    Initial(n); // 初始化那些边
    sortEdges(edgeNumber);
    int sum = 0;
    for (int i = 0; i < edgeNumber; i++)
    {
        if (findFather(edges[i].from) != findFather(edges[i].to))
        {
            // 如果边两边的点不在一个集合里，那么将其加入到集合中
            Union(edges[i].from, edges[i].to);
            sum += edges[i].length;
        }
    }
    return sum;
}

int main()
{
    freopen("data.txt", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        int m = (n * (n - 1)) / 2;
        for (int i = 0; i < m; i++)
        { // 读取所有的边
            scanf("%d %d %d", &edges[i].from, &edges[i].to, &edges[i].length);
        }
        int sum = Kruskal(n, m);
        printf("%d\n", sum);
    }
    return 0;
}