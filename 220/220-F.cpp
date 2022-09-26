#include<iostream>
#include<vector>
#include<queue>

using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

int dfs(int no, vector<bool>& visited, vector<int>& size, graph& g ) {
  int tmp = 1;
  visited[no] = true;

  for( int to : g[no] ) {
    if ( !visited[to] ) {
      tmp += dfs(to, visited, size, g);
    }
  }
  size[no] = tmp;
  return tmp;
}

void dfscal(int no, int n, vector<ll>& ans, vector<int>& size, graph& g ) {
  for ( int to : g[no] ) {
    if ( ans[to] == -1 ) {
      ans[to] = ans[no]+n-2*size[to];
      dfscal(to, n, ans, size, g);
    }
  }
}

int main()
{
  int n, gcnt;
  graph g;
  queue<int> q;

  cin >> n;
  vector<ll> d = vector<ll>(n, -1);
  ll sumd = 0;
  vector<int> size(n);
  vector<ll> ans(n,-1);
  vector<bool> visited(n, false);

  g = graph(n, vector<int>());
  for ( int i = 0; i < n-1; ++i ) {
    int u,v;
    cin >> u >> v; --u; --v;
    g[u].push_back(v); g[v].push_back(u);
  }

  d[0] = 0;
  q.push(0);
  while( !q.empty() ) {
    int now = q.front(); q.pop();
    for ( int to : g[now] ) {
      if ( d[to] == -1 ) {
        d[to] = d[now]+1;
        sumd += d[to];
        q.push(to);
      }
    }
  }

  ans[0] = sumd;
  dfs(0, visited, size, g);
  dfscal(0, n, ans, size, g);

  for ( int i = 0; i < n; ++i ) cout << ans[i] << endl;
}
