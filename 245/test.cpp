#include<set>
#include<vector>
#include<iostream>

using namespace std;

int main()
{
    multiset<int> s;
    vector<int> v = { 1, 2, 2, 4, 8, 7, 10, 11};

    for ( auto i : v ) s.insert(i);

    cout << (*s.lower_bound(6)) << endl;
    cout << (*s.lower_bound(7)) << endl;
    cout << ( s.lower_bound(100) == s.end() ? "end" : "not end" ) << endl;
}