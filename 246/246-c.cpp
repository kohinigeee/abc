#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

using ll = long long;

int main()
{
  priority_queue<ll> q;

  ll n, k, x;

  cin >> n >> k >> x;

  for ( int i = 0; i < n; ++i ) {
    ll tmp; cin >> tmp;
    q.push(tmp);
  }

  ll nowk = 0;
  while ( q.top() >= x && nowk < k ) {
    ll tmp = q.top(); q.pop();
    ll mai = min(k-nowk, ll(tmp/x));
    tmp = tmp-x*mai;
    nowk += mai;
    q.push(tmp);
  }

  if ( nowk < k) {
    while( (!q.empty()) && nowk< k ) {
      q.pop();
      nowk++;
    }
  }

  ll sum = 0;
  while(!q.empty()) {
    sum += q.top(); q.pop();
  }

  cout << sum << endl;
}
