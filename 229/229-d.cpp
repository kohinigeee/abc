#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;

int main()
{
  vector<ll> v;
  string str;
  ll l,r;
  ll k;
  ll cnt = 0;
  ll ans = 0;

  cin >> str;
  cin >> k;

  v = vector<ll>(str.size()+1, 0);
  for ( int i = 1; i <= str.size(); ++i ) {
    v[i] = v[i-1];
    if ( str[i-1] == '.' ) v[i] += 1;
  }

  // for ( auto e : v ) cout << e << " "; cout << endl;
  l = 0, r = 1;

  while ( r <= str.size() ) {
    int tmp = v[r]-v[l];
    if ( tmp > k ) {
      while ( v[r]-v[++l] > k );
    } else {
      if ( ans < r-l ) ans = r-l;
      ++r;
    }
  }

  cout << ans << endl;
}
