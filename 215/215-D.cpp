#include<iostream>
#include<vector>

#define MM 100000

using namespace std;

typedef long long ll;
vector<int> dp = vector<int>(MM+1, 1);
vector<int> ddp = vector<int>(MM+1, 1);
vector<int> a;
vector<int> ans = vector<int>();

bool judge( int x ) {
  for ( int i = 0; i < a.size(); ++i ) {
    if (a[i] % x == 0) return true;
  }
  return false;
}

int main() {
  int n,m;
  cin >> n >> m;
  a = vector<int>(n);
  for ( int i = 0; i < n; ++i ) cin >> a[i];

  int tmp = 2;
  while( tmp * tmp <= MM ) {
    if ( dp[tmp] == 1 ) {
      int tmp2 = tmp*2;
      while(tmp2 <= MM ) {
        dp[tmp2] = 0;
        tmp2 += tmp;
      }
    }
    tmp += 1;
  }

  for ( int i = 2; i <= MM; ++i ) {
    if ( dp[i] == 1 && judge(i) ) {
      int cnt = i;
      while( cnt <= m ) {
        ddp[cnt] = 0;
        cnt += i;
      }
    }
  }

  for ( int i = 1; i <= m; ++i ) {
    if ( ddp[i] == 1 ) ans.push_back(i);
  }

  cout << ans.size() << endl;
  for ( int i = 0; i < ans.size(); ++i ) {
    cout << ans[i] << endl;
  }
}
