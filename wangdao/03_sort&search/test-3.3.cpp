#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct mice {
    int weight;
    char color[10];
}mices[101];

bool cmp(mice a, mice b) {
    return a.weight > b.weight;
}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for(int i=0;i<n;i++){
            scanf("%d%s",&mices[i].weight, mices[i].color);
        }
        sort(mices, mices+n, cmp);
        for(int i=0;i<n;i++) {
            printf("%s\n", mices[i].color);
        }
    }
    return 0;

}