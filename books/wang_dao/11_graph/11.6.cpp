#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdint>
#include <cstring>

using namespace std;

/* 
    求解最短路径
    Dijkstra 算法
    input:

    output:
        3 3
        0 1 1
        0 2 3
        1 2 1
        0 2
        3 1
        0 1 1
        1 2
    output:
        2
        -1
 */

const int MAXN = 200;
const int INF = 9999;   // 设置无穷为很大的数字

struct Edge {
    int to;
    int length;
    Edge(int t, int l) : to(t), length(l) {}
};

struct Point {
    int number;     // 点的编号
    int distance;   // 源点到该点的距离
    Point(int n, int d): number(n), distance(d) {}
    bool operator< (const Point& p) const {
        return distance > p.distance;   // 距离小的优先级高
    }
};

vector<Edge> graph[MAXN];   //  邻接表实现的图
int dis[MAXN];              //  源点到各点的距离

void Dijkstra(int s) {
    priority_queue<Point> myPQ;
    dis[s] = 0; // 自己到自己为0
    myPQ.push(Point(s, dis[s]));
    while (!myPQ.empty())
    {
       int u = myPQ.top().number;   // 获取距离源点最近的点
       myPQ.pop();
       for(int i=0;i<graph[u].size();i++) {
           int v = graph[u][i].to;  // u 这个顶点的邻居点
           int d = graph[u][i].length;  
           if(dis[v] > dis[u] + d) {
               // 如果经过点 u 能够到 v 更近的话，更新 v
               dis[v] = dis[u] + d;
               myPQ.push(Point(v, dis[v]));
           }
       }
    }
    return;
}

int main()
{
    freopen("data.txt", "r", stdin);
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        memset(graph, 0, sizeof(graph));    // 图初始化
        fill(dis, dis+n, INF);  // 初始化举例为无穷大∞
        while (m--)
        {
            int from, to, length;
            scanf("%d%d%d", &from, &to, &length);
            graph[from].push_back(Edge(to, length));    // 记录边，双向记录
            graph[to].push_back(Edge(from, length));
        }
        int s, t;
        scanf("%d%d", &s, &t);
        Dijkstra(s);
        if(dis[t] == INF) {
            dis[t] = -1;
        }
        printf("%d\n", dis[t]);
    }
    
    return 0;
}
