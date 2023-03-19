#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

using graph = vector<vector<int>>;
using ll = long long;


long long func(graph& g, vector<int>& visit, int st ) {
    queue<int> que;

    int vcnt = 0;
    int ecnt = 0;

    que.push(st);

    while(!que.empty()) {
        ++vcnt;
        int top = que.front(); que.pop();
        visit[top] = 1;

        for ( auto to : g[top] ) {
            ++ecnt;
            if ( visit[to] == 0 ) que.push(to);
            visit[to] = 1;
        }
    }

    ecnt /= 2;
    return  ecnt-(vcnt-1);
}

int main()
{
    int n, m;

    cin >> n >> m;
    graph g = graph(n, vector<int>());
    for ( int i = 0; i < m; ++i ) {
        int a, b; cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> visit(n, 0);
    ll ans = 0;
    for ( int i = 0; i < n; ++i ) {
        if ( visit[i] == 0 ) ans += func(g, visit, i); 
    }

    cout << ans << endl;
}