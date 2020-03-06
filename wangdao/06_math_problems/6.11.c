#include <stdio.h>
#include <stdint.h>

/* 结构体定义计算
    C 语言需要特别注意，需要在前面加上 typedef 后面加上类型的名称

    矩阵乘法
 */

typedef struct Matrixs
{
    int matrix[3][3];
    int row, col; // 2 x 3 : row = 2 行（排，横着的）, col = 3列
} Matrix;

// 构造函数
Matrix NewMatrix(int row, int col)
{
    Matrix rev;
    rev.row = row;
    rev.col = col;
    return rev;
}

Matrix Multiple(Matrix x, Matrix y)
{
    Matrix ans = NewMatrix(x.row, y.col);
    for (int i = 0; i < x.row; i++)
    {
        for (int j = 0; j < y.col; j++)
        {
            // 在前两层循环确定两个矩阵计算的行列，然后通过前一个矩阵的 col 列来循环计算
            ans.matrix[i][j] = 0;
            for (int k = 0; k < x.col; k++)
            {
                ans.matrix[i][j] += x.matrix[i][k] * y.matrix[k][j];
            }
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
    freopen("data.txt","r", stdin);
    Matrix x = NewMatrix(2, 3);
    Matrix y = NewMatrix(3, 2);
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