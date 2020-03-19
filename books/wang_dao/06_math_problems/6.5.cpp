#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

/* 最大公因数 */

// 递归
int GCD(int a, int b) {
    if(b == 0) {
        return a + b;
    }else {
        return GCD(b, a % b);
    }
}

// 非递归
int GCD2(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a=b; b = temp;
    }
    return a;
}

int main()
{
    int a, b;
    while(scanf("%d%d", &a, &b) != 0) {
        printf("%d\n", GCD2(a, b));
    } 
    return 0;

}