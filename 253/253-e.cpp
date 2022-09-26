#include<iostream>
#include<vector>
#include<algorithm>

#define MAXD 998244353

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vll = vector<vl>;

int main()
{
    ll n, m, k;

    cin >> n >> m >> k;

    if ( k == 0 ) {
        ll ans = 1;
        for ( int i = 0; i < n; ++i ) {
            ans *= m;
            ans %= MAXD;
        }
        cout << ans << endl;
        return 0;
    }

    vll dp( n, vl(m+1, 0));

    for ( int i = 1; i <= m; ++i ) dp[0][i] = 1;

    for ( int i = 1; i < n; ++i ) {
        vl sum(m+1, 0);

        for ( int t = 1; t <= m; ++t ) {
            sum[t] = sum[t-1]+dp[i-1][t];
            sum[t] %= MAXD;
        }

        for ( int j = 1; j <= m; ++j ) {
            ll l = max(0LL, j-k);
            ll r = min(j+k-1, m);

            ll tmp = (sum[l]+sum[m])%MAXD;
            tmp -= sum[r];
            if ( tmp < 0 ) tmp += MAXD;
            dp[i][j] = tmp;
            // if ( dp[i][j] < 0 ) dp[i][j] += MAXD;
        }
    }

    ll ans = 0;
    for ( auto v : dp[n-1] ) { ans += v; ans %= MAXD; }
    cout << ans << endl;

    // for ( auto v: dp ) {
    //     for ( auto v1 : v ) cout << v1 << " ";
    //     cout << endl;
    // }
}