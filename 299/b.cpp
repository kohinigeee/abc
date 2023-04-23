
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;
using ll = long long;
using pi = pair<ll,ll>;
using ll = long long;

int main()
{
    int n, t;

    cin >> n >> t;
    vector<ll> c(n), r(n);

    for ( int i = 0; i < n; ++i ) cin >> c[i];
    for ( int i = 0; i < n; ++i ) cin >> r[i];

    map<ll, pi> mp;

    for ( int i = 0; i < n; ++i ) {
        if ( mp.find(c[i]) == mp.end() ) mp[c[i]] = make_pair(r[i], i);
        else if ( mp[c[i]].first < r[i] ) mp[c[i]] = make_pair(r[i], i);
    }

    ll ans;

    if ( mp.find(t) == mp.end() ) ans = mp[c[0]].second;
    else ans = mp[t].second;

    cout << ans+1 << endl;
}