#include<iostream>
#include<map>
#include<vector>

using ll = long long;
using namespace std;

vector<vector<map<ll, ll>>> dp;
vector<vector<ll>> a;
int n;


void dp_func_up( int i, int j, int border) { //マス i, j のときにxになる

    // cout << "i = " << i << ", j = " << j << endl;
    for ( auto it = dp[i][j].begin(); it != dp[i][j].end(); ++it ) {
        ll v = a[i][j]^(it->first); ll amount = it->second;

        if ( i-1 > border) {
            if ( dp[i-1][j].find(v) == dp[i-1][j].end() ) dp[i-1][j][v] = 0;
            dp[i-1][j][v] += amount;
        }

        if ( j-1 >= 0 ) {
            if ( dp[i][j-1].find(v) == dp[i][j-1].end() ) dp[i][j-1][v] = 0;
            dp[i][j-1][v] += amount;
        }
    }
}


void dp_func_down( int i, int j, int border) { //マス i, j のときにxになる

    // cout << "i = " << i << ", j = " << j << endl;
    for ( auto it = dp[i][j].begin(); it != dp[i][j].end(); ++it ) {
        ll v = a[i][j]^(it->first); ll amount = it->second;

        if ( i+1 <= border ) {
            if ( dp[i+1][j].find(v) == dp[i+1][j].end() ) dp[i+1][j][v] = 0;
            dp[i+1][j][v] += amount;
        }

        if ( j+1 < n ) {
            if ( dp[i][j+1].find(v) == dp[i][j+1].end() ) dp[i][j+1][v] = 0;
            dp[i][j+1][v] += amount;
        }
    }
}


int main()
{

    cin >> n;
    a = vector<vector<ll>>(n, vector<ll>(n));
    dp = vector<vector<map<ll, ll>>>(n, vector<map<ll,ll>>(n, map<ll,ll>()));

    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < n; ++j ) cin >> a[i][j];
    }

    // dp[0][0][0] = 1;
    dp[n-1][n-1][0] = 1;

    // int border_i = n/2-1;
    int border_i = -1;
    for ( int i = 0; i <= border_i; ++i ) {
        for ( int j = 0; j < n; ++j ) {
            dp_func_down(i, j, border_i);
        }
    }
    for ( int i = n-1; i > border_i; --i ) {
        for ( int j = n-1; j >= 0; --j ) {
            dp_func_up(i, j, border_i);
        }
    }

    cout << "border_i = " << border_i << endl;
    ll ans = 0;
    // for ( int j = 0; j < n; ++j ) {
    //     for ( auto it = dp[border_i][j].begin(); it != dp[border_i][j].end(); ++it ) {
    //         ll v = it->first; ll amount = it->second;
    //         v = a[border_i][j]^v^a[border_i+1][j];
    //         // cout << "amount = " << amount << endl;
    //         if ( dp[border_i+1][j].find(v) != dp[border_i+1][j].end() ) {
    //             ans += amount*dp[border_i][j][v];
    //         }
    //     }
    // }

    // cout << dp[n-1][n-1][a[n-1][n-1]] << endl;

    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < n; ++j ) {
            cout << dp[i][j][1] << " ";
        }
        cout << endl;
    }
}