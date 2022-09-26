#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

double func(int k, int s) {
  double ans = 1;
  for ( int i = s; i < k; i *= 2 ) ans *= 0.5;

  return ans;
}

int main()
{
  double ans = 0;
  int k;
  int n;

  cin >> n >> k;
  for ( int i = 1; i <= n; ++i ) {
    ans += func(k, i)*(1.0/n);
  }

  cout << setprecision(15) << ans << endl;
}
