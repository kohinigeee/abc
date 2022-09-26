#include<iostream>
#include<vector>

#define MODK  998244353
#define N 100
using namespace std;

using ll = long long;
using vll = vector<ll>;

ll dp[N+1][N+1][N+1][N+1];
vll a;
int n;

int main()
{
    ll ans = 0;

    for ( int i = 0; i < N+1; ++i ) {
        for ( int j = 0; j < N+1; ++j ) {
            for ( int k = 0; k < N+1; ++k ) {
                for ( int t = 0; t < N+1; ++t ) dp[i][j][k][t] = 0;
            }
        }
    }

    cin >> n;
    a = vll(n, 0);
    for ( int i = 0; i < n; ++i ) cin >> a[i];
    
    for ( int i = 0; i <= n; ++i ) {
        for ( int m = 1; m <= n; ++m ) {
            dp[i][0][m][0] = 1;
        }
    }

    for ( int i = 1; i <= n; ++i ) {
        for ( int j = 1; j <= i; ++j ) {
            for ( int m = 2; m <= n; ++m ) {
                for ( int k = 0; k < m; ++k ) {
                    int tmpk = k-(a[i-1]%m);
                    if ( tmpk < 0 ) tmpk += m;
                    // cout << "m = " << m << ", k = " << k << ", tmpk = " << tmpk << endl;
                    dp[i][j][m][k] = dp[i-1][j][m][k]+dp[i-1][j-1][m][tmpk];
                    dp[i][j][m][k] %= MODK;
                }
            }
        }
    }

    ans = n;
    for ( int j = 2; j <= n; ++j ) {
        ans += dp[n][j][j][0];
        ans %= MODK;
    }
    cout << ans << endl;
    
}