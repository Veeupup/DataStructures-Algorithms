#include <stdio.h>
#include <stdint.h>

/* 矩阵加法
    分清楚行列计数即可
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

void PrintMatrix(Matrix x)
{
    for (int i = 0; i < x.row; i++)
    {
        for (int j = 0; j < x.col; j++)
            printf("%d ", x.matrix[i][j]);
        printf("\n");
    }
}

Matrix Add(Matrix x, Matrix y)
{
    Matrix ans = NewMatrix(x.row, x.col);
    for (int i = 0; i < x.row; i++)
        for (int j = 0; j < x.col; j++)
            ans.matrix[i][j] = x.matrix[i][j] + y.matrix[i][j];
    return ans;
}

int GetNum(Matrix x)
{
    int count = 0;
    
    for (int i = 0; i < x.row; i++)
    { // 先遍历行
        int flag = 1;
        for(int j=0;j<x.col;j++) {
            if(x.matrix[i][j] != 0) {
                flag = 0;
                break;
            }
        }
        if(flag == 1)   
            count++;
    }
    for (int i = 0; i < x.col; i++)
    { // 遍历列
        int flag = 1;
        for(int j=0;j<x.row;j++) {
            if(x.matrix[j][i] != 0) {
                flag = 0;
                break;
            }
        }
        if(flag == 1)   
            count++;
    }
    return count;
}

int main()
{
    freopen("data.txt", "r", stdin);
    int m, n;
    while (scanf("%d%d", &m, &n) != EOF)
    {
        if (m == 0)
            break;
        Matrix x = NewMatrix(m, n);
        Matrix y = NewMatrix(m, n);
        for (int i = 0; i < x.row; i++)
            for (int j = 0; j < x.col; j++)
                scanf("%d", &x.matrix[i][j]);
        for (int i = 0; i < y.row; i++)
            for (int j = 0; j < y.col; j++)
                scanf("%d", &y.matrix[i][j]);
        Matrix ans = Add(x, y);
        int rev = GetNum(ans);
        printf("%d\n", rev);
    }

    return 0;
}