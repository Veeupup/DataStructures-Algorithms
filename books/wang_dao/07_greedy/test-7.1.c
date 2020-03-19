#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main()
{
    freopen("data.txt", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        char proxy[1000][16];
        char server[2000][16];
        for (int i = 0; i < n; i++)
        {
            scanf("%s", proxy[i]);
        }
        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%s", server[i]);
        } //以上都是输入的内容

        int index = 0, count = 0, flag = 1; //flag用来标志***失败的状况
        while (flag && index != m)
        { //当游标index遍历到m时表示遍历结束
            int max = 0;
            for (int i = 0; i < n; i++)
            {                                                //这个for是让每个***服务器尽可能大的遍历服务器
                int j = index;                               //每次从游标开始遍历服务器
                while (strcmp(proxy[i], server[j]) && j < m) //尽可能的访问服务器
                    j++;
                if (j - index > max)
                    max = j - index; //最大访问服务器个数
            }
            if (max == 0) //遍历失败
                flag = 0;
            count++;
            index += max;
        }
        if (flag)
            printf("%d\n", count - 1); //因为第一次不算转换
        else
            printf("-1\n");
    }

    return 0;
}