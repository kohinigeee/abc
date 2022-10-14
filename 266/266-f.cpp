#include<iostream>
#include<vector>

using namespace std;

vector<int> dfs(int x, int no, vector<int>& path, vector<int>& visited, vector<vector<int>>& graph ) {
    visited[x] = no;
    path.push_back(x);
    vector<int> ans;

    for ( auto to : graph[x] ) {
        if ( visited[to] == -1 ) {
            ans = dfs(to, no+1, path, visited, graph);
            if ( ans.size() > 0 ) return ans;    
        }
        if ( visited[to] < no-1 ) {
            int sno = visited[to];
            for ( int i = sno; i < path.size(); ++i ) ans.push_back(path[i]);
        }
    }

    visited[x] = -1;
    path.pop_back();
    return ans;
}

vector<int> calcCircle(vector<vector<int>> graph) {
    vector<int> ans;
    vector<int> visited(graph.size(), -1);
    vector<int> path;

    ans = dfs(0, 0, path, visited, graph);
    return ans;
}

void dfs2(int x, int gno, vector<int>& group, vector<vector<int>> graph ) {
    group[x] = gno;

    for ( auto to : graph[x] ) {
        if ( group[to] == -1 ) {
            dfs2(to, gno, group, graph);
        }
    }
}

int main()
{
    vector<vector<int>> graph;
    int n;

    cin >> n;
    graph = vector<vector<int>>(n);
    for ( int i = 0; i < n; ++i ) {
        int u, v;
        cin >> u >> v; --u; --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> circle = calcCircle(graph);

    
    vector<int> group(n, -1);
    int cnt = 1;
    for ( auto v: circle ) group[v] = 0;
    for ( int i = 0; i < n; ++i )  {
        if ( group[i] == -1 ) {
            dfs2(i, cnt++, group, graph);
        }
    }

    for ( auto v: group ) cout << v << " "; cout << endl;

    int q; cin >> q;
    for ( int i = 0; i < q; ++i ) {
        int x, y; cin >> x >> y;
        --x; --y;
        if ( group[x] == 0 || group[y] == 0 || group[x] != group[y] ) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}