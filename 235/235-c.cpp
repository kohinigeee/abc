#include<iostream>
#include<map>
#include<utility>
#include<set>

using namespace std;

int main()
{
  map<pair<int,int>, int> m1;
  map<int, int> cnt;
  int n,q;

  cin >> n >> q;

  for ( int i = 0; i < n; ++i ) {
    int a;
    cin >> a;
    if ( cnt.find(a) == cnt.end() ) cnt[a] = 1;
    else cnt[a] += 1;
    m1[make_pair(a,cnt[a])] = i+1;
  }

  for ( int i = 0; i < q; ++i ) {
    int x, k;
    cin >> x >> k;
    if ( m1.find(make_pair(x,k)) == m1.end() ) cout << -1 << endl;
    else cout << m1[make_pair(x,k)] << endl;
  }
}
