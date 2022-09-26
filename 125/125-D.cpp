#include<iostream>
#include<cmath>
#include<vector>
#include<cstdio>

#define MAX 1000000001

typedef long long ll;

using namespace std;

int main()
{
  int cnt = 0;
  int cnt0 = 0;
  int n;
  ll sum = 0;
  vector<int> v;

  cin >> n;
  for ( int i = 0; i < n; ++i ) {
    int tmp;
    scanf("%d", &tmp);
    v.push_back(tmp);
    if ( tmp == 0 ) ++cnt0;
    if ( tmp < 0 ) ++cnt;
    sum += abs(v[i]);
  }

  /*
  if ( cnt0 > 0 ) {
    for ( int i = 0; i < v.size(); ++i ) sum += abs(v[i]);
  } else {
    if ( cnt % 2 == 0 ) for ( int i = 0; i < v.size(); ++i ) sum += abs(v[i]);
    else if ( cnt < v.size() ) {
      if ( cnt % 2 == 0 )
      for ( int i = 0; i < v.size(); ++i ) {
        sum += abs(v[i]);

    }
  }
  */

  if ( cnt0 == 0 && cnt > 0) {
    if ( cnt % 2 == 1 ) {
      if ( cnt < v.size() ) {
        ll m = MAX;
        for ( int i = 0; i < v.size(); ++i ) {
          if ( abs(m) > abs(v[i]) ) m = v[i];
        }
        sum -= abs(m)*2;
      } else {
        ll m = -MAX;
        for ( int i = 0; i < v.size(); i += 2 ) {
          if ( v[i] < 0 && m < v[i] ) m = v[i];
        }
        sum += m*2;
      }
    }
  }

  cout << sum << endl;
}
