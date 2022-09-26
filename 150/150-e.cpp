#include<iostream>
#include<vector>
#include<algorithm>

#define MAXN 200000+1
#define LIM 1000000007

typedef long long ll;
using namespace std;


ll fac[MAXN];

int main()
{

  ll tmp = 1;
  int n;
  ll sum = 0;
  vector<ll> c = vector<ll>();

  fac[0] = 1;
  for ( int i = 1; i < MAXN; ++i ) {
    tmp *= 2;
    tmp %= LIM;
    fac[i] = tmp;
  }

  cin >> n;
  for ( int i = 0; i < n; ++i ) {
    ll tmp;
    cin >> tmp;
    c.push_back(tmp);
  }

  sort(c.begin(), c.end());

  for ( int i = 1; i <= n; ++i ) {
    int l = i-1;
    int r = n-i;

    ll tmp = (fac[r]+r*fac[r-1])%LIM;
    tmp = (fac[l]*tmp)%LIM;
    tmp = tmp*c[i-1]%LIM;

    sum += tmp;
    sum %= LIM;
  }

  sum = sum*(fac[n])%LIM;

  cout << sum << endl;
}
