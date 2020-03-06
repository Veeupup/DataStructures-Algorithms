#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>
#define N 1000010

/* 
    第一题
 */

int father[N];
int height[N];
int exist[N];

void Initial() {
    for (int i = 0; i < N; i++)
    {
        father[i] = i;
        height[i] = 0;
        exist[i] = 0;
    }
}

int Find(int x) {
    if(x != father[x]) {
        x = Find(father[x]);
    }
    return x;
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if(x != y) {
        if(height[x] < height[y]) {
            father[x] = y;
        }else if(height[y] < height[x]) {
            father[y] = x;
        }else {
            father[y] = x;
            height[x]++;
        }
    }
}

int main()
{
    freopen("data.txt","r", stdin);
    int x, y;
    Initial();
    while(scanf("%d %d", &x, &y) != EOF) {
        exist[x]++;
        exist[y]++;
        Union(x, y);
    }
    
    int root = 0;
    for (int i = 1; i < N; i++)
    {
        if(exist[i] != 0 && i == Find(i)) {
            root++;
        }
    }
    printf("%d\n", root);
    return 0;
}