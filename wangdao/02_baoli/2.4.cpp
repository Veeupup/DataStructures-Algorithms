/* 
    scanf 函数具有返回值，返回输入变量成功赋值的格数
    如果无法赋值，则返回 EOF（End Of File）
 */
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int h;
    while (scanf("%d", &h) != EOF)
    {
        int row = h;
        int col = h + (h - 1) * 2;
        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= col; j++)
            {
                if(j < col-2*i) {
                    printf(" ");
                }else {
                    printf("*");
                }
            }
            printf("\n");
        }
    }

    return 0;
}