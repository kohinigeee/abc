#include<iostream>
#include<vector>
#include<queue>
#include<utility>

#define WHITE -1
#define BLACK 0
#define MAXS 2010

using namespace std;
using vi = vector<int>;

int dx[] = {-1, -1, 0, 0, 1, 1};
int dy[] = {-1, 0, -1, 1, 0, 1};

int main()
{
    vector<vi> masu = vector<vi>(MAXS, vi(MAXS, WHITE));
    int n;
    int cnt = 0;

    cin >> n;
    for ( int i = 0; i < n; ++i ) {
        int x, y; cin >> x >> y;
        x += 1000; y += 1000;
        masu[x][y] = BLACK;
    }

    for ( int x = 0; x < MAXS; ++x ) {
        for ( int y = 0; y < MAXS; ++y ) {
            if ( masu[x][y] == BLACK ) {
                queue<pair<int,int>> q;
                masu[x][y] = ++cnt;
                q.push(make_pair(x,y));

                while(!q.empty()) {
                    int x = q.front().first, y = q.front().second;
                    q.pop();

                    for ( int i = 0; i < 6; ++i ) {
                        int tmpx = x+dx[i], tmpy = y+dy[i];
                        if ( tmpx < 0 || tmpx >= MAXS || tmpy < 0 || tmpy >= MAXS ) continue;
                        if ( masu[tmpx][tmpy] == BLACK ) {
                            masu[tmpx][tmpy] = cnt;
                            q.push(make_pair(tmpx,tmpy));
                        }
                    }
                }
            }
        }
    }

    std::cout << cnt << endl;
}