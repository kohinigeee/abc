#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    vector<ll> a(n+1), s(n+1);
    for ( int i = 1; i <= n; ++i ) {
        cin >> a[i];
    }
    s[0] = 0;
    for ( int i = 1; i <= n; ++i ) s[i] = a[i]+s[i-1];

    vector<ll> score(n+1, 0);
    for ( int i= 1; i <= n; ++i ) {
        if ( i%2 == 0 ) score[i] = 2*s[i/2];
        else score[i] = 2*s[i/2]+a[i/2+1];
    }

    // vector<vector<ll>> dp(n+1, vector<ll>(n+1));

    // for ( int i = 1; i <= n; ++i ) {
    //     int l = i+1;
    //     for ( int j = 1; j <= n; ++j ) {
    //         dp[i][j] = dp[i-1][j];
    //         if ( j-l >= 0 ) dp[i][j] = max(dp[i][j], dp[i][j-l]+score[i]);
    //     }
    // }
    
    vector<ll> dp(n+1, 0);
    for ( int i = 1; i <= n; ++i ) {
        int l = i+1;
        for ( int j = 1; j <= n; ++j ) {
            if ( j-l >= 0 ) dp[j] = max(dp[j], dp[j-l]+score[i]);
        }
    }

    cout << dp[n] << endl;
}