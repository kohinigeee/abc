#include<iostream>
#include<vector>

#define rep(i,n) for ( int i = 0; i < n; ++i )
#define WHITE 0
#define BLACK 1
#define MMM 998244353

using namespace std;
using vi = vector<int>;

void dfs(int no, vi& c, vector<vi>& g, int& v, int& e) {
  c[no] = BLACK;
  v += 1;
  e += g[no].size();
  for ( auto to : g[no] ) {
    if ( c[to] == WHITE ) dfs(to, c, g, v, e );
  }
}

long long fac ( long long x, long long n) {
  long long ans = 1;
  long long base = x;

  while( n > 0 ) {
    if ( n & 1 ) ans = ans*base%MMM;
    base = base*base%MMM;
    n = n>>1;
  }

  return ans;
}


int main()
{
  int n,m;
  cin >> n >> m;
  vector<vi> g(n);
  vi c(n,WHITE);
  int cnt = 0;

  rep(i,m) {
    int u,v;
    cin >> u >> v; --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  rep(i,n) {
    int v = 0, e = 0;
    if ( c[i] == WHITE ) {
      dfs(i,c,g, v, e);
      if ( v != (e/2) ) {
        cout << 0 << endl;
        return 0;
      }
      ++cnt;
    }
  }

  cout << fac(2,cnt) << endl;
}
