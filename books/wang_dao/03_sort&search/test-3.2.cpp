#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[10];

int main()
{
    while(cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7]>>a[8]>>a[9]) 
    {
        sort(a, a+10);
        // 输出奇数,从后往前输出
        for(int i=9;i>=0;i--) {
            if(a[i]%2==1)
                printf("%d ", a[i]);
        }
        // 输出偶数
        for(int i=0;i<10;i++) {
            if(a[i]%2==0)
                printf("%d ", a[i]);
        }
        printf("\n");
    }
    return 0;

}