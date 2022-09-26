#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

#define MAXV 5000
#define MM 998244353

#define rep(i,n) for(int i = 0; i < n; ++i )

using namespace std;
using vvi = vector<vector<long long>>;
using ll = long long;

int n;
vvi dp1,dp2;
vector<pair<int,int>> p;


int main()
{
  cin >> n;
  ll ans = 0;
  p = vector<pair<int,int>>(n);
  for ( int i = 0; i < n; ++i ) cin >> p[i].first;
  for ( int i = 0; i < n; ++i ) cin >> p[i].second;
  sort(p.begin(), p.end());

  dp1 = vvi(n+1, vector<ll>(MAXV+1,0));
  dp2 = vvi(n+1, vector<ll>(MAXV+1,0));

  dp2[0][0] = 1;
  for ( int i = 1; i <= n; ++i ) for ( int j = 0; j < MAXV+1; ++j ) {
    ll newj = j-p[i-1].second;
    if ( newj >= 0 ) dp1[i][j] = (dp1[i-1][newj]+dp2[i-1][newj]) % MM ; //
    dp2[i][j] = (dp1[i-1][j]+dp2[i-1][j]) % MM;
  }

  for ( int i = 1; i <= n; ++i ) for ( int j = 1; j < MAXV+1; ++j ) {
    if ( j <= p[i-1].first ) { ans += dp1[i][j]; ans %= MM; }
  }

  cout << ans << endl;
}
