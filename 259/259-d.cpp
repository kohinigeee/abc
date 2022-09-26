#include<iostream>
#include<vector>
#include<utility>
#include<cstdio>

using namespace std;

using ll = long long;
using point = pair<ll, ll>;

class UnionFind {
  vector<int> p;
  vector<int> size;

  int root( int x ) {
    if ( x == p[x] ) return x;
    return p[x] = root(p[x]);
  }

public:

  UnionFind(int n ) {
    p = vector<int>(n);
    size = vector<int>(n, 1);
    for ( int i = 0; i < n; ++i ) p[i] = i;
  }

  bool same( int x, int y ) {
    return root(x) == root(y);
  }

  void unite( int x, int y ) {
    if ( same(x,y) ) return;
    x = root(x); y = root(y);
    size[x] += size[y];
    p[y] = x;
  }

  int get_size( int x ) {
    return size[root(x)];
  }
};

ll dis2( point p1, point p2 ) {
    ll x = p1.first-p2.first;
    ll y = p1.second-p2.second;
    return x*x+y*y;
}

int main() {
  int n;
  vector<point> cpv;
  vector<ll> rv;
  point s, t;

  cin >> n;
  cin >> s.first >> s.second;
  cin >> t.first >> t.second;

  cpv = vector<point>(n);
  rv = vector<ll>(n);
  for ( int i = 0; i < n; ++i ) {
    cin >> cpv[i].first >> cpv[i].second >> rv[i];
  }

  UnionFind uf(n);

  for ( int i = 0; i < n; ++i ) {
    for ( int j = i+1; j < n; ++j ) {
        ll r = rv[i]+rv[j];
        ll d = dis2( cpv[i], cpv[j] );

        ll tmpr = rv[i]-rv[j];
        tmpr = tmpr*tmpr;

        if ( d >= tmpr && r*r >= d ) uf.unite(i,j);
    }
  }

  vector<ll> scircle, tcircle;
  bool flag = false;

  for ( int i = 0; i < n; ++i ) {
    ll d = dis2(cpv[i], s);
    if ( d == rv[i]*rv[i] ) scircle.push_back(i);
    d = dis2(cpv[i], t);
    if ( d == rv[i]*rv[i] ) tcircle.push_back(i);
  }

  for ( int i = 0; i < scircle.size(); ++i ) {
    for ( int j = 0; j < tcircle.size(); ++j ) {
        if ( uf.same(scircle[i], tcircle[j] ) ) flag = true;
    }
  }

  if ( flag ) cout << "Yes" << endl;
  else cout << "No" << endl;

    // for ( int i = 0; i < n; ++i ) {
    //     for ( int j = i+1; j < n; ++j ) {
    //         printf("i = %d, j = %d, is_same = %d\n", i, j, uf.same(i,j));
    //     }
    // }
    // for ( auto v : scircle ) cout << v << " "; cout << endl;
    // for ( auto v : tcircle ) cout << v << " "; cout << endl;

}
