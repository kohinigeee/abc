#include<iostream>
#include<vector>
#include<queue>
#include<map>

#define INF (1<<28)

using namespace std;
using ll = long long;

vector<int> bfs(int st, int n, vector<vector<int>>& edges ) {
    vector<int> d(n,-1);
    queue<int> que;

    que.push(st);
    d[st] = 0;
    while(!que.empty()) {
        int top = que.front(); que.pop();
        for ( auto to : edges[top] ) {
            if ( d[to] != -1 ) continue;
            d[to] = d[top]+1;
            que.push(to);
        }
    }
    return d;
}

int calc(int k, int n, int m, vector<vector<int>>& edges, vector<int>& d_from0, vector<int>& d_fromn ) {
    int ans = INF;
    for ( int i = max(0, k-m); i < k; ++i ) {
        map<int, int> mp;
        queue<int> que;

        que.push(i);
        mp[i] = 0;
        
        while(!que.empty()) {
            int top = que.front(); que.pop();
            if ( top > k ) {
                if ( d_from0[i] == -1 || d_fromn[top] == -1 ) continue;
                ans = min(ans, d_from0[i]+mp[top]+d_fromn[top]);
                continue;
            }
            for ( auto to : edges[top] ) {
                if ( to == k ) continue;
                if ( mp.find(to) != mp.end() ) continue;
                mp[to] = mp[top]+1;
                que.push(to);
            }
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(n, vector<int>());
    vector<vector<int>> edges_rev(n, vector<int>());

    for  ( int i = 0; i < n; ++i ) {
        string s; cin >> s;
        for ( int j = 0; j < s.size() ; ++j ) {
            if ( s[j] == '1' && i+j+1 < n ) {
                edges[i].push_back(i+j+1);
                edges_rev[i+j+1].push_back(i);
            }
        }
    }

    vector<int> d_from0 = bfs(0, n, edges);
    vector<int> d_fromn = bfs(n-1, n, edges_rev);

    for ( int k = 1; k < n-1; ++k ) {
        int ans = calc(k, n, m, edges, d_from0, d_fromn);
        if ( ans == INF ) ans = -1;
        cout << ans << " ";
    }
    cout << endl;

    // for ( auto v : d_from0 ) cout << v << " "; cout << endl;
    // for ( auto v : d_fromn ) cout << v << " "; cout << endl;
}