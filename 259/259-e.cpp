#include<iostream>
#include<vector>
#include<map>
#include<utility>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main()
{
    ll n;
    map<ll, pll> mp;
    vector<vector<pair<ll, ll>>> v;

    cin >> n;
    v = vector<vector<pair<ll, ll>>>(n);

    for ( int i = 0; i < n; ++i ) {
        ll m; cin >> m;
        for ( int j = 0; j < m; ++j ) {
            ll p, e;
            cin >> p >> e;

            v[i].push_back(make_pair(p,e));
            if ( mp.find(p) == mp.end() ) mp[p] = make_pair(e,1);
            else {
                if ( mp[p].first == e ) mp[p].second += 1;
                else if ( mp[p].first < e ) mp[p] = make_pair(e,1);
            }
        }
    }

    int l = 0;
    ll ans = 0;
    for ( auto v1 : v ) {
        bool f = true;
        for ( auto pe : v1 ) {
            ll p = pe.first, e = pe.second;
            if ( mp[p].first == e && mp[p].second == 1 ) {
                ++ans;
                // cout << "break" << endl;
                f = false;
                break;
            }
        }
        if ( f ) l = 1;

    }

    // if ( l+ans > n ) cout << v[n+1][0].first << endl;
    cout << l+ans << endl;
    // cout << min(ans+1, n) << endl;
    // for ( auto it = mp.begin(); it != mp.end(); ++it ) {
    //     cout << it->first << " " << (it->second).first << "," << (it->second).second << endl;
    // }
}