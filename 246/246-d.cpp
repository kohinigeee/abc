#include<iostream>
#include<algorithm>

using namespace std;

using ll = long long;

ll func( ll a, ll b ) {
  return a*a*a+a*a*b+a*b*b+b*b*b;
}

int main()
{
  ll b = 1000000;
  ll n;
  ll x = func(0, b);

  cin >> n;

  for ( ll i = 0; i <= 1000000; ++i ) {
    ll tmp = func(i,b);
    while( b > 0 ) {
      --b;
      tmp = func(i, b);
      if ( tmp < n ) { ++b; break; }
    }

    x = min( x, func(i, b) );
  }

  cout << x << endl;
}
