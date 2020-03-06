#include <cstdio>

int main()
{
    int a, b, c;
    for (a = 0; a < 10; a++)
        for (b = 0; b < 10; b++)
            for (c = 0; c < 10; c++)
            {
                if ((a * 100 + b * 10 + c) + (b * 100 + c * 10 + c) == 532)
                {
                    printf("%d %d %d\n", a, b, c);
                }
            }
    return 0;
}
