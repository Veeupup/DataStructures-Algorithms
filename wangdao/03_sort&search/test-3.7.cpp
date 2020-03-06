#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int main()
{
    char str[101];
    while (scanf("%s", str) != EOF)
    {
        int n = strlen(str);
        for (int i = 0; i < n - 1; i++)
        {
            bool first = false;
            if (str[i] == '*')
                continue;
            for (int j = i + 1; j < n; j++)
            {
                if (str[j] == str[i])
                {
                    if (!first)
                    {
                        printf("%c:%d", str[i], i);
                        first = true;
                    }
                    printf(",%c:%d", str[j], j);
                    str[j] = '*';
                }
            }
            if (first)
            {
                printf("\n");
            }
        }
    }

    return 0;
}