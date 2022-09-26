#include <iostream>

using namespace std;

int main()
{
  int a,b;
  int ans;

  cin >> a >> b;

  if ( a > b ) swap(a,b);
  if ( b == a ) ans = b*2;
  else ans = b*2-1;

  cout << ans << endl;
}
