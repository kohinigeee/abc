#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

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

void gs(UnionFind& uf, int x ) {
  cout << "size[" << x << "] = " << uf.get_size(x) << endl;
}

struct Edge{
    public:
    int u, v;
    ll c;
};


ll clascal(int n, vector<Edge>& edges) {
    UnionFind uf(n);
    sort(edges.begin(), edges.end(), [](Edge e1, Edge e2){
        return e1.c > e2.c;
    });

    ll ans = 0;
    for ( int i = 0; i < edges.size(); ++i ) {
        if ( uf.same(edges[i].u, edges[i].v) ) continue;
        ans += edges[i].c;
        uf.unite(edges[i].u, edges[i].v);
    }
    return ans;
}

ll M;

ll power(ll x, ll y) {
    ll ans = 1;
    ll ord = x;
    while( y > 0 ) {
        if ( y & 1 ) {
            ans *= ord;
            ans %= M;
        }
        ord *= ord;
        ord %= M;
        y = y>>1;
    }
    return ans;
}

int main() {

    int n;
    cin >> n >> M;

    vector<int> a(n);
    for ( int i = 0; i < n; ++i ) cin >> a[i];

    vector<Edge> edges;
    for ( int i = 0; i < n; ++i ) {
        for ( int j = i+1; j < n; ++j ) {
            ll x = power(a[i], a[j]);
            ll y = power(a[j], a[i]);
            ll tmp = (x+y)%M;
            Edge e = { i, j, tmp };
            edges.push_back(e);
        }
    }

    ll ans = clascal(n, edges);
    cout << ans << endl;
}
