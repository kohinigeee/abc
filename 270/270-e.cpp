#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;
using ll = long long;
ll n, k;

int main()
{
  vector<ll> a;
  vector<ll> b;
  vector<ll> c;
  map<ll, ll> mp;

  cin >> n >> k;
  for ( int i = 0; i < n; ++i ) {
    ll tmpa; cin >> tmpa;
    a.push_back(tmpa);
  }

  b = a;
  c = a;

  sort(a.begin(), a.end());
  sort(c.begin(), c.end());

  ll circle = 0;
  ll plus_ones;
  ll result_no;

  for ( int i = 0; i < n; ++i ) {
    a[i] -= circle;
    ll remains = n-i;

    if ( k > a[i]*remains ) {
      circle += a[i];
      k -= a[i]*remains;
      a[i] = 0;
    } else if ( k <= a[i]*remains ) {
      result_no = i;
      ll circle_2 = k/remains;
      plus_ones = k%remains;
      circle += circle_2;

      a[i] -= circle_2;
      for ( int j = i+1; j < n; ++j ) a[j] -= circle;
      break;
    }
  }

  // for ( auto v : a ) cout << v << " "; cout << endl;
  for ( auto v : b ) {
    if ( mp.find(v) == mp.end() ) mp[v] = 0;
    auto it = lower_bound(c.begin(), c.end(), v);
    ll no = it-c.begin();
    no += mp[v];

    ll ans = a[no];
    if ( no >= result_no && plus_ones > 0 ) { --ans; --plus_ones; }
    cout << ans << " ";
    mp[v] += 1;
  }
  cout << endl;
}
