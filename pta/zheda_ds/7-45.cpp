/* 
    思路：
        用 map<string, int> 的结构存储数据
        在读入数据的时候就应该对里程进行总结

 */
#include <iostream>
#include <string>
#include <map>

using namespace std;

int N, K;   // 会员数目，最低里程数
map<string, int> members;

int main()
{ 
    scanf("%d%d", &N, &K);
    char number[20];
    string num;
    int dis;
    while (N--)
    {
        scanf("%s%d", number, &dis);
        if(dis > 0)
            dis = max(K, dis); // 至少算作 500
        num = string(number);
        if (members.find(num) == members.end())
            members[num] = dis;
        else
            members[num] += dis;
    }
    int count;
    cin >> count;
    while (count--)
    {
        scanf("%s", number);
        num = string(number);
        if (members.find(num) != members.end())
        {
            printf("%d\n", members[num]);
        }
        else
        {
            printf("No Info\n");
        }
    }
    return 0;
}