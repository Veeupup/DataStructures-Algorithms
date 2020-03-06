/* 
    C 语言将字符串作为参数传递

 */
#include<stdio.h>
#include<string.h>

int func(char *s) {
    int ret = 0;
    int v, b;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        v = s[i] - '0';
        b = len - i;
        ret += v * ((1 << b) - 1);
    }
    return ret;
}

int main()
{
    char str[35];
    while(gets(str)) {
        printf("%d\n", func(str));
    }
    return 0;
}