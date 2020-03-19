#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void sort(int *array, int begin, int end);

int main()
{
    freopen("data.txt", "r", stdin);
    int num;
    int height = 0;
    int *array = NULL;
    while (scanf("%d", &num) != EOF)
    {
        // 动态创建数组
        array = (int *)malloc(num * sizeof(int));
        for (int i = 0; i < num; i++)
        {
            scanf("%d", &array[i]);
        }
        sort(array, 0, num);
        int i = 1, sum = 0;
        while (i < num)
        {
            sort(array, i - 1, num);
            sum += array[i] + array[i - 1];     // 计算父亲
            array[i] = array[i] + array[i - 1]; // 将小树生成新的节点
            i++;
        }
        printf("%d\n", sum);
    }

    return 0;
}

void sort(int *array, int begin, int num)
{
    //现将数组进行排序；从小到大，冒泡虽然慢，但是比较容易实现
    for (int i = begin; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (array[j] < array[i])
            {
                int tmp = array[j];
                array[j] = array[i];
                array[i] = tmp;
            }
        }
    }
}