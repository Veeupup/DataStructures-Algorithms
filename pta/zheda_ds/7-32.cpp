/* 
    欧拉图：
        设图 G 是一个没有孤立结点的图，如果存在一条回路经过图中
        的每条边一次且仅一次，则称这条回路为该图的一条欧拉回路，
        含有欧拉回路的图称为欧拉图

    欧拉通路：
        无向图 G =< V, E > 具有一条欧拉通路，当且仅当 G 是连通的，且仅有零个或两个奇度数结点

    欧拉回路的判定定理：
        无向图 G =< V, E > 具有一条欧拉回路，当且仅当 G 是连通的，并且所有结点的度数均为偶数。

    采用并查集+度数的判定即可

 */
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1010;
vector<int> G[maxn]; // 保存图
int father[maxn];    // 并查集的使用
int height[maxn];    // 保存每个结点的高度
int degree[maxn];    // 保存每个节点的度数

void Initial(int n)
{
    fill(degree, degree + n, 0);
    for (int i = 1; i <= n; i++)
    {
        father[i] = i;
        height[i] = 1;
    }
}

// 找父结点
int findFather(int x)
{
    while (x != father[x])
        x = father[x];
    return x;
}

// 合并
void Union(int x, int y)
{
    x = findFather(x);
    y = findFather(y);
    if (x != y)
    {
        if (height[x] < height[y])
        {
            father[x] = y;
        }
        else if (height[x] > height[y])
        {
            father[y] = x;
        }
        else
        {
            father[x] = y;
            height[y]++;
        }
    }
}

int main()
{
    freopen("data.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    Initial(n); // 初始化
    int u, v;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        Union(u, v);
        degree[u]++;
        degree[v]++;
    }
    bool flag = true;
    int root = findFather(1);
    for (int i = 1; i <= n; i++)
    { // 判断是否所有的点都在集合中
        if (findFather(i) != root)
        {
            flag = false;
            break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (degree[i] % 2 != 0)
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        printf("1");
    }
    else
    {
        printf("0");
    }
    return 0;
}