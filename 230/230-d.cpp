#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>

using namespace std;

using ll = long long;

bool func(pair<ll,ll>& p1, pair<ll,ll>& p2 ) {
  if ( p1.second == p2.second ) return p1.first < p2.first;
  return p1.second < p2.second;
}

int main()
{
  ll n, d;
  vector<pair<ll,ll>> v;
  cin >> n >> d;

  for ( ll i = 0; i < n; ++i ) {
    ll l, r;
    cin >> l >> r;
    v.push_back(make_pair(l,r));

  }

  sort(v.begin(), v.end(), func);
  ll cnt = 1;
  ll r = v[0].second;

  for ( ll i = 1; i < v.size(); ++i ) {
    if ( v[i].first > r+d-1 ) {
      ++cnt;
      r = v[i].second;
    }
  }

  cout << cnt << endl;
}
