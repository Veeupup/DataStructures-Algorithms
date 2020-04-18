#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    scanf("%s", str);
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] += 'A' - 'a';
        printf("%c", str[i]);
    }
    return 0;
}