#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

/* 分解质因数 */

const int MAXN = sqrt(1e9) + 1;
vector<int> prime;
bool isPrime[MAXN];

void Initial()
{
    long i = 0;
    for (i = 0; i < MAXN; i++)
        isPrime[i] = true;
    isPrime[0] = false;
    isPrime[1] = false;
    for (i = 2; i < MAXN; i++)
    {
        if (!isPrime[i])
        {
            continue; // 非质数则跳过
        }
        prime.push_back(i);
        for (long j = i * i; j < MAXN; j += i)
        {
            isPrime[j] = false;
        }
    }
}

int main()
{
    // freopen("data.txt","r", stdin);
    Initial();
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int count = 0;
        for(int i=0;i<prime.size() && prime[i] < n;i++) {
            int factor = prime[i];
            while (n % factor == 0)
            {
                n/=factor;
                count++;
            }
        }
        if(n > 1) {
            count++;
        }
        // int count = 0, i = 0;
        // while (n != 1 && i < prime.size())
        // {
        //     if(n % prime[i] == 0) {
        //         count++;
        //         n /= prime[i];
        //         // printf("%d ", prime[i]);
        //     }else {
        //         i++;
        //     }
        // }
        // if(i == prime.size()) count++;  // 如果到了最后，还有自己本身这个数字
        printf("%d\n", count);
    }

    return 0;
}