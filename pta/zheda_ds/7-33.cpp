#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1010;

int n, m, s;
int sum = 0; // 经过的结点数目
vector<int> G[maxn];
bool vis[maxn] = {false}; // 是否访问过了

bool flag = false; // 调整格式
void DFS(int s)
{
    sum++;
    if (flag)
    { // 调整格式
        printf(" %d", s);
    }
    else
    {
        printf("%d", s);
        flag = true;
    }
    vis[s] = true;
    int v;
    bool hasVis;
    for (int i = 0; i < G[s].size(); i++)
    {
        v = G[s][i];
        hasVis = false;
        if (vis[v] == false)
        {
            hasVis = true;
            DFS(v);
        }
        if (hasVis) // 如果访问了这个结点的临界结点，那么一定会返回来访问他
            printf(" %d", s);
    }
}

int main()
{
    // freopen("data.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &s);
    int u, v;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    { // 对结点进行排序
        sort(G[i].begin(), G[i].end());
    }
    DFS(s);
    if (sum != n)
        printf(" 0");

    return 0;
}