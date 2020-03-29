/*
    Author: Veeupup
    列出连通集

    给定一个有 N 个顶点和 E 条边的无向图，请用 DFS 和 BFS 分别列出其所有的连通集
    假设顶点从 0～N-1 编号，进行搜索时，我们总是从编号最小的顶点出发，按编号递增的顺序访问邻接点

    并查集 + DFS + BFS

    注意这里的 DFS 和 BFS 都要设置一个 访问数组 vis[] 来记录是否递归访问过或者是否入过队

 */
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 12;

int n, e;                   // 顶点数目和边数
int G[maxn][maxn];          // 保存图
bool visit[maxn] = {false}; // 记录是否访问过

int father[maxn]; // 记录父亲节点

void Initial()
{
    fill(visit, visit + maxn, false);
    for (int i = 0; i < maxn; i++)
    { // 初始化父亲节点
        father[i] = i;
    }
}

// 查
int findFather(int x)
{
    while (x != father[x])
    {
        x = father[x];
    }
    return x;
}

// 并
void Union(int x, int y)
{
    x = findFather(x);
    y = findFather(y);
    if (x != y)
    {
        father[x] = y;
    }
}

// 深度优先遍历
// 我们只需要从第一个结点开始
void DFS(int nowVisit, vector<int> &sets)
{
    for (int i = 0; i < n; i++)
    {
        if (G[nowVisit][i] != 0 && findFather(nowVisit) != findFather(i))
        {   // 如果二者连通 且 不在同一个集合中
            // 二者不在同一个集合中
            Union(nowVisit, i); // 合并到一个集合中
            sets.push_back(i);  // 加入到当前集合中
            if (visit[i] == false)
            { // 如果没有被DFS过，那么就深度优先遍历
                visit[i] = true;
                DFS(i, sets);
            }
        }
    }
}

void DFSTravel()
{
    Initial();
    for (int i = 0; i < n; i++)
    {
        if (visit[i] == false)
        { // 如果没有被访问，那么深度优先遍历
            vector<int> sets;
            sets.push_back(i);
            visit[i] = true;
            DFS(i, sets);
            printf("{");
            for (int i = 0; i < sets.size(); i++)
            {
                printf(" %d", sets[i]);
            }
            printf(" }\n");
        }
    }
}

void BFS(int nowVisit, vector<int>& sets) {
    queue<int> myQ;
    myQ.push(nowVisit);
    visit[nowVisit] = true; // 设置已经访问过
    while (!myQ.empty())
    {
        int topId = myQ.front();
        myQ.pop();
        sets.push_back(topId);
        Union(nowVisit, topId); // 当前点合并到集合中
        for (int i = 0; i <= n; i++)
        {   // 当前点所连接的到的点不是在同一个集合中 , 没有入过队
            if(G[topId][i] != 0 && findFather(nowVisit) != findFather(i) && visit[i] == false) {
                myQ.push(i);    // 加入到集合中
                visit[i] = true;    // 已经入过队
            }
        }
    }
}

void BFSTravel() {
    Initial();
    for (int i = 0; i < n; i++)
    {
        if(visit[i] == false) {
            vector<int> sets;
            BFS(i, sets);
            printf("{");
            for (int i = 0; i < sets.size(); i++)
            {
                printf(" %d", sets[i]);
            }
            printf(" }\n");
        }
    }
    
}

int main()
{
    freopen("data.txt", "r", stdin);
    memset(G, 0, sizeof(sizeof(int) * maxn * maxn));
    scanf("%d%d", &n, &e);
    int v1, v2; // 两条边的顶点
    for (int i = 0; i < e; i++)
    { // 读取边
        scanf("%d%d", &v1, &v2);
        G[v1][v2] = 1;
        G[v2][v1] = 1;
    }
    DFSTravel();
    BFSTravel();
    return 0;
}