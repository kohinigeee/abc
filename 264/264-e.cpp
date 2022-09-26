#include<iostream>
#include<vector>
#include<utility>

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

int func ( UnionFind& uf, vector<int> &ans, vector<int>& power, int u, int v, int sum ) {
    int ru = uf.root(u), rv = uf.root(v);
        if ( power[ru] && power[rv] ) {
            ans.push_back(sum);
            return sum;
        } else if ( power[ru] == 0 && power[rv] == 0 ) {
            uf.unite(u,v);
            ans.push_back(sum);
            return sum;
        }

        int black;
        if ( power[ru] ) black = rv;
        else black = ru;
        sum += uf.get_size(black);
        ans.push_back(sum);
        power[black] = 1;
        return sum;
}

int main()
{
    int n, m, e, q;
    vector<int> power;
    vector<pair<int,int>> cables;
    vector<int> qs, has_event;

    cin >> n >> m >> e;
    power = vector<int>(n+m, 0);
    for ( int i = 0; i < m; ++i ) power[i+n] = 1;
    for ( int i = 0; i < e; ++i ) {
        int u, v; cin >> u >> v;
        --u; --v; cables.push_back(make_pair(u,v));
    }

    cin >> q;
    qs = vector<int>(q);
    has_event = vector<int>(e, 0);

    for ( int i = 0; i < q; ++i ) {
        cin >> qs[i]; --qs[i];
        has_event[qs[i]] = 1;
    }

    UnionFind uf(n+m);
    vector<int> ans;


    int sum = 0;
    for ( int i = 0; i < has_event.size(); ++i ) {
        if ( has_event[i] ) continue;
        // cout << "i = " << i << endl;
        int u = cables[i].first, v = cables[i].second;
        sum = func(uf, ans, power, u, v, sum);
    }

    // cout << "test" << endl;
    ans = vector<int>();
    ans.push_back(sum);
    for ( int i = qs.size()-1; i >= 0; --i ) {

        int u = cables[qs[i]].first, v = cables[qs[i]].second;
        sum = func(uf, ans, power, u, v, sum);
    }

    for ( int i = ans.size()-2; i >= 0; --i ) cout << ans[i] << endl;
}