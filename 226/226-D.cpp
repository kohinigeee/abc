#include<iostream>
#include<utility>
#include<set>
#include<vector>
#include<cmath>

using namespace std;
using pii = pair<int,int>;

int gcd(int x, int y ) {
  int r;
  while( (r = x%y) != 0 ) {
    x = y;
    y = r;
  }
  return y;
}

int main()
{
  set<pii> s;
  int n;
  vector<pii> v;

  cin >> n;
  for ( int i = 0; i < n; ++i ) {
    int x,y;
    cin >> x >> y;
    v.push_back(make_pair(x,y));
  }

  for ( int i = 0; i < n; ++i ) {
    for ( int j = 0; j < n; ++j ) {
      if ( i == j ) continue;
      int dx = v[i].first-v[j].first;
      int dy = v[i].second-v[j].second;
      pii tmp;

      if ( dx ==0 ) {
        if ( dy > 0 ) tmp = make_pair(0,1);
        else tmp = make_pair(0,-1);
      } else if ( dy == 0) {
        if ( dx > 0 ) tmp = make_pair(1,0);
        else tmp = make_pair(-1,0);
      } else {
        int gcdv = gcd(abs(dx), abs(dy));
        dx /= gcdv; dy /= gcdv;
        tmp = make_pair(dx,dy);
      }
      if ( s.find(tmp) == s.end() ) {
        s.insert(tmp);
      }
    }
  }

  cout << s.size() << endl;
}
