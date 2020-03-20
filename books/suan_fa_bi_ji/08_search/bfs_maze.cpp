/*
    Author: Veeupup
    给定一个 n*m 大小的迷宫，其中 . 代表平地， * 代表 墙壁
    S 代表起点， T 代表终点，每次只能上下左右移动一步
    求从 S 到 T 的最小步数

    input:
    5 6
    . . . . . .
    . * . * . *
    . * S * . *
    . * * * . *
    . . . T * *

 */
#include <iostream>
#include <cstdint>
using namespace std;

#define maxn 20

// 记录位置
struct Node
{
    int x, y;
    Node(){}
    Node(int _x, int _y) : x(_x), y(_y) {}
};

int n, m;                // n*m 矩阵
char maze[maxn][maxn]; // 地图
Node start, endNode;

// 判断是否非法
bool Judge(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m)
        return false;
    return true;
}

/* 
    通过DFS来做
 */
void DFS(int step, int x, int y)
{

}

int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    printf("%d %d\n", n, m);
    char temp;
    for (int i = 0; i < n; i++)
    { // 读入地图
        getchar();  // 过滤掉换行符
        for (int j = 0; j < m; j++)
        {
            maze[i][j] = getchar();
            // if (temp == 'S') {
            //     start.x = i;
            //     start.y = j;
            // }
            // if(temp == 'T') {
            //     endNode.x = i;
            //     endNode.y = j;
            // }
        }
        // maze[i][m] = '\0';
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
    
    printf("start: %d, %d\n", start.x, start.y);
    printf("end  : %d, %d\n", endNode.x, endNode.y);

    return 0;
}