#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;


class UnionFind {
  vector<int> p;

  int root( int x ) {
    if ( x == p[x] ) return x;
    return p[x] = root(p[x]);
  }

public:

  UnionFind(int n ) {
    p = vector<int>(n);
    for ( int i = 0; i < n; ++i ) p[i] = i;
  }

  bool same( int x, int y ) {
    return root(x) == root(y);
  }

  void unite( int x, int y ) {
    if ( same(x,y) ) return;
    p[root(y)] = root(x);
  }
};


ll func( int no, vi& d, vi& x, vi& c ) {

    ll minc = 1000000001;
    while(1) {
        d[no] = 1;
        minc = min(minc, ll(c[no]));
        int to = x[no];
        if ( d[to] == 1 ) break;
        else no = to;
    }
    return minc;
}

int main()
{
    int n;
    vector<int> x;
    vector<int> c;
    vector<int> in;
    ll ans = 0;

    cin >> n;
    x = vi(n); c = vi(n);
    in = vi(n, 0);
    vi ord = vi(n, 0);

    for ( int i = 0; i < n; ++i ) { cin >> x[i]; --x[i]; in[x[i]] += 1; }
    for ( int i = 0; i < n; ++i ) { cin >> c[i];  ord[i] = i; }

    sort(ord.begin(), ord.end(), [in](int x, int y ){ return in[x] < in[y]; });

    // vi d(n, 0);
    // UnionFind uf(n);

    // for ( int i = 0; i < n; ++i ) {
    //     if ( uf.same(i, x[i]) ) ans += func(i, d, x, c);
    //     else uf.unite(i, x[i]);
    // }


    // for ( auto v : ord ) cout << v+1 << " "; cout << endl;
    vi d(n, 0 );

    // なんでTLE????
    for ( int i = 0; i < n; ++i ) {
        int no = ord[i];
        if ( d[no] > 0 ) continue;
        while(1) {
            d[no] = 1;
            int to = x[no];
            if ( d[to] != 0 ) { no = to; break; }
            else no = to;
        }

        if ( d[no] == 2 ) {
            no = ord[i];
            while(1) {
                d[no] = 2;
                int to = x[no];
                if ( d[to] == 2 ) break;
                else no = to;
            }
            continue;
        }

        ll minc = 1000000001;
        while(1) {
            d[no] = 2;
            minc = min(minc, ll(c[no]));
            int to = x[no];
            if ( d[to] == 2 ) break;
            else {
                no = to;
            }
        }
        ans += minc;

        no = ord[i];
        if ( d[no] != 2 ) {
            while(1) {
                d[no] = 2;
                int to = x[no];
                if ( d[to] == 2 ) break;
                else no = to;
            }
        }
    }

    cout << ans << endl;

}