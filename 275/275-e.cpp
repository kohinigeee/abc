#include<iostream>
#include<vector>
#include<cstdio>
#include<utility>

using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

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
ll n, m, k;
ll MOD = 998244353;
vector<vector<pll>> dp;

int main()
{
    cin >> n >> m >> k;

    ll revm = rev_mod(m, MOD);
    cout << "revm = " << revm << endl;
    dp = vector<vector<pll>>(k+1, vector<pll>(n+1, make_pair(0,1)));

    for ( ll i = 1; i < n; ++i ) {
        if ( i+m < n ) dp[1][i] = make_pair(0,1);
        else dp[1][i] = make_pair(1, m);
    }
    for ( ll i = 1; i <= k; ++i ) dp[i][n] = make_pair(1,1);


    for ( ll kai = 2; kai <= k; ++kai ) {
        for ( ll masu = 1; masu < n; ++masu ) {
            // cout << "kai = " <<kai << ", masu = " <<masu << endl;
            ll sumx = 1;
            for ( ll i = 1; i <= m; ++i ) {
                ll to = masu+i;
                if ( to > n ) {
                    ll tmp = to-n;
                    to = n-tmp;
                }
                sumx *= dp[kai-1][to].second;
                sumx %= MOD;
            }
            dp[kai][masu].second = sumx;

            cout << "kai = " << kai << ", masu = "<< masu << endl;
            cout << "sumx = " << dp[kai][masu].second << endl;

            for ( ll i = 1; i <= m; ++i ) {
                ll to = masu+i;
                if ( to > n ) {
                    ll tmp = to-n;
                    to = n-tmp;
                }
                ll revx = dp[kai][masu].second;
                dp[kai][masu].first += sumx*revx%MOD*dp[kai-1][to].first;
                dp[kai][masu].first %= MOD;
            }
            dp[kai][masu].second %= MOD;
            dp[kai][masu].second *= revm;

            cout << "dp[kai][masu] = " << dp[kai][masu].second << endl;
            
            dp[kai][masu].first %= MOD;
            dp[kai][masu].second %= MOD;

            cout << dp[kai][masu].first << " " << dp[kai][masu].second << endl;
            for ( auto v : dp ) {
                for ( auto i : v ) cout << "( " << i.first << ", " << i.second << ") ";
                cout << endl;
            }
            cout << endl;
        }

    }

    cout << dp[k][n-1].first << " " << dp[k][n-1].second << endl;

    ll revx = rev_mod(dp[k][n-1].second, MOD);
    ll ans = revx*dp[k][n-1].first%MOD;
    cout << ans << endl;

    ll y = dp[2][1].first;
    ll x = dp[2][1].second;
    cout << "test :" << y*rev_mod(x,MOD)%MOD << endl;
}