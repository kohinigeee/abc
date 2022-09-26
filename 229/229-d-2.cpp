#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;

int main()
{
  string str;
  ll l,r;
  ll k;
  ll cnt = 0;
  ll ans = 0;

  cin >> str;
  cin >> k;

  for ( r = 0; r < str.size(); ++r ) {
    if ( str[r] == '.' ) ++cnt;
    if ( cnt == k+1 ) {
      r--;
      break;
    }
  }

  ans = min(r+1, (ll)str.size());
  l = -1;
  while( r < str.size() ) {
    ++r;
    if ( str[r] == '.' ) {
      while ( str[++l] == 'X' );
    }

    ll tmp = r-l;
    if ( tmp > ans ) ans = tmp;
  }

  cout << ans << endl;
}
