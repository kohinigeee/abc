#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

typedef long long ll;

using namespace std;

int main()
{
  vector<vector<ll>> dp (2); // [i][0] ‚ª‚»‚Ì‚Ü‚ÜA[i][1]‚ª‚Â‚©‚¤
  vector<int> v;
  int n;

  cin >> n;
  for ( int i = 0; i < n; ++i ) {
    int tmp;
    scanf("%d", &tmp);
    v.push_back(tmp);
  }

  dp[0].push_back(v[0]);
  dp[1].push_back(v[0]);
  dp[0].push_back(v[0]+v[1]);
  dp[1].push_back(-(v[0]+v[1]));
  for ( int i = 2; i < v.size(); ++i ) {
    //cout << "i = " << i << endl;
    ll dp0,dp1;
    dp0 = max(dp[0][i-1]+v[i], dp[1][i-1]+v[i]);
    //cout << "test1" << endl;
    dp1= max(dp[0][i-1]+2*(-v[i-1])-v[i], dp[1][i-1]+2*v[i-1]-v[i]);
    //cout << "test2" << endl;
    dp[0].push_back(dp0);
    dp[1].push_back(dp1);
  }

  cout << max(dp[0][dp[0].size()-1], dp[1][dp[1].size()-1]) << endl;
}
