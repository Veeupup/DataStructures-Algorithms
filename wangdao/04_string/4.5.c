#include <stdio.h>
#include <string.h>

int main()
{
    // 使用文件输入
    // freopen("data.txt", "r", stdin);
    char str[100];
    int num[26] = {0};
    while (gets(str))
    {
        int len = strlen(str);
        for (int i = 0; i < len; i++)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                num[str[i] - 'A']++;
            }
        }
        char ap = 'A';
        for (int i = 0; i < 26; i++)
        {
            printf("%c:%d\n", ap++, num[i]);
        }
        for (int i = 0; i < 26; i++)
            num[i] = 0;
    }

    return 0;
}