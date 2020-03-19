#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

/* 求解最小公倍数 */

int GCD(int a, int b) {
    if(b == 0)
        return a + b;
    else return GCD(b, a % b);
}

int main()
{
    int a, b;
    while(scanf("%d%d", &a, &b) != 0) {
        printf("%d\n", a * b / GCD(a ,b));
    }



    return 0;

}