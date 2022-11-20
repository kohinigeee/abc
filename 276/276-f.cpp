#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

#define MOD 998244353 
#define MAXV 200000

using namespace std;
using ll = long long;

ll kousoku2(ll x, ll y, ll p ) {
    ll ans = 1;
    ll base = x;
    while( y > 0 ) {
        if ( y&1 ) {
            ans *= base;
            ans %= p;
        }
        base *= base;
        base %= p;
        y = y >> 1;
    }
    return ans;
}

ll rev_mod(ll x, ll p ) {
    return kousoku2(x, p-2, p);
}


template<class T>
class SegTree {
  T (*ope) ( T, T );
  T zele;
  int ln;
  vector<T> tree;

  void build() {
    for ( int i = ln-2; i >= 0; --i ) {
      tree[i] = (*ope)(tree[i*2+1], tree[i*2+2]);
    }
  }

public:

  SegTree( T (*ope1) (T,T), T zele1, const vector<T>& v) : ope(ope1), zele(zele1) {

    this->ln = 1;
    while( ln < v.size() ) this->ln = ln<<1;
    tree = vector<T>(ln*2-1, zele);
    for ( int i = 0; i < v.size(); ++i ) tree[i+ln-1] = v[i];
    if ( ln > 1 ) build();
  }

  SegTree ( T (*ope1) (T,T), T zele1, int n ) : SegTree( ope1, zele1, vector<T>(n, zele1)){
  }

  void update(int i, T v ) { // 0-origin
    i = i+ln-1;
    tree[i] = v;
    while( i > 0 ) {
      i = (i-1)/2;
      tree[i] = (*ope)(tree[i*2+1], tree[i*2+2]);
    }
  }

  void add( int i, T v ) { //+演算子必須
    update( i, (tree[i+ln-1]+v)%MOD );
  }

  T find(int l, int r, int i, int nl, int nr ) { //半開区間[l-r)の探索 0-origin
    if ( nl >= l && nr <= r ) return tree[i];
    if ( nl >= r || nr <= l ) return zele;

    int mid =  (nl+nr)/2;
    return (*ope)( find(l,r,i*2+1,nl,mid), find(l,r,i*2+2,mid,nr));
  }

  T find(int l, int r) { return find(l,r,0,0,ln); }

  void print() {
    cout << "ln = " << ln << endl;
    cout << "Print: ";
    for ( auto v : tree ) cout << v << " ";
    cout << endl;
  }
};

long long gcd ( long long a, long long b ) {
    long long r;

    while ( r = a%b ) {
        a = b;
        b = r;
    }
    return b;
}

using ll = long long;

int main()
{
    int n;

    cin >> n;
    vector<ll> a(n);
    for ( auto& v: a ) cin >> v;

    SegTree<ll> seg_value([](ll x, ll y ) { return (x+y)%MOD; }, 0, MAXV+10);
    SegTree<ll> seg_cnt([](ll x, ll y ) { return x+y; }, 0, MAXV+10);

    ll SUMA = 0;
    ll preX = 0;
    for ( int k = 1; k <= n; ++k ) {
        ll v = a[k-1];
        ll revk = rev_mod(k, MOD);
        revk = revk*revk%MOD;
       
        ll cntv = seg_cnt.find(0, v);
        ll P = (cntv*v%MOD+seg_value.find(v, MAXV+10))%MOD;
        P *= 2; 
        P %= MOD;
        
        ll X = (preX+P+v)%MOD;

        cout << (revk*X%MOD) << endl;
        preX = X;
        seg_value.add(int(v), v);
        seg_cnt.add(int(v), 1LL);
    }

    
    
    
}

