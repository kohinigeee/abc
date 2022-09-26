#include<iostream>
#include<vector>

#define LIM 1000000007

using namespace std;

vector<vector<int>> vec;

int main()
{
  int s;
  unsigned long long int ans = 0;
  vec = vector<vector<int>>();

  cin >> s;
  for ( int i = 0; i < s+1; i++ ) {
    //cout << "i-" << i << endl;
    vec.push_back(vector<int>(s+1,0));
  }

  if ( s >= 3 ) ans += 1
  if ( s >= 6) {
    vec[2][s-3] = s-5;
    ans += s-5;
    vec[2][s-3]
  }
  for ( int i = 3; i < int(s/3); ++i ) {
    for ( int j = )
  }

  cout << ans << endl;
}
