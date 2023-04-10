#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
using ll = long long;

int main()
{
    vector<ll> values;
    ll n, m;
    cin >> n >> m;

    if ( n*n < m ) {
        cout << -1 << endl;
        return 0;
    }

    ll ans = n*n;
    ll maxi;
    for ( maxi = 1; maxi*maxi <= m; ++maxi);
    ++maxi;

    for ( ll i = 1; i <= maxi; ++i ) {
        if ( i > n ) break;
        // ll b = (m+i-1)/i;
        ll b = m/i;
        if ( m%i != 0 ) b += 1;
        if ( b > n ) continue;
        if ( i*b < m ) continue;
        ans = min<ll>(i*b, ans);
    }

    cout << ans << endl;
}