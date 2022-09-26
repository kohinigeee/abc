#include<iostream>
#include<queue>
#include<string>
#include<utility>

#define MAXN 100
#define rep(i,n) for ( int i = 0; i < n; ++i )

int masu[MAXN][MAXN];

using namespace std;

int main()
{
  int h,w;
  queue<pair<int,int>> q;
  int ans = 0;

  cin >> h >> w;
  rep(i, h) rep(j,w) masu[i][j] = 0;

  rep(i, h) {
    string tmp; cin >> tmp;
    rep(j, w) {
      if ( tmp[j] == '#' ) masu[i][j] = -1;
    }
  }

  q.push(make_pair(0,0));

  while( !q.empty() ) {
    pair<int,int> top = q.front(); q.pop();
    int tmp = masu[top.first][top.second];
    if ( tmp > ans ) ans = tmp;
    if ( top.first+1 < h && masu[top.first+1][top.second] == 0 ) {
      masu[top.first+1][top.second] = tmp+1;
      q.push(make_pair(top.first+1, top.second));
    }
    if ( top.second+1 < w && masu[top.first][top.second+1] == 0 ) {
      masu[top.first][top.second+1] = tmp+1;
      q.push(make_pair(top.first, top.second+1));
    }
  }

  cout << ans+1 << endl;
}
