#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll,ll>;

int main()
{
    ll n, m;
    vvl graph;
    vl a, sum;
    vector<bool> visited;

    cin >> n >> m;
    a = vl(n);
    sum = vl(n,0);
    graph = vvl(n, vl());
    visited = vector<bool>(n,false);

    for ( int i = 0; i < n; ++i ) cin >> a[i];
    for ( int i = 0; i < m; ++i ) {
        int u, v; cin >> u >> v; --u; --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        sum[u] += (a[v]);
        sum[v] += (a[u]);
    }

    ll ans = 0;

    priority_queue<pll, vector<pll>, greater<pll>> q;
    for ( int i = 0; i < n; ++i ) {
        q.push(make_pair(sum[i], i));
    }

    while(!q.empty()) {
        ll no = q.top().second, score = q.top().first;
        q.pop();
        if ( visited[no] || sum[no] < score ) continue;
        visited[no] = true;
        ans = max(ans, score);

        for ( int to : graph[no] ) {
            if ( visited[to] ) continue;
            sum[to] -= a[no];
            q.push(make_pair(sum[to], to));
        }
    }

    cout << ans << endl;
}