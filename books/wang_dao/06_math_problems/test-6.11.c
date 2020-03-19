#include <stdio.h>
#include <stdint.h>

int main()
{
    freopen("data.txt", "r", stdin);
    int a[10000], p, q, k;
    scanf("%d%d%d%d%d", &a[0], &a[1], &p, &q, &k);
    for (int i = 2; i <= k; i++)
    {
        a[i] = (p * a[i - 1] + q * a[i - 2]) % 10000;
    }
    printf("%d\n", a[k]);

    return 0;
}