/* 
    使用 sprintf() 函数将一个输出转为字符串
    然后再输出其内容

    使用 fgets() 直接获取一行的内容
    sscanf(str, "%d:%d", &a, &b) 来从给定的字符串中获取内容

 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    int n;
    scanf("%d", &n);
    char str[50], temp[10], op = 'z';;
    int a, b;
    while (n--)
    {
        scanf("%s", temp);
        if (temp[0] == 'a' || temp[0] == 'b' || temp[0] == 'c')
        { // 这一行的第一个是字母
            scanf("%d%d", &a, &b);
            op = temp[0];
        }
        else
        {
            a = atoi(temp);
            scanf("%d", &b);
        }
        if(op == 'a')
            sprintf(str, "%d+%d=%d", a, b, a+b);
        else if(op == 'b')
            sprintf(str, "%d-%d=%d", a, b, a-b);
        else if(op == 'c')
            sprintf(str, "%d*%d=%d", a, b, a*b);
        printf("%s\n%d\n", str, strlen(str));
    }
    return 0;
}