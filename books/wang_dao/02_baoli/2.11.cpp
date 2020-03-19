#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        int count = 0;
        while (n != 1)
        {
            count++;
            if (n % 2 == 0)
                n /= 2;
            else
            {
                n = n * 3 + 1;
                n /= 2;
            }
        }
        printf("%d\n", count);
    }

    return 0;
}