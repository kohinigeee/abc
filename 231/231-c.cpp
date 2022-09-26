#include<iostream>
#include<vector>
#include<algorithm>

#define rep(i,n) for ( int i = 0; i < n; ++i )

using namespace std;

int main()
{
  vector<int> a;
  int n, q;

  cin >> n >> q;

  rep(i,n) {
    int tmp; cin >> tmp;
    a.push_back(tmp);
  }
  sort(a.begin(), a.end());

  rep(i,q) {
    int x;
    cin >> x;
    auto itr = lower_bound(a.begin(), a.end(), x);
    cout << a.end()-itr << endl;
  }
}
