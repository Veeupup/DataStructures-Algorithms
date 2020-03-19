/*
    Author: Veeupup
    分割平衡字符串

 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0;
        int num = 0;
        int i = 0;
        while(s[i] != '\0') {
            if(s[i] == 'R')
                num++;
            if(s[i] == 'L')
                num--;
            if(num == 0)
                res++;
            i++;
        }
        if(res == 0) return 1;
        return res;
    }
};


int main()
{
    
    Solution *so = new Solution();
    string s1 = "RLRRLLRLRL";
    string s2 = "RLLLLRRRLR";
    string s3 = "LLLLRRRR";
    cout << so->balancedStringSplit(s1) << endl;
    cout << so->balancedStringSplit(s2) << endl;
    cout << so->balancedStringSplit(s3) << endl;
    return 0;

}