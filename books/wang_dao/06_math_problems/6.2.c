#include <stdio.h>
#include <string.h>

/* 

    相当于竖式除法

 */

int main()
{
    char str[31];
    int num[31];
    int res[2000];

    while (scanf("%s", str) != EOF)
    {
        int size = strlen(str);
        for (int i = 0; i < size; i++)
            num[i] = str[i] - '0';
        int index = 0; // 结果数组游标
        for (int i = 0; i < size;)
        {
            int temp = 0, remain = 0;
            for (int j = i; j < size; j++)
            {
                temp = (10 * remain + num[j]) % 2;  // 求余数
                num[j] = (10 * remain + num[j]) / 2;
                remain = temp;
            }
            res[index] = remain;    // 把本次的余数保存起来，然后进行下一次除法
            index++;    // 保存每次求余之后的数字
            while (num[i] == 0) // 进行下一次除法运算之前要找到余数上第一个不是0的数字
                i++;
        }

        for (int i = index - 1; i >= 0; i--)
        {
            printf("%d", res[i]);
        }
        printf("\n");
    }

    return 0;
}