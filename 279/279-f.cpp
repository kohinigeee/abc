#include<iostream>
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

  int n, q;
  cin >> n >> q;

  vector<int> box(n+1, -1);
  vector<int> inbox(n+q+10, -1);

  UnionFind uf(n+q+10);

  for ( int i = 0; i <= n; ++i ) box[i] = i;
  for ( int i = 0; i <= n; ++i ) inbox[i] = i;

  int cnt = n;

  for ( int i = 0; i < q; ++i ) {
    int cmd; cin >> cmd;
    if ( cmd == 1 ) {
        int x, y; cin >> x >> y;
        if ( box[y] == -1 ) continue;
        if ( box[x] == -1 ) {
            int root = uf.root(box[y]);
            inbox[root] = x;
            box[x] = root;
            box[y] = -1;
            continue;
        }
        uf.unite(box[x], box[y]);
        int root = uf.root(box[x]);
        inbox[root] = x;
        box[y] = -1;
        box[x] = root;
    }
    if ( cmd == 2 ) {
        int x; cin >> x;
        ++cnt;
        if ( box[x] == -1 ) {
            box[x] = cnt;
            inbox[cnt] = x;
            continue;
        } else {
            uf.unite(box[x], cnt);
            int root = uf.root(cnt);
            box[x] = root;
            inbox[root] = x;
            continue;
        }
    }
    if ( cmd == 3 ) {
        int x; cin >> x;
        int root = uf.root(x);
        cout << inbox[root] << endl;
    }
  }  
}
