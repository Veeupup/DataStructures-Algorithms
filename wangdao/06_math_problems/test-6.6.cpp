#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

const unsigned int MAXN = 100000;

vector<int> prime;
bool isPrime[MAXN];

void Initial()
{   // 开始假定所有人都是质数
    unsigned int i;
    for (i = 0; i < MAXN; i++)
    {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for (i = 2; i < MAXN; i++)
    {
        if (!isPrime[i])
        {
            continue; // 非质数则跳过
        }
        prime.push_back(i);
        for (int j = i * i; j < MAXN; j += i)
        {
            isPrime[j] = false; // 质数的倍数是非质数
        }
    }
}

int main()
{
    // freopen("data.txt", "r", stdin);
    Initial();
    int n;
    while (scanf("%d", &n) != EOF)
    {
        printf("%d\n", prime[n-1]);
    }

    return 0;
}