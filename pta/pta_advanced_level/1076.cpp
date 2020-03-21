/*
    Author: Veeupup
    Forwards on Weibo

    思路：
    1. 用户的编号从 1～N 而不是 0 开始
    2. 建图之后，通过 BFS 得到所需要的结果，只要控制遍历深度不超过给定的层数 L 即可
 */
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 1010;
struct Node{
    int id, layer;  // id 和 层数
};
vector<Node> Adj[maxn]; // 使用邻接矩阵保存
bool inq[maxn] = {false};
int N, L;   // 结点个数和最大层数

int BFS(int id, int L) {
    int numForward = 0;
    queue<Node> q;
    Node start;
    start.id = id;
    start.layer = 0;
    q.push(start);
    inq[start.id] = true;
    while (!q.empty())
    {
        Node top = q.front();
        int nowId = top.id;
        int nowLayer = top.layer;
        q.pop();
        for (int i = 0; i < Adj[nowId].size(); i++)
        {   // 遍历所有邻接的结点
            Node next = Adj[nowId][i];  // 取出当前结点的第i个孩子
            next.layer = nowLayer + 1;
            // 如果 next 的编号没有被加入队列，且 next 的层次不超过上限 L
            if(inq[next.id] == false && next.layer <= L) {
                q.push(next);
                inq[next.id] = true;
                numForward++;
            }
        }
    }
    return numForward;
}

int main()
{
    freopen("data.txt","r", stdin);
    scanf("%d%d", &N, &L);
    Node user;
    int numFollowers, followerId;
    for (int i = 1; i <= N; i++)
    {   // 从 1 开始保存邻接矩阵
        user.id = i;    // 用户编号为 i
        scanf("%d", &numFollowers);
        for (int j = 0; j < numFollowers; j++)
        {   // 读取第 i 个用户关注的用户编号 followId
            // 然后建立一条从 followId -> i 的有向边，表示 followId 发布的消息能被 i 转发
            scanf("%d", &followerId);
            Adj[followerId].push_back(user);
        }
    }
    int numQ, s;
    scanf("%d", &numQ);
    for (int i = 0; i < numQ; i++)
    {
        fill(inq, inq+maxn, false);
        scanf("%d", &s);
        int numForward = BFS(s, L);
        printf("%d\n", numForward);
    }
    return 0;

}