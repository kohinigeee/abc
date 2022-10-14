#include<iostream>
#include<vector>
#include<utility>
#include<queue>

using namespace std;
using pii = pair<int,int>;
using ll = long long;

int dx[] = {1, -1, 1, -1};
int dy[] = {1, 1, -1, -1};

vector<pii> calc(int m ) {
    vector<ll> sq( m+1, -1);
    vector<pii> ans;

    for ( int i = 0; i*i <= m; ++i ) {
       sq[i*i] = i; 
    }
    
    for ( int i = 0; i*i <= m; ++i ) {
        int j = m-i*i;
        if ( sq[j] != -1 ) ans.push_back(make_pair(i,sq[j])); 
    }
    return ans;
}

int main()
{
    int n, m;

    cin >> n >> m;

    vector<pii> dir = calc(m);
    vector<vector<ll>> d( n, vector<ll>(n, -1));
    queue<pii> que;

    
    d[0][0] = 0;
    que.push(make_pair(0,0));

    while(!(que.empty())) {
        int x = que.front().second;
        int y = que.front().first;
        que.pop();

        for ( auto p : dir ) {
            int ddx = p.second;
            int ddy = p.first;

            for ( int i = 0; i < 4; ++i ) {
                int nx = x+ddx*dx[i];
                int ny = y+ddy*dy[i];

                if ( nx < 0 || ny < 0 || nx >= n || ny >= n ) continue;
                if ( d[ny][nx] == -1 ) {
                    d[ny][nx] = d[x][y]+1;
                    que.push(make_pair(ny, nx));
                }
            }
        }
    }

    for ( auto vec : d ) {
        for ( auto v : vec ) cout << v << " ";
        cout << endl;
    }
}