#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//
// int lower_bound(vector<int>& v, int key ) {
//   int l = 0, r = v.size();
//
//   while(r - l > 1 ) {
//     int mid = (l+r)/2;
//     if ( v[mid] < key ) l = mid;
//     else r = mid;
//   }
//   return l;
// }
//
// int upper_bound(vector<int>& v, int key ) {
//   int l = 0, r = v.size();
//
//   while(r-l > 1 ) {
//     int mid = (l+r)/2;
//     if ( v[mid] <= key ) l = mid;
//     else r = mid;
//   }
//   return r;
// }

int main() {
  int n;
  long long sum = 0;

  cin >> n;
  vector<int> a(n), b(n), c(n);
  for ( int i = 0; i < n; ++i ) cin >> a[i];
  for ( int i = 0; i < n; ++i ) cin >> b[i];
  for ( int i = 0; i < n; ++i ) cin >> c[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  for ( int i = 0; i < n; ++i ) {
    auto ita = lower_bound(a.begin(), a.end(), b[i]);
    auto itc = upper_bound(c.begin(), c.end(), b[i]);
    sum += (ita-a.begin())*(c.end()-itc);
  }
  cout << sum << endl;
}
