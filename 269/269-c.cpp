#include<iostream>
#include<algorithm>
#include<vector>

using ll = long long;
using namespace std;

ll change ( ll x, ll no ) { // xのno目のbitを1にする
    return x | ( 1LL<<no );
}

ll take_bit( ll x, ll no ) {
    return ( x >> no ) & 1LL;
}

int main()
{
    vector<int> ord;
    ll n;
    vector<ll> ans;

    cin >> n;
    ll cnt = 0;
    while( n > 0 ) {
        if ( n & 1LL ) ord.push_back(cnt);
        ++cnt; n = n>>1;
    }

    for ( ll i = 0; i < (1LL << ord.size() ); ++i ) {
        // cout << "i = " << i <<endl;
        ll tmp = 0;
        for ( int j = 0; j < ord.size(); ++j ) {
            if ( take_bit(i, j) ) {
                tmp = change(tmp, ord[j]);
            }
        }
        ans.push_back(tmp);
    }

    sort(ans.begin(), ans.end());
    for ( auto v : ans ) cout << v << endl;
}