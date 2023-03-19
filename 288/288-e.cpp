#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;
using ll = long long;

long long INF = (1LL<<60);

int main()
{
    vector<int> a, c;
    set<int> st;
    int m, n;
    int mmax = 0;

    cin >> n >> m;
    a = vector<int>(n);
    c = vector<int>(n);

    for ( int i = 0; i < n; ++i ) cin >> a[i];
    for ( int i = 0; i < n; ++i ) cin >> c[i];
    for ( int i = 0; i < m; ++i ) {
        int tmp; cin >> tmp;
        st.insert(tmp);
        mmax = max(tmp, mmax);
    }
    

    vector<vector<ll>> dp(n+1, vector<ll>(n+1, INF));
    for ( int i = 0; i <= n; ++i ) dp[i][0] = 0;
    dp[1][1] = a[0]+c[0];

    ll cnt = 0;
    if ( st.find(1) != st.end() ) ++cnt;
    for ( int i = 1; i < n; ++i ) {
        ll minc = c[i];

        for ( int j = 0; j <= i; ++j ) {
            minc = min(minc, ll(c[i-j]));

            if ( j+1 < cnt ) continue;

            if ( j+1 != cnt ) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+a[i]+minc);
            if ( st.find(i+1) != st.end() ) continue;
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
        }
        if ( st.find(i+1) != st.end() ) ++cnt;
    }

    ll ans = INF;
    for ( int i = st.size(); i <= n; ++i ) {
        ans = min(ans, dp[n][i]);
    }
    cout << ans << endl;

    // for ( auto d : dp ) {
    //     for ( auto v : d ) cout << ( (v == INF)? -1 :v ) << " ";
    //     cout << endl;
    // }
}