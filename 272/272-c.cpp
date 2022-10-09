#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>
#include<queue>

int dx[] = {1, -1, 1, -1};
int dy[] = {1, 1, -1, -1};

using namespace std;
using ll = long long;
using pii = pair<int, int>;

vector<pii> calc(ll m ) {
    // cout << "m = " << m << endl;
    vector<pii> ans;
    if ( m == 1 ) {
        ans.push_back(make_pair(1,0));
        ans.push_back(make_pair(0,1));
        return ans;
    }
    ll maxi = sqrt(m);
    for ( int i = 1; i <= maxi; ++i ) {
        ll tmp = m-i*i;
        ll p = sqrt(tmp);
        // cout << "tmp = " << tmp << endl;
        // cout << "i = " << i << ", p = " << p << endl;
        if ( p*p == tmp ) {
            ans.push_back(make_pair(i,p));
        }
    }
    return ans;
}

int main()
{
    vector<pii> dir;
    vector<vector<int>> masu;
    int n, m;

    cin >> n >> m;
    dir = calc(m);
    masu = vector<vector<int>>(n, vector<int>(n, -1));

    // for ( auto p : dir ) cout << p.first << " " << p.second << endl;

    queue<pii> que;
    masu[0][0] = 0;
    que.push(make_pair(0,0));

    while(!que.empty()) {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for ( auto p : dir ) {
            for ( int i = 0; i < 4; ++i ) {
                int mx = x+dx[i]*p.second;
                int my = y+dy[i]*p.first;

                if ( mx < 0 || my < 0 || mx >= n || my >= n ) continue;
                if ( masu[my][mx] == -1 ) {
                    masu[my][mx] = masu[y][x]+1;
                    que.push(make_pair(my, mx));
                }
            }
        }
    }

    for ( auto vec : masu ) {
        for ( auto v : vec ) {
            cout << v << " "; 
        }
        cout << endl;
    }
}