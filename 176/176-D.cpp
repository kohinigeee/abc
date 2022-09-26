#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<queue>

using namespace std;

int h,w;
int sx,sy,gx,gy;
int direx[] = {0,1,0,-1};
int direy[] = {1,0,-1,0};
int dire5x[] = {-2,-1,0,1,2};
int dire5y[] = {-2,-1,0,1,2};
int cnt = 0;

int main()
{
  vector<string> meiro = vector<string>();
  vector<vector<int>> gro = vector<vector<int>>();
  queue<pair<int,int>> q1 = queue<pair<int,int>>();
  queue<pair<int,int>> q2 = queue<pair<int,int>>();
  pair<int,int> pos;

  cin >> h >> w;
  cin >> sx >> sy;
  cin >> gx >> gy;

  for ( int i = 0; i < h; ++i ) {
    string tmp;
    cin >> tmp;
    meiro.push_back(tmp);

    gro.push_back(vector<int>(w,-1));
  }

  gro[sx-1][sy-1] = 0;
  pos = pair<int, int>(sx-1, sy-1);
  q1.push(pos);
  q2.push(pos);

  while(1) {
    while ( !q1.empty()) {
      pos = q1.front();
      q1.pop();
      q2.push(pos);

      for ( int i = 0; i < 4; ++i ) {
        int tmpx = pos.second+direx[i];
        int tmpy = pos.first+direy[i];

        if( tmpx >= 0 && tmpx < w && tmpy >= 0 && tmpy < h ) {
          if (gro[tmpy][tmpx] == -1 && meiro[tmpy][tmpx] == '.') {
            gro[tmpy][tmpx] = gro[pos.first][pos.second];
            q1.push(pair<int,int>(tmpy, tmpx));
          }
        }
      }
    }

    while ( !q2.empty()) {
      pos = q2.front();
      q2.pop();
      for ( int i = 0; i < 5; ++i ) {
        for ( int j = 0; j < 5; ++j ) {
          int tmpx = pos.second+dire5x[i];
          int tmpy = pos.first+dire5y[j];

          if ( tmpx >= 0 && tmpx < w && tmpy >= 0 && tmpy < h ) {
            if ( gro[tmpy][tmpx] == -1 && meiro[tmpy][tmpx] == '.') {
              gro[tmpy][tmpx] = gro[pos.first][pos.second]+1;
              q1.push(pair<int,int>(tmpy,tmpx));
            }
          }
        }
      }
    }

    if ( q1.empty() && q2.empty() ) break;
  }

cout << gro[gx-1][gy-1] << endl;
}
