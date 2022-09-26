#include<iostream>
#include<set>
#include<string>
#include<vector>

using namespace std;

int main()
{
  int n, m;
  set<string> s;
  vector<string> v;

  cin >> n >> m;
  for ( int i = 0; i < n; ++i ) {
    string tmp;
    cin >> tmp;
    v.push_back(tmp);
  }

  for ( int i = 0; i < m; ++i ) {
    string tmp;
    cin >> tmp;
    s.insert(tmp);
  }

  for ( int i = 0; i < n; ++i ) {
    if ( s.find(v[i]) != s.end() ) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}
