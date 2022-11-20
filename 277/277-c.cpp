#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<utility>
#include<map>
#include<queue>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main()
{
    vector<int> q;
    vector<pll> hasigo;
    set<int> st;
    map<int, int> mp;
    vector<int> no;
    int n;

    cin >> n;
    for ( int i = 0; i < n; ++i ) {
        ll a, b; cin >> a >> b;
        if ( a >  b ) swap(a,b);
        st.insert(a);
        st.insert(b); 
        hasigo.push_back(make_pair(a,b));
    }

    st.insert(1);

    auto it = st.begin();

    while( it != st.end() ) {
        mp[*it] = no.size();
        no.push_back(*it);
        ++it;
    }

    vector<vector<int>> g(no.size());
    for ( auto p : hasigo ) {
        int no1 = mp[p.first];
        int no2 = mp[p.second];
        g[no1].push_back(no2);
        g[no2].push_back(no1);
    }
    
    queue<int> que;
    vector<int> visited(no.size(), 0);
    visited[0] = 1;
    que.push(0);

    int ans = 0;

    while(!que.empty()) {
        int top = que.front(); que.pop();
        ans = max(ans, no[top]);

        for ( auto to : g[top] ) {
            if ( visited[to] == 0 ) {
                visited[to] = 1;
                que.push(to);
            }
        }
    }

    cout << ans << endl;
}