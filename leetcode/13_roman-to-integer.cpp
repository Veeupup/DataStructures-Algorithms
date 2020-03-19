/*
    Author: Veeupup
    罗马数字转为整数

    思路：
        从前往后，每次看两位
        如果后面的那一位是比前面的更大，则应该两位一起看
        不然的话，一次看一位
        （我们需要写一个映射函数来返回字符对应的值
        （如果是两位一起看的话，需要计算减法
        我们应该用一个游标来指示当前看到哪里了，但是每次检测都应该检测当前位和下一位
        
    边界情况：
        如果为空则为 0 
        如果当前的游标已经是最后一位，那么就只看这一位


 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {   
        int len = s.size();
        if(len == 0) return 0;
        int sum = 0;
        map<char, int> m = { {'I',1} ,{'V', 5} ,{'X', 10},{'L', 50} ,{'C', 100} ,{'D', 500} ,{'M', 1000} };
        for (int i = 0; i < len; i++)
        {
            if(i+1 < len) {
                // 如果当前位还不是最后一位，那么就需要检测下一位
                int nextVal = m[s[i+1]];
                int thisVal = m[s[i]];
                if(nextVal > thisVal) {
                    // 如果下一位的值比当前位大，
                    // 那么就需要用下一位的值减去当前位的值然后加上
                    // 同时移动游标
                    sum += (nextVal - thisVal);
                    i++;
                }else {
                    sum += thisVal;
                }
            }else {
                // 如果是最后一位
                sum += m[s[i]];
            }
        }
        
        return sum;
    }
};

int main()
{
    Solution *so = new Solution();
    string s1 = "III";
    string s2 = "IV";
    string s3 = "IX";
    string s4 = "LVIII";
    string s5 = "MCMXCIV";
    cout << so->romanToInt(s1) << endl;
    cout << so->romanToInt(s2) << endl;
    cout << so->romanToInt(s3) << endl;
    cout << so->romanToInt(s4) << endl;
    cout << so->romanToInt(s5) << endl;
    return 0;
}