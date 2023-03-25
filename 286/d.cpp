#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<vector<int>> dp(n, vector<int>(x+1, 0));
    vector<int> a(n), b(n);

    for ( int i = 0; i < n; ++i ) {
        cin >> a[i] >> b[i];
    }

    for ( int j = 0; j <= b[0]; ++j ) {
        int tmp = a[0]*j;
        if ( tmp > x ) break;
        dp[0][tmp] = 1;
    }

    for ( int i = 1; i < n; ++i ) {
        for ( int k = 0; k <= x; ++k ) dp[i][k] = dp[i-1][k];
        for ( int j = 1; j <= b[i]; ++j ) {
            for ( int k = x; k >= 0; --k ) {
                if ( k-a[i] >= 0 && dp[i][k-a[i]]  == 1) dp[i][k] = 1;
            }
        }
    }

    if ( dp[n-1][x] ) cout << "Yes" << endl;
    else cout << "No" << endl;
}