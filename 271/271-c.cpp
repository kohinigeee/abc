#include<iostream>
#include<vector>
#include<map>

using namespace std;

using ll = long long;

int main()
{
    map<ll, ll> mp;
    int n;
    cin >> n;

    for ( int i = 0; i < n; ++i ) {
        ll a; cin >> a;
        if ( mp.find(a) == mp.end() ) mp[a] = 0;
        mp[a] += 1;
    }

    ll sum = n;
    ll i;

    for ( i = 1; i <= n; ++i ) {
        if ( mp.find(i) == mp.end() ) {
            if ( sum >= 2 ) sum -= 2;
            else {
                --i;
                break;
            }
        } else {
            sum -= 1;
        }
        if ( sum == 0 ) break;
    }

    cout << i << endl;
}