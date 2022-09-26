#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vvi graph;
int n, x, y;

bool dfs(int t, int no, vector<int>& visited, vector<int>& path) {
    visited[no] = 1;
    path.push_back(no);

    if ( no == t) return true;
    for ( auto to : graph[no] ) {
        if ( visited[to] == 1 ) continue;

        bool ans = dfs(t, to, visited, path);
        if ( ans ) return true;
    }
    path.pop_back();
    return false;
}

int main()
{
    cin >> n >> x >> y;
    --x; --y;
    graph = vvi(n, vi());

    for ( int i = 0; i < n-1; ++i ) {
        int u, v;
        cin >> u >> v; --u; --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> visited(n, 0);
    vector<int> paths;

    dfs(y, x, visited, paths);

    for ( auto v : paths ) {
        cout << v+1 << " ";
    }
    cout << endl;

}