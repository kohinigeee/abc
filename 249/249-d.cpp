#include<iostream>
#include<vector>
#include<algorithm>


#define MAXV 2000105LL

using namespace std;
using ll = long long;

int main()
{
  vector<ll> v;
  vector<ll> a;
  ll n;
  long long anst = 0;

  cin >> n;
  v = vector<ll>(n);
  a = vector<ll>(MAXV+1, 0);

  for ( ll i = 0; i < n; ++i ) {
    cin >> v[i];
    a[v[i]] += 1;
  }

  sort(v.begin(), v.end(), greater<ll>());
  // for ( auto c : v ) cout << c << " "; cout << endl;

  for ( ll i = 0; i < n; ++i ) {
    ll ans = 0;
    if ( v[i] == 1 ) break;
    ll j = 1;
    for ( j = 1; j*j < v[i]; ++j ) {
      if ( v[i]%j == 0 ) ans += 2*a[v[i]/j]*a[j];
    }
    if ( j*j == v[i] ) {
      if ( a[j] > 1 ) {
        ll tmp = a[j]*(a[j]-1)/2;
        ans += 2*tmp+a[j];
      } else ans += a[j];
    }
    anst += ans;
  }

  if ( a[1] >= 1 ) anst += ((a[1]*(a[1]-1))+a[1])*a[1];
  cout << anst << endl;
}
