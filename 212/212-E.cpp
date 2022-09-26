#include<iostream>
#include<vector>

#define MAXV 998244353

typedef long long ll;

using namespace std;

int main() {
  vector<vector<int>> edges;
  vector<vector<ll>> dp;
  int n,m,k;

  cin >> n >> m >> k;
  edges = vector<vector<int>>(n, vector<int>());
  for ( int i = 0; i < m; ++i ) {
    int u,v;
    cin >> u >> v;
    u -= 1; v -= 1;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  dp = vector<vector<ll>>( k+1, vector<ll>(n, 0));
  dp[0][0] = 1;

  // for ( int i = 0; i < k+1; ++i ) {
  //   for ( int j = 0; j < n; ++j ) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  for ( int i = 1; i <= k; ++i ) {
    ll sum = 0;

    for ( int j = 0; j < n; ++j ) sum += dp[i-1][j];
    for ( int j = 0; j < n; ++j ) {
      ll tmp = dp[i-1][j];
      for ( int s = 0; s < edges[j].size(); ++s ) tmp += dp[i-1][edges[j][s]];
      dp[i][j] = (sum-tmp)%MAXV;
    }
  }
  //
  // for ( int i = 0; i < k+1; ++i ) {
  //   for ( int j = 0; j < n; ++j ) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  cout << dp[k][0] << endl;
}
