#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

map<string, int> myMap;

int main()
{
    myMap["Emma"] = 67;
    myMap["tanwei"] = 21;
    myMap.insert(pair<string, int>("bob", 12));
    myMap.insert(pair<string, int>("mike", 13));
    printf("the size of map is : %d\n", myMap.size());
    printf("the age of bob is : %d\n", myMap["bob"]);
    printf("the age of mike is : %d\n", myMap.at("mike"));
    myMap.erase("bob");
    printf("\n");
    map<string, int>::iterator it;
    for (it = myMap.begin(); it != myMap.end(); it++)
    {
        cout << "the score of" << it->first;
        cout << ": " << it->second << endl;
    }
    myMap.clear();
    if (myMap.empty())
    {
        printf("the map is empty!\n");
    }
    it = myMap.find("bob");
    if (it != myMap.end())
    {
        printf("bob is found.\n");
    }
    printf("the size of myMap : %d \n", myMap.size());
    return 0;
}