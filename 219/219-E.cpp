#include<iostream>
#include<vector>
#include<utility>
#include<queue>

using namespace std;
using ll = long long;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

bool isExist(ll x ) {
  vector<vector<int>> b(6, vector<int>(6)), c(6, vector<int>(6, -1));
  queue<pair<int,int>> q;

  for ( int i = 0; i < 4; ++i ) {
    for ( int j = 0; j < 4; ++j ) {
      if ( (x & (1LL<<(i*4+j)) )  == 0 ) b[i+1][j+1] = 0;
      else b[i+1][j+1] = 1;
    }
  }

  int cnt = 0;
  for ( int i = 0; i < 6; ++i ) {
    for ( int j = 0; j < 6; ++j ) {
      if ( c[i][j] != -1 ) continue;

      q.push(make_pair(i,j));
      c[i][j] = cnt;
      ++cnt;
      while(!q.empty()) {
        int tmpy = q.front().first;
        int tmpx = q.front().second;
        q.pop();

        for ( int k = 0; k < 4; ++k ) {
          int nx = tmpx+dx[k];
          int ny = tmpy+dy[k];

          if ( (nx >= 0) && (nx < 6) && (ny >= 0) && (ny < 6) && (c[ny][nx] == -1) && (b[tmpy][tmpx] == b[ny][nx]) ) {
            q.push(make_pair(ny,nx));
            c[ny][nx] = c[tmpy][tmpx];
          }
        }
      }
    }
  }

  if ( cnt >= 3 ) return false;
  else return true;

}

bool iscontain( ll x, vector<vector<int>>& a ) {
  for ( int i = 0; i < 4; ++i ) {
    for ( int j = 0; j < 4; ++j ) {
      if ( a[i][j] == 0 ) continue;
      if ( (x & (1<<(i*4+j)) )  == 0 ) return false;
    }
  }
  return true;
}

ll solve(vector<vector<int>>& a ) {
  ll ans = 0;
  for ( ll i = 1; i < (1LL<<16); ++i ) {
    if ( isExist(i) && iscontain(i, a) ) ++ans;
  }
  return ans;
}

int main()
{
  vector<vector<int>> a(4, vector<int>(4));

  for ( int i = 0; i < 4; ++i ) {
    for ( int j = 0; j < 4; ++j ) cin >> a[i][j];
  }

  cout << solve(a) << endl;
}
