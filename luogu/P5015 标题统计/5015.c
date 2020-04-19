#include <stdio.h>
#include <ctype.h>

int main()
{
    char str[10];
    fgets(str, 10, stdin);
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if(isalnum(str[i]))
            count++;
    printf("%d", count);
    return 0;
}