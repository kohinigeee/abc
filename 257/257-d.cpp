#include<iostream>
#include<vector>
#include<cmath>
#include<queue>

using namespace std;
using ll = long long;

bool bfs( int x, int n, ll s, vector<ll>& p, vector<pair<ll,ll>>& b) {
    vector<bool> visited(n,false);
    queue<int> que;


    visited[x] = true;
    que.push(x);
    int cnt = n-1;

    while(!que.empty()) {
        int top = que.front(); que.pop();
        for ( int i = 0; i < n; ++i ) {
            if ( visited[i] ) continue;
            if ( abs(b[top].first-b[i].first)+abs(b[top].second-b[i].second) > s*p[top] ) continue;
            visited[i] = true;
            que.push(i);
            --cnt;
        }
    } 
    return cnt == 0;
}

int main()
{
    int n;
    
    cin >> n;

    vector<ll> p(n);
    vector<pair<ll,ll>> b(n);
    for ( int i = 0; i < n; ++i ) {
        ll x,y; cin >> x >> y >> p[i];
        b[i] = make_pair(x,y);
    }

    ll no = 0, ok = (10000000000);

    while( no+1 < ok ) {
        ll mid = (no+ok)/2;

        bool f = false;
        for ( int i = 0; i < n; ++i ) {
            f = (f||bfs(i, n, mid, p, b));
            if ( f ) break;
        }

        if ( f ) ok = mid;
        else no = mid;
    }

    cout << ok << endl; 
}