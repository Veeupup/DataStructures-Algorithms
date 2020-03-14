/*
    Author: Veeupup

    输入一个 C 语言的 enum 语句，输出每个 enum 的值

    input:
        enum bool { true, false};

    output:
        true0
        false1
    
    input:
        enum date { JAN=1, FEB, MAR, APR, MAY, JUN, JULY, AUG, SEP, OCT, NOV, DEC, MON=1, TUE, WED, THU, FRI, SAT, SUN, found=1949 };

    output:
        JAN1
        FEB2
        ...
        DEC12
        MON1
        THU2
        ...
        SUN7
        found1949

    思路：
        读取一个语句，去除前面的 enum 和 最后的分号
        然后根据逗号将整个语句分隔开成不同的枚举量，采用结构体来存储
        从前往后遍历每个结构体，
            如果该值含有等号，则该结构体的值为等号之后的值
            如果不含等号，则该结构体的值等于前一个结构体的值加 1
    0123456789012
    enum a{true};

    0123456789012
    jan,thu=1,wed

 */
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

struct val
{
	char name[20];
	int num;
} vs[2000];
char str[2000];
int value = 0;

bool isV(char ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '_')
		return true;
	return false;
}

int main()
{
	cin.getline(str, 2000);
	int x = 0, y = 0, i = 0, len = strlen(str);
	while (str[i] != '{')
		i++;	// 找到字符串开始的位置，使用 while 来查找
	i++;
	char name[20];
	int flag = 1;
	for (; i < len; i++)
	{
		if (str[i] == ' ')
			continue;
		if (isV(str[i]))
		{
			name[y++] = str[i];
			if (flag == 0)
				flag = 1;
			continue;
		}
		if (str[i] == '=' || str[i] == ',' || str[i] == '}')
		{
			if (flag == 1)
			{
				name[y] = '\0';
				vs[x].num = value++;
				strcpy(vs[x++].name, name);
				y = 0;
			}
			else if (flag == 2)
			{
				name[y] = '\0';
				value = atoi(name);	// 将其转换为 整数
				vs[x - 1].num = value++;
				y = 0;
			}
			if (str[i] == '=')
				flag = 2;	// 遇到等号了
			else
				flag = 0;// 遇到末尾了 '}'
		}
	}
	for (i = 0; i < x; i++)
		printf("%s%d\n", vs[i].name, vs[i].num);

	return 0;
}
