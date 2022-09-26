#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
using ll = long long;

long long getSum(ll from, ll to ) { // from+1 ~ toまでの和
  return (to*(to+1)-from*(from+1))/2;
}

long long tousa(ll x ) {
  if ( x <= 0 ) return 0;
  return x*(x+1)/2;
}


int main()
{
  vector<ll> a;
  ll k;
  int n;
  ll cnt = 0;
  long long ans, nowv; //nowは計算済みの値
  ans = 0;

  cin >> n >> k;
  for ( int i = 0; i < n; ++i ) { ll tmp; cin >> tmp; a.push_back(tmp); }
  sort(a.begin(), a.end(), greater<ll>() );
  a.push_back(0);

  nowv = a[0];
  for ( int i = 0; i < n+1; ++i ) {
    if ( nowv > a[i] ) {
      ll tmpp =  tousa(nowv-1)-tousa(a[i]-1);// a[i]~now-1までの和
      ll tmpno = (nowv-a[i]);
      ll rest = k-cnt;
      ll cycle = rest/i;

      if ( cnt+ tmpno*(i) > k ) {
        tmpp = tousa(nowv-1)-tousa(nowv-cycle-1);
        ans += tmpp*i + ( nowv-cycle-1 ) * (rest%i);
        cnt = k;
        break;
      } else {
        ans += tmpp*i;
        cnt += tmpno*i;
        nowv = a[i];
        if ( cnt == k ) break;
      }
    }


    if ( nowv == a[i] ) {
      ans += a[i];
      ++cnt;
    }
    if ( cnt == k ) break;
  }

  cout << ans << endl;
}
