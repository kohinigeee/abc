#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<utility>
#include<string>
#include<algorithm>

#define INF 1LL<<60

using namespace std;
using pi = pair<int,int>;
using ll = long long;

set<pi> v1;
map<pi, vector<pi>> m; //s,tが key valueは　X,Y
int a = 0, b = 0;

int getq(pi p) {
  return p.first/a;
}

bool comp1(pi p1, pi p2 ) {
  int q1 = getq(p1);
  int q2 = getq(p2);

  return q1 < q2;
}

int main()
{
  string s;
  long long k,ans;
  ans = 0;

  cin >> s;
  cin >> k;

  for ( auto c : s ) {
    switch(c) {
    case 'L':
     --a;  break;
    case 'R':
     ++a; break;
    case 'U':
     --b; break;
    case 'D':
     ++b; break;
   }
     v1.insert(make_pair(a,b));
  }

  if ( a == 0 && b == 0 ) { cout << v1.size() << endl; return 0; }
  else if ( a == 0 ) {
    set<pi> tmp;
    int tmpi;
    for ( pi p : v1 ) tmp.insert( make_pair(p.second, p.first));
    v1 = tmp;
    tmpi = a; a = b; b = tmpi;
  }

  for ( pi p : v1 ) {
    int q = p.first/a;
    int s = p.first-q*a, t = p.second-q*b;

    if ( m.find(make_pair(s,t)) == m.end() ) {
      m[make_pair(s,t)] = vector<pi>(1,p);
    } else m[make_pair(s,t)].push_back(p);
  }

  for ( auto it = m.begin(); it != m.end(); ++it ) {
    vector<pi> tmp = (*it).second;
    sort(tmp.begin(), tmp.end(), comp1);

    for ( int i = 0; i < tmp.size(); ++i ) {
      if ( i+1 >= tmp.size() ) break;
      ans += min<ll>(k, getq(tmp[i+1])-getq(tmp[i]));
    }
    ans += k;
  }

  cout << ans+1 << endl;
}
