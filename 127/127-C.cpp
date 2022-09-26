#include<vector>
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
  int n;
  int m;
  int cnt = 0;

  cin >> n >> m;
  vector<int> v (n);

  for ( int i = 0; i < m; ++i ) {
    int l, r;
    scanf("%d%d", &l, &r);
    v[l-1] += 1;
    if ( r < n ) v[r] -= 1;
  }

  for ( int i = 1; i < v.size(); ++i ) {
    v[i] = v[i-1]+v[i];
    if(v[i] == m ) ++cnt;
  }
  if(v[0] == m ) ++cnt;
  
  cout << cnt << endl;
}
