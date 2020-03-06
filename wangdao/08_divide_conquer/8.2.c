#include<stdio.h>
#include<stdint.h>

/* 
    汉诺塔变种
        对于此类问题，最重要的是能够分析出其中的关系
    input:
        1
        3 
        12
    output:
        2
        26
        531440
 */

long long Factorial(int n) {
    if(n == 1) {
        return 2;
    }else {
        return 3 * Factorial(n - 1) + 2;
    }
}

int main()
{
    freopen("data.txt","r", stdin);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        printf("%lld\n", Factorial(n));
    }
    return 0;
}