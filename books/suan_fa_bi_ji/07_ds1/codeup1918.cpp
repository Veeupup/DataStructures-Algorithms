#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <cctype>
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
    
    如果遇到左括号直接压入栈，随后正常进行，直到遇到右括号时，一直从符号栈弹出加入到后缀表达式中

    2. 计算后缀表达式
        * 从左到右扫描后缀表达式，如果是操作数，就压入栈，如果是操作符，就连续弹出两个操作数，（后弹出的是第一操作数）
        * 然后进行操作符的操作，直到后缀表达式扫描完毕，这个时候结果栈中只剩一个元素，即为运算的结果
        
 */

struct node {
    double num;
    char op;
    bool flag;  // 标记是操作数还是操作符
};

string str;
char tempStr[10];  // 用来转换
stack<node> s;
queue<node> q;  // 后缀表达式序列
map<char, int> op;

void Change()
{
    for (int i = 0; i < str.size();)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            // 如果是数字
            node temp;
            temp.flag = true; // 表明是数字
            int pos = 0;
            while (str[i] >= '0' && str[i] <= '9')
            {
                tempStr[pos++] = str[i++];
            }
            tempStr[pos] = '\0';
            temp.num = (double)atoi(tempStr);
            q.push(temp);
        }
        else if (str[i] == ')')
        {
            while (s.top().op != '(')
            {
                q.push(s.top());
                s.pop();
            }
            s.pop();
            i++;
        }
        else if (str[i] == '(')
        {
            node temp;
            temp.flag = false;
            temp.op = str[i];
            s.push(temp);
            i++;
        }
        else
        { // 如果是操作符
            node temp;
            temp.flag = false;
            // 直接放入的情况有两种：
            // 1. 栈顶是左括号
            // 2. 栈顶符号的优先级小于当前符号的优先级
            // 当这两条都不满足时候才进行 弹出
            while (s.top().op != '(' && op[str[i]] <= op[s.top().op])
            {
                q.push(s.top());
                s.pop();
            }
            temp.op = str[i];
            s.push(temp);
            i++;
        }
    }
    while (s.size() > 1)
    {
        q.push(s.top());
        s.pop();
    }
}

double cal(char op, double a, double b) {
    double rev;
    switch (op)
    {
    case '+':
        rev = a + b;
        break;
    case '-':
        rev = a - b;
        break;
    case '*':
        rev = a * b;
        break;
    case '/':
        rev = a / b;
        break;
    default:
        break;
    }
    return rev;
}

double Cal()
{
    stack<double> rev;
    while (!q.empty())
    {
        if(q.front().flag) {
            rev.push(q.front().num);
            q.pop();
        }else {
            // 如果遇到操作符
            double a = rev.top();
            rev.pop();
            double b = rev.top();
            rev.pop();
            char c = q.front().op;
            q.pop();
            double temp = cal(c, b, a);
            rev.push(temp);
        }
    }
    return rev.top();
}

int main()
{
    freopen("data.txt", "r", stdin);
    op['#'] = -1;
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;
    while (getline(cin, str))
    {
        for (string::iterator it = str.end(); it != str.begin(); it--)
        {
            if(*it == ' ') str.erase(it);
        }
        while (!s.empty())s.pop();  // 清空栈
        node x;
        x.op = '#';
        x.flag = false; // 表明是操作符
        s.push(x);
        Change();   // 转为后缀表达式
        printf("%.2f\n", Cal());    // 计算后缀表达式
    }
    return 0;
}

