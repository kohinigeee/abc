#include<iostream>
#include<set>
#include<vector>

#define rop(i,n) for ( int i = 0; i < n; ++i )

using namespace std;

using Graph = vector<vector<int>>;
using vi = vector<int>;
using ll = long long;
using vl = vector<ll>;

Graph g;
int n;
vector<ll> a;
vector<ll> medi;
multiset<ll> r;
multiset<ll,greater<ll>> l;
vl dp;

ll getmedi() {
  if ( l.size() > r.size() ) return *(l.begin());
  else {
  ll tmpl,tmpr;
    tmpl = *(l.begin());
    tmpr = *(r.begin());
    return (tmpl+tmpr)/2;
  }
}

void add( ll no ) {
  // cout << "add no = " << no << endl;
  if ( r.size() == 0 ) l.insert(no);
  else {
    ll tmpr = *(r.begin());
    if ( no > tmpr ) r.insert(no);
    else l.insert(no);
  }

  // cout << l.size() << ", " << r.size() << endl;
  if ( l.size() >= r.size()+2 ) {
    r.insert(*(l.begin()));
    l.erase(l.begin());
  } else if ( r.size() > l.size() ) {
    l.insert(*(r.begin()));
    r.erase(r.begin());
  }

  // cout << "add comp no = " << no << endl;
  // cout << "(" << l.size() << ", " << r.size() << ")" << endl;
}

void erase(ll no ) {
  // cout << "erase no = " << no << endl;
  if ( no > *l.begin() ) r.erase(no);
  else l.erase(no);

  // cout << l.size() << ", " << r.size() << endl;
  if ( l.size() >= r.size()+2 ) {
    r.insert(*(l.begin()));
    l.erase(l.begin());
    // cout << "test2" << endl;
  } else if ( r.size() > l.size() ) {
    l.insert(*(r.begin()));
    r.erase(r.begin());
    // cout << "test" << endl;
  }

  // cout << "erase comp no = " << no << endl;
  // cout << "(" << l.size() << ", " << r.size() << ")" << endl;
}

void dfs( int no ) {
  // cout << endl;
  // cout << "no = " << no << endl;
  bool f = false;
  add(a[no]);
  medi[no] = getmedi();
  for ( int to : g[no] ) {
    if ( medi[to] == -1 ) { dfs(to); f = true; }
  }
  if ( !f ) dp[no] = medi[no];
  erase(a[no]);
  // cout << endl;
}

ll DP( int no, int p, int cnt ) {
  if ( dp[no] >= 0 ) return dp[no];

  if ( cnt%2 == 0 ) {
    ll maxv = 0;
    for ( auto to : g[no] ) {
      if ( to == p ) continue;
      if ( DP(to, no, cnt+1) > maxv ) maxv = dp[to];
    }
    return dp[no] = maxv;
  } else {
    ll minv = 1<<60;
    for ( auto to : g[no] ) {
      if ( to == p ) continue;
      if ( DP(to, no, cnt+1) < minv ) minv = dp[to];
    }
    return  dp[no] = minv;
  }

}

int main() {
  cin >> n;
  a = vl(n);
  medi = vl(n, -1);
  dp = vl(n,-1);
  g = Graph(n);

  for(int i = 0; i < n; ++i ) cin >> a[i];
  rop(i,n-1) {
    int s,t;
    cin >> s >> t; --s; --t;
    g[s].push_back(t);
    g[t].push_back(s);
  }

  dfs(0);
  cout << DP(0,-1,0);
}
