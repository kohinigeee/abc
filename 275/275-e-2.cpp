#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

ll kousoku2(ll x, ll y, ll p ) {
    ll ans = 1;
    ll base = x;
    while( y > 0 ) {
        if ( y&1 ) {
            ans *= base;
            ans %= p;
        }
        base *= base;
        base %= p;
        y = y >> 1;
    }
    return ans;
}

ll rev_mod(ll x, ll p ) {
    return kousoku2(x, p-2, p);
}

int main()
{
    const ll MOD = 998244353;
    ll n, m, k;
    vector<vector<ll>> dp;
    
    cin >> n >> m >> k;

    dp = vector<vector<ll>>(k+1, vector<ll>(n+1, 0));
    ll revm = rev_mod(m, MOD);

    // cout << revm*m%MOD << endl;
    dp[0][0] = 1;

    for ( int kai = 0; kai < k; ++kai ) {
        for ( int i = 0; i < n; ++i ) {
            for ( int d = 1; d <= m; ++d ) {
                int to = (i+d);
                if ( to > n ) to = n-(to-n);

                dp[kai+1][to] += dp[kai][i]*revm%MOD;
                dp[kai+1][to] %= MOD;
            }
        }
    }

    ll ans = 0;
    for ( int i = 0; i <= k; ++i ) { ans += dp[i][n]; ans %= MOD; }
    cout << ans << endl;
}