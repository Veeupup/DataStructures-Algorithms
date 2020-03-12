/*
 * 清华上机
 *
 * 手机键盘
 *
 * https://www.nowcoder.com/practice/20082c12f1ec43b29cd27c805cd476cd?tpId=40&tqId=21337&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 *
 */
#include <cstdio>
#include <cstring>
#include <cstdint>

int keyboard[26] = {
        1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};

int main()
{
    freopen("data.txt", "r", stdin);
    char str[101];
    while (scanf("%s", str) != EOF) {
        int len = strlen(str);
        int time = 0;
        for (int i = 0; i < len; ++i) {
            // 至少要按下这么多次
            time += keyboard[str[i] - 'a'];
            // 判断是否是键盘上的同一个按键上的位置
            // 如果是同一个按键上:
            //      则字符之间的差值 == 按键数的差值
            if(i != 0 && str[i] - str[i-1] == keyboard[str[i] - 'a'] - keyboard[str[i-1] - 'a']) {
                time += 2;
            }
        }
        printf("%d\n", time);
    }




    return 0;
}

