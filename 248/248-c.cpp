#include<iostream>

using namespace std;

using ll = long long;

int main()
{
  ll a, b, k;

  cin >> a >> b >> k;
  ll ans = 0;

  while( a < b ) {
    ++ans;
    a *= k;
  }

  cout << ans << endl;
}
