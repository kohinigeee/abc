#include<iostream>
#include<vector>

using namespace std;

int main()
{
    string s;

    int ans = 0;
    cin >> s;

    int l = 0;
    int pass0 = 0;
    while( l < s.size() ) {
        if ( s[l] == '0' ) {
           if ( pass0 ) {
            pass0 = 0;
           }  else {
            ++ans;
            pass0 = 1;
           }
        } else {
            ++ans;
            pass0 = 0;
        }
        ++l;
    }

    cout << ans << endl;
}