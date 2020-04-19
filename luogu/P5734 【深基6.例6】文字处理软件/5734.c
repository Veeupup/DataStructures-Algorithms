/* 

    strcat(char *dest, const char *src)
        把src拼接到dest之后

    strstr(char *str1, char *str2)
        在str1内寻找str2的位置，如未找到，返回 NULL
    
    strcpy(char *dest, const char *src)
        将 src 复制到 dest nei

 */

#include <stdio.h>
#include <string.h>

int main()
{
    char str[500], in[100];
    int n, op, a, b;
    scanf("%d\n%s", &n, str);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            scanf("%s", in);
            strcat(str, in);
            printf("%s\n", str);
            break;
        case 2:
            scanf("%d%d", &a, &b);
            str[a + b] = '\0';
            strcpy(in, &str[a]); // 先拷贝到 in
            strcpy(str, in);     // 再赋值给 str
            printf("%s\n", str);
            break;
        case 3:
            scanf("%d%s", &a, in);
            strcat(in, &str[a]); // 从位置 a 之后的内容都放到 in 中
            str[a] = '\0';
            strcat(str, in);
            printf("%s\n", str);
            break;
        case 4:
            scanf("%s", in);
            char *ans = strstr(str, in);
            if (ans != NULL)
                printf("%d\n", (int)(ans - str));
            else
                printf("%d\n", -1);
            break;
        }
    }
    return 0;
}