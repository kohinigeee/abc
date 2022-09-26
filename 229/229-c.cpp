#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

using ll = long long;

bool func( pair<ll, ll> p1, pair<ll, ll> p2 ) {
  return p1.first > p2.first;
}

int main()
{
  vector<pair<ll,ll>> v;

  ll n,w;
  ll cap = w;
  unsigned long long sumv = 0;

  cin >> n >> w;
  cap = w;
  for ( int i = 0; i < n; ++i ) {
    ll a,b;
    cin >> a >> b;
    v.push_back(make_pair(a,b));
  }

  sort(v.begin(), v.end(), func);
  for ( auto p : v ) {
    if ( cap >= p.second ) {
      cap -= p.second;
      sumv += p.first*p.second;
    } else {
      sumv += p.first*cap;
      break;
    }
  }

  cout << sumv << endl;
}
