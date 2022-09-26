#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

#define MAXC 100010

using namespace std;

struct Edge {
  int to, c, rev;
  Edge(int t, int c1, int r ):to(t), c(c1), rev(r) {}
};

using Graph = vector<vector<Edge>>;
using ll = long long;

int dfs( int no, int end, int minf, vector<int>& stats, Graph& g ) { //残余グラフの探索と更新
  if ( no == end ) return minf;

  for ( Edge& e : g[no] ) {
    if ( e.c > 0 && stats[e.to] < stats[no] ) {
      stats[e.to] = stats[no];
      int tmpe = dfs(e.to, end, min(minf,e.c), stats, g);
      if ( tmpe == 0 ) continue;
      Edge& re = g[e.to][e.rev];
      e.c -= tmpe;
      re.c += tmpe;
      return tmpe;
    }
  }

  return 0;
}

ll ford_fullcarson( int s, int t, Graph&g ) {
  vector<int> stats(g.size(), 0);
  ll sum = 0;

  while( 1 ) {
    stats[s] += 1;
    ll tmpe = dfs(s, t, MAXC, stats, g );
    if ( tmpe == 0 ) break;
    sum += tmpe;
  }

  return sum;
}

int main()
{
  Graph g;
  int n,g1,e;

  cin >> n >> g1 >> e;
  g = Graph(n+1);
  for ( int i = 0; i < g1; ++i ) {
    int p;
    cin >> p;
    g[p].push_back(Edge(n, 1, g[n].size()));
    g[n].push_back(Edge(p, 0, g[p].size()-1));
  }
  for ( int i = 0; i < e; ++i ) {
    int s,t;
    cin >> s >> t;
    g[s].push_back(Edge(t, 1, g[t].size()));
    g[t].push_back(Edge(s, 0, g[s].size()-1));
    g[s].push_back(Edge(t, 0, g[t].size()));
    g[t].push_back(Edge(s, 1, g[s].size()-1));

  }

  cout << ford_fullcarson( 0, n, g) << endl;
}
