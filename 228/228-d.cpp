#include<iostream>
#include<vector>

#define MAXN 1048576

using namespace std;

using ll = long long;

vector<ll> p(MAXN);
vector<ll> v(MAXN);

ll get( int h ) {
  if ( p[h] == h ) return p[h];
  else {
    return p[h] = (get((h+1)%MAXN)+1)%MAXN;
  }
}

ll inser( ll h, ll x ) {
  if ( p[h] == h ) {
    p[h] = p[(h+1)%MAXN];
    v[h] = x;
    return p[h];
  } else {
    return p[h] = inser( p[h], x);
  }
}

int main()
{
  int q;

  for ( ll i = 0; i < MAXN; ++i ){  p[i] = i; v[i] = -1; }

  cin >> q;
  for ( int i = 0; i < q; ++i ) {
    ll t,x;
    cin >> t >> x;
    if ( t == 1 ) {
      inser( x%MAXN, x);
    } else {
      cout << v[x%MAXN] << endl;
    }
  }
}
