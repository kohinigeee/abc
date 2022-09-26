#include<iostream>

#define rep(i,n) for ( int i = 0; i < n; ++i )

using namespace std;

bool prime[201];

int main()
{
  rep(i, 201) prime[i] = true;

  for ( int i = 2; i < 201; ++i ) {
    if ( prime[i] ) for ( int j = i*2; j < 201; j += i ) prime[j] = false;
  }

  bool win = false;
  int a,b,c,d;

  cin >> a >> b >> c >> d;

  for ( int i = a; i <= b; ++i ) {
    bool f = false;
    for ( int j = i+c; j <= i+d; ++j ) {
      if ( prime[j] ) f = true;
    }
    if ( !f ) {
      win = true;
      break;
    }
  }

  if ( win ) cout << "Takahashi" << endl;
  else cout << "Aoki" << endl;
}
