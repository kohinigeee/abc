#include<iostream>
#include<vector>

#define ORD 998244353

using ll = long long;

using namespace std;

ll dp[1000000][11];

int main()
{
  for ( int i = 1; i < 10; ++i ) dp[0][i] = 1;
  dp[0][10] = dp[0][0] = 0;

  ll n;
  cin >> n;

  for ( int i = 1; i < n; ++i ) {
    for ( int j = 1; j < 10; ++j ) {
      ll tmp = 0;
      tmp = dp[i-1][j+1];
      tmp = (tmp+dp[i-1][j])%ORD;
      tmp = (tmp+dp[i-1][j-1])%ORD;
      dp[i][j] = tmp;
    }
    dp[i][10] = dp[i][0] = 0;
  }

  ll ans = 0;
  for ( int j = 1; j < 10; ++j ) {
    ans = (ans+dp[n-1][j])%ORD;
  }

  cout <<ans << endl;
}
