#include<iostream>
#include<vector>

#define rep(i,n) for ( int i =0 ; i < n; ++i )

using namespace std;
using vvi = vector<vector<int>>;

int main()
{
  int n, m;

  cin >> n >> m;
  vvi mat = vvi(n, vector<int>(m));

  rep(i,n) {
    rep(j,m) {
      cin >> mat[i][j];
    }
  }

  rep(i,n) for ( int j = 1; j < m; ++j ) if ( mat[i][j]-mat[i][j-1] != 1 ) { cout << "No" << endl; return 0; }
  for ( int i = 1; i < n; ++i ) {
    if ( mat[i][0]-mat[i-1][0] != 7 ) { cout << "No" << endl; return 0; }
  }

  int tmp = (mat[0][0]-1)/7;
  tmp = 7*(tmp+1);
  if ( mat[0][m-1] > tmp ) { cout << "No" << endl; return 0; }

  cout << "Yes" << endl;
}
