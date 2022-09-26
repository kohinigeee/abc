#include <iostream>
#include <string>

using namespace std;

int main()
{
  string s;
  int ans = 0;
  int cnt = 0;

  cin >> s;

  for ( int i = 0; i < s.size(); ++i ) {
    if ( s[i] == 'A' || s[i] == 'T' || s[i] == 'G' || s[i] == 'C' ) {
      ++cnt;
    }
    else {
      if ( ans < cnt ) ans = cnt;
      cnt = 0;
    }
  }
  ans = ans < cnt ? cnt:ans;

  cout << ans << endl;
}
