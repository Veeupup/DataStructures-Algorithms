/*
    Author: Veeupup
    玩筹码 
    贪心 数组

 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCostToMoveChips(vector<int> &chips)
    {
        int odds = 0;   // 偶数个数
        int evens = 0;  // 奇数个数
        for (int i = 0; i < chips.size(); i++)
        {
            if(chips[i]&1)
                odds++;
            else
                evens++;
        }
        return min(odds, evens);
    }
};

int main()
{
    Solution *so = new Solution();
    
    
    return 0;
}