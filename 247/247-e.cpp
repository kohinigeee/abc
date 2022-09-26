#include<iostream>
#include<vector>

using namespace std;

int main()
{
  vector<int> v;
  int n, x, y;

  cin >> n >> x >> y;
  for ( int i = 0; i < n; ++i ) {
    int a; cin >> a;
    v.push_back(a);
  }

  int l,r, sum;
  l = r = 0;
  sum = 0;
  fx = false;
  fy = false;

  while(1) {
    ++r;
    if ( v[r] == x ) fx = true;
    if ( v[r] == y ) fy = true;
    if ( v[r] > x || v[r] < y) {
      l = r+1;
      fx = fy = false;
    }
    if ( fx && fy ) sum += 1;

  }
}
