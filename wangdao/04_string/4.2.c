/* C读取一行字符串,使用 fgets */
#include<stdio.h>
#include<stdint.h>
#include<string.h>

int main()
{
    int size = 100;
    char *str = (char*) malloc(size);

    while(NULL != fgets(str, size, stdin)) {
        int len = strlen(str);
        for (int i = 0; i < len; i++)
        {
            if (str[i] == 'z' || str[i] == 'Z')
            {
                str[i] -= 25;
            }
            else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            {
                str[i]++;
            }
            
        }
        printf("%s", str);
    }

    return 0;
}