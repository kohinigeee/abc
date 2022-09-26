#include<iostream>
#include<cmath>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int ans = 0;
  for ( int c = 1; c < n; ++c ) {
    int tmp = n-c;
    int rt = sqrt(tmp);
    int cnt = 0;
    //cout << "c = " << c << "rt = " << rt << "cnt = " << cnt << endl;
    for ( int j = 1; j <= rt; ++j ) {
      if ( tmp%j == 0 ) cnt += 2;
    }
    if ( rt*rt == tmp) cnt -= 1;
    ans += cnt;
  }

  cout << ans << endl;
}
