#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        vector<int> res;
        while (n != 0)
        {
            res.push_back(n % 8);
            n /= 8;
        }
        for (int i = res.size() - 1; i >= 0; i--)
        {
            printf("%d", res[i]);
        }
        printf("\n");
    };

    return 0;
}