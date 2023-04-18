#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

const ll MOD = 998244353;

ll kousoku(ll x, ll y ) {
    ll ans = 1;
    ll ord = x;

    while( y > 0 ) {
        if ( y & 1 ) {
            ans *= ord;
            ans %= MOD;
        }
        ord *= ord;
        ord %= MOD;
        y = (y>>1);
    }

    return ans;
}

ll rev(ll x) {
    return kousoku(x, MOD-2);
}

int main()
{
     int n, a, b, p, q;

     cin >> n >> a >> b >> p >> q;

     vector<vector<ll>> dp(n+1, vector<ll>(n+1, 1));
     ll r = rev(p*q);

     for ( int i = 1; i <= n-1; ++i ) dp[i][n] = 0;

     for ( int i = n-1; i >= 1; --i ) {
        for ( int j = n-1; j >= 1; --j ) {
            ll sum = 0;
            for ( int k = 1; k <= p; ++k ) {
                for ( int t = 1; t <= q; ++t ) {

                    int ni = min(i+k, n);
                    int nj = min(j+t, n);

                    sum += dp[ni][nj];
                    sum %= MOD;
                }
            }
            dp[i][j] = (sum*r)%MOD;
        }
     }

     cout << dp[a][b] << endl;
}