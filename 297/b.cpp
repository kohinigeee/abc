#include<iostream>
#include<vector>

using namespace std;

int main()
{
    string s; cin >> s;

    int k;
    vector<int> r(2,-1), b(2,-1);
    int rcnt = 0, bcnt = 0;

    for ( int i = 0; i < 8; ++i ) {
        if ( s[i] == 'K' ) k = i;
        if ( s[i] == 'R' ) r[rcnt++] = i;
        if ( s[i] == 'B' ) b[bcnt++] = i;
    }

    bool ans = true;
    if ( (b[0]+b[1])%2 == 0 ) ans =false;
    if ( k < r[0] || k > r[1] ) ans = false;

    if ( ans ) cout << "Yes" << endl;
    else cout << "No" << endl;
}