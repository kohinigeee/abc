#include<iostream>
#include<vector>
#include<string>

using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;

    ll ans = 0;

    ll tmp = 1;
    if ( s.size() >= 2 ) {
        for ( int i = 0; i < s.size()-1; ++i ) {
            tmp *= 26;
            ans += tmp;
        }
    }

    tmp = 1;
    for ( int i = 0; i < s.size(); ++i ) {
        char ch = s[s.size()-i-1];
        ans += tmp*(ch-'A');
        tmp *= 26; 
    }
    ++ans;
    cout << ans << endl;
}