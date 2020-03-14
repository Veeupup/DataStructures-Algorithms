/*
    Author: Veeupup
    2019 第一题
    输入一个数，求 1 到这个数之间连续的合数最长的那一组，比如输入 50 输入 24 25 26 27 28
    数据规模是从 1 到 1000000

    解决思路：
        * 快速求解质数
        * 使用标记法，从前往后找连续的合数
        
    注意点：
        * 由于超过了 65535 我们可以使用 long 
 */
#include <iostream>
#include <cstdint>
#include <cstdio>
#include <vector>
#include <algorithm>
#define N 1000010
using namespace std;

bool isPrime[N];

// 快速求质数
void Initial()
{
    fill(isPrime, isPrime + N, true); // 初始化，假设所有的数字都是质数
    isPrime[0] = false;
    isPrime[1] = false;
    long i, j;
    for (i = 2; i < N; i++)
    {
        if (!isPrime[i]) // 如果不是质数，则跳过
            continue;
        for (j = i * i; j < N; j += i) // 如果是质数，则质数的所有倍数都不是质数
        {
            isPrime[j] = false;
        }
    }
    return;
}

int main()
{
    // freopen("data.txt", "r", stdin);
    Initial();
    int n;
    scanf("%d", &n);
    int max_start = 4, max_long = 1;
    int now_start, now_long;
    for (int i = 2; i <= n;)
    {
        if (isPrime[i - 1] && !isPrime[i])
        {
            // 如果上一个不是合数，但是这个数是合数，那么就找到了一个新开始
            now_start = i, now_long = 1;
            while (!isPrime[++i])   
            {
                // 如果下一个数仍然是合数，那么继续增加 now_long
                // 如果不是，则会退出
                now_long++;
            }
            if(now_long > max_long) {
                max_long = now_long;
                max_start = now_start;
            }
        }else {
            i++;
        }
    }
    for (int i = max_start; i < max_start + max_long; i++)
    {
        printf("%d ", i);
    }
    return 0;
}