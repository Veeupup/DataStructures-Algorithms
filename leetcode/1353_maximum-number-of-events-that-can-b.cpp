/*
    Author: Veeupup
    最多可以参加的会议数目

    按照会议开始日期对 events 排序，使用默认排序算法就可以
    再使用一个优先队列，根据日期，将今天开始的会议全都加入到优先队列中
    优先队列的排序以会议的结束日期为标准，保证越接近结束日期的越靠前
    每一天如果优先队列里还有会议，就去参加一个
    新的一天，先把优先队列里已经过期的会议清除掉


 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEvents1(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;  // 小顶堆

        int ans = 0;
        int day = 0;
        int i = 0;
        while (i < events.size() || !pq.empty())
        {
            day++;
            while (!pq.empty() && pq.top() < day)
            {   // 如果今天已经过了会议的结束时间，那么就清除这个会议
                pq.pop();
            }
            while (i < events.size() && events[i][0] == day)
            {
                pq.push(events[i][1]);  // 如果该会议今天开始，则加入到优先队列
                i++;
            }
            if(pq.empty()) continue;
            pq.pop();
            ans++; 
        }
        return ans;
    }

    /* 
        普通贪心
     */
    int maxEvents(vector<vector<int>>& events) {
        if(events.size() == 0 || events.size() == 1)
            return events.size();

        unordered_set<int> res; // 用来记录这一天是否已经参加会议
        sort(events.begin(), events.end(), compare);    // 根据结束时间早晚排序
        for (int i = 0; i < events.size(); i++)
        {
            for (int d = events[i][0]; d <= events[i][1]; d++)
            {   // 如果这天能参加，我们就参加，然后看下一个会议
                if(res.find(d) == res.end()) {
                    res.insert(d);
                    break;
                }
            }
        }
        return res.size();
    }
private:
    // 按照结束时间排序，结束早的排在前面
    static bool compare(vector<int> a, vector<int> b) {
            return a[1] < b[1];
    }
};


int main()
{
    Solution *so = new Solution();
    /* 
        二维 vector 的使用，需要提前 resize 之后就可以直接访问了
     */
    vector<vector<int>> events;
    events.resize(4);
    events[0].push_back(1);
    events[0].push_back(2);
    events[1].push_back(2);
    events[1].push_back(3);
    events[2].push_back(3);
    events[2].push_back(4);
    events[3].push_back(1);
    events[3].push_back(2);
    cout << so->maxEvents(events) << endl;


    return 0;

}