#include<iostream>
#include<stack>
#include<string>

using namespace std;

using ll = long long;

int main()
{
  stack<char> st;
  ll n, x;
  string s;

  cin >> n >> x;
  cin >> s;

  st.push('U');
  for ( int i = 0; i < n; ++i ) {
    if ( s[i] == 'U' && st.top() != 'U') st.pop();
    else st.push(s[i]);
  }

  stack<char> st2;
  while( !st.empty() ) { st2.push(st.top()); st.pop(); }
  st2.pop();

  while( !st2.empty() ) {
    char c = st2.top(); st2.pop();
    if ( c == 'U' ) x = x/2;
    if ( c == 'L' ) x = x*2;
    if ( c == 'R' ) x = x*2+1;
  }

  cout << x << endl;
}
