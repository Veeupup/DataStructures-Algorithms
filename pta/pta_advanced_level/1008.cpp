/*
    Author: Veeupup
    Elevator 

    计算需要多长时间

 */
#include <iostream>
#include <cstdio>
#include <cstdint>
using namespace std;

int main()
{
    freopen("data.txt","r", stdin);
    int n;
    scanf("%d", &n);
    int nextFloor, nowFloor = 0, total = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nextFloor);
        if(nextFloor > nowFloor) {
            // 下一次去的地方比当前楼层高
            int upTime = 6 * (nextFloor - nowFloor);
            total += upTime;
        }else if(nextFloor < nowFloor) {
            int downTime = 4 * (nowFloor - nextFloor);
            total += downTime;
        }
        nowFloor = nextFloor;
        total += 5; // 等待 5 s
    }
    printf("%d", total);
    return 0;
}