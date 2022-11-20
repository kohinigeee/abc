#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<queue>

using namespace std;

int dx[]={1, 0, -1, 0}, dy[]={0, 1, 0, -1};
int h, w;
vector<string> masu;

bool valid(int y, int x ) {
    return max(0, min(y, h-1)) == y && max(0, min(x, w-1)) == x && masu[y][x] == '.';
}

vector<vector<int>> bfs( pair<int,int> a ) {
    queue<pair<int,int>> que;
    vector<vector<int>> visit( masu.size(), vector<int>(masu[0].size(), 0));

    visit[a.first][a.second] = 1;
    que.push(a);
    while(!que.empty()) {
        pair<int,int> b = que.front(); que.pop();
        for ( int i = 0; i < 4; ++i ) {
            int ny = b.first+dy[i];
            int nx = b.second+dx[i];
            if ( valid(ny,nx) && visit[ny][nx] == 0 ) {
                visit[ny][nx] = 1;
                que.push(make_pair(ny,nx));
            }
        }

    }
    return visit;
}

int main()
{
    pair<int,int> st;

    cin >> h >> w;
    masu = vector<string>(h);
    for ( auto& s : masu ) cin >> s;
    for ( int i = 0; i < h; ++i ) {
        for ( int j = 0; j < w; ++j ) if ( masu[i][j] == 'S' ) st = make_pair(i, j);
    }


    bool ans = false;

    for ( int i = 0; i < 4; ++i ) {
        int ny = st.first+dy[i];
        int nx = st.second+dx[i];
        if ( !valid(ny, nx) ) continue;
        vector<vector<int>> visit = bfs(make_pair(ny, nx));
      

        for ( int j = 1; j < 4; ++j ) {
             int gy = st.first+dy[(i+j)%4];
             int gx = st.second+dx[(i+j)%4];

             if ( valid(gy,gx) && visit[gy][gx] ) { cout << "Yes" << endl; return 0; }
        }
    }
    cout << "No" << endl;

}