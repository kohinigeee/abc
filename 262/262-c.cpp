#include<iostream>
#include<vector>

#define MODK 998244353
using namespace std;
using ll = long long;


int main()
{
    vector<ll> a;
    ll n;
    ll ans = 0;
    ll tmp = 0;

    cin >> n;
    a = vector<ll>(n, 0);
    ll s = 0;
    for ( ll i = 0; i < n; ++i ) cin >> a[i];

    for ( ll i = n-1; i >= 0; --i ) {
        if ( a[i] == i+1 ) {
            ans += s;
            s += 1;
        } else if ( a[i] > i+1 ) {
            if ( a[a[i]-1] == i+1 ) ans += 1;
        }
    }
    cout << ans << endl;
}