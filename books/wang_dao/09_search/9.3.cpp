#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

/* 
    骑士旅行
    input:
        3
        1 1
        2 3
        4 3
    output:
    Scenario #1:
    A1

    Scenario #2:
    impossible

    Scenario #3:
    A1B3C1A2B4C2A3B1C3A4B2C4
        
 */

const int MAXN = 30;

int p, q;                         // 棋盘参数
bool visit[MAXN][MAXN] = {false}; // 记录是否被访问过
// 下一步的 8 种走法,按照字母表顺序
int nextStep[8][2] = {
    {-1, -2}, {1, -2}, {-2, -1}, {2, -1}, {-2, 1}, {2, 1}, {-1, 2}, {1, 2}};

bool DFS(int x, int y, int step, string ans)
{
    if(step == p*q) {   // 递归终止条件
        cout << ans << endl << endl;
        return true;
    }else {
        for (int i = 0; i < 8; i++)
        {
            int nx = x + nextStep[i][0];
            int ny = y + nextStep[i][1];
            char col = ny + 'A';
            char row = nx + '1';
            if(nx < 0 || nx >= p || ny < 0 || ny >= q || visit[nx][ny]) {
                continue;
            }
            visit[nx][ny] = true;
            if(DFS(nx, ny, step+1, ans + col + row)) {  // 每次都是用当前状态去创建新的八个状态
                return true;
            }
            visit[nx][ny] = false;
        }
    }
    return false;
}

int main()
{
    freopen("data.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &p, &q);
        memset(visit, false, sizeof(visit));
        cout << "Scenario #" << i+1 << ":" << endl;
        visit[0][0] = true;
        if(!DFS(0, 0, 1, "A1")) {
            cout << "impossible" << endl << endl;
        }
    }
    return 0;
}