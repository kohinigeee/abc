#include<iostream>
#include<vector>
#include<map>

using namespace std;

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


int main()
{
  int n,m;
  map<int,int> mp;
  bool ans = true;

  cin >> n >> m;
  unionSet us(n);

  for ( int i = 0; i < n; ++i ) mp[n] = 0;
  for ( int i = 0; i < m; ++i ) {
    int a,b;
    cin >> a >> b;
    --a; --b;
    mp[a] += 1; mp[b] += 1;
    if ( mp[a] >= 3 || mp[b] >= 3 ) ans = false;
    if ( us.same(a,b) ) ans = false;
    us.unite(a,b);
  }

  if ( ans ) cout << "Yes" << endl;
  else cout << "No" << endl;
}
