#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

#define MAXN 200001

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

int dp[MAXN];
vector<pair<int,long long>> v;

int main()
{
  int n;
  cin >> n;
  for ( int i = 0; i < n; ++i ) {
    ll a,b;
    cin >> a >> b;
    ll tmpb = a+b;
    v.push_back(make_pair(a,1));
    v.push_back(make_pair(tmpb,-1));
  }

  for ( int i = 0; i <= n; ++i ) dp[i] = 0;

  sort(v.begin(), v.end());
  // ll nowv = -1;
  ll cnt = 0;
  int pos = -1;
  int x = v.size();
  ll nowday = 0, nextday = 0;

   // for ( int i = 0; i < v.size(); ++i ) cout << v[i].first << " "; cout << endl;
   // for ( int i = 0; i < v.size(); ++i ) cout << v[i].second << " "; cout << endl;

  while ( pos < x-1 ) {
    ++pos;
    cnt += v[pos].second;
    nowday = v[pos].first;

    while( pos+1 < x && v[pos].first == v[pos+1].first ) {
      ++pos;
     cnt += v[pos].second;
    }
    // cout << "cnt = " << cnt << endl;

    if ( cnt == 0 ) continue;
    ll nextday = v[pos+1].first;
    dp[cnt] += nextday-nowday;
  }

  for ( int i = 1; i < n; ++i ) cout << dp[i] << " ";
  cout << dp[n] << endl;
}
