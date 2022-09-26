#include<iostream>
#include<string>

using namespace std;

int func( char x, char y ) {
  return ( x > y ) ? ( y - x + 26 ) : ( y-x );
}

int main()
{
  string s,t;

  cin >> s >> t;
  int v = func(s[0], t[0]);

  for ( int i = 1; i < s.size(); ++i ) {
    if ( v != func(s[i], t[i]) ) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout  << "Yes" << endl;
}
