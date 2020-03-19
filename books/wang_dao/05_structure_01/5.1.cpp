/* 
    完数与盈数
 */
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> wan, ying, temp;

int main()
{
    for (int i = 2; i <= 60; i++)
    { // 找到所有因子
        for (int j = 1; j < i; j++)
        {
            if (i % j == 0)
                temp.push_back(j);
        }
        int total = 0;
        for (int k = 0; k < temp.size(); k++)
        {
            total += temp[k];
        }
        temp.clear();
        if (total == i)
            wan.push_back(i);
        else if (total > i)
            ying.push_back(i);
    }
    printf("E: ");
    for (int i = 0; i < wan.size(); i++)
    {
        if (i == wan.size() - 1)
            printf("%d", wan[i]);
        else
            printf("%d ", wan[i]);
    }
    printf("\n");
    printf("G: ");
    for (int i = 0; i < ying.size(); i++)
    {
        if (i == ying.size() - 1)
            printf("%d", ying[i]);
        else
            printf("%d ", ying[i]);
    }
    return 0;
}