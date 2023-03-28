#include<iostream>
#include<set>
#include<vector>

using namespace std;

class UnionFind {
  vector<int> p;
  vector<int> size;

 public:
  int root( int x ) {
    if ( x == p[x] ) return x;
    return p[x] = root(p[x]);
  }

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

int main() {
    int n, m;
    cin >> n >> m;

    UnionFind uf (n);

    while(m--) {
        int u, v; cin >> u >> v;
        --u; --v;
        uf.unite(u,v);
    }

    set<int> s;
    for ( int i = 0; i < n; ++i ) {
       s.insert(uf.root(i));
    }


    cout << s.size() << endl;
}
