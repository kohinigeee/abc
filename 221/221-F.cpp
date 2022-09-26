#include<iostream>
#include<vector>

#define rep(i,n) for ( long long i = 0; i < n; ++i )
#define M 998244353

using namespace std;

using graph = vector<vector<long long>>;
using vi = vector<long long>;
using ll = long long;

graph g;
long long n;
vi p, d;

void dfs(long long no, graph& g ) {
  for ( long long to : g[no] ) {
    if ( d[to] == -1 ) {
      d[to] = d[no]+1;
      p[to] = no;
      dfs(to,g);
    }
  }
}

long long dfs2(long long no, long long D, graph& g ) {
  long long sum = 0;
  if ( d[no] == D ) ++sum;
  for ( long long to: g[no] ) {
    if ( d[to] == -1 ) {
      d[to] = d[no]+1;
      sum += dfs2(to, D ,g);
    }
  }
  return sum;
}

int main()
{
  long long x,y;
  long long D = 0;

  x = 0, y = 0;
  cin >> n;
  g = graph(n);
  rep(i,n-1) {
    long long u, v;
    cin >> u >> v;
    --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  p = vi(n,-1); d = vi(n,-1);
  d[0] = 0;
  dfs(0,g);

  rep(i,n) if ( d[x] < d[i] ) x = i;

  p = vi(n,-1),d = vi(n,-1);
  d[x] = 0;
  dfs(x,g);

  y = x;
  rep(i,n) if ( D < d[i] ) { D = d[i]; y = i; }

  if ( D%2 == 1 ) {
    long long a,b;
    ll cnt = 0;
    ll cnts = 0;

    long long now = y;

    // cout << "x = " << x << ", y = " << y << endl;
    // cout<< "D= " << D << endl;
    for ( long long i = 0; i <= D; ++i ) {
      if ( i == (D-1)/2 ) a = now;
      if ( i == (D+1)/2 ) {
        b = now;
        break;
      }
      now = p[now];
    }

    // cout << "a = " << a << ", b = " << b << endl;

    for ( long long i = 0; i < g[a].size(); ++i )  if ( g[a][i] == b ) { g[a][i] = g[a][g[a].size()-1]; g[a].pop_back(); }
    for ( long long i = 0; i < g[b].size(); ++i )  if ( g[b][i] == a ) { g[b][i] = g[b][g[b].size()-1]; g[b].pop_back(); }

    p = vi(n,-1); d = vi(n,-1);
    d[a] = 0;
    dfs(a,g);
    rep(i,n) if ( d[i] == (D-1)/2 ) ++cnt;

    d[b] = 0;
    dfs(b,g);
    rep(i,n) if ( d[i] == (D-1)/2 ) ++cnts;

    cout << cnt*(cnts-cnt)%M << endl;
  } else {

    long long c;
    long long now = y;
    long long ans = 1;
    ll mcnt = 0;

    for ( long long i = 0; i <= D; ++i ) {
      if ( i == D/2 ) { c = now; break; }
      now = p[now];
    }

    // cout << "D = " << D << endl;
    // cout << "c = " << c << endl;
    graph g2(n);
    for ( long long i = 0; i < n; ++i ) {
      if ( i == c ) continue;
      for ( auto to : g[i] ) {
        if ( to == c ) continue;
        g2[i].push_back(to);
      }
    }

    d = vi(n, -1);
    for ( auto to: g[c] ) {
      d[to] = 0;
      long long tmp = dfs2(to, D/2-1, g2);
      // cout << "to = " << to << ", temp = " << tmp << endl;
      ans = ans*(tmp+1)%M;
      mcnt = (mcnt+tmp)%M;
    }
    ans -= mcnt+1;
    if ( ans < 0 ) ans += M;

    cout << ans << endl;
  }
}
