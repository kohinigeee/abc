#include<iostream>
#include<vector>
#include<set>

using namespace std;
using ll = long long;

int main()
{
    int n, k;

    cin >> n >> k;
    vector<ll> a(n);

    for ( int i = 0; i < n; ++i ) {
        cin >> a[i];
    }

    set<ll> s;
    for ( auto v : a ) s.insert(v);

    ll ans;
    for ( int i = 0; i < k; ++i ) {
        ans = *(s.begin());
        for ( auto v : a ) {
            ll tmp = ans+v;
            if ( s.find(tmp) == s.end() ) s.insert(tmp);
        }
        s.erase(ans);
    } 

    cout << ans << endl;
}