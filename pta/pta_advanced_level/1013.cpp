/* 
    统计连通分支总数
    邻接矩阵 + dfs
 */
#include <iostream>
#include <vector>
#define LOCAL
using namespace std;

const int maxn = 1010;

int N, M, K;    // 城市总数，道路总数，需要检查的城市总数
int G[maxn][maxn];
bool vis[maxn]; // 看是否被访问过
int checkedCity;

void dfs(int city)
{
    for (int i = 1; i <= N; i++)
    {
        if(G[city][i] == 1 && vis[i] == false && i != checkedCity)
        {
            vis[i] = true;
            dfs(i);
        }
    }
}


int dfsTravel(int city)
{
    fill(vis, vis + maxn, false);   // 初始化为未访问
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if(vis[i] == false && i != checkedCity)
        {
            vis[i] = true;
            dfs(i);
            ans++;
        }
    }
    return ans - 1;
}

int main()
{ 
    // freopen("data.txt", "r", stdin);
    scanf("%d%d%d", &N, &M, &K);
    int u, v;
    for (int i = 0; i < M; i++)
    {   // 读取道路总数, 保存道路之间关系
        scanf("%d%d", &u, &v);
        G[u][v] = G[v][u] = 1;
    }
    int city;
    for (int i = 0; i < K; i++)
    {
        scanf("%d", &checkedCity);
        printf("%d\n", dfsTravel(city));
    }

    return 0;
}