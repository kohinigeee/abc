#include<iostream>
#include<vector>

#define INF 100000

using namespace std;
using ll = long long;

int main()
{
    vector<int> a;
    vector<vector<vector<int>>> dp;
    int n, m;

    cin >> n >> m;
    a = vector<int>(n);
    for ( auto& v: a ) cin >> v;

    dp = vector<vector<vector<int>>>( n, vector<vector<int>>(m+1, vector<int>(2,INF)));
    if ( a[0] <= m ) dp[0][a[0]][1] = 0;
    dp[0][0][0] = 1;

    for ( int i = 1; i < n; ++i ) {
        for ( int j = 0; j <= m; ++j ) {
            int prev = j-a[i];

            if ( dp[i-1][j][0] != INF ) {
                dp[i][j][0] = dp[i-1][j][0];
            }
            if ( dp[i-1][j][1] != INF ) {
                dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][1]+1);
            }

            if ( prev >= 0 ) {
                if ( dp[i-1][prev][0] != INF ) {
                    dp[i][j][1] = min(dp[i][j][1], dp[i-1][prev][0]);
                }
                if ( dp[i-1][prev][1] != INF ) {
                    dp[i][j][1] = min(dp[i][j][1], dp[i-1][prev][1]);
                }
            }
        }
    }

    for ( int i = 1; i <= m; ++i ) {
        int ans = min(dp[n-1][i][0], dp[n-1][i][1]);
        if ( ans == INF ) ans = -1;
        cout << ans << endl;
    }
}