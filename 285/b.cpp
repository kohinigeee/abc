#include<iostream>
#include<string>

using namespace std;

int main()
{
    int n;
    string s;
    
    cin >> n;
    cin >> s;

    for ( int i = 1; i < n; ++i ) {
        int ans = 0;
        for ( int l = 1; l <= n; ++l ) {
            if ( l+i > n ) break;
            if ( s[l-1] == s[l+i-1] ) {
                break;
            }
            ans = l;
        }
        cout << ans << endl;
    }
}