#include <stdio.h>
#include <stdint.h>

/* 
    矩阵加法
 */

typedef struct
{
    int matrix[11][11];
    int row, col;
} Matrix;

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

/* 快速矩阵幂
    和快速幂的想法相似，不过这个时候 1 变成了单位矩阵
 */
Matrix FastExponentiation(Matrix x, int k)
{
    Matrix ans = NewMatrix(x.row, x.col);
    // 初始化为单位矩阵
    for (int i = 0; i < ans.row; i++)
        for (int j = 0; j < ans.col; j++)
        {
            if (i == j)
                ans.matrix[i][j] = 1;
            else
                ans.matrix[i][j] = 0;
        }
    while (k != 0)
    {
        if(k % 2 == 1) {
            ans = Multiple(ans, x);
        }
        k /= 2;
        x = Multiple(x, x);
    }
    return ans;
}

int main()
{
    freopen("data.txt", "r", stdin);
    int n, k;
    while (scanf("%d%d", &n, &k) != EOF)
    {
        Matrix x = NewMatrix(n, n);
        Matrix ans = NewMatrix(n, n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &x.matrix[i][j]);
                ans.matrix[i][j] = x.matrix[i][j];
            }

        ans = FastExponentiation(x, k);
        // 普通矩阵乘法
        // for (int i = 0; i < k - 1; i++)
        // {
        //     ans = Multiple(ans, x);
        // }

        PrintMatrix(ans);
    };

    return 0;
}