/*
    Author: Veeupup
    按照 C 语言的定义方式，输入两个 C 语言语句
    第一句中包含定义语句，第二句为变量运算语句，要求输出第二句中未定义的变量

    input:
    int x12, y=1, num_stu=89, a[30], *p;
    Sum=num+x12*y;

    output:
    Sum, num

    思路：
    读取字符串，从前往后，按照逗号 ',' 为分割线，
    来找到不同变量定义的位置，起始位置和结束位置
        如果该定义为含等号，则寻找变量开始到等号之前的内容
        根据 基本类型，数组定义，指针定义 三种类型依次判断 
        然后将变量名加入数组中

    检测字符串时，需要根据符号，例如 + - * / 来把不同的符号分隔开
    然后和之前保存的变量名依次比较，看是否在其中
        
 */
#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> symbols;

// 去除首尾的空格
string trim(string str)
{
    int start, end;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            start = i;
            break;
        }
    }
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] != ' ' && str[i] != ';')
        {
            end = i;
            break;
        }
    }
    string s(str, start, end - start + 1); // 构造新的字符串
    return s;
}

void getSymbols(string str)
{
    str = trim(str);
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i] == ' ') {
            str = string(str, i);
            break;
        }
    }
    // 从现在开始找到所有逗号的位置
    vector<int> comma;
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i] == ',') 
            comma.push_back(i);
    }
    // 根据逗号位置来切割成不同的变量，我们还需要处理特殊处理指针和数组
    for (int i = 0; i < comma.size(); i++)
    {
        if(i == 0) {
            symbols.push_back(string(str, 0, comma[0]));
        }else{
            symbols.push_back(string(str, comma[i-1]+1, comma[i]-comma[i-1]-1));
        }
    }
    symbols.push_back(string(str, comma[comma.size()-1]+1));
    for (int i = 0; i < symbols.size(); i++)
    {
        symbols[i] = trim(symbols[i]);
        string temp = symbols[i];
        int hasEqual = -1;  // 如果有等号，记录下等号的位置
        int hasArray = -1;  // 如果出现数组定义的方括号，则记录下其位置
        int hasPointer = -1;
        if(temp[0] == '*') {
            hasPointer = 0;
        }
        for (int i = 0; i < temp.size(); i++)
        {
            if(temp[i] == '=') {
                hasEqual = i;
            }
            if(temp[i] == '[') {
                hasArray = i;
            }
        }
        if(hasEqual != -1) 
        {   // 如果有等号，那么等号之前的就是变量名,这个时候还可能包含数组
            temp = string(temp, 0, hasEqual);
        }
        if(hasArray != -1) 
        {   // 如果有数组，则截取去名称
            temp = string(temp, 0, hasArray);
        }
        if(hasPointer != -1) 
        {   // 如果有指针，则截取指针之后的
            temp = string(temp, 1);
        }
        symbols[i] = temp;
    }
}

void testSymbols(string test_str) {
    test_str = trim(test_str);  // 去掉前面的空格和最后的分号
    vector<int> comma;
    for (int i = 0; i < test_str.size(); i++)
    {   // 记录下运算符号的位置
        if(test_str[i] == '+' || test_str[i] == '-' || test_str[i] == '*' || test_str[i] == '/' || test_str[i] == '=' ) 
            comma.push_back(i);
    }
    vector<string> tests;
        for (int i = 0; i < comma.size(); i++)
    {
        if(i == 0) {
            tests.push_back(string(test_str, 0, comma[0]));
        }else{
            tests.push_back(string(test_str, comma[i-1]+1, comma[i]-comma[i-1]-1));
        }
    }
    tests.push_back(string(test_str, comma[comma.size()-1]+1));
    for (int i = 0; i < tests.size(); i++)
    {
        bool hasFind = false;
        for (int j = 0; j < symbols.size(); j++)
        {
            if(tests[i] == symbols[j]) {
                hasFind = true;
                break;
            }
        }
        if(!hasFind) {
            cout << tests[i] << " ";
        }
    }
    cout << endl;
}

int main()
{
    // freopen("data.txt", "r", stdin);
    string str_input, str_check;
    getline(cin, str_input);
    getline(cin, str_check);
    getSymbols(str_input);
    testSymbols(str_check);

    return 0;
}