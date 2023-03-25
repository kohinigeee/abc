#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<utility>


#define INF (1<<30)

using namespace std;
using ll = long long;

vector<pair<int,ll>> calc( int n, int s, vector<int>& a, vector<vector<int>>& edges ) {
    vector<pair<int,ll>> ans(n, make_pair(INF, 0));
    queue<int> que;

    ans[s] = make_pair(0, a[s]);
    que.push(s);

    while( !que.empty() ) {
        int top = que.front(); que.pop();
        int top_d = ans[top].first;
        ll top_score = ans[top].second;

        for ( int to : edges[top] ) {
            if ( ans[to].first > top_d+1 ) {
                ans[to] = make_pair(top_d+1, top_score+a[to]);
                que.push(to);
            } else if ( ans[to].first == top_d+1 ) {
                ans[to].second = max(ans[to].second, top_score+a[to]);
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    vector<int> a;
    vector<vector<int>> edges;
    vector<vector<pair<int,ll>>> ans;


    cin >> n;
    a = vector<int>(n);
    edges = vector<vector<int>>(n);
    for ( int i = 0; i < n; ++i ) cin >> a[i];

    for ( int i = 0; i < n; ++i ) {
        string tmp; cin >> tmp; 
        for ( int j = 0; j < n; ++j ) {
            if ( tmp[j] == 'Y' ) edges[i].push_back(j);
        }
    }
    for ( int j = 0; j < n; ++j ) {
        ans.push_back(calc(n, j, a, edges) );
    }

    int q; cin >> q;
    for ( int i = 0; i < q; ++i ) {
        int s, t; cin >> s >> t;
        --s; --t;
        if ( ans[s][t].first == INF ) cout <<"Impossible" << endl;
        else cout << ans[s][t].first << " " << ans[s][t].second << endl;
    }
}