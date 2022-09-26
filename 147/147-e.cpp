#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
  int h,w;
  vector<vector<int>> grid;
  vector<vector<vector<bool>>> dp;
  int ans = -1;
  int MAXK;
  int m = 0;

  cin >> h >> w;

  grid = vector<vector<int>>( h, vector<int>(w, 0));
  for ( int i = 0; i < h; ++i ) {
    for ( int j = 0; j < w; ++j ) {
      int tmp;
      cin >> tmp;
      grid[i][j] = tmp;
    }
  }

  for ( int i = 0; i < h; ++i ) {
    for ( int j = 0; j < w; ++j ) {
      int tmp;
      cin >> tmp;
      grid[i][j] = abs(grid[i][j]-tmp);
      m = max(m, grid[i][j]);
    }
  }

  MAXK = m*(h+w)+1;
//  MAXK = 6500;
  dp = vector<vector<vector<bool>>>( h, vector<vector<bool>>(w, vector<bool>( MAXK, false)));

  for ( int i = 0; i < h; ++i ) {
    for ( int j = 0; j < w; ++j ) {
      int tmp = grid[i][j];

      if ( !(i|j) ) {
        dp[i][j][tmp] = true;
        //cout << "test" << endl;
        //cout << "tmp = " << tmp << endl;
      }

      if ( i-1 >= 0 ) {
        for ( int k = 0; k < MAXK; ++k ) {
          if ( dp[i-1][j][k] ) {
            dp[i][j][k+tmp] = true;
            dp[i][j][abs(k-tmp)] = true;
            //cout << "uekara " << "K+tmp = " << k+tmp << endl;
            //cout << "uekara " << "k-tmp = " << abs(k-tmp) << endl;
          }
        }
      }

      if ( j-1 >= 0 ) {
        for ( int k = 0; k < MAXK; ++k ) {
          if ( dp[i][j-1][k] ) {
            dp[i][j][k+tmp] = true;
            dp[i][j][abs(k-tmp)] = true;

          //  cout << "sitakra " << "K+tmp = " << k+tmp << endl;
            //cout << "stakara " << "k-tmp = " << abs(k-tmp) << endl;
          }
        }
      }
    }
  }

  for ( int k = 0; k < MAXK; ++k ) {
    if ( dp[h-1][w-1][k] ) {
      ans = k;
      break;
    }
  }

  cout << ans << endl;


}
