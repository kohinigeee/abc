#include<iostream>
#include<vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;

int main()
{
  int n;
  vvi mat;
  vector<ll> t;
  vector<bool> f;
  ll ans = 0;

  cin >> n;
  mat = vvi(n);
  t = vector<ll>(n);
  f = vector<bool>(n, false);

  for ( int i = 0; i < n; ++i ) {
    ll tmpt;
    int k;
    cin >> t[i] >> k;
    for ( int j = 0; j < k ; ++j ) {
      int tmpa;
      cin >> tmpa; --tmpa;
      mat[tmpa].push_back(i);
    }
  }

  f[n-1] = true;
  for( int i = n-2; i >= 0; --i ) {
    for ( int j = 0; j < mat[i].size(); ++j ) {
      if ( f [ mat[i][j] ] ) { f[i] = true; break; }
    }
  }

  for ( int i = 0; i < n; ++i ) if ( f[i] ) ans += t[i];

  cout << ans << endl;
}
