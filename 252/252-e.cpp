#include<iostream>
#include<vector>
#include<queue>
#include<utility>

#define WHITE 0
#define BLACK 1
#define INF -1

class Data {
public:
  int to, c, no;

  Data(int to1, int c1, int no1 ) : to(to1), c(c1), no(no1) {}
};

using namespace std;

using vp = vector<pair<int,int>>;
using Graph = vector<vector<Data>>;
using ll = long long;

vector<ll> dijkstra( int s, Graph& g ) {
  vector<ll> d( g.size(), INF);
  vector<ll> road( g.size(), INF);
  priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;

  q.push(make_pair(0, s));
  d[s] = 0;

  while( !q.empty() ) {
    ll v = q.top().second, dv = q.top().first; q.pop();
    if ( d[v] != dv ) continue;

    for ( Data p : g[v] ) {
      if ( d[p.to] == INF ||  d[v] + p.c < d[p.to] ) {
        d[p.to] = d[v]+p.c;
        road[p.to] = p.no;
        q.push(make_pair(d[p.to], p.to));
      }
    }
  }
  return road;
}

int main()
{
  Graph g;
  int n, m;
  vector<int> tmp();

  cin >> n >> m;
  g = Graph( n, vector<Data>());
  for( int i = 0; i < m; ++i ) {
    int a, b, c;
    cin >> a >> b >> c; --a; --b;
    g[a].push_back(Data(b, c, i+1));
    g[b].push_back(Data(a, c, i+1));
  }

  vector<ll> road = dijkstra(0, g);
  for ( int i = 1; i < road.size()-1; ++i ) cout << road[i] << " ";
  cout << road.back() << endl;
}
