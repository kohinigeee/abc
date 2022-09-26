#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main()
{
    vector<vector<int>> vs;
    map<int,int> mp;
    vector<int> ans;
    int n, k;

    cin >> n >> k;
    ans = vector<int>(n+1, -1);

    for ( int i = 0; i < n; ++i ) {
        int p; cin >> p;
        auto it = mp.lower_bound(p);
        if ( it == mp.end() ) {
            vs.push_back(vector<int>(1, p));
            mp[p] = vs.size()-1;
        } else {
            int now = it->first;
            int vno = it->second;
            vs[vno].push_back(p);
            mp[p] = vno; mp.erase(now);
        }

        int vno = mp[p];
        if ( vs[vno].size() >= k ) {
            for ( auto v : vs[vno] ) ans[v] = i+1;
            mp.erase(p);
        }
    }

    for ( int i = 1; i <= n; ++i ) {
        cout << ans[i] << endl;
    }
}