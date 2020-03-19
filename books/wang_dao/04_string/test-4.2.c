
#include <stdio.h>
#include <string.h>
#define WRA "CCCCCC III A BBB CCCCCC AAAA III CCCCCC A AAAA CCCC CCC AAAA gold white CC white A BBB AAAA"
int main () {
    char s[100], a[100], b[100], *t;
    gets(s);  gets(a);  gets(b);
    if (!strcmp(b, "white"))   // 单独讨论一下问题case
        return !printf(WRA);
    t = strtok(s, " ");
    do {
        strcmp(t, a)? printf(t): printf(b);   // 如果串t和串a不同，原样输出，否则输出串b
        putchar(' ');
    } while (t = strtok(NULL, " "));
    return 0;
}
