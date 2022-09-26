#include<iostream>
#include<vector>
#include<string>

#define MM 998244353
#define lop(i,n) for( int i = 0; i < n; ++i )

using namespace std;

int chno(char ch ) {
  return ch-'A';
}

bool havech( int x, char ch ) {
  int tmp = x & ( 1 << chno(ch) );
  return tmp;
}

int dp[1001][1<<10][10];

int main()
{
  string s;
  int n;
  lop(i,1001) {
    lop(j,1<<10) {
      lop(k,10) dp[i][j][k] = 0;
    }
  }

  cin >> n;
  cin >> s;

  for ( int i = 1;  i <= n; ++i ) {
    int no = chno(s[i-1]);
    for ( int j = 0; j < 1<<10; ++j ) {
      for ( int k = 0; k < 10; ++k ) {
        dp[i][j][k] += dp[i-1][j][k];
        dp[i][j][k] %= MM;
        if ( k == no ) {
          dp[i][j][k] += dp[i-1][j][k];
          dp[i][j][k] %= MM;
        }
        if ( !havech(j, s[i-1]) ) {
          int nextu = j | (1 << no);
          dp[i][nextu][no] += dp[i-1][j][k];
          dp[i][nextu][no] %= MM;
        }
      }
    }
    dp[i][1 << no][no] += 1;
  }

  int sum = 0;
  for ( int j = 0; j < 1<<10; ++j ) {
    for ( int k = 0; k < 10; ++k ) {
      sum += dp[n][j][k];
      sum %= MM;
    }
  }

  cout << sum << endl;
}
