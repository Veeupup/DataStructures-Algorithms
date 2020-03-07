#include<iostream>
#include<cstdio>
#include<cstdint>
using namespace std;

int getN(int n) {
    if(n == 0 || n == 1)
        return 1;
    int rev = 1;
    for(int i=2;i <= n;i++) {
        rev *= i;
    }
    return rev;
}

int main()
{
    int n, pos;
    int num[100];
    while(scanf("%d", &n) != EOF)
    {
        if(n == 0)
            break;
        int ant = n;
        pos = 0;
        while(ant != 0) {
            num[pos++] = ant % 10;
            ant /= 10;
        }
        printf("%d,", n);
        int sum = 0;
        for(int i=pos-1;i>=0;i--) {
            sum += getN(num[i]);
            printf("%d!", num[i]);
            if(i != 0) {
                printf("+");
            }
        }
        printf("=%d\n", sum);
        if(sum == n) {
            printf("YES\n");
        }else {
            printf("NO\n");
        }
    }
    return 0;
}









