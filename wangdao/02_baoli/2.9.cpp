/* 清华上机，剩下的树 */
#include<iostream>
#include<cstdio>
using namespace std;

const int MAXN = 10001;

bool arr[MAXN];

int main()
{
    int L, M;
    while(scanf("%d%d", &L, &M) != EOF)
    {   // 初始化
        for(int i=0; i<=L;i++) {
            arr[i]=true;
        }
        int start, end;
        for(int i=0;i<M;i++) {
            scanf("%d%d", &start, &end);
            for(int i=start;i<=end;i++) {
                if(arr[i]) {
                    arr[i] = false;
                    L--;
                }    
            }
        }
        printf("%d\n", L+1);
    }



    return 0;

}