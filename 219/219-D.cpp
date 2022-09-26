#include<iostream>
#include<vector>
#include<algorithm>

#define MAXV 1000

using namespace std;

using vvi = vector<vector<int>>;
using vvvi = vector<vvi>;

int disi(int x, int y ) {
  return max(x-y, 0);
}

int main()
{
  int n,x,y;
  vector<int> a,b;

  cin >> n;
  cin >> x >> y;
  for ( int i = 0; i < n; ++i ) {
    int tmpa,tmpb;
    cin >> tmpa >> tmpb;
    a.push_back(tmpa);
    b.push_back(tmpb);
  }

  vvvi dp(n+1, vvi(x+1, vector<int>(y+1, MAXV)));

  dp[0][0][0] = 0;
  for ( int i = 1; i <= n; ++i ) {
    for ( int j = 0; j <= x; ++j ) {
      for ( int k = 0; k <= y; ++k ) {
        dp[i][j][k] = min(dp[i-1][j][k], dp[i-1][disi(j,a[i-1])][disi(k,b[i-1])]+1);
      }
    }
  }

  if ( dp[n][x][y] >= MAXV ) cout << -1;
  else cout << dp[n][x][y] << endl;
}
