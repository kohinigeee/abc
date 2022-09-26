#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

using ll = unsigned long long;

bool judge( vector<ll>& v, ll x, ll k ) {
  ll sum = 0;
  for ( auto i : v ) {
    sum += min( x, i);
  }
  return sum >= x*k;
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<ll> v;

  for ( int i = 0; i < n; ++i ) {
    ll tmp; cin >> tmp;
    v.push_back(tmp);
  }

  ll l = 0, r = 1e18/k;

  while ( l+1 < r ) {
    ll mid = (l+r)/2;
    if ( judge(v, mid, k ) ) l = mid;
    else r = mid;
  }

  cout << l << endl;
}
