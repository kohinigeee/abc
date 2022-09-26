#include<iostream>
#include<set>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

using pii = pair<int,int>;

int main() {
  int n;
  vector<pii> p;
  set<pii> s;
  long long ans = 0;

  cin >> n;
  p = vector<pii>(n);
  for ( int i = 0; i < n; ++i ) {
    int x,y;
    cin >> x >> y;
    p[i] = make_pair(x,y);
    s.insert(make_pair(x,y));
  }

  sort(p.begin(), p.end());

  for ( int i = 0; i < n; ++i ) {
    for ( int j = i+1; j < n; ++j ) {
      if ( p[i].first >= p[j].first || p[i].second >= p[j].second ) continue;
      pii p1 = make_pair(p[i].first, p[j].second);
      pii p2 = make_pair(p[j].first, p[i].second);
      if ( s.find(p1) != s.end() && s.find(p2) != s.end() ) ++ans;
    }
  }

  cout << ans << endl;
}
