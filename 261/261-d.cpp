#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

int main()
{
    int m, n;

    cin >> n >> m;
    vector<ll> x(n+1, 0);
    vector<ll> y(n+1, 0);

    for ( int i = 0; i < n; ++i ) cin >> x[i+1];
    for ( int i = 0; i < m; ++i ) {
        int tmpc, tmpy; cin >> tmpc >> tmpy;
        y[tmpc] = tmpy;
    }

    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));

    for ( int i = 1; i <= n; ++i ) {
        ll maxv = 0;
        for ( int j = 0; j <= i; ++j ) maxv = max(maxv, dp[i-1][j]);
        dp[i][0] = maxv;

        for ( int j = 1; j <= n; ++j ) {
            if ( i < j ) break;
            dp[i][j] = dp[i-1][j-1]+x[i]+y[j];
        }
    }

    ll ans = 0;
    for ( int j = 0; j <= n; ++j ) ans = max(ans, dp[n][j] );

    // for ( int i = 0; i < n; ++i ) {
    //     for ( int j = 0; j < n; ++j ) cout << dp[i+1][j+1] << " ";
    //     cout << endl;
    // }
    cout << ans << endl;
}