#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
using namespace std;

/* 
    计算中缀表达式：
    1. 转换为后缀表达式
        * 建立一个操作符栈，用以临时存放操作符，建立一个数组或者队列，用以存放后缀表达式
        * 从左到右扫描中缀表达式，如果碰到操作数，就把操作数加入到后缀表达式中
        * 如果碰到操作符 op，就把其优先级和操作符栈顶操作符优先级比较
          * 如果 op 的优先级高于栈顶，就压入操作符栈（trick：初始化操作符栈时候增加一个 # 运算符为最低）
          * 如果低于或者等于栈顶，就将操作符栈的操作符不断弹出到后缀表达式中，直到 op 的优先级高于栈顶操作符
        * 重复直到中缀表达式扫描完毕，如果操作符栈中仍然有元素，则依次弹出放到后缀表达式中
    
    2. 计算后缀表达式
        * 从左到右扫描后缀表达式，如果是操作数，就压入栈，如果是操作符，就连续弹出两个操作数，（后弹出的是第一操作数）
        * 然后进行操作符的操作，直到后缀表达式扫描完毕，这个时候结果栈中只剩一个元素，即为运算的结果
        
    本题的难点在于如何区分小数和带有符号的正负数
    但是换个角度，这个题不需要我们计算出具体的结果！
    所以我们只需要把每个部分分开计算即可！

 */

vector<string> ans;
map<char, int> priority;
string operators = "+-*/()";    // 保存所有的计算符号

void trans(string str) 
{
    stack<char> ops;
    ops.push('#');
    string tempStr;
    for (int i = 0; i < str.size(); i++)
    {   // 检查是否是带符号的数字
        // 1. 带正负号且前一个字符为运算符（i=0时直接带正负号的也是数字）
        // 2. 当前字符为数字
        if( ((str[i] == '-' || str[i] == '+') && (i == 0 || string("+-/*(").find(str[i-1])!=string::npos)) || isdigit(str[i]) ) 
        {   // 把操作数加入到后缀式中
            // 如果是正号就不用加入，负号或者数字本身都要加入
            tempStr = str[i] != '+' ? str.substr(i, 1) : "";
            while (i + 1 < str.size() && operators.find(str[i+1]) == string::npos)
            {
                tempStr += str[++i];
            }
            ans.push_back(tempStr);
        }else { // 出现操作符
            if(str[i] == '(') 
                ops.push(str[i]);
            else if(str[i] == ')') {
                while (ops.top() != '(')
                {
                    ans.push_back(string(1, ops.top()));
                    ops.pop();
                }
                ops.pop();
            }else {
                while (priority[str[i]] <= priority[ops.top()])
                {
                    ans.push_back(string(1, ops.top()));
                    ops.pop();
                }
                ops.push(str[i]);
            }
        }
    }
    while (ops.size() > 1)
    {
        ans.push_back(string(1, ops.top()));
        ops.pop();
    }
}

int main()
{
    priority['*'] = priority['/'] = 3;
    priority['+'] = priority['-'] = 2;
    priority['('] = 1;
    priority['#'] = 0;
    string str;
    getline(cin, str);
    trans(str);
    for (int i = 0; i < ans.size(); i++)
        cout << (i ? " " : "") << ans[i]; 
    return 0;
}