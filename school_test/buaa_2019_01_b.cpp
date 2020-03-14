/*
    Author: Veeupup
    给定a，b，求a～b范围内的素数，找到这些素数中的等差数列（三个数字以上），每行输出一组等差数列

    input:
    199 300
    
    output:
    199 211 223
    251 257 263 269

    input:
    2 500

    output:
    3 5 7
    47 53 59
    151 157 163
    167 173 179
    199 211 223
    251 257 263 269
    367 373 379   

 */
#include <iostream>
#include <cstdint>
#include <cstdio>
#include <vector>
#include <algorithm>
#define N 100010
using namespace std;

bool isPrime[N];
vector<int> primes;

// 快速求解质数
void Initial()
{
    fill(isPrime, isPrime + N, true);
    isPrime[0] = false;
    isPrime[1] = false;
    long i, j;
    for (i = 2; i < N; i++)
    {
        if (!isPrime[i]) // 如果是合数，则跳过
            continue;
        primes.push_back(i);
        for (j = i * i; j < N; j += i)
        { // 所有质数的倍数都是合数
            isPrime[j] = false;
        }
    }
}

int main()
{
    Initial();
    int a, b;
    scanf("%d %d", &a, &b);
    long start = 0;  // 找到第一个大于等于 a 的质数的位置
    while (primes[start] < a)
    {
        start++;
    }
    long end = start;   // 找到第一个大于 b 的质数的位置
    while (primes[end] <= b)
    {
        end++;
    }
    end--;  // 然后 -- 就找到了小于 b 的最大的质数的位置
    int step;
    int i;
    for (i = start+2; i <= end;)
    {
        if((primes[i] - primes[i-1]) == (primes[i-1]-primes[i-2])) {
            // 至少三个为等差，此时输出这三个数，并且继续往后
            printf("%d %d %d", primes[i-2], primes[i-1], primes[i]);
            step = primes[i] - primes[i-1];
            i++;    // 看之后是否也满足
            while (primes[i] - primes[i-1] == step)
            {   // 如果满足则继续输出
                printf(" %d", primes[i++]);
            }
            printf("\n");
        }else {
            i++;
        }
    }
    return 0;
}