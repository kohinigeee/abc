#include<iostream>
#include<vector>

#define LIM 10000000

typedef unsigned long long ll;

using namespace std;

vector<ll> v = vector<ll>(LIM+1,1);

int main() {
  ll n;
  cin >> n;

  for ( ll i = 2; i <= n; i++ ) {
    ll tmp = i;
    while(tmp <= n ) {
      v[tmp] += 1;
      tmp += i;
    }
  }

  ll ans = 0;
  for ( ll i = 1; i <= n; ++i ) {
    ans += i*v[i];
  }

  cout << ans << endl;
}
