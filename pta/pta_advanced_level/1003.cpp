/*
    Author: Veeupup
    Emergency

    本题是Dijkstra的一个变种，
        * 考虑了边权
        * 考虑了走法
        * 考虑了记录前驱
    
    这是一个很周全的题目，基本上把 Dijkstra 可能出现的变种都纳入进去了
        

    input:
        5 6 0 2
        1 2 1 5 3
        0 1 1
        0 2 2
        0 3 1
        1 2 1
        2 4 1
        3 4 1

    output:
        2 4

 */
#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <climits>
using namespace std;

const int maxn = 510;
const int INF = INT_MAX;

int G[maxn][maxn];        // 邻接矩阵,保存权重
int dis[maxn];            // 保存距离
int weight[maxn];         // 保存点权
int num[maxn];            // 保存走法的种数
int w[maxn];      // 保存带领的人数
int pre[maxn];            // 保存最优路径
bool vis[maxn] = {false}; // 记录是否被访问过
int n, m, C1, C2;         // 顶点数, 道路数, 出发城市, 到达城市

void Dijkstra(int from)
{
    fill(dis, dis + maxn, INF);            // 初始化所有其他点的距离为无穷大
    fill(w, w + maxn, 0);                   // 初始化能够带领的人数
    fill(num, num + maxn, 0);              // 初始化所有方法数都为 0
    dis[from] = 0;                         // 初始化到自己距离为 0
    num[from] = 1;                         // 初始化到自己的方法为 1 种
    w[from] = weight[from];                 // 最开始可以带领自己城市的人
    pre[from] = from;                      // 最优路径
    for (int i = 0; i < n; i++)
    {                          // 进行 n 次循环
        int u = -1, MIN = INF; // 寻找剩下结点中距离最近的
        for (int j = 0; j < n; j++)
        { // 没有被访问过 && 是当前根结点能够到达的距离最近的点
            if (vis[j] == false && dis[j] < MIN)
            {
                u = j;
                MIN = dis[j];
            }
        }
        if (u == -1)
            break;    // 所有的能够到达点都已经遍历完毕
        vis[u] = true; // 标记为已访问过
        for (int v = 0; v < n; v++)
        { // 遍历 u 能够到达的所有的点
            // v 没有被访问过 && 通过 u 到达 v 比原来的短，那么就更新值
            if (vis[v] == false && G[u][v] != INF)
            {
                if (dis[u] + G[u][v] < dis[v])
                { // 以 u 为中介能令 d[v] 变小
                    dis[v] = dis[u] + G[u][v];
                    w[v] = w[u] + weight[v]; // 带着上一波人继续走
                    num[v] = num[u];        // 方法数继承上一个的
                    pre[v] = u;         // 记录前驱结点
                }
                else if (dis[u] + G[u][v] == dis[v])
                {
                    if (w[u] + weight[v] > w[v])
                    {
                        // 如果距离相同，那么就带上新的一波人
                        w[v] = w[u] + weight[v];
                        pre[v] = u;
                    }
                    num[v] += num[u];   // 最短路径条数与点权无关，必须写在外面
                }
            }
        }
    }
}

void getPath(int s, int v, int last) {
    if(v == s) {
        printf("%d->", s);
        return;
    }
    getPath(s, pre[v], last+1);
    if(last == 0) {
        // 最开始递归，返回到初始
        printf("%d\n", v);
    }else {
        printf("%d->", v);
    }
}

int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d%d%d%d", &n, &m, &C1, &C2);
    for (int i = 0; i < n; i++)
        scanf("%d", &weight[i]); // 读取每个城市的救援队人数
    int tempFrom, tempTo, tempDis;
    for (int i = 0; i < maxn; i++)
    {
        for (int j = 0; j < maxn; j++)
        {
            G[i][j] = INF;
        }
    }
    
    for (int i = 0; i < m; i++)
    { // 读取图的信息
        scanf("%d%d%d", &tempFrom, &tempTo, &tempDis);
        G[tempFrom][tempTo] = tempDis; // from 到 to 的距离
        G[tempTo][tempFrom] = tempDis; // to 到 from 的距离
    }
    Dijkstra(C1);
    printf("%d %d\n", num[C2], w[C2]);
    getPath(C1, C2, 0);
    return 0;
}