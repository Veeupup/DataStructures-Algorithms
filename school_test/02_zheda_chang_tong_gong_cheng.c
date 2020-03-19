/*
    Author: Veeupup
    畅通工程

    考察并查集:
    * 一个 Find 寻找父亲结点
    * 一个 Union 将点之间联系起来

    https://www.nowcoder.com/practice/4878e6c6a24e443aac5211d194cf3913?tpId=40&tqId=21457&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking

 */
#include <stdio.h>
#include <stdint.h>
#define N 1000

int father[N]; // 记录某点的父亲节点
int height[N]; // 记录某点的高度

void Initial()
{
    for (int i = 0; i < N; i++)
    {
        father[i] = i; // 每个结点是自己本身的父节点
        height[i] = 0;
    }
}

// 寻找某点的父亲节点
int Find(int x)
{
    if (x != father[x])
    {
        x = Find(father[x]);
    }
    return x;
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x != y)
    { // 如果 x y 不是同一个根结点，也就是不在同一个集合中的时候
        if (height[x] < height[y])
            father[x] = y; // 认比自己高的树当爸爸
        else if (height[y] < height[x])
            father[y] = x;
        else
        { // 如果高度相同，那么 x 认 y 当爸爸
            father[x] = y;
            height[y]++;
        }
    }
    return;
}

int main()
{
    freopen("data.txt", "r", stdin);
    int n, m;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        scanf("%d", &m);
        Initial();
        int x, y;
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d", &x, &y);
            Union(x, y);
        }
        int ans = 0; // ans 表示集合的个数
        for (int i = 1; i <= n; i++)
        { // 如果有孤立的结点，
            //或者是一个集合（集合内只算根结点，其他结点由于 Find(i) != i,计算集合的个数）
            if (Find(i) == i)
                ans++;
        }
        printf("%d\n", ans - 1);
    }
    return 0;
}