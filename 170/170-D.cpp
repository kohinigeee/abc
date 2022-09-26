#include<iostream>
#include<vector>
#include<algorithm>

#define LMAX 1000000

using namespace std;

vector<bool> dp = vector<bool>(LMAX+1, true);

int main()
{
  int n;
  vector<int> lis = vector<int>();
  int cnt = 0;
  int maxv;

  cin >> n;
  for ( int i = 0; i < n; ++i ) {
    int tmp;
    cin >> tmp;
    lis.push_back(tmp);
  }

  sort(lis.begin(), lis.end());
  maxv = lis[n-1];

  for ( int i = 0; i < n; i++) {
    int now = lis[i];
    if (dp[now]) {
      if (i+1 < n) {
        if ( now != lis[i+1]) cnt += 1;
      } else cnt += 1;

      int tmp = now;
      while(tmp <= maxv) {
        dp[tmp] = false;
        tmp += now;
      }
    }
  }

  cout << cnt << endl;

}
