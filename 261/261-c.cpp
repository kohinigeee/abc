#include<iostream>
#include<set>
#include<map>

using namespace std;

int main()
{
    map<string, int> mp;
    int n;

    cin >> n;
    while(n--) {
        string tmp; cin >> tmp;
        if ( mp.find(tmp) == mp.end() ) {
            mp[tmp] = 1;
            cout << tmp << endl;
        } else {
            cout << tmp << "(" << mp[tmp] << ")" << endl;
            mp[tmp] += 1;
        }
    }
}