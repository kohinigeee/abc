#include<iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
    map<string,int> mp;
    mp["Monday"] = 5;
    mp["Tuesday"] = 4;
    mp["Wednesday"] = 3;
    mp["Tursday"] = 2;
    mp["Friday"] = 1;

    string s;
    cin >> s;
    cout << mp[s] << endl;
    // Monday, Tuesday, Wednesday, Thursday, Friday
}