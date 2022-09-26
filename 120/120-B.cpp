#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> stk;
int cnt1 = 0;
int cnt2 = 0;


int main()
{
  string str;
  cin >> str;

  for ( int i = 0; i < str.length(); ++i ) {
    if ( str[i] == '0' ) ++cnt1;
    else ++cnt2;
  }

  cout << ( cnt1 < cnt2 ? cnt1: cnt2 ) * 2 << endl;
}
