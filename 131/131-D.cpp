#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

vector<pair<int,int>> v;

int main() {
  int n;
  int t = 0;
  bool ok = true;

  cin >> n;
  for ( int i = 0; i < n; ++i ) {
    int a,b;
    cin >> a >> b;
    v.push_back(make_pair(b,a));
  }
  sort(v.begin(), v.end());

  for ( int i = 0; i < n; ++i ) {
    t += v[i].second;
    if ( t > v[i].first ) {
      ok = false;
      break;
    }
  }

  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
