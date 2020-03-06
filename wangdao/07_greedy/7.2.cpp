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
    最简单的背包问题，采用贪心即可解决
    input:
        5 3
        7 2
        4 3
        5 2
        20 3
        25 18
        24 15
        15 10
        -1 -1
    output:
        13.333
        31.500
 */

const int MAXN = 1000;

struct JaveBean
{
    double weight;
    double price;
};

JaveBean arr[MAXN];

// 单价低的放在前面
bool Compare(JaveBean x, JaveBean y) {
    return (x.price / x.weight) < (y.price / y.weight);
}

int main()
{
    freopen("data.txt","r", stdin);
    int m, n;   // m 为猫粮数目（钱）， n 为 JavaBean 的种类
    while (scanf("%d%d", &m, &n) != EOF)
    {
        if(m == -1 && n == -1)
            break;
        for(int i=0;i<n;i++) {
            scanf("%lf %lf", &arr[i].weight, &arr[i].price);
        }
        sort(arr, arr+n, Compare);
        double sum = 0;
        int index = 0;
        while (m != 0 && index < n)
        {
            if(m >= arr[index].price) { // 能买得起当前所有的咖啡豆
                m -= arr[index].price;      // 猫粮减少
                sum += arr[index].weight;   // 咖啡豆增加
            }else { // 买不起当前所有的咖啡豆
                double temp = m / ( arr[index].price / arr[index].weight );
                sum += temp;
                break;
            }
            index++;
        }
        printf("%.3f\n", sum);
    }
    



    return 0;

}