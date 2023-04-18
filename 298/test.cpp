#include<iostream>
#include<map>

using namespace std;

int main()
{
    map<int,int> mp;

    mp[10] += 10;

    cout << mp[10] << endl;
}