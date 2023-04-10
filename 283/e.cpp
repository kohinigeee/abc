#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

#define INF 1500000
// 0: 表, 1: 裏

bool below_is_ok( vector<int>& upper, vector<int>& midle, vector<int>& below ) {
    for ( int i = 0; i < upper.size(); ++i ) {
        if ( midle[i] == upper[i] ) continue;
        if ( midle[i] == below[i] ) continue;
        if ( i-1 >= 0 && midle[i] == midle[i-1] ) continue;
        if ( i+1 < upper.size() && midle[i] == midle[i+1] ) continue;
        return false;
    }
    return true;
}

int main()
{
    int h, w;
    cin >> h >> w;

    vector<vector<vector<int>>> dp( h+1, vector<vector<int>>(2, vector<int>(2, INF)));
    vector<vector<int>> a(h, vector<int>(w));
    vector<vector<int>> b(h, vector<int>(w));

    for ( int i = 0; i < h; ++i ) {
        for ( int j = 0; j < w; ++j ) {
            int tmp; cin >> tmp;
            a[i][j] = tmp;
            b[i][j] = 1-tmp;
        }
    }

    a.push_back(vector<int>(w, -1));
    b.push_back(vector<int>(w, -1));

    dp[0][0][0] = dp[0][0][1] = 0;
    dp[0][1][0] = dp[0][1][1] = 1;

    for ( int i = 1; i <= h; ++i ) {
        for ( int j = 0; j < 2; ++j ) {
            for ( int k = 0; k < 2; ++k ) {
                vector<int>& midle = ( k == 0 ? a[i-1] : b[i-1] );
                vector<int>& below = ( j == 0 ? a[i] : b[i] );
                vector<int> dummy = vector<int>(w,-1);

                int add_v;
                if ( i == h ) add_v = 0;
                else add_v = j;

                vector<int> upper = ( (i-2 >= 0) ? a[i-2] : dummy);
                if( dp[i-1][k][0] != INF && below_is_ok(upper, midle, below) ) dp[i][j][k] = min(dp[i][j][k], dp[i-1][k][0]+add_v);

                upper = ( (i-2 >= 0) ? b[i-2] : vector<int>(w,-1));
                if( dp[i-1][k][1] != INF && below_is_ok(upper, midle, below) ) dp[i][j][k] = min(dp[i][j][k], dp[i-1][k][1]+add_v);
            }
        }
    }

    int ans = INF;
    for ( int j = 0; j < 2; ++j ) {
        for ( int k = 0; k < 2; ++k ) {
            ans = min(ans,dp[h][j][k]);
        }
    }

    if  ( ans == INF ) ans = -1;
    cout << ans << endl;

    // for ( int i = 0; i <= h; ++i ) {
    //     for ( int j = 0; j < 2; ++j ) {
    //         for ( int k = 0; k < 2; ++k ) {
    //             printf("dp[%d][%d][%d] = %d\n", i, j, k, dp[i][j][k]);
    //         }
    //     }
    //     cout << endl;
    // }

    // cout << endl;
    // for ( auto v : a ) {
    //     for ( auto v2 : v ) cout << v2 << " ";
    //     cout << endl;
    // }

    // cout << endl;
    // for ( auto v : b ) {
    //     for ( auto v2 : v ) cout << v2 << " ";
    //     cout << endl;
    // }
}