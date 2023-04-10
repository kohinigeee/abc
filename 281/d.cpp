#include<iostream>
#include<vector>
#include<set>

using namespace std;
using ll = long long;

int main()
{
    int n, k, d;
    cin >> n >> k >> d;
    vector<ll> a(n);

    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(k+1, vector<ll>(d, -1)));
    for ( int i = 0; i < n; ++i ) cin >> a[i];

    for ( int i = 0; i < n; ++i ) dp[i][0][0] = 0;
    dp[0][1][a[0]%d] = a[0];
    
    for ( int i = 1; i < n; ++i ) {
        for ( int j = 1; j <= k; ++j ) {
            ll m = a[i]%d;
            for ( int s = 0; s < d; ++s ) {
                ll tmp = (s-m);
                if ( tmp < 0 ) tmp += d;
                if ( dp[i-1][j-1][tmp] != -1 ) dp[i][j][s] = max(dp[i][j][s], dp[i-1][j-1][tmp]+a[i]);
                if ( dp[i-1][j][s] != -1 ) dp[i][j][s] = max(dp[i][j][s], dp[i-1][j][s]);
            }
        }
    }

    cout << dp[n-1][k][0] << endl;

}