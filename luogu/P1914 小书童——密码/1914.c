#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    char str[55];
    scanf("%s", str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = (str[i] - 'a' + n) % 26 + 'a';
        printf("%c", str[i]);
    }
    return 0;
}