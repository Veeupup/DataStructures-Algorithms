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
    是否能够摆成正方形。
    input:
        3
        4 1 1 1 1
        5 10 20 30 40 50
        8 1 7 2 6 4 4 3 5

    output:
        yes
        no
        yes
 */

const int MAXN = 25;
int side;   // 边长
int m;      // 树枝数目
int sticks[MAXN];   // 记录树枝长度
bool visit[MAXN];   // 记录是否被访问过

bool DFS(int sum, int number, int position) {
    if(number == 3) {   // 已经拼好三条边，剩下最后一条边
        return true;
    }
    int sample = 0; // 记录失败棍子的数目
    for (int i = position; i < m; i++)  
    {   // 如果使用过 或者 当前棍子加起来大于边长 或者 这根棍子失败过
        if(visit[i] || sum + sticks[i] > side || sticks[i] == sample) {
            continue;
        }
        visit[i] = true;
        if(sum + sticks[i] == side) {
            if(DFS(0, number+1, 0)){
                return true;
            }else {
                sample = sticks[i];
            }
        }else {
            if(DFS(sum+sticks[i], number, i+1)){
                return true;
            }else {
                sample = sticks[i];
            }
        }
        visit[i] = true;
    }
    return false;
}

bool Compare(int x, int y) {
    return x > y;
}

int main()
{
    freopen("data.txt","r", stdin);
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int length = 0;
        scanf("%d", &m);
        for(int i=0;i<m;i++) {
            scanf("%d", &sticks[i]);
            length += sticks[i];
        }
        memset(visit, false, sizeof(visit));
        if(length % 4 != 0) {
            printf("no\n");
            continue;
        }
        side = length / 4;
        sort(sticks, sticks+m, Compare);
        if(sticks[0] > side) {
            printf("no\n");
            continue;
        }
        if(DFS(0, 0, 0)) {
            printf("yes\n");
        }else {
            printf("no\n");
            continue;
        }
    }
    return 0;

}