#include<iostream>
#include<set>
#include<vector>

using namespace std;

using ll = long long;

multiset<ll> sp, sm;

int main()
{
  ll q; cin >> q;

  while(q--) {
    ll cmd, x, k;

    cin >> cmd >> x;
    if ( cmd == 1 ) {
      sp.insert(x); sm.insert(-x);
    } else if ( cmd == 3 ) {
      cin >> k;
      vector<ll> v;
      ll ans;

      while(k--) {
        auto it = sp.lower_bound(x);
        if ( it == sp.end() ) {
          ans = -1;
          break;
        }
        ans = *it;
        v.push_back(*it);
        sp.erase(it);
      }

      cout << ans << endl;
      for ( ll var : v ) sp.insert(var);
    } else {
      cin >> k;
      vector<ll> v;
      ll ans;
      bool f = true;
      while(k--) {
        auto it = sm.lower_bound(-x);
        if ( it == sm.end() ) {
          ans = 1;
          break;
        }
        ans = *it;
        v.push_back(*it);
        sm.erase(it);
      }

      cout << -ans << endl;
      for ( ll var : v ) sm.insert(var);
    }
  }
}
