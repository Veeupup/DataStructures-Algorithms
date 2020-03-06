#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    unsigned int n;
    while (scanf("%d", &n) != EOF)
    {
        vector<int> V;
        while (n != 0)
        {
            V.push_back(n % 2);
            n /= 2;
        }
        for (int i = V.size() - 1; i >= 0; i--)
        {
            printf("%d", V[i]);
        }
        printf("\n");
    }
    return 0;
}