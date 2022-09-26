#include<iostream>
#include<vector>
#include<utility>
#include<queue>

#define INF (1<<30)

using namespace std;
using Graph = vector<vector<int>>;

int bfs( int s, vector<int>& d, vector<int>& p, Graph& g, int f = -1, int t = -1 ) {
  d = vector<int>(g.size(), -1);
  queue<int> q;
  q.push(s);
  d[s] = 0;

  while( !q.empty() ) {
    int now = q.front(); q.pop();

    for ( auto to : g[now] ) {
      if ( f == now && t == to ) continue;
      if ( d[to] == -1 ) {
        d[to] = d[now]+1;
        p[to] = now;
        q.push(to);
      }
    }
  }

  return d[g.size()-1];
}


int main()
{
  int n,m;
  Graph g;

  cin >> n >> m;
  g = Graph(n);
  vector<int> d(n), p(n, -1);
  vector<pair<int,int>> dedges;
  vector<pair<int,int>> edges;
  int mind;

  for ( int i = 0; i < m; ++i ) {
    int s,t;
    cin >> s >> t; --s; --t;
    g[s].push_back(t);
    edges.push_back(make_pair(s,t));
  }

  mind = bfs(0, d, p, g);

  for ( int i = n-1; p[i] != -1; i = p[i] ) dedges.push_back(make_pair(p[i],i));
  for ( auto e : edges ) {
    bool f = false;
    for ( auto de : dedges ) {
      if ( e == de ) { f = true; break; }
    }
      if ( f ) cout << bfs(0, d, p, g, e.first, e.second ) << endl;
      else cout << mind << endl;
    }


}
