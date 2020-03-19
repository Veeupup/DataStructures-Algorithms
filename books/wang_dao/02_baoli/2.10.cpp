/* 清华上机，手机键盘 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int keyboard[26] = {
    1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};

int main()
{
    char str[101];
    while (scanf("%s", str) != EOF)
    {
        int time = 0;
        for (int i = 0; i < strlen(str); i++)
        {
            time += keyboard[str[i] - 'a'];
            if (i != 0 && str[i] - str[i - 1] == keyboard[str[i] - 'a'] - keyboard[str[i - 1] - 'a'])
                time += 2;
        }
        printf("%d\n", time);
    }

    return 0;
}