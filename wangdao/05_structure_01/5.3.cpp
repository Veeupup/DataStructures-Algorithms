#include <iostream>
#include <cstdio>
#include <cstdint>
#include <queue>
using namespace std;

struct animal
{
    int number;
    int order;
    animal(int n, int o) : number(n), order(o) {} // 构造函数
};

int main()
{
    freopen("data.txt", "r", stdin);
    queue<animal> dogs, cats;
    int n, order = 0;
    scanf("%d", &n);
    int method, type;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &method, &type);
        if (method == 1)
        { // 进入
            if (type > 0)
            {
                dogs.push(animal(type, order++));
            }
            else
            {
                cats.push(animal(type, order++));
            }
        }
        else
        { // 收养
            if(type == 0 && !dogs.empty ()&& !cats.empty()) {
                // 都还有，且用第一种方式收养
                if(dogs.front().order < cats.front().order) {
                    printf("%d ", dogs.front().number);
                    dogs.pop();
                }else {
                    printf("%d ", cats.front().number);
                    cats.pop();
                }
            }else if(type == 0 && dogs.empty() && !cats.empty()) {
                // 狗已经空了，只有猫咪了
                printf("%d ", cats.front().number);
                cats.pop();
            }else if(type == 0 && !dogs.empty() && cats.empty()) {
                // 狗已经空了，只有猫咪了
                printf("%d ", dogs.front().number);
                dogs.pop();
            }else if(type == 1 && !dogs.empty()) {
                printf("%d ", dogs.front().number);
                dogs.pop();
            }else if(type == 1 && !cats.empty()) {
                printf("%d ", cats.front().number);
                cats.pop();
            }
        }
    }

    return 0;
}