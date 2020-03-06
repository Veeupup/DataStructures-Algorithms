/* 
    浙大：简单计算器
    使用栈来进行计算，此时不包括括号

    eg:
        in:     1 + 2
        out:    3.00
        in:     4 + 2 * 5 - 7 / 11
        out:    13.36

 */
#include <iostream>
#include <cstdio>
#include <stack>
#include <cctype>
using namespace std;

int Priority(char c);                          // 返回运算符优先级顺序
double GetNumber(string str, int &index);      // 获得下一个数字
double Calculate(double x, double y, char op); // 计算结果

int main()
{
    string str;
    while (getline(cin, str))
    {
        if (str == "0")
            break;
        int index = 0;
        stack<char> oper;
        stack<double> data;
        // 预处理，在字符串的末尾增加 $ 结尾，在运算符栈中增加一个空运算符
        str += '$';
        oper.push('#');
        while (index < str.size())
        {
            if (str[index] == ' ')
            {
                index++;
            }
            else if (isdigit(str[index]))
            {
                data.push(GetNumber(str, index));
            }
            else
            {
                if (Priority(oper.top()) < Priority(str[index]))
                {
                    // 运算符栈顶优先级小于该运算符，入栈（也就是运算符栈内优先级由低到高）
                    // 例如运算符栈里是加法，遇到乘法，则乘号入栈
                    oper.push(str[index]);
                    index++;
                }
                else
                {
                    // 例如运算符栈顶是乘号，遇到加号，则先运算乘号的内容，然后将运算结果进入结果栈
                    double y = data.top();
                    data.pop();
                    double x = data.top();
                    data.pop();
                    data.push(Calculate(x, y, oper.top()));
                    oper.pop();
                }
            }
        }
        printf("%.2f\n", data.top());
    }

    return 0;
}

int Priority(char c)
{
    if (c == '#')
    {
        return 0;
    }
    else if (c == '$')
    {
        return 1;
    }
    else if (c == '+' || c == '-')
    {
        return 2;
    }
    else
    {
        return 3;
    }
}; // 返回运算符优先级顺序
double GetNumber(string str, int &index)
{
    double number = 0;
    while (isdigit(str[index]))
    {
        number = number * 10 + str[index] - '0';
        index++;
    }
    return number;

}; // 获得下一个数字
double Calculate(double x, double y, char op)
{
    double result = 0;
    if (op == '+')
    {
        result = x + y;
    }
    else if (op == '-')
    {
        result = x - y;
    }
    else if (op == '*')
    {
        result = x * y;
    }
    else if (op == '/')
    {
        result = x / y;
    }
    return result;
}; // 计算结果
