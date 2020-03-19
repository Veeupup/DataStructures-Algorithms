/*
    Author: Veeupup
    有效的括号

 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> myS;
        int len = s.size();
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                myS.push(s[i]);
            }
            else
            {
                if (myS.empty())
                    return false;
                switch (s[i])
                {
                case ')':
                    if (myS.top() == '(')
                        myS.pop();
                    else
                        return false;
                    break;
                case ']':
                    if (myS.top() == '[')
                        myS.pop();
                    else
                        return false;
                    break;
                case '}':
                    if (myS.top() == '{')
                        myS.pop();
                    else
                        return false;
                    break;
                default:
                    break;
                }
            }
        }
        if (myS.empty())
            return true;
        else
            return false;
    }
};

int main()
{
    string s1 = "()";
    string s2 = "()[]{}";
    string s3 = "(]";
    string s4 = "([)]";
    string s5 = "{[]}";
    string s6 = "]";
    Solution *so = new Solution();
    cout << so->isValid(s1) << endl;
    cout << so->isValid(s2) << endl;
    cout << so->isValid(s3) << endl;
    cout << so->isValid(s4) << endl;
    cout << so->isValid(s5) << endl;
    cout << so->isValid(s6) << endl;
    return 0;
}