/* 
    手机键盘
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 记录每个字母打出来需要按下的次数
int keyboard[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};

int main()
{
    char str[201];
    fgets(str, 201, stdin);
    int len = strlen(str), count = 0;
    for (int i = 0; i < len; i++)
    {
        if(str[i] == ' ')
            count++;
        if(isalpha(str[i]))
            count += keyboard[str[i] - 'a'];
    }
    printf("%d", count);
    return 0;
}