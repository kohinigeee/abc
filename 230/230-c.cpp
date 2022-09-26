#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

using ll = long long;

ll mink, maxk;
ll mink2, maxk2;

bool func1(ll x ) {
  return (mink <= x && x <= maxk);
}

bool func2(ll x ) {
  return (mink2 <= x && x <= maxk2);
}

int main()
{
  ll n, a, b;
  ll p,q,r,s;

  cin >> n >> a >> b;
  cin >> p >> q >> r >> s;

  mink = max(1-a, 1-b);
  maxk = min(n-a, n-b);

  mink2 = max(1-a, b-n);
  maxk2 = min(n-a, b-1);

  for ( ll i = p; i <= q; ++i ) {
    for ( ll j = r; j <= s; ++j ) {
      char c = '.';
      ll tmpi = i-a;
      ll tmpj = j-b;

      if ( ( tmpi == tmpj ) && func1(tmpi) && func1(tmpj) ) c = '#';

      tmpi = i-a;
      tmpj = -j+b;

      if ( ( tmpi == tmpj ) && func2(tmpi) && func2(tmpj) ) c = '#';
      cout << c;
    }
    cout << endl;
  }
}
