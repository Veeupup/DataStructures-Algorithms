#include <stdio.h>

/* 
    畅通工程

    图 并查集 常常用来判断是否为连通图

    input:
        4 2
        1 3
        4 3
        3 3
        1 2
        1 3
        2 3
        5 2
        1 2
        3 5
        999 0
        0
    output:
        1
        0
        2
        998

 */
#define N 1001

int father[N]; //记录父节点
int height[N]; //记录每个节点的高度

void Initial(int n)
{
    for (int i = 0; i <= n; i++)
    {
        father[i] = i; // 初始化，父节点是自己
        height[i] = 0; // 高度为0
    }
}

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
    {
        if (height[x] < height[y])
        { // 矮树添加到高树上
            father[x] = y;
        }
        else if (height[x] > height[y])
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

int main()
{
    freopen("data.txt", "r", stdin);
    int n, m;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        scanf("%d", &m);
        Initial(n);
        int x, y;
        while (m--)
        {
            scanf("%d", &x);
            scanf("%d", &y);
            Union(x, y);
        }
        int ans = -1;
        for (int i = 1; i <= n; i++)
        {
            if (Find(i) == i)   // 其实就是找有多少个根结点，每个根结点总是指向自己（孤立的点也是根结点）
            {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}