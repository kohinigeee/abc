#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

vvi graph;
int n, q;
vvi queries;
vi vk, vu;

int bfs( int s ) {
    vi d(n,-1);
    queue<int> que;
    d[s] = 0;
    que.push(s);
    int no = s;

    while(!que.empty()){
        int x = que.front(); que.pop();
        for ( int to : graph[x] ) {
            if ( d[to] == -1 ) {
                d[to] = d[x]+1;
                no = to;
                que.push(to);
            }
        }
    }

    return no;
}

void dfs(vector<map<int,int>>& ans, vector<int>& d, vector<int>& visited,  int x ) {
    visited[x] = 1;
    for ( auto k : queries[x] ) {
        if ( k > d.size() ) ans[x][k] = -2;
        else ans[x][k] = d[d.size()-k];
    }
    d.push_back(x);
    for ( auto to : graph[x] ) {
        if ( visited[to] ) continue;
        dfs(ans, d, visited, to);
    }
    d.pop_back();
}

vector<map<int,int>> ance_level( int s ) {
    vector<map<int,int>> ans(n, map<int,int>());
    vector<int> visited(n, 0);
    vector<int> d;
    dfs(ans, d, visited, s);
    return ans;
}

int main()
{
    cin >> n;
    graph = vvi(n,vi());
    queries = vvi(n, vi());

    for ( int i = 0; i < n-1; ++i ) {
        int a, b; cin >> a >> b; --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cin >> q;
    vk = vi(q); vu = vi(q);

    for ( int i = 0; i < q; ++i ) {
        int u, k; cin >> u >> k; --u;
        queries[u].push_back(k);
        vk[i] = k; vu[i] = u;
    }

    int s,t;

    s = bfs(0);
    t = bfs(s);

    // cout << "s=" << s+1 << ", t=" << t+1 <<endl;
    vector<map<int,int>> ans1 = ance_level(s);
    vector<map<int,int>> ans2 = ance_level(t);
    
    for ( int i = 0; i < q; ++i ) {
        int u = vu[i], k = vk[i];
        cout << max(ans1[u][k], ans2[u][k])+1 << endl;
    }
}