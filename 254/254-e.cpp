#include<iostream>
#include<vector>
#include<queue>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vector<int> d;

long long bfs( int s, int k, vvi& g ) {
    queue<int> q;
    queue<int> p;

    long long sum = 0;
    d[s] = 0;
    q.push(s);

    while(!q.empty()) {
        int no = q.front(); q.pop();
        sum += no+1;
        p.push(no);
        if ( d[no] >= k ) continue;
        for ( auto to : g[no] ) {
            if ( d[to] == -1 ) {
                d[to] = d[no]+1; q.push(to);
            }
        }
    }

    while(!p.empty()) {
        int no = p.front(); p.pop();
        d[no] = -1;
    }

    return sum;
}

int main()
{
    int n;
    int m;
    int q;
    vvi g;

    cin >> n >> m;
    g = vvi(n , vi());

    for ( int i = 0;  i < m; ++i ) {
        int a,b; cin >> a >> b; --a; --b; 
        g[a].push_back(b); g[b].push_back(a);
    }
    d = vi(n, -1);

    cin >> q;
    for ( int i = 0; i < q; ++i ) {
        int x, k;
        cin >> x >> k;
        --x;
        cout << bfs(x, k, g) << endl;
    }
}