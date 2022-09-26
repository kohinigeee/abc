#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

#define rep(i,n) for ( int i = 0; i < n; ++i )
#define INF (1LL<<61)
using namespace std;

using Graph = vector<vector<pair<int,int>>>;

int main() {
  int n,m;
  bool updated = false;
  long long ans;
  cin >> n >> m;

  Graph g = Graph(n);
  vector<long long> dp(n,INF);
  vector<int> stats(n, 0);
  vector<bool> negative(n, false);

  rep(i,m) {
    int s,t,c;
    cin >> s >> t >> c;
    --s; --t;
    g[s].push_back(make_pair(t,-c));
  }

  dp[0] = 0;
  for ( int cnt = 0; cnt < n; ++cnt) {
    for ( int i = 0; i < n; ++i ) {
      if ( dp[i] == INF ) continue;
      for ( int j = 0; j < g[i].size(); ++j ) {
        int to = g[i][j].first, c = g[i][j].second;
        if ( dp[to] > dp[i]+c ) {
          dp[to] = dp[i]+c;
        }
      }
    }
  }
  ans = dp[n-1];
  for ( int cnt = 0; cnt <= n; ++cnt ) {
    for ( int i = 0; i < n; ++i ) {
      if ( dp[i] == INF ) continue;
      for ( int j = 0; j < g[i].size(); ++j ) {
        int to = g[i][j].first, c = g[i][j].second;
        if ( negative[i] ) negative[to] = true;
        if ( dp[to] > dp[i]+c ) {
          dp[to] = dp[i]+c;
          negative[to] = true;
        }
      }
    }
  }

  if ( negative[n-1] ) cout << "inf" << endl;
  else cout << -ans << endl;
}
