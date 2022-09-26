#include<iostream>
#include<vector>
#include<cstdio>

#define MOD 998244353

using namespace std;
using ll = long long;

ll extend_gcd(ll a, ll b, ll &x, ll &y ) {
    if ( b == 0 ) {
        x = 1;
        y = 0;
        return a;
    }

    ll d = extend_gcd(b, a%b, x, y);
    ll xd = y; ll yd = x-a/b*y;
    x = xd; y = yd;
    return d;
}

ll rev_mod( ll a, ll p ) {
    ll x, y;
    extend_gcd(a,p, x, y);
    return ( ( x < 0 ) ? x+p : x );
}

int main()
{
    vector<ll> a, sum, dp;
    ll n;

    // cout << rev_mod(3, 5) << endl;

    cin >> n;
    a = vector<ll>(n+1, 0);
    sum = vector<ll>(n+1, 0);
    dp = vector<ll>(n+1, 0);

    for ( int i = 0; i < n-1; ++i ) cin >> a[i+1];

    dp[n] = 0;

    for ( int i = n-1; i > 0; --i ) {
        // cout << "i = " << i << endl;
        ll r = i+a[i]+1;
        if ( r > n ) r = n;
        ll tmp = sum[i+1]-sum[r];
        if ( tmp < MOD ) tmp += MOD;
        dp[i] = rev_mod(a[i], MOD)*tmp%MOD;
        dp[i] += rev_mod(a[i], MOD)*(a[i]+1);
        dp[i] %= MOD;
        sum[i] = sum[i+1]+dp[i];
        sum[i] %= MOD;
    }

    cout << dp[1] << endl;

}