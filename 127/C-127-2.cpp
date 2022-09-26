#include<vector>
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
  int n;
  int m;
  int cnt = 0;
  int l, r;

  cin >> n >> m;
  l = 1;
  r = n;

  for ( int i = 0; i < m; ++i ) {
    int tmpl, tmpr;
    scanf("%d%d", &tmpl, &tmpr);
    if ( tmpl > l ) l = tmpl;
    if ( tmpr < r ) r = tmpr;
  }

  cnt = r-l+1;
  if ( cnt < 0 ) cnt = 0;
  cout << cnt << endl;
}
