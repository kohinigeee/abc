#include<iostream>
#include<vector>

#define rep(i,n) for ( int i = 0; i < n; ++i )

int arr[2*100000];
int sums[2*100000];
int n;
long long k;
using namespace std;

int main()
{
  int l,r;
  int cnt = 0;
  cin >> n >> k;
  rep(i,n) cin >> arr[i];

  sums[0] = 0;
  for ( int i = 1; i <= n; ++i ) sums[i] = sums[i-1]+arr[i-1];

  for ( int l = 0; l < n; ++l ) {
    for ( int r = l+1; r <= n; ++r ) {
      long long tmp = sums[r];
      tmp -= sums[l];
      if ( tmp == k ) {
        // cout << "l = " << l << ", r = " << r << endl;
        ++cnt;
      }
    }
  }

  cout << cnt << endl;
}
