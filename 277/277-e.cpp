#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;
using pii = pair<int,int>;

int main()
{
    int n, m, k;

    cin >> n >> m >> k;

    vector<pii> edges(m);
    vector<vector<int>> graph(n*2);
    vector<int> switchs(n);

    while(m--) {
        int u, v, a;
        cin >> u >> v >> a; --u; --v;
        if ( a == 0 ) { u+=n; v+=n;}
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool have0 = false;
    while(k--) {
        int s; cin >> s;
        --s;
        if ( s == 0 ) have0 = true;
        for ( auto to : graph[s+n] ) {
            graph[s].push_back(to);
        }
        for ( auto to : graph[s] ) {
            graph[s+n].push_back(to);
        }
    }

    queue<int> que;
    vector<int> d(n*2, -1);
    d[0] = 0;
    que.push(0);
    if ( have0 ) {
        d[0+n] = 0;
        que.push(0+n);
    }

    while( !que.empty() ) {
        int top = que.front(); que.pop();
        for ( auto to : graph[top] ) {
            if ( d[to] == -1 ) {
                d[to] = d[top]+1;
                que.push(to);
            }
        }
    }

    int ans = (1<<30);
    if ( d[n-1] != -1 ) ans = min(ans, d[n-1]);
    if ( d[2*n-1] != -1 ) ans = min(ans, d[2*n-1]);
    if ( ans == (1<<30) ) ans = -1;

    cout << ans << endl;
}