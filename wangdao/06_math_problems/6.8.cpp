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

/* 质数筛选，质数的倍数不是质数，通过标记来快速标记 */

const int MAXN = 10001;

vector<int> prime;
bool isPrime[MAXN];

void Initial()
{
	for (int i = 0; i < MAXN; i++)
	{
		isPrime[i] = true;
	}
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i < MAXN; i++)
	{
		if (!isPrime[i])
		{ // 非质数则跳过
			continue;
		}
		prime.push_back(i);
		for (int j = i * i; j < MAXN; j += i)
		{
			isPrime[j] = false; // 质数的倍数是非质数
		}
	}
	return;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	Initial();
	int n;
	while (scanf("%d", &n) != EOF)
	{
		bool isOutput = false;
		for (int i = 0; i < prime.size() && prime[i] < n; i++)
		{
			if (prime[i] % 10 == 1)
			{
				isOutput = true;
				printf("%d ", prime[i]);
			}
		}
		if (!isOutput)
		{
			printf("-1");
		}
		printf("\n");
	}

	return 0;
}