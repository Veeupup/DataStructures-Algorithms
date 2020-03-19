/*
    Author: Veeupup
    由于这个时候不需要记录我们删除的是哪个数，所以只需要记录每个数字出现的次数即可

 */
#include <bits/stdc++.h>    // 万能头
using namespace std;

class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        unordered_map<int, int> m; // 保存每个数字的个数
        for (int i = 0; i < arr.size(); i++)
        {
            m[arr[i]]++;
        }
        vector<int> occ;
        unordered_map<int, int>::iterator iter;
        for (iter = m.begin(); iter != m.end(); iter++)
        {
            occ.push_back(iter->second);
        }
        sort(occ.begin(), occ.end(), greater<int>()); // 从大到小排序
        int cnt = 0, ans = 0;
        for (int i = 0; i < occ.size(); i++)
        {
            cnt += occ[i];
            ans += 1;
            if(cnt * 2 >= arr.size())
                break;
        }
        return ans;
    }
};

int main()
{
    Solution *so = new Solution();
    vector<int> vec = {3, 3, 3, 3, 5, 5, 5, 2, 2, 7};
    so->minSetSize(vec);
    return 0;
}