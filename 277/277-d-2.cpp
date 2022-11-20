#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

class UnionFind {
  vector<int> p;
  vector<int> size;

  public:

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

using ll = long long;

int main()
{
    int n, m;
    vector<ll> a;
    set<ll> st;
    map<ll, int> mp;
    map<ll, int> maisuu;
    vector<int> no;
    ll sumv = 0;

    cin >> n >> m;
    a = vector<ll>(n);
    for ( auto& v : a ) {
        cin >> v;
        sumv += v;
        st.insert(v);
        if ( maisuu.find(v) == maisuu.end() ) maisuu[v] = 0;
        maisuu[v] += 1;
    }

    for ( auto it = st.begin(); it != st.end(); ++it ) {
        mp[*it] = no.size();
        no.push_back(*it);
    }

    UnionFind uf(no.size());

    for ( int i = 0; i < no.size(); ++i ) {
        ll v = no[i];
        ll r = (v+1)%m;

        if ( mp.find(r) == mp.end() ) continue;
        uf.unite(i, mp[r]);
    }

    ll ans = 0;
    vector<ll> sums(n,0);
    for ( int i = 0; i < no.size(); ++i ) {
        ll v = no[i];
        ll p = uf.root(i);
        sums[p] += v*maisuu[v];
        ans = max(ans, sums[p]);
    }

    cout << sumv-ans << endl;
}