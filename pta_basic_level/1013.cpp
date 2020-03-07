/*
    Author: Veeupup
 */
#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

bool isZhi(int n)
{
    int bound = sqrt(n);
    for (int i = 2; i <= bound; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

vector<int> nums;

int main()
{
    // 初始化
    int m, n;
    scanf("%d%d", &m, &n);
    nums.push_back(0);
    for (int i = 2; nums.size() <= n + 1; i++)
    {
        if (isZhi(i))
        {
            nums.push_back(i);
        }
    }
    int counter = 1;
    for (int i = m; i <= n; i++)
    {
        if (counter % 10 == 1)
        { // 第一行的第一个数字
            printf("%d", nums[i]);
        }
        else if (counter % 10 == 0)
        {
            printf(" %d\n", nums[i]);
        }
        else
        {
            printf(" %d", nums[i]);
        }
        counter++;
    }
    return 0;
}