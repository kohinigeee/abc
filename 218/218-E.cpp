#ifndef ___UNION_SET
#define ___UNION_SET

#include<iostream>
#include<vector>
#include<algorithm>

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
#endif

using namespace std;

struct Edge {
  int a,b,c;
  Edge(int a1, int b1, int c1 ) : a(a1), b(b1), c(c1) {}

  bool operator<(Edge& e ) {
    return c < e.c;
  }
};

int main()
{
  vector<Edge> v;
  long long ans = 0;
  int n,m;

  cin >> n >> m;
  unionSet u(n);
  for ( int i = 0; i < m; ++i ) {
    int a,b,c;
    cin >> a >> b >> c; --a; --b;
    if ( c <= 0 ) u.unite(a,b);
    else v.push_back(Edge(a,b,c));
  }

  sort(v.begin(), v.end());
  for ( auto e : v ) {
    if ( u.same(e.a, e.b) ) ans += e.c;
    else u.unite(e.a, e.b);
  }

  cout << ans << endl;
}
