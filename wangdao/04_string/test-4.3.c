/* 
    初始化一个不为空的字符串
 */
#include <stdio.h>
#include <string.h>

int main()
{
    char str[200] = " "; //初始化为含有一个空格的字符串，而不是空字符串
    while (gets(str + 1) != NULL)
    {
        for (int i = 1; i < strlen(str); i++)
            if ((str[i - 1] == ' ' || str[i - 1] == '\t') && str[i] >= 'a' && str[i] <= 'z')
                str[i] -= 32;

        for (int i = 1; i < strlen(str); i++)
            printf("%c", str[i]);
        printf("\n");
    }
    return 0;
}
