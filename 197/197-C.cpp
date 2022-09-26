#include<iostream>
#include<vector>

typedef long long ll;

using namespace std;


vector<int> lis = vector<int>();

int main()
{
  ll ans = 1LL<<32;
  int n;
  ll tmp;

  cin >> n;
  for ( int i = 0; i < n; ++i ) {
    int a;
    cin >> a;
    lis.push_back(a);
  }
  tmp = 1LL << (n-1);

  for ( ll i = 0; i < tmp; ++i ) {

    ll tmpans = 0;
    ll bit = i;
    ll tail = 0;

    for ( ll j = 0; j < n-1; ++j ) {
      if ( ( 1LL << j) & bit ) {
        ll tmp1 = 0;
        for ( ll k = tail; k < j+1; ++k ) tmp1 = tmp1|lis[k];
        tmpans = tmpans^tmp1;
        tail = j+1;
      }
    }
    ll tmp1 = 0;
    for ( ll j = tail; j < n; ++j ) tmp1 = tmp1|lis[j];
    tmpans = tmpans^tmp1;
    ans = ans > tmpans ? tmpans: ans;
  }

  cout << ans << endl;
}
