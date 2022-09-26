#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#define rep(i, n) for ( int i = 0; i < n; ++i )

using namespace std;

int masu[15][26];

int main()
{
  vector<string> v;
  int n, k;
  int ans = 0;

  cin >> n >> k;
  for ( int i = 0; i < n; ++i ) for ( int j = 0; j < 26; ++j ) masu[i][j] = 0;
  for ( int i = 0; i < n; ++i ) {
    string tmp;
    cin >> tmp;
    for ( auto c : tmp ) masu[i][c-'a'] += 1;
  }

  int maxn = 1<<n;

  for ( int i = 1; i < maxn; ++i ) {
    vector<int> sumv(26, 0);
    int j = 0, tmp = 1;
    while ( tmp < maxn ) {
      int anst = 0;
      if ( (tmp & i ) > 0 ) for ( int t = 0; t < 26; ++t ) sumv[t] += masu[j][t];
      for ( int t = 0; t < 26; ++t ) if ( sumv[t] == k ) ++anst;
      ans = max(anst, ans);
      tmp = tmp << 1;
      ++j;
    }
  }

  cout << ans << endl;

}
