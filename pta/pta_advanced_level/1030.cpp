/*
    Author: Veeupup
    Travel Plan
    我们使用 Dijkstra + DFS 来实现

    首先是第一权值仍然是路径和，第二权值使用 DFS 的方式来记录

    input:
        4 5 0 3
        0 1 1 20
        1 3 2 30
        0 3 4 10
        0 2 2 20
        2 3 1 20

    output:
        0 2 3 3 40

 */
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <climits>
#include <vector>
using namespace std;

const int maxn = 510;
const int INF = INT_MAX;

int n, m, st, ed;       //  顶点个数，边数，起点，终点
int G[maxn][maxn];      //  邻接矩阵保存图, 保存最短路径
int cost[maxn][maxn];   //  保存每条路径的花费
int dis[maxn], minCost = INF;          //  保存起来
bool vis[maxn] = {false};         //  记录是否被访问过

vector<int> pre[maxn];  // 记录前驱结点
vector<int> tempPath, path; // 记录最短路径

void Dijkstra(int from) {
    fill(dis, dis+maxn, INF);   //  初始化所有距离无限大
    dis[from] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++)
        {   // 如果没有被访问过，而且二者之间能够走
            if(vis[j] == false && dis[j] < MIN) {
                u = j;
                MIN = dis[j];
            } 
        }
        if(u == -1) return;  // 所有能够到达的点都找过啦
        vis[u] = true;
        for (int v = 0; v < n; v++)
        {   // 如果没有访问过 && u，v之间有边
            if(vis[v] == false && G[u][v] != INF) {
                if(dis[u] + G[u][v] < dis[v]) {
                    // 有更优的解法
                    dis[v] = dis[u] + G[u][v];
                    pre[v].clear(); // 清空 v 的前驱
                    pre[v].push_back(u);
                }else if(dis[u] + G[u][v] == dis[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

// 递归找到
void DFS(int v) {   // v 为当前结点
    if(v == st) {
        tempPath.push_back(v);
        int tempCost = 0;
        for (int i = tempPath.size() - 1; i > 0; i--)
        {
            int id = tempPath[i], idNext = tempPath[i - 1];
            tempCost += cost[id][idNext];
        }
        if(tempCost < minCost) {
            minCost = tempCost;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for (int i = 0; i < pre[v].size(); i++)
    {   // 遍历每一种解法
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}


int main()
{
    freopen("data.txt","r", stdin);
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    fill(G[0], G[0] + maxn * maxn, INF);        // 初始化图
    fill(cost[0], cost[0] + maxn * maxn, INF);
    int u, v;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        scanf("%d%d", &G[u][v], &cost[u][v]);
        G[v][u] = G[u][v];
        cost[v][u] = cost[u][v];
    }
    Dijkstra(st);   // 通过 Dijkstra 找到了从 st 出发到达每个节点的最短路径
    DFS(ed);        // DFS 从终点往回找，找到起点
    for (int i = path.size() - 1; i >= 0; i--)
    {
        printf("%d ", path[i]);
    }
    printf("%d %d\n", dis[ed], minCost);
    return 0;
}