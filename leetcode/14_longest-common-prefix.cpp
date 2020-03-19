/*
    Author: Veeupup
    最长公共前缀

 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if(strs.size() == 0) return string("");
        int minLen = INT_MAX;
        // 找到最短的字符串长度
        for (int i = 0; i < strs.size(); i++)
            if(strs[i].size() < minLen)
                minLen = strs[i].size();
        bool flag = false;
        int pos = 0;
        for (int i = 0; i < minLen; i++)
        {   
            char c = strs[0][i];   
            for (int j = 0; j < strs.size(); j++)
            {
                if(strs[j][i] != c) {
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
            pos++;
        }
        string prefix = string(strs[0], 0, pos);
        return prefix;
    }
};

int main()
{
    vector<string> strs1 = { "flower","flow","flight"};
    vector<string> strs2 = { "flower","abc","flight"};
    vector<string> strs3 = { "flower" };
    Solution *so = new Solution();
    cout << so->longestCommonPrefix(strs1) << endl;
    cout << so->longestCommonPrefix(strs2) << endl;
    cout << so->longestCommonPrefix(strs3) << endl;
    return 0;
}