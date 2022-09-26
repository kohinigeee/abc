#include<iostream>
#include<string>
#include<algorithm>

typedef long long int ll;
#define INF 400000100

using namespace std;

ll dp[2010][2010];
ll masu[2010][2010];

ll func( int h, int w) {
  if ( dp[h][w] != INF ) return dp[h][w];
  ll p = 1;
  ll tmp;
  if ( (h+w)%2 == 0) p = -1;

  if ( h-1 < 0 ) tmp = func(h,w-1)+ p*masu[h][w];
  else if ( w-1 < 0 ) tmp = func(h-1, w) + p*masu[h][w];
  else {
    if ( (h+w)%2 == 1 ) tmp = max(func(h-1,w), func(h,w-1))+p*masu[h][w];
    else tmp = min(func(h-1,w), func(h,w-1))+p*masu[h][w];
  }

  return dp[h][w] = tmp;
}

int main()
{
  int h,w;

  cin >> h >> w;
  for ( int i = 0; i < h; ++i ) {
    string s;
    cin >> s;
    for ( int j = 0; j < w; ++j ) {
      if (s[j] == '+') masu[i][j] = 1;
      else masu[i][j] = -1;
    }
  }
  for ( int i = 0; i < h; ++i ) {
    for ( int j = 0; j < w; ++j ) {
      dp[i][j] = INF;
    }
  }
  masu[0][0] = 0;
  dp[0][0] = 0;

  func(h-1,w-1);

  if ( dp[h-1][w-1] > 0 ) cout << "Takahashi" << endl;
  else if ( dp[h-1][w-1] < 0 ) cout << "Aoki" << endl;
  else cout << "Draw" << endl;
}
