#include <iostream>
#include <vector>
using namespace std;

const int maxn = 510, INF = 1e5;

int n, m, s, d;           // 城市个数（0～n-1），道路条数，出发点，目的地
int G[maxn][maxn];        // 保存城市之间的距离
int persons[maxn];        // 每个城市救援队的数目
int dis[maxn];            // 到某个点的距离
bool vis[maxn] = {false}; // 是否被访问过
vector<int> pre[maxn];    // 上一个结点

void Dijkstra(int s)
{
    fill(dis, dis + n, INF); // 初始化所有距离为无限远
    dis[s] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++)
        { // 寻找到能到达的距离最小的点
            if (vis[j] == false && dis[j] < MIN)
            {
                u = j;
                MIN = dis[j];
            }
        }
        if (u == -1)
            break; // 所有能到达的结点都使用过了
        vis[u] = true;
        for (int v = 0; v < n; v++)
        { // 如果 k 未被访问，且经过 u 为中介点使得到 k 的距离更小，那么就更新这条线路
            if (G[u][v] != INF)
            {
                if (dis[u] + G[u][v] < dis[v])
                {
                    dis[v] = dis[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(dis[u] + G[u][v] == dis[v])
                {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

int optValue = 0;
vector<int> tempPath, path; // 临时路径，最短路径
int num = 0;                // 记录最短路径条数
void DFS(int v)
{
    if (s == v)
    { // 递归到了出发的结点
        num++;
        tempPath.push_back(v);
        int value = 0, id;
        for (int i = 0; i < tempPath.size(); i++)
        {
            id = tempPath[i];
            value += persons[id];
        }
        if (value > optValue)
        {
            optValue = value;
            path = tempPath;
        }
        tempPath.pop_back();
    }
    else
    {
        tempPath.push_back(v);
        for (int i = 0; i < pre[v].size(); i++)
        {
            DFS(pre[v][i]);
        }
        tempPath.pop_back();
    }
}

int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d%d%d%d", &n, &m, &s, &d);
    fill(G[0], G[0] + maxn * maxn, INF);

    int i;
    for (i = 0; i < n; i++)
    { // 读取每个城市的救援队数目
        scanf("%d", &persons[i]);
    }
    int u, v;
    for (i = 0; i < m; i++)
    { // 读取城市间的距离
        scanf("%d%d", &u, &v);
        scanf("%d", &G[u][v]);
        G[v][u] = G[u][v];
    }
    Dijkstra(s);
    DFS(d);
    printf("%d %d\n", num, optValue);
    bool flag = false;
    for (int i = path.size() - 1; i >= 0; i--)
    {
        if (flag)
        {
            printf(" %d", path[i]);
        }
        else
        {
            printf("%d", path[i]);
            flag = true;
        }
    }

    return 0;
}