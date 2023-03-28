#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

int main()
{
    int n, m;
    int x;
    vector<int> dp;
    vector<ll> a,b;


    cin >> n;
    a = vector<ll>(n);
    for ( int i = 0; i < n; ++i ) cin >> a[i];

    cin >> m;
    b = vector<ll>(m);
    for ( int i = 0; i < m; ++i ) cin >> b[i];

    cin >> x;
    dp = vector<int>(x+1,0);

    dp[0] = 2;
    for ( auto v : b ) dp[v] = 1;

    for ( int i = 1; i <= x; ++i ) {
        if ( dp[i] != 0 ) continue;
        dp[i] = 1;
        for ( auto jump_range : a ) {
            int tmpx = i-jump_range;
            if ( tmpx >= 0 && dp[tmpx] == 2 ) dp[i] = 2;
        }
    }

    if ( dp[x] == 2 ) cout << "Yes" << endl;
    else cout << "No" << endl;
}