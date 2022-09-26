#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

bool judge(vector<int>& v, int x) {
  for ( int i = 2; i < v.size(); ++i ) {
    if ( v[i] % x != 0 ) return false;
  }
  return true;
}

int main()
{
  int n,x,ans = 1;
  vector<int> v;
  vector<int> s;

  cin >> n;
  for ( int i = 0; i < n; ++i ) {
    int tmp;
    scanf("%d", &tmp);
    v.push_back(tmp);
  }

  sort(v.begin(), v.end());

  x = v[1];
  for ( int i = 1; i <= sqrt(x); ++i ) {
    if ( x % i == 0 ) {
      s.push_back(i);
      s.push_back(x/i);
    }
  }
  sort(s.begin(), s.end(), greater<int>());

  for( int i = 0; i < s.size(); ++i ) {
    if (judge(v,s[i])) {
      if ( s[i] > ans ) ans = s[i];
      break;
    }
  }

  x = v[0];
  s.clear();
  for ( int i = 1; i <= sqrt(x); ++i ) {
    if ( x % i == 0 ) {
      s.push_back(i);
      s.push_back(x/i);
    }
  }
  sort(s.begin(), s.end(), greater<int>());

  for( int i = 0; i < s.size(); ++i ) {
    if (judge(v,s[i])) {
      if ( s[i] > ans ) ans = s[i];
      break;
    }
  }

  /*
  for ( int i = 0; i < s.size(); ++i ) {
    cout << s[i] << " ";
  }
  cout << endl;
  */
  cout << ans << endl;

}
