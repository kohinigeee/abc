#include<iostream>
#include<vector>
#include<queue>
        

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(n);
    vector<int> colour(n, -1);
    vector<int> group_no(n, -1);
    vector<pair<int,int>> groups; //first:0 second:1

    while(m--) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int group_cnt = 0;
    for ( int i = 0; i < n; ++i ) {
        if ( colour[i] != -1 ) continue;
        queue<int> que;
        que.push(i);
        colour[i] = 0;

        groups.push_back(make_pair(0,0));
        group_no[i] = group_cnt++;
        groups.back().first += 1;

        while( !que.empty() ) {
            int node = que.front(); que.pop();
            for ( auto to : edges[node] ) {
                if ( colour[to] == -1 ) {
                    int to_colour = (colour[node]+1)%2;
                    colour[to] = to_colour;
                    group_no[to] = group_no[node];
                    if ( to_colour == 1 ) groups.back().second += 1;
                    else groups.back().first += 1;
                    que.push(to);
                }
                if ( colour[to] == colour[node] ) {
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
    }

    long long ans = 0;
    for ( int i = 0; i < n; ++i ) {
        long long tmp = n-edges[i].size();
        if ( colour[i] ) tmp -= groups[group_no[i]].second;
        else tmp -= groups[group_no[i]].first;
        ans += tmp;
    }
    cout << ans/2 << endl;
}