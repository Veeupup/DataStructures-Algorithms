/*
    Author: Veeupup
    求中位数的位置，接着输入 n 个无序的数字。
    要求输出升序后排列的中位数，以及该中位数输入的次序
    如果 n 是偶数，则输出两个中位数

    input:  
    5
    9 2 7 1 6
    output:
    6 5

    input:
    6
    9 6 7 1 2 3
    output:
    3 6
    6 2


 */
#include <iostream>
#include <cstdint>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Num
{
    int num;
    int seq;
} nums[1000];

bool cmp(Num a, Num b)
{
    return a.num < b.num;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &nums[i].num);
        nums[i].seq = i;
    }
    sort(nums+1, nums + n + 1, cmp);
    if(n % 2 == 0) {
        int mid = n / 2;
        printf("%d %d\n", nums[mid].num, nums[mid].seq);
        printf("%d %d\n", nums[mid+1].num, nums[mid+1].seq);
    }else {
        int mid = n / 2 + 1;
        printf("%d %d\n", nums[mid].num, nums[mid].seq);
    }


    return 0;
}