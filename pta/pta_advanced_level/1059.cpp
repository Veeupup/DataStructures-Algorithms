/*
    Author: Veeupup
 */
#include <cstdio>
#include <climits>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const long maxn = 1e7;

vector<long> primes;     //  保存质数
bool isPrime[maxn];     //  质数判断

// 质数表初始化
void Initial() {
    fill(isPrime, isPrime + maxn, true);    // 所有的数字都初始化为 true，为质数，随后筛
    isPrime[0] = isPrime[1] = false;
    for(long i = 2; i < maxn; i++) {
        if(!isPrime[i]) 
            continue;   // 如果 i 不是质数，则跳过
        primes.push_back(i);
        for(long j = i * i; j < maxn; j += i) {
            isPrime[j] = false; // i 的倍数被标记为合数
        }
    }
    return;
}

struct Factor {
    long x, cnt;
}fac[10];   // 保存质因子

int main()
{
    Initial();  // 初始化质数表
    long n, num = 0;    // num 为不同质因子的个数
    scanf("%ld", &n);
    if(n == 1) {
        printf("1=1");
    }else {
        printf("%ld=", n);
        long sqr = (long)sqrt(n);
        // 枚举根号 n 以内的质因子
        for (int i = 0; i < primes.size() && primes[i] < sqr; i++)
        {
            if(n % primes[i] == 0) {
                fac[num].x = primes[i];
                fac[num].cnt = 0;
                while (n % primes[i] == 0)
                {
                    fac[num].cnt++;
                    n /= primes[i];
                }
                num++;
            }
            if(n == 1)
                break;
        }
        if(n != 1) {
            fac[num].x = n;
            fac[num++].cnt = 1;
        }
        // 按照格式输出
        for (int i = 0; i < num; i++)
        {
            if(i > 0) printf("*");
            printf("%ld", fac[i].x);
            if(fac[i].cnt > 1) {
                printf("^%d", fac[i].cnt);
            }
        }
    }
    
    return 0;
}