#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>

using namespace std;

bool judge(vector<pair<int,int>>& e, vector<int>& p, set<pair<int,int>>& s ) {
  for ( auto edge: e ) {
    if ( s.find(make_pair(p[edge.first-1], p[edge.second-1])) == s.end() ) return false;
  }
  return true;
}

int main()
{
  int n, m;
  set<pair<int,int>> s;
  vector<pair<int,int>> e;
  vector<int> p;
  bool ans = false;
  cin >> n >> m;

  for ( int i = 0; i < n; ++i ) p.push_back(i+1);
  for ( int i = 0; i < m; ++i ) {
    int a, b;
    cin >> a >> b;
    e.push_back(make_pair(a,b));
  }

  for ( int i = 0; i < m; ++i ) {
    int c,d;
    cin >> c >> d;
    s.insert(make_pair(c,d));
    s.insert(make_pair(d,c));
  }

  do {
    if ( judge(e, p, s) ) {
       ans = true;
       break;
     }
  } while( next_permutation(p.begin(), p.end()) );

  if ( ans ) cout << "Yes" << endl;
  else cout << "No" << endl;
}
