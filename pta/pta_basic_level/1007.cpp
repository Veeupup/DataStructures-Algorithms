/*
    Author: Veeupup

    输入格式:
        输入在一行给出正整数N
    输出格式:
        在一行中输出不超过N的满足猜想的素数对的个数

    输入样例:
    20

    输出样例:
    4
 */
#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int isZhi(int n) {
    int bound = sqrt(n);
    for (int i = 2; i <= bound; i++)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> nums;
    for (int i = 2; i <= n; i++)
    {
        if(isZhi(i) == 1) {
            
            nums.push_back(i);
        }
    }
    int counter = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if(nums[i+1] - nums[i] == 2) 
            counter++;
    }
    printf("%d\n", counter);
    return 0;

}