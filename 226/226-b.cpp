#include<iostream>
#include<set>
#include<vector>

using namespace std;

int main()
{
  set<vector<int>> s;
  int n;
  int cnt = 0;

  cin >> n;
  for ( int i = 0; i < n; ++i ) {
    int l;
    cin >> l;
    vector<int> v(l);
    for ( int j = 0; j < l; ++j ) cin >> v[j];

    if ( s.find(v) == s.end() ) {
      s.insert(v);
      cnt += 1;
    }
  }

  cout << cnt << endl;
}
