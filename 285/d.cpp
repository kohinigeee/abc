#include<iostream>
#include<vector>
#include<map>

using namespace std;

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

int main() {
    int n;
    vector<int> to;
    map<string, int> mp;

    cin >> n;
    int cnt = 0;
    to = vector<int>(2*n, -1);
    
    for ( int i = 0; i < n; ++i ) {
        string s, t;
        cin >> s >> t;

        if ( mp.find(s) == mp.end() ) mp[s] = cnt++;
        if ( mp.find(t) == mp.end() ) mp[t] = cnt++;  

        int sno = mp[s], tno = mp[t];
        to[sno] = tno;
    }

    UnionFind uf(2*n);
    bool ans = true;
    for ( int i = 0; i < to.size(); ++i ) {
        if ( to[i] == -1 ) continue;
        if ( uf.same(i, to[i]) ) {
            ans = false;
            break;
        }
        uf.unite(i, to[i]);
    }

    if ( ans ) cout << "Yes" << endl;
    else cout << "No" << endl;
}
