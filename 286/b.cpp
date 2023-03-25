#include<iostream>
#include<string>

using namespace std;

int main()
{
    int n;
    int sta = 0;
    string s, ans;

    cin >> n;
    cin >> s;

    for ( int i = 0; i < n; ++i ) {
        if ( s[i] == 'n' ) {
            sta = 1;
        } else if ( sta == 1 && s[i] == 'a' ) {
            ans += 'y';
            sta = 0;
        } else sta = 0;
        ans += s[i];
    }

    cout << ans << endl;
}
