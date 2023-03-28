#include<iostream>
#include<vector>
#include<map>

using namespace std;
using ll = long long;

int main()
{
    map<ll,ll> mp;

    int n; cin >> n;
    for ( int i = 0; i < n; ++i ) {
        ll a; cin >> a;
        if ( mp.find(a) == mp.end() ) mp[a] = 0;
        mp[a] += 1;
    }
    

    ll ans = 0;
    for ( auto it = mp.begin(); it != mp.end(); ++it ) {
        ans += (it->second)/2;
    }
    cout << ans << endl;
}