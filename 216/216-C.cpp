#include<iostream>
#include<vector>

using namespace std;

int main()
{
  long long n;
  vector<char> ans;

  cin >> n;
  while( n > 0 ) {
    if ( n & 1 ) ans.push_back('A');
    ans.push_back('B');
    n = n>>1;
  }

  for ( int i = ans.size()-1; i >= 0; --i ) cout << ans[i]; cout << endl;
}
