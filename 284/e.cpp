#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

const ll LIMIT = 1000000;

void dfs(ll* cnt, int node, vector<vector<int>>& edges, vector<int>& visited ) {
    visited[node] = 1;
    for ( auto to : edges[node] ) {
        if ( (*cnt) > LIMIT ) return;
        if ( visited[to] == 1 ) continue;
        (*cnt) += 1;
        if ( (*cnt) > LIMIT ) return;
        dfs(cnt, to, edges, visited);
    }
    visited[node] = 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n, vector<int>());
    vector<int> visited(n, 0);
    ll cnt = 0;

    while(m--) {
        int u, v; cin >> u >> v;
        --u; --v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    dfs(&cnt, 0, edges, visited);

    cout << min(cnt+1, LIMIT) << endl;
}