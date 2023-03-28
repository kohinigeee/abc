#include<iostream>
#include<vector>
#include<utility>
#include<queue>

using namespace std;
using ll = long long;

ll judge(int n, int m, vector<int>& colour, vector<vector<int>>& edges ) {
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    //dp[i][j] : 高橋がi,青木がj
    queue<pair<int,int>> que;
    
    dp[0][n-1] = 0;
    que.push(make_pair(0,n-1));

    while(!que.empty()) {
        int taka = que.front().first, aoki = que.front().second;
        que.pop();
        if ( taka == n-1 && aoki == 0 ) return dp[taka][aoki];

        for ( auto to_taka : edges[taka] ) {
            for ( auto to_aoki : edges[aoki] ) {
                if ( colour[to_aoki] == colour[to_taka] ) continue;
                if ( dp[to_taka][to_aoki] != 0 ) continue;
                que.push(make_pair(to_taka, to_aoki));
                dp[to_taka][to_aoki] = dp[taka][aoki]+1;
            }
        }
    }
    return -1;
}

int main()
{
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<int> colour(n);
        vector<vector<int>> edges(n, vector<int>());

        for ( int i = 0; i < n; ++i ) cin >> colour[i];
        for ( int i = 0; i < m; ++i ) {
            int v1, v2; cin >> v1 >> v2;
            --v1; --v2;
            edges[v1].push_back(v2);
            edges[v2].push_back(v1);
        }

        ll ans = judge(n, m, colour, edges);
        cout << ans << endl;
    }
}