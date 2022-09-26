#include<iostream>
#include<string>
#include<vector>

using namespace std;

int dx[] = {1, 0, 1, 1};
int dy[] = {0, 1, 1, -1};

int main()
{
  vector<string> masu;
  int n;
  bool ans = false;

  cin >> n;
  for ( int i = 0; i < n; ++i ) {
    string tmp; cin >> tmp;
    masu.push_back(tmp);
  }

  for ( int i = 0; i < n; ++i ) {
    for ( int j = 0; j < n; ++j ) {
      for ( int k = 0; k < 4; ++k ) {
        int x = j, y = i;
        if ( ( x+dx[k]*5 < n ) && ( y+dy[k]*5 >= 0 ) && ( y+dy[k]*5 < n ) ) {
          int cnt = 0;
          if ( masu[y][x] == '#' ) ++cnt;

          for ( int t = 0; t < 5; ++t ) {
            x += dx[k]; y+= dy[k];
            if ( masu[y][x] == '#' ) ++cnt;
          }
          if ( cnt >= 4 ) ans = true;
        }
      }
      if ( ans ) break;
    }
    if ( ans ) break;
  }

  if ( ans ) cout << "Yes" << endl;
  else cout << "No" << endl;
}
