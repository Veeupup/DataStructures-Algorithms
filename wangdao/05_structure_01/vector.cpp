#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector<int> myV;

void print_vector(vector<int> myV)
{
    for (int i = 0; i < myV.size(); i++)
    {
        printf("%d ", myV[i]);
    }
    printf("\n");
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        myV.push_back(i);
    }
    print_vector(myV);

    myV.insert(myV.begin(), 3, 15);
    print_vector(myV);

    myV.pop_back();
    print_vector(myV);

    for (vector<int>::iterator it = myV.begin(); it != myV.end(); it++)
    {
        printf("%d ", *it);
    }


    return 0;
}