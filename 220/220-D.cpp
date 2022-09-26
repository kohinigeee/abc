#include<iostream>

#define MM 998244353
#define MAXN 100000

using namespace std;
using ll = long long;

ll dp[10][MAXN+1];
int n;
int a[MAXN];

int main()
{
  cin >> n;
  for ( int i = 0; i < n; ++i ) cin >> a[i];
  for ( int i = 0; i < 10; ++i ) {
    for ( int j = 0; j < n; ++j ) dp[i][j] = 0;
  }

  dp[(a[0]*a[1])%10][0] += 1;
  dp[(a[0]+a[1])%10][0] += 1;

  for ( int j = 1; j < n-1; ++j ) {
    for ( int i = 0; i < 10; ++i ) {
      dp[(i+a[j+1])%10][j] = ( dp[(i+a[j+1])%10][j] + (dp[i][j-1]) ) %MM;
      dp[(i*a[j+1])%10][j] = ( dp[(i*a[j+1])%10][j] + (dp[i][j-1]) ) %MM;
    }
  }

  for ( int i = 0; i < 10; ++i ) {
    cout << dp[i][n-2] << endl;
  }
}
