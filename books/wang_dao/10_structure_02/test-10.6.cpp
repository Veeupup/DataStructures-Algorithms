#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

/* 
    谁是你的潜在朋友
    input:
        4  5
        2
        3
        2
        1
    output:
        1
        BeiJu
        1
        BeiJu
 */
const int N = 201;

int main()
{
    freopen("data.txt","r", stdin);
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        int reader[201]= {0}, book[201] = {0};
        for (int i = 1; i <= n; i++)
        {
            int temp;
            scanf("%d", &temp);
            reader[i] = temp;  // 记录第i个读的哪本书
            book[temp]++;    // 记录读这本书的人数
        }
        for (int i = 1; i <= n; i++)
        {
            if(book[reader[i]] > 1) {
                printf("%d\n", book[reader[i]]-1);
            }else {
                printf("Beiju\n");
            }
        }
    
    }
    



    return 0;

}