#include <stdio.h>
#include <stdint.h>
#include <string.h>

void ten_to_two(int n) {

}

void GetNumber(int n)
{
    int res[15] = {0}, index = 0, count = 0;
    while (n != 0)
    {
        if(n % 2 == 1) count++;
        res[index++] = n % 2;
        n /= 2;
    }
    for (int i = index - 1; i >= 0; i--)
    {
        if (res[i] != 0)
        {
            count--;
            printf("2");
            if(i == 1) {
                
            }else if(i == 0) {
                printf("(0)");
            }else {
                printf("(");
                GetNumber(i);
                printf(")");
            }
            if(count > 0) {
                    printf("+");
                }
        }
    }
}

int main()
{
    // freopen("data.txt", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        GetNumber(n);
        printf("\n");
    }

    return 0;
}