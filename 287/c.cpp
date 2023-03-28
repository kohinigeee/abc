#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool judge(int n, int m, vector<vector<int>>& edges ) {
    if ( m != n-1 ) return false;
    int d2 = 0;
    vector<int> d1;
    for ( int i = 0; i < n; ++i ) {
        vector<int>& v = edges[i];
        switch(v.size()) {
            case 1:
                d1.push_back(i);
                break;
            case 2:
                ++d2;
                break;
            default:
                return false;
        }
   }
   if (d1.size() != 2) return false;

   vector<int> visited(n, 0);
   queue<int> que;
   int cnt = 0;

   que.push(0);
   visited[0] = 1;
   while(!que.empty()) {
    ++cnt;
    int top = que.front(); que.pop();
    for ( auto to : edges[top] ) {
        if ( visited[to] == 0 ) {
            visited[to] = 1;
            que.push(to);
        }
    }
   }

   return cnt == n;
}

int main()
{
    int n, m;
    vector<vector<int>> edges;

    cin >> n >> m;
    edges = vector<vector<int>>(n, vector<int>());
    for ( int i = 0; i < m; ++i ) {
        int u, v; cin >> u >> v;
        --u; --v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    if ( judge(n, m, edges) ) cout << "Yes" << endl;
    else cout << "No" << endl;
}