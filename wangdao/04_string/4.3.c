/*  浙大，统计字符
    使用C读取字符串
    使用文件输入
 */

#include <stdio.h>
#include <string.h>
#include    <stdint.h>

int main()
{
    // 使用文件输入
    freopen("data.txt", "r", stdin);
    char str1[6], str2[81];
    while (gets(str1) && str1[0] != '#')
    {
        gets(str2);
        int count[128] = {0};                  //统计128个ASCII出现的次数，每次统计都要清零
        for (int i = 0; i < strlen(str2); i++) //统计str2中每个字符出现的次数，只需遍历一遍
            count[(int)str2[i]]++;

        for (int i = 0; i < strlen(str1); i++)
            printf("%c %d\n", str1[i], count[(int)str1[i]]);
    }

    return 0;

    return 0;
}