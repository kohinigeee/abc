#include<iostream>
#include<vector>
#include<algorithm>

#define INF (1<<30)
#define MOD (998244353)

using namespace std;
using ll = long long;

ll func( int x, int x_ch, int n, vector<vector<int>>& delta ) {
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));

    if ( delta[0][x_ch] >= x ) return 0;
    dp[delta[0][x_ch]][x] = 1;

    for ( int i = 1; i < x; ++i ) {
        for ( int j = x; j <= n; ++j ) {
            for ( int k = 0; k < 26; ++k ) {
                if ( delta[i][k] >= x ) continue;
                if ( delta[j][k] == INF ) continue;
                dp[delta[i][k]][delta[j][k]] += dp[i][j];
            }
        }
    }

    ll ans = 0;
    for ( int i = 1; i < x; ++i ) {
        if ( delta[i][x_ch] != x ) continue;
        for ( int j = x; j <= n; ++j ) {
            ans += dp[i][j];
            ans %= MOD;
        }
    }
    return ans;
}

int main()
{
    string s;

    cin >> s;
    vector<int> v(s.size()+1);

    for ( int i = 0; i < s.size(); ++i ) v[i] = s[i]-'a';

    vector<vector<int>> delta = vector<vector<int>>(s.size()+1);
    vector<int> d(26, 0);

    delta[s.size()] = d;
    for ( int i = s.size()-1; i >= 0; --i ) {
        d[v[i]] = i+1;    
        delta[i] = d;
    }

    ll ans = 0;
    if ( s.size() > 0 ) {
        for ( int x = 2; x <= s.size(); ++x ) {
            ll tmp = func(x, v[x-1], s.size(), delta);
            // printf("x = %d, tmp = %d\n", x, tmp);
            ans += func(x, v[x-1], s.size(), delta);
            ans %= MOD;
        }
    }

    cout << ans << endl;

    // cout << "  ";
    // for ( int i = 0; i < 26; ++i ) cout << char(i+'a') << " "; cout << endl;
    // for ( int i = 0; i <= s.size(); ++i ) {
    //     cout << i << " ";
    //     for ( auto v : delta[i] ) cout << v << " "; cout << endl;
    // }
}