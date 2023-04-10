#include<iostream>
#include<vector>
#include<queue>

using namespace std;
using ll = long long;

ll bfs( int x, vector<vector<int>>& edges ) {
    vector<int> d(edges.size(), -1);
    queue<int> que;
    ll ans = 0;

    que.push(x);
    d[x] = 0;
    while(!que.empty()) {
        int top = que.front(); que.pop();
        if ( d[top] >= 2 ) ++ans;
        for ( auto to : edges[top] ) {
            if ( d[to] == -1 ) {
                d[to] = d[top]+1;
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

    for ( int i = 0; i < m; ++i ) {
        int u, v; cin >> u >> v;
        --u; --v;
        edges[u].push_back(v);
    }

    ll ans = 0;
    for ( int i = 0; i < n; ++i ) {
        ans += bfs(i, edges );
    }
    cout << ans << endl;
}