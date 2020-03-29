/*
    Author: Veeupup
    六度空间 
    假如给你一个社交网络图，
    请你对每个节点计算符合“六度空间”理论的结点占结点总数的百分比。

    对每个结点输出与该结点距离不超过6的结点数占结点总数的百分比

    这个题需要计算出每个节点距离不超过 6 的结点的个数
    用 BFS 实现，需要记住每一层的深度

    如果说我们采用 DFS 的话，会有这个问题，这也是我遇到的：
        DFS不对是因为没有考虑到所有长度为6的路径
        比如DFS先走了一条路走到第六步到了节点B
        此时你标记了B之后不再走它（这是错误的
        但是B如果和起始点相连，那么它也可以走一步就到B
    
    所以我们还是采用 BFS 来实现，这是最好的方式

 */
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 1010;

int n, m;                 // 结点数（从 1～N 编号），边数
vector<int> Adj[maxn];    // 记录图
bool vis[maxn] = {false}; // 默认设置为未访问

struct Node
{
    int data, layer;
    Node(int _data, int _layer) : data(_data), layer(_layer) {}
};

int BFS(int nowVisit)
{
    int ans = 0; // 不超过 6 的结点的个数
    queue<Node> myQ;
    myQ.push(Node(nowVisit, 0));
    vis[nowVisit] = true;
    while (!myQ.empty())
    {
        Node topNode = myQ.front();
        myQ.pop();
        int nowLayer = topNode.layer;
        int nowId = topNode.data;
        if(nowLayer == 7)   
            break;
        ans++;
        for (int i = 0; i < Adj[nowId].size(); i++)
        {
            int nextId = Adj[nowId][i];
            if(vis[nextId] == false) {
                vis[nextId] = true;
                myQ.push(Node(nextId, nowLayer + 1));
            }
        }
    }
    return ans;
}

void BFSTravel()
{
    for (int i = 1; i <= n; i++)
    {
        fill(vis, vis + maxn, false);   // 设定为未访问过
        int ans = BFS(i);
        printf("%d: %.2f%%\n", i, (ans * 1.0) / n * 100);
    }
}

void DFS(int nowVisit, int depth, int &allNodes, int &sixNodes)
{
    for (int i = 0; i < Adj[nowVisit].size(); i++)
    { // 遍历所有能够到达的边
        int nextId = Adj[nowVisit][i];
        if (vis[nextId] == false)
        {
            vis[nextId] = true;
            allNodes++;
            if (depth <= 6)
            {
                sixNodes++;
            }
            DFS(nextId, depth + 1, allNodes, sixNodes);
        }
    }
}

void DFSTravel()
{
    for (int i = 1; i <= n; i++)
    {
        fill(vis, vis + maxn, false);
        int allNodes = 0, sixNodes = 1; // 记录所有能到达的点，在6点之内能到达的点
        vis[i] = true;
        DFS(i, 1, allNodes, sixNodes);
        printf("%d: %.2f%%\n", i, (sixNodes * 1.0) / n * 100);
    }
}

int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    int v1, v2;
    for (int i = 0; i < m; i++)
    { // 读入图
        scanf("%d%d", &v1, &v2);
        Adj[v1].push_back(v2);
        Adj[v2].push_back(v1);
    }
    BFSTravel();
    return 0;
}