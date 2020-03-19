/*
    Author: Veeupup
    实现 strStr()

 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.size() == 0)
            return 0;   // needle 为空时返回 0
        else if (needle.size() > haystack.size())
            return -1;  // 当 needle 的长度比 haystack 长的时候就没了
        int len = haystack.size();
        for (int i = 0; i < len; i++)
        {
            if (haystack[i] == needle[0])
            {
                int j;
                for (j = 0; j < needle.size(); j++)
                {
                    if (i + j >= len || haystack[i + j] != needle[j])
                        break;
                }
                if (j == needle.size())
                    return i;
            }
        }
        return -1;
    }
};

int main()
{

    string haystack = "hello", needle = "ll";
    string haystack2 = "aaaaa", needle2 = "bba";
    string haystack3 = "mississippi", needle3 = "issip";
    Solution *so = new Solution();
    cout << so->strStr(haystack, needle) << endl;
    cout << so->strStr(haystack2, needle2) << endl;
    cout << so->strStr(haystack3, needle3) << endl;
    return 0;
}