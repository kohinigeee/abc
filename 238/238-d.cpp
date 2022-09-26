#include<iostream>

using namespace std;

using ll = long long;

int main()
{
  ll t, a, s;

  cin >> t;
  while(t--) {
    bool f = true;
    cin >> a >> s;
    ll tmp = a<<1;
    tmp = s-tmp;
    if ( tmp < 0 ) f = false;
    else {
      if ( (a&tmp) == 0 ) f = true;
      else f = false;
    }
    if ( f ) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}
