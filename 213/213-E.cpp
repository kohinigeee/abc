#include<iostream>
#include<list>
#include<vector>
#include<string>
#include<utility>

#define MAXV 5000

using namespace std;

typedef  pair<int,int> pi;

int d[] = {-2, -1, 0, 1, 2};
int dh2[] = {1,0,-1,0};
int dw2[] = {0,1,0,-1};
int h,w;

bool judge(pi p) {
  return (p.first >= 0 && p.first < h && p.second >= 0 && p.second < w);
}

int main() {
  vector<string> masu = vector<string>();
  vector<vector<int>> g;
  list<pair<int,int>> l;

  cin >> h >> w;
  for ( int i = 0; i < h; ++i ) {
    string tmp;
    cin >> tmp;
    masu.push_back(tmp);
  }

  g = vector<vector<int>>(h, vector<int>(w, MAXV));

  l.push_front(pi(0,0));
  g[0][0] = 0;
  while(!l.empty()) {
    pi now = l.front(); l.pop_front();
    for ( int i = 0; i < 4; ++i ) {
      pi tmp = pi(now.first+dh2[i], now.second+dw2[i]);

      if ( judge(tmp) && masu[tmp.first][tmp.second] != '#' && g[tmp.first][tmp.second] > g[now.first][now.second] ) {
        g[tmp.first][tmp.second] = g[now.first][now.second];
        l.push_front(tmp);
      }
    }

    for ( int i = 0; i < 5; ++i ) {
      for ( int j = 0; j < 5; ++j ) {
        if ( d[i]*d[j] == 4 || d[i]*d[j] == -4 ) continue;
        pi tmp = pi(now.first+d[i], now.second+d[j]);

        if ( judge(tmp) && g[tmp.first][tmp.second] > g[now.first][now.second]+1 ) {
          g[tmp.first][tmp.second] = g[now.first][now.second]+1;
          l.push_back(tmp);
        }
      }
    }
  }

  cout << g[h-1][w-1] << endl;
}
