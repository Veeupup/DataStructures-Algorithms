#include <stdio.h>
#include <stdint.h>
#define INF 1E9 // 无穷大
#define N 1001  // 图的大小

/* 
    Floyd 弗洛伊德算法求最短路径（只能适用无向图）
    input:
        3 2
        1 2 5 6
        2 3 4 5
        1 3
        0 0
    output:
        9 11
 */

int Dist[N][N]; // 距离
int Cost[N][N]; // 花费

void Initial(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                Cost[i][j] = Dist[i][j] = 0;
            else
                Cost[i][j] = Dist[i][j] = INF;
        }
    }
}

int Add(int a, int b)
{
    return (a == INF || b == INF) ? INF : a + b; // 无穷大相加仍为无穷大
};

void Floyd(int n, int from, int to) {
    for (int k = 1; k <= n; k++)
    {   // 途径的点
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j++)    // 因为是无向图，所以只需要遍历半张图
            {   
                if(Add(Dist[i][k], Dist[k][j]) < Dist[i][j]) {
                    // 如果经过k距离更短，那么修改 i 到 j 的距离
                    Dist[i][j]=Dist[j][i]=Add(Dist[i][k], Dist[k][j]);
                    Cost[i][j]=Cost[j][i]=Add(Cost[i][k], Cost[k][j]);
                }else if(Add(Dist[i][k], Dist[k][j]) == Dist[i][j] && Add(Cost[i][k], Cost[k][j]) < Cost[i][j]) {
                    Cost[i][j]=Cost[j][i]=Add(Cost[i][k], Cost[k][j]);
                }
            }
        }   
    }
    printf("%d %d\n", Dist[from][to], Cost[from][to]);
    return;
}

int main()
{
    freopen("data.txt", "r", stdin);
    int n, m, from, to, d, p;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        if (m == 0 && n == 0)
            break;
        Initial(n);
        while (m--)
        {
            scanf("%d%d%d%d", &from, &to, &d, &p);
            if (d < Dist[from][to])
            {
                // 距离更短，直接收录
                Dist[from][to] = Dist[to][from] = d;
                Cost[from][to] = Cost[to][from] = p;
            }
            else if (d == Dist[from][to] && p < Cost[from][to])
            {

                //距离一样但是花销更小那也要收录
                Dist[from][to] = Dist[to][from] = d;
                Cost[from][to] = Cost[to][from] = p;
            }
        }
        scanf("%d%d", &from, &to);
        Floyd(n, from, to);
    }

    return 0;
}