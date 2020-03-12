/*
 * 清华上机
 *
 * 质因数的个数
 *
 * https://www.nowcoder.com/practice/20426b85f7fc4ba8b0844cc04807fbd9?tpId=40&tqId=21338&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 *
 * 快速求解质数的方法
 *
 */
#include <cstdio>
#include <cstdint>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

const long MAXN = 100000;
vector<int> primes;
bool isPrime[MAXN];

/*
 * 快速求解质数
 * 首先将所有的数字标为质数
 * 然后从小到大，所有质数的倍数都不是质数
 * 一直寻找
 */
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
        primes.push_back(i);
        for (long j = i * i; j < MAXN; j += i)
        {
            isPrime[j] = false;
        }
    }
}


int main()
{
//    Initial();
    freopen("data.txt", "r", stdin);
//    int n;
//    while (scanf("%d", &n) != EOF) {
//        int count = 0;
//        for (int i = 0; i < primes.size() && primes[i] < n; ++i) {
//            int factor = primes[i];
//            while (n % factor == 0) {
//                n /= factor;
//                count++;
//            }
//        }
//        if(n > 1) {
//            count++;
//        }
//        printf("%d\n", count);
//    }
    long M = 100;
    while (cin >> M) {
        long count = 0;
        for (long j = 2; j <= sqrt(M); ++j) {
            while (M % j == 0) {
                M /= j;
                count++;
            }
            if(M <= 1) break;
        }
        if(M > 1) count++;// 最多有一个大于 sqrt 的质因数，原因是如果有两个，则相乘就大于 n
        cout << count << endl;
    }

    return 0;
}

