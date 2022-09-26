#include<iostream>
#include<vector>
#include<utility>

class unionSet {
private:
  std::vector<int> siz, p;

public:
  unionSet(int x) {
    siz = std::vector<int>(x,1);
    p = std::vector<int>(x);
    for ( int i = 0; i < x; ++i ) p[i] = i;
  }

  int root(int x ) {
    if ( p[x] == x ) return x;
    else return p[x] = root(p[x]);
  }

  bool unite(int x, int y) {
    int xp,yp;
    xp = root(x);
    yp = root(y);
    if ( xp == yp ) return false;

    if ( siz[xp] < siz[yp] ) { int tmp = xp; xp = yp; yp = tmp; }
    siz[xp] += siz[yp];
    p[yp] = xp;
    return true;
  }

  bool same(int x, int y) {
    return root(x) == root(y);
  }

  int size(int x) {
    if ( x < 0 || x > p.size() ) return -1;
    return siz[root(x)];
  }
};

using namespace std;

using Edge = pair<int,int>;

int main() {
  int n, k, l;

  cin >> n >> k >> l;
  unionSet u_trains = unionSet(n);
  unionSet u_roads = unionSet(n);
  unionSet u_both = unionSet(n);
  vector<Edge> ts(l), rs(k);

  for ( int i = 0; i < k; ++i ) {
    int a,b;
    cin >> a >> b;
    --a; --b;
    u_roads.unite(a,b);
    rs[i] = make_pair(a,b);
  }

  for ( int i = 0; i < l; ++i ) {
    int a,b;
    cin >> a >> b;
    --a; --b;
    u_trains.unite(a,b);
    ts[i] = make_pair(a,b);
  }

  for ( int i = 0; i < ts.size(); ++i ) {
    int a = ts[i].first, b = ts[i].second;
    if ( u_roads.same(a,b) ) u_both.unite(a,b);
  }

  for ( int i = 0; i < rs.size(); ++i ) {
    int a = rs[i].first, b = rs[i].second;
    if ( u_trains.same(a,b) ) u_both.unite(a,b);
  }

  for ( int i = 0; i < n-1; ++i ) cout << u_both.size(i) << " ";
  cout << u_both.size(n-1) << endl;
}
