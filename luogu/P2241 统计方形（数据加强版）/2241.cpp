#include <cstdio>
#include <iostream>
long long M, N, x, y = 0;
using namespace std;

long long min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    scanf("%lld%lld", &M, &N);
    x = ((M + 1) * M / 2) * ((N + 1) * N / 2);
    for (long long i = 1; i <= min(M, N); i++)
    {
        y += (M - i + 1) * (N - i + 1);
    }
    printf("%lld %lld", y, x, y);
    return 0;
}