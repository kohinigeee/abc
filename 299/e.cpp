#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
using graph = vector<vector<int>>;
using pi = pair<int,int>;

vector<int> bfs( graph& g, int st, int n ) {
    vector<int> d(n,-1);
    queue<int> que;

    que.push(st);
    d[st] = 0;
    while(!que.empty()) {
        int top = que.front(); que.pop();
        for ( auto to : g[top] ) {
            if ( d[to] == -1 ) {
                d[to] = d[top]+1;
                que.push(to);
            }
        } 
    }
    return d;
}

int main()
{
    int n, m, k;
    
    cin >> n >> m;
    graph g(n);
    vector<pi> p;
    vector<int> isok(n, 1);

    for ( int i = 0; i < m; ++i ) {
        int u, v; cin >> u >> v; --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cin >> k;
    p = vector<pi>(k);
    for ( int i = 0; i < k; ++i ) {
        int tmpp, d; cin >> tmpp >> d;
        --tmpp;
        p[i] = make_pair(tmpp, d);
    }

    vector<vector<int>> d;
    for ( int i = 0; i < n; ++i ) {
        d.push_back(bfs(g, i, n));
    }

    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < k; ++j ) {
            int node = p[j].first, reqd = p[j].second;
            if ( d[i][node] < reqd ) isok[i] = 0;
        }
    }

    vector<int> ans(n,0);

    for ( int i = 0; i < k; ++i ) {
        int node = p[i].first, reqd = p[i].second;
        bool existed = false;
        for ( int j = 0; j < n; ++j ) {
            if ( d[node][j] == reqd && isok[j] ) {
                ans[j] = 1;
                existed = true;
                break;
            }
        }
        if ( existed == false ) {
            cout << "No" << endl;
            return 0;
        }
    }

    int cnt = 0;
    for ( auto v : ans ) cnt += v;
    if ( cnt == 0 ) ans[0] = 1;

    cout << "Yes" << endl;
    for ( auto v : ans ) cout << v ; cout << endl;
}