#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int Char2Int(char c) {
    if(c >= '0' && c <= '9') {
        return c - '0';
    }else if(c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }else if(c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }
    return -1;
}

char Int2Char(int x) {
    if(x >= 0 && x <= 9) {
        return x + '0';
    }else {
        return x - 10 + 'A';
    }
}

int main()
{
    int a, b;
    char str[1000];
    while (scanf("%d%s%d", &a, str, &b) != EOF)
    {
        long temp = 0;
        for(int i=0;i<strlen(str);i++) {
            temp = a * temp + Char2Int(str[i]);
        }
        vector<char> res;
        while (temp != 0)
        {
            res.push_back( Int2Char(temp%b));
            temp /= b;
        }
        for(int i=res.size()-1;i>=0;i--) {
            printf("%c", res[i]);
        }
        printf("\n");
    }
    
    return 0;

}