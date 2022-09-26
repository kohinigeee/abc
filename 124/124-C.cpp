#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  string str;
  int cnt01, cnt10;
  cnt01 = cnt10 = 0;

  cin >> str;

  for ( int i = 0; i < str.size(); ++i ) {
    if ( i%2 == 0 ) {
      if ( str[i] == '0' ) ++cnt10;
      else ++cnt01;
    } else {
      if ( str[i] == '0' ) ++cnt01;
      else ++cnt10;
    }
  }

  cout << ( cnt10 < cnt01 ? cnt10 : cnt01 ) << endl;
}
