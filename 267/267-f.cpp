#include<iostream>
#include<vector>
#include<algorithm>

#define INF (1LL<<60)

using namespace std;

template<class T>
class SegTree {
  T (*ope) ( T, T ); //比較関数
  T zele; //ゼロ元
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
    update( i, tree[i+ln-1]+v);
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

using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

vector<ll> sumv;

int main()
{
  int n, m;
  vvi g;
  vector<ll> a;

  cin >> n >> m;
  g = vvi(n, vi());
  a = vector<ll>(n,0);
  sumv = vector<ll>(n, 0);
  vector<ll> tmpv = vector<ll>(n,0);
  ll ans = 0;

  for ( int i = 0; i < n; ++i ) cin >> a[i], tmpv[i] = i;
  for ( int i = 0; i < m; ++i  ){
    int u, v; cin >> u >> v; --u; --v;
    g[u].push_back(v); g[v].push_back(u);
    sumv[u] += a[v]; sumv[v] += a[u];
  }

  // for ( auto v : sumv ) cout << v << " "; cout << endl;
  // for ( int i = 0; i < m; ++i ) {
  //   if ( sumv[i] == 0 ) sumv[i] = INF;
  // }

  // cout << "test1" << endl;
  SegTree<ll> st = SegTree<ll>([](ll x1, ll x2) { 
    if ( x1 == INF ) return x2;
    if ( x2 == INF ) return x1;
    return sumv[x1] <= sumv[x2] ? x1 : x2 ; }, INF, tmpv);
  // cout << "test2" << endl;


  while(1) {
    ll minno = st.find(0,n);
    // for ( auto v : sumv ) cout << v << " ";
    // cout << endl;

    // cout << "minno = " << minno << endl;
    if ( sumv[minno] == INF ) break;
    ans = max(ans, sumv[minno]);
    sumv[minno] = INF;
    st.update(minno, minno);
    for ( auto to : g[minno] ) {
        if ( sumv[to] == INF ) continue;
        sumv[to] -= a[minno];
        st.update(to, to);
    }
  }

  cout << ans << endl;
}
