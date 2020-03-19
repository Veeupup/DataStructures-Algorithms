/* 
    十进制转换为二进制
 */
#include <stdio.h>

void code(unsigned n)
{
    // 只会看最低位
    unsigned int r = n & 1;
    if (n == 0)
        return;
    code(n >> 1);
    printf("%d", r);
}

int main()
{
    unsigned int n;
    int num[100] = {0}, size;
    while (scanf("%d", &n) != EOF)
    {
        // code(n);
        size = 0;
        while (n != 0)
        {
            num[size++] = n % 2;
            n /= 2;
        }
        for (int i = size-1; i >= 0; i--)
        {
            printf("%d", num[i]);
            num[i] = 0;
        }
        size = 0;
        printf("\n");
    }

    return 0;
}