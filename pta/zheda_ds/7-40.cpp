/* 
    奥运排行榜
 */
#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 225

struct Goal
{
    int id, gold, medal, population;
    double averageGold, averageMedal;
} ranks[maxn];

int N, M;          // 参与排名的国家总数（0～N-1），前来咨询的国家总数
int country[maxn]; // 最后参与排名的国家

bool cmpGold(Goal a, Goal b)
{
    return a.gold > b.gold;
}

bool cmpMedal(Goal a, Goal b)
{
    return a.medal > b.medal;
}

bool cmpAverGold(Goal a, Goal b)
{
    return a.averageGold > b.averageGold;
}

bool cmpAverMedal(Goal a, Goal b)
{
    return a.averageMedal > b.averageMedal;
}

int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf("%d%d%d", &ranks[i].gold, &ranks[i].medal, &ranks[i].population);
        ranks[i].averageGold = ranks[i].gold * 1.0 / ranks[i].population;
        ranks[i].averageMedal = ranks[i].medal * 1.0 / ranks[i].population;
        ranks[i].id = i;
    }
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &country[i]);
    }

    int rank1[maxn], rank2[maxn], rank3[maxn], rank4[maxn];

    // 1. 根据金牌数排名
    sort(ranks, ranks + N, cmpGold);
    int level = 1;
    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            rank1[ranks[i].id] = level;
        }
        else
        {   // 如果当前金牌数和上一个的金牌数一样，那么就和上一个的排名一样
            if (ranks[i].gold == ranks[i - 1].gold)
                rank1[ranks[i].id] = rank1[ranks[i - 1].id];
            else
                rank1[ranks[i].id] = level;
        }
        level++;
    }

    // 2. 根据奖牌数排名
    level = 1;
    sort(ranks, ranks + N, cmpMedal);
    for (int i = 0; i < N; i++)
    {

        if (i == 0)
        {
            rank2[ranks[i].id] = level;
        }
        else
        {   // 如果当前金牌数和上一个的金牌数一样，那么就和上一个的排名一样
            if (ranks[i].medal == ranks[i - 1].medal)
                rank2[ranks[i].id] = rank2[ranks[i - 1].id];
            else
                rank2[ranks[i].id] = level;
        }
        level++;
    }

    // 3. 根据人均金牌数排名
    level = 1;
    sort(ranks, ranks + N, cmpAverGold);
    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            rank3[ranks[i].id] = level;
        }
        else
        {   // 如果当前金牌数和上一个的金牌数一样，那么就和上一个的排名一样
            if (ranks[i].averageGold == ranks[i - 1].averageGold)
                rank3[ranks[i].id] = rank3[ranks[i - 1].id];
            else
                rank3[ranks[i].id] = level;
        }
        level++;
    }

    // 4.根据人均奖牌数排名
    level = 1;
    sort(ranks, ranks + N, cmpAverMedal);
    for (int i = 0; i < N; i++)
    {

        if (i == 0)
        {
            rank4[ranks[i].id] = level;
        }
        else
        {   // 如果当前金牌数和上一个的金牌数一样，那么就和上一个的排名一样
            if (ranks[i].averageMedal == ranks[i - 1].averageMedal)
                rank4[ranks[i].id] = rank4[ranks[i - 1].id];
            else
                rank4[ranks[i].id] = level;
        }
        level++;
    }

    int rankType = 0;   // 记录方案
    int bestRank = N + 1;   // 记录排名
    for (int i = 0; i < M; i++)
    {
        rankType = 0;
        bestRank = N + 1;
        if (rank1[country[i]] < bestRank)
        {
            rankType = 1;
            bestRank = rank1[country[i]];
        }
        if(rank2[country[i]] < bestRank)
        {
            rankType = 2;
            bestRank = rank2[country[i]];
        }
        if(rank3[country[i]] < bestRank)
        {
            rankType = 3;
            bestRank = rank3[country[i]];
        }
        if(rank4[country[i]] < bestRank)
        {
            rankType = 4;
            bestRank = rank4[country[i]];
        }
        if(i != 0)
            printf(" ");
        printf("%d:%d", bestRank, rankType);
        }


    return 0;
}
