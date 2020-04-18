/* 
    模拟排队
 */
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#define LOCAL
using namespace std;

const int INF = INT_MAX;

struct person
{
    int id, takingTime, endTime;
} peoples[1100]; // 保存每个人的耗费时间，结束时间

int N, M, K, Q;                      // 窗口数目，每条队最大人数，客户数，用户查询数目
queue<person> windows[25], waitings; // 所有的窗口的人的队伍，外面等待的队伍
int times[25];                       // 每个队，我们给一个时钟记录当前处理时间

int main()
{
    scanf("%d%d%d%d", &N, &M, &K, &Q);
    fill(times, times + N + 1, 0); // 初始化所有的时钟为 0
    for (int i = 1; i <= K; i++)
    { // 记录每个人花费的时间
        scanf("%d", &peoples[i].takingTime);
        peoples[i].id = i;
        waitings.push(peoples[i]); // 放入到等待队列中
    }
    // 先把到的人都放到窗口上
    int counter = 0;
    while (counter < N * M && !waitings.empty())
    {
        int MIN = INF, chooseQ;
        for (int i = 1; i <= N; i++)
        { // 寻找到一个排队人数最少，而且没有超过最多能排的人
            if (windows[i].size() < M && windows[i].size() < MIN)
            {
                chooseQ = i;
                MIN = windows[i].size();
            }
        }
        person topOne = waitings.front();
        waitings.pop();
        windows[chooseQ].push(topOne);
        counter++;
    }
    while (!waitings.empty() || K > 0)
    {
        // 开始遍历每条队伍处理当前正排着队的人，处理完最当前最先能处理的队伍，处理好这个人
        int minNowTime = INF, nowQ = 1;
        for (int i = 1; i <= N; i++)
        {
            if (windows[i].size() > 0)
            {
                if (times[i] + windows[i].front().takingTime < minNowTime)
                {
                    minNowTime = times[i] + windows[i].front().takingTime;
                    nowQ = i;
                }
            }
        }
        person nowOne = windows[nowQ].front();
        windows[nowQ].pop();
        times[nowQ] += nowOne.takingTime;
        peoples[nowOne.id].endTime = times[nowQ]; // 保存好当前完成任务的结束时间
        K--;

        if (waitings.size() > 0)
        {
            person topOne = waitings.front(); // 取出来最先来的人
            waitings.pop();                   // 然后从等待大厅中离开
            // 选择一个当前最短的队伍，而且能够进入的队伍
            int MIN = INF, chooseQ;
            for (int i = 1; i <= N; i++)
            {
                if (windows[i].size() < M && windows[i].size() < MIN)
                {
                    chooseQ = i;
                    MIN = windows[i].size();
                }
            }
            // 选择好队伍之后开始进入这条队伍
            windows[chooseQ].push(topOne);
        }
    }
    int queryId, endTime;
    int hour, minute;
    for (int i = 0; i < Q; i++)
    {
        scanf("%d", &queryId);
        endTime = peoples[queryId].endTime;
        hour = endTime / 60;
        minute = endTime % 60;
        if(hour > 9 || hour == 9 && minute > 0)
            printf("Sorry\n");
        else
            printf("%02d:%02d\n", 8 + hour, minute);
    }
    return 0;
}