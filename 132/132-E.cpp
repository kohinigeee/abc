#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

using Graph = vector<vector<int>>;

Graph g,g3;
int n,m;
int s,t;

int main () {
  queue<pair<int,int>> q;
  cin >> n >> m;
  vector<vector<int>> d(n, vector<int>(3,-1));
  g = Graph(n);
  for ( int i = 0; i < m; ++i ) {
    int u,v;
    cin >> u >> v;
    --u; --v;
    g[u].push_back(v);
  }
  cin >> s >> t;
  --s; --t;

  d[s][0] = 0;
  q.push(make_pair(s,0));
  while(!q.empty()) {
    int no = q.front().first, div = q.front().second;
    q.pop();
    int nextdiv = (div+1)%3;

    for ( auto to: g[no] ) {
      if ( d[to][nextdiv] == -1 ) {
        d[to][nextdiv] = div+1;
        q.push(make_pair(to, div+1));
      }
    }
  }

  if ( d[t][0] == -1 ) cout << d[t][0] << endl;
  else cout << d[t][0]/3 << endl;
}
