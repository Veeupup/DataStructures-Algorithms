/*
    tag:string

    Author: Veeupup
    暴力法：
        直接遍历
    
    暴力法 -> 滑动窗口
    
    这道题应该使用滑动窗口法：
        其实就是一个队列,比如例题中的 abcabcbb，
        进入这个队列（窗口）为 abc 满足题目要求，
        当再进入 a，队列变成了 abca，这时候不满足要求。
        所以，我们要移动这个队列！

        如何移动？
            我们只要把队列的左边的元素移出就行了，直到满足题目要求！
            一直维持这样的队列，找出队列出现最长的长度时候，求出解！

 */
#include <bits/stdc++.h> // 万能头
using namespace std;

class Solution
{

public:
    /* 
        滑动窗口法
    */
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
            return 0;
        int maxSize = 0;
        int left = 0;
        int len = s.size();
        unordered_set<char> words;
        for (int i = 0; i < len; i++)
        {
            char c = s[i];
            while (words.find(c) != words.end())
            {   // 如果遇到了重复的字符
                words.erase(s[left]);   // 去除最左边的字符,不断缩小窗口
                left++;
            }
            maxSize = max(maxSize, i - left + 1);
            words.insert(c);
        }
        return maxSize;
    }

    /* 
        暴力遍历法
     */
    int baoli(string s)
    {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                if (allUnique(s, i, j) && (j - i > ans))
                    ans = j - i;
        return ans;
    }

private:
    bool allUnique(string s, int left, int right)
    {
        set<char> words;
        for (int i = left; i < right; i++)
        {
            char c = s[i];
            if (words.find(c) != end(words))
                return false;
            words.insert(c);
        }
        return true;
    }
};

int main()
{
    string s1 = "abcd";
    string s2 = "abcabcbb";
    string s3 = "dvdf";
    string s4 = "pkwwl";
    Solution *so = new Solution();
    cout << so->lengthOfLongestSubstring(s4) << endl;
    return 0;
}
