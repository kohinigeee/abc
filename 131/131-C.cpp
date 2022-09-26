#include<iostream>
#include<cmath>
#include<algorithm>

typedef long long int ll;
using namespace std;

ll gcd ( ll x, ll y ) {
  if ( x < y ) swap(x,y);
  ll r = x%y;

  while( r > 0 ) {
    x = y;
    y = r;
    r = x%y;
  }

  return y;
}

ll lcm( ll x, ll y ) {
  return x*(y/gcd(x,y));
}

ll func( ll A,ll C,ll D ) {
  ll tmp1 = A/C;
  ll tmp2 = A/D;
  ll tmp3 = A/lcm(C,D);

  return A-(tmp1+tmp2-tmp3);
}

int main()
{
  ll A,B,C,D;

  cin >> A >> B >> C >> D;

  cout << func(B,C,D) - func(A-1,C,D) << endl;

}
