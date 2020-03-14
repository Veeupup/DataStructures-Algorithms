//
// Created by 谭巍 on 2020-03-11.
//  北航

/*
 * 这个题是正则表达式中的一种实现，不区分大小写
 * 还包含了大小写字符的转换
 * 在 cctype 中包含了大小写转换的函数 tolower(int n) toupper(int c)
 * isalnum(int c) 检查是否是字母和数字
 * isalpha(int c) 检查是狗屎字母
 * isdigit(int c) 检查是否是十进制数字
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

#define N 1010
char str[N][100];
char symbol[50];
int numSymbols = 0;
char temStr[100];
int beforeNum = 0, afterNum = 0;

bool isMatch(char *str1, char *str2) {
    for (int i = 0; i < beforeNum; ++i) {
        // 检测匹配规则之前的字符
        if(str1[i] != str2[i])
            return false;
    }
    // 检测中间的字符
    bool flag = false;
    for (int i = 0; i < numSymbols; ++i) {
        if(str1[beforeNum] == symbol[i]) {
            flag = true;
        }
    }
    // 如果没有任何一个符合，则返回false
    if(!flag)
        return false;
    // 检测匹配之后的是否相同
    int x = strcmp(str1+beforeNum+1, str2+beforeNum+numSymbols+2);
    if(x == 0) {
        return true;
    }else {
        return false;
    }
}

void Big2Small(char *str, char *dst) {
    int len = strlen(str);
    for (int i = 0; i < len+1; ++i) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            dst[i] = str[i] + 32;
        }else {
            dst[i] = str[i];
        }
    }
}

void notUseString() {
    freopen("data.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", str[i]);
    }
    scanf("%s", temStr);
    Big2Small(temStr, temStr);  // 模板自己变为全小写
    int len = strlen(temStr);
    bool flag = false;
    for (int i = 0; i < len; ++i) {
        if(flag) {
            if(temStr[i] == ']') break;
            symbol[numSymbols++] = temStr[i];
            continue;
        }
        if(temStr[i] == '[') {
            flag = true;
            continue;
        }
        beforeNum++;
    }
    afterNum = len - beforeNum - numSymbols - 2;
    char meanStr[100];
    for (int i = 0; i < n; ++i) {
        Big2Small(str[i], meanStr);
        if(isMatch(meanStr, temStr)) {
            printf("%d %s\n", i+1, str[i]);
        }
    }
}

int main()
{
    notUseString();
    return 0;
}
