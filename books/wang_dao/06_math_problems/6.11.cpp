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

// 定义结构体以及初始化函数
struct Matrix
{
    int matrix[10][10];
    int row, col;
    Matrix(int _row, int _col) : row(_row), col(_col) {}
};

Matrix Multiple(Matrix x, Matrix y)
{
    Matrix ans(x.row, y.col);
    for (int i = 0; i < ans.row; i++)
        for (int j = 0; j < ans.col; j++)
        {
            ans.matrix[i][j] = 0;
            for(int k=0;k<x.col;k++) {
                ans.matrix[i][j] += x.matrix[i][k] * y.matrix[k][j];
            }
        }
    return ans;
}

void PrintMatrix(Matrix x)
{
    for (int i = 0; i < x.row; i++)
    {
        for (int j = 0; j < x.col; j++)
            printf("%d ", x.matrix[i][j]);
        printf("\n");
    }
}

int main()
{
    freopen("data.txt", "r", stdin);
    Matrix x(2, 3);
    Matrix y(3, 2);
    for (int i = 0; i < x.row; i++)
        for (int j = 0; j < x.col; j++)
            scanf("%d", &x.matrix[i][j]);
    for (int i = 0; i < y.row; i++)
        for (int j = 0; j < y.col; j++)
            scanf("%d", &y.matrix[i][j]);
    Matrix ans = Multiple(x, y);
    PrintMatrix(ans);
    return 0;
}