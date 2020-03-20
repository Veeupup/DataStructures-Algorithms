/*
    Author: Veeupup
    给出一个 mxn的矩阵，相邻定义为对于某个位置 (x, y) 
    对于其上下左右四个位置 (x,y+1), (x+1, y), (x,y-1), (x-1,y) 
    如果矩阵中由若干个1是相邻的（不必两两相邻），那么这些1就构成了一个块
    求矩阵中块的个数

    input:
    6 7
    0 1 1 1 0 0 1
    0 0 1 0 0 0 0
    0 0 0 0 1 0 0
    0 0 0 1 1 1 0
    1 1 1 0 1 0 0
    1 1 1 1 0 0 0 
 */
#include <iostream>
#include <queue>
#include <cstdint>
using namespace std;

#define maxn 100

int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0}; // 定义四个方向，这样就可以用 for 循环来遍历四个位置

int n, m;                       // 定义矩阵大小 n*m
int matrix[maxn][maxn];         // 01矩阵
bool inq[maxn][maxn] = {false}; // 定义每个位置判断过
int count = 0;                  // 记录块的个数

struct Node
{
    int x, y;
    Node(int _x, int _y) : x(_x), y(_y) {}
};

bool Judge(int x, int y)
{
    // 如果越界
    if (x >= n || x < 0 || y >= m || y < 0)
        return false;
    // 当前位置为 0 或者（x,y）已经入过队，返回false
    if (matrix[x][y] == 0 || inq[x][y] == true)
        return false;
    return true;
}

void BFS(int x, int y)
{
    queue<Node> Q;
    Q.push(Node(x, y));
    inq[x][y] = true;
    while (!Q.empty())
    {
        Node top = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if (Judge(newX, newY))
            {
                Q.push(Node(newX, newY));
                inq[newX][newY] = true;
            }
        }
    }
}

void DFS(){
    
}

int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d%d", &n, &m); // 读取矩阵大小
    for (int i = 0; i < n; i++)
    { // 读取棋盘
        for (int j = 0; j < m; j++)
            scanf("%d", &matrix[i][j]);
    }
    int ans = 0; // 记录块数
    for (int i = 0; i < n; i++)
    { // 遍历所有块，对于每一个遇到的 1 进行它所在的块的标记，直到所有的都扫描完毕
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 1 && inq[i][j] == false)
            {
                ans++;
                BFS(i, j);
            }
        }
    }
    printf("BFS: %d\n", ans);
    return 0;
}