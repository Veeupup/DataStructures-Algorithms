#include <iostream>
#include <cstdio>
using namespace std;

int reverse(int n)
{
    int result = 0;
    while (n != 0)
    {
        result *= 10;
        result += n % 10;
        n /= 10;
    }
    return result;
}

int main()
{
    for(int i=0;i<256;i++)
    {
        if(i*i == reverse(i*i)){
            printf("%d\n", i);
        }
    }
    return 0;
}