#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

/* 
    Find the Multiple
        使用 BFS 的思想，逆向解决这个问题
    input:
        2
        6
        19
        0
    output:
        10
        100100100100100100
        111111111111111111
 */

int BFS(int n)
{
    queue<int> myQ;
    myQ.push(1);
    while (!myQ.empty())
    {
        int curr = myQ.front();
        myQ.pop();
        if (curr % n == 0 && curr / n > 0)
        {
            return curr;
        }
        myQ.push(10 * curr);
        myQ.push(10 * curr + 1);
    }
    return -1;
}

int main()
{
    freopen("data.txt", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        printf("%lld\n", BFS(n));
    }

    return 0;
}