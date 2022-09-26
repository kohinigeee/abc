#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int judge(vector<int>& v, int x, int s) {
  int cnt = 0;
  for ( int i = s; i < v.size(); ++i ) {
    if ( v[i] % x != 0 ) ++cnt;
  }
  return cnt;
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

  x = v[0];
  for ( int i = 1; i <= sqrt(x); ++i ) {
    if ( x % i == 0 ) {
      s.push_back(i);
      s.push_back(x/i);
    }
  }
  sort(s.begin(), s.end(), greater<int>());

  for ( int i = 0; i < s.size(); ++i ) {
    int cnt = judge(v, s[i], 1);
    if ( cnt <= 1 ) {
      if ( ans < s[i] ) ans = s[i];
      break;
    }
  }

  x = v[1];
  s.clear();
  for ( int i = 1; i <= sqrt(x); ++i ) {
    if ( x % i == 0 ) {
      s.push_back(i);
      s.push_back(x/i);
    }
  }
  sort(s.begin(), s.end(), greater<int>());

  for ( int i = 0; i < s.size(); ++i ) {
    int cnt = judge(v,s[i], 0);
    if ( cnt <= 1 ) {
      if ( ans < s[i] ) ans = s[i];
      break;
    }
  }

  cout << ans << endl;
}
