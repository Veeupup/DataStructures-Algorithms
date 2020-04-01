/*
    Author: Veeupup
    旅游规划
    单源最短路径 Dijkstra，有两个标尺 1. 距离 2. 过路费

    典型的单源最短路径的变形

 */
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <vector>
using namespace std;

const int maxn = 510, INF = 1e4;

int N, M, S, D;
int G[maxn][maxn];  // 保存距离，第一标尺
int cost[maxn][maxn]; // 保存收费金额，图的边权
int dis[maxn], minCost = INF;  // 记录起点到某点的最小距离
bool vis[maxn] = {false};   // 记录是否访问过

vector<int> pre[maxn];  // 保存前一个结点
vector<int> tempPath, path;

void Initial()
{   // 初始化距离和花费最大
    fill(G[0], G[0] + maxn * maxn, INF);
    fill(cost[0], cost[0] + maxn * maxn, INF);
}

void Dijkstra(int S) {
    fill(dis, dis+maxn, INF);   // 初始化到所有点距离无限大
    dis[S] = 0; // 到自己距离为 0
    for (int i = 0; i < N; i++)
    {
        int u = -1, MIN = INF;
        for (int j = 0; j < N; j++)
        {   // 寻找未访问的距离最小值
            if(vis[j] == false && dis[j] < MIN) {
                u = j;
                MIN = dis[j];
            }
        }
        if(u == -1) break;  // 所有可以到达的点都访问过了
        vis[u] = true;  // 设置为已访问
        for (int v = 0; v < N; v++)
        {   // 遍历能从 u 出发到达的所有点
            // 如果经过 u 到达 v 更近，那么就更新 v
            if(dis[u] + G[u][v] < dis[v]) {
                dis[v] = dis[u] + G[u][v];
                pre[v].clear();
                pre[v].push_back(u);    // 经过 u 能够更近的到达 v
            }else if(dis[u] + G[u][v] == dis[v]) {
                // 如果经过 u 到达的时候距离一样远，那么增加到其前面去
                pre[v].push_back(u);
            }   
        }
    }
}

void DFS(int V) {
    if(V == S) {
        tempPath.push_back(S);
        int tempCost = 0;
        int nowId, nextId;
        for (int i = tempPath.size()-1; i > 0; i--)
        {
            nowId = tempPath[i];
            nextId = tempPath[i-1];
            tempCost += cost[nowId][nextId];
        }
        if(tempCost < minCost) {
            minCost = tempCost;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }else {
        tempPath.push_back(V);
        for (int i = 0; i < pre[V].size(); i++)
        {
            DFS(pre[V][i]);
        }
        tempPath.pop_back();
    }
}

int main()
{
    freopen("data.txt","r", stdin);
    Initial();
    scanf("%d%d%d%d", &N, &M, &S, &D);
    int u, v;
    for (int i = 0; i < M; i++)
    {   // 读取图信息
        scanf("%d%d", &u, &v);
        scanf("%d%d", &G[u][v], &cost[u][v]);
        G[v][u] = G[u][v];
        cost[v][u] = cost[u][v];
    }
    Dijkstra(S);
    DFS(D);   // 从终点向前回溯
    printf("%d %d\n", dis[D], minCost);

    return 0;

}