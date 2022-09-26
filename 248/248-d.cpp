#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vvi table;

int main()
{
  int n,q;
  cin >> n;

  table = vvi(n+1, vi());
  for ( int i = 0; i < n; ++i ) {
    int a; cin >> a;
    table[a].push_back(i+1);
  }

  cin >> q;
  while(q--) {
    int l,r,x;
    cin >> l >> r >> x;
    auto itl = lower_bound(table[x].begin(), table[x].end(), l);
    auto itr = upper_bound(table[x].begin(), table[x].end(), r);
    cout << int(itr-itl) << endl;
  }
}
