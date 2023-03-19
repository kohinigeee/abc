#include<iostream>
#include<vector>
#include<string>

using namespace std;
using ll = long long;

int main()
{
    string s, t;
    int ans;
    cin >> s >> t;

    for ( ans = 0; ans < s.size(); ++ ans ) {
        if ( s[ans] != t[ans] ) break;
    }

    cout << ans+1 << endl;
}