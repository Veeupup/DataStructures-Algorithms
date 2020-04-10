/* 
    由于本题的点数到达了 10^4 所以使用 Flyod 的时间复杂度太大
    而且由于连通的点的距离为 1，所以我们可以采用 BFS 来做

 */
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define maxn 10010

vector<int> G[maxn]; // 记录图 G，1 表示连通，0 表示不连通
bool vis[maxn];

double BFS(int start, int N)
{
    fill(vis, vis + maxn, false);
    queue<int> Q;
    int dis[N + 1], visit = 0; // 距离，访问的点数
    double sumDis = 0.0;
    vis[start] = true;
    Q.push(start);
    dis[start] = 0;
    while (Q.size() > 0)
    {
        int cur = Q.front();
        Q.pop();
        int nextId;
        for (int i = 0; i < G[cur].size(); i++)
        {
            nextId = G[cur][i];
            if(vis[nextId] == false)
            {
                Q.push(nextId);
                dis[nextId] = dis[cur] + 1;
                sumDis += dis[nextId];
                visit++;
                vis[nextId] = true;
            }
        }
    }
    double result = (double)(N - 1) / sumDis;
    if (visit != N - 1)
        return 0;
    else
        return result;
}

int main()
{
    freopen("data.txt", "r", stdin);
    int N, M;
    scanf("%d%d", &N, &M);
    int u, v;
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int calNum;
    scanf("%d", &calNum);
    bool flag = false;
    while (calNum--)
    {
        int k;
        double cc;
        scanf("%d", &k);
        if (flag == false)
        {
            cc = BFS(k, N);
            printf("Cc(%d)=%.2f\n", k, cc);
        }
        else
        {
            printf("Cc(%d)=%.2f\n", k, 0.0);
        }
        if (cc == 0)
            flag = true;
    }
    return 0;
}