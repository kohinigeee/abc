#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

#define MIN ((-1LL)<<50)

using namespace std;

using ll = long long;

int main()
{
    vector<vector<ll>> dp;
    vector<ll> a;
    int m, n;

    cin >> n >> m;
    dp = vector<vector<ll>>( n+1, vector<ll>(m+1, MIN));
    a = vector<ll>(n,0);

    for ( int  i = 0; i < n; ++i ) {
        cin >> a[i];
    }

    // ll tmp = 0;
    // for ( int i = 1; i <= m; ++i ) {
    //     tmp += a[i-1];
    //     dp[i][i] = tmp;
    // }

    dp[0][0] = 0;
    for ( int i = 1; i <= n; ++i ) dp[i][0] = 0;
    for ( int i = 1; i <= n; ++i ) {
        for ( int j = 1; j <= min(m, i); ++j ) {
            // cout << "t1 :" << dp[i][j-1]+a[i-1]*j << " ";
            // printf("%d + %d * %d = %d\n", dp[i][j-1], a[i-1], j, dp[i][j-1]+a[i-1]*j);
            // cout << "t2 :" << dp[i-1][j] << endl;
            if ( i-1 >= j ) dp[i][j] = dp[i-1][j];
            dp[i][j] = max(dp[i-1][j-1]+a[i-1]*(j), dp[i][j]);
        }
    }

    cout << dp[n][m] << endl;

    // for ( int i = 1; i <= n; ++i ) {
    //     for ( int j = 1; j <= m; ++j ) {
    //         printf("%3d ", dp[i][j]);
    //     }
    //     cout << endl;
    // }

}