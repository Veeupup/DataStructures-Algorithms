/* 
    给定输入的日期，输出日期
    示例1
        输入
        9 October 2001
        14 October 2001

        输出
        Tuesday
        Sunday

    思路：
        隐藏条件就是1年1月1日是星期一，把这个时间点设为锚点
        计算输入的日期与锚点之间隔了多少天
        天数对7取余，所得结果就是星期几
 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int month[13][2]={
    {0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},
    {30,30},{31,31},{30,30},{31,31}
};
char month_name[13][20]={
    "","January","February","March","April","May","June","July","August",
    "September","October","November","December"
};
char week_name[7][20]={
    "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"
};
bool isLeap(int year){
    return (year%4==0&&year%100!=0)||(year%400==0);
}
int main(){
    int d,m,y;
    char s[20];
    while(scanf("%d%s%d",&d,s,&y)!=EOF){
        for(m=1;m<=12;m++){
            if(strcmp(s,month_name[m])==0) break;
        }
        int y1=1,m1=1,d1=1,day=1;
        while(y1<y||m1<m||d1<d){
            d1++;
            if(d1==month[m1][isLeap(y1)]+1){
                d1=1;
                m1++;
            }
            if(m1==13){
                m1=1;
                y1++;
            }
            day++;
        }
        printf("%s\n",week_name[day%7]);
    }
    return 0;
}