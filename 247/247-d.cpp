#include<iostream>
#include<deque>
#include<utility>

using namespace std;

using ll = long long;

using pll = pair<ll,ll>;

int main()
{
  ll n;
  deque<pair<ll, ll>> st;

  cin >> n;
  while(n--) {
    ll cmd, x,c;

    cin >> cmd;
    if ( cmd == 1 ) {
      cin >> x >> c;
      st.push_back(make_pair(x,c));
    } else {
      cin >> c;
      ll sum = 0;
      while( c > 0 ) {
        pll tmp = st.front();
        st.pop_front();
        if ( tmp.second >= c ) {
          sum += c*tmp.first;
          tmp.second -= c;
          c = 0;
          if ( tmp.second > 0 ) st.push_front(tmp);
        } else {
          sum += tmp.first*tmp.second;
          c -= tmp.second;
        }
      }
      cout << sum << endl;
    }
  }
}
