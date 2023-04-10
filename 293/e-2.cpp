#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

ll power(ll x, ll y, ll p ) {
    ll ord = x;
    ll ans = 1;

    while ( y > 0 ) {
        if ( y & 1 ) {
            ans *= ord;
            ans %= p;
        }
        ord *= ord;
        ord %= p;
        y = y>>1;
    }

    return ans;
}

ll func(ll a, ll x, ll m) {
    if ( x == 0 ) return 0;
    if( x == 1 ) return a%m;
    if ( x % 2 ) return a*(func(a, x-1, m)+1)%m;
    else return func(a, x/2, m)*(power(a, x/2, m)+1)%m;
}

int main()
{
    ll a, x, m;
    cin >> a >> x >> m;
    ll ans = 1%m;

    ans += func(a, x-1, m);
    ans %= m;
    cout << ans << endl;
}