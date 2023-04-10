#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

ll power(ll x, ll y, ll p) {
    ll ord = x;
    ll ans = 1;

    while( y > 0 ) {
        if ( y & 1 ) {
            ans *= ord;
            ans %= p;
        }
        ord *= ord; ord %= p;
        y =  y>>1;
    }
    return ans;
}

int main()
{
    ll a, x, m;
    cin >> a >> x >> m;
    vector<ll> s;

    ll ord = a%m;
    ll ans = a%m;
    ll tmpx = x-1;
    ll no = 1;

    s.push_back(ans);
    tmpx =  tmpx>>1;
    while ( tmpx > 0 ) {
        no *= 2;
        ans = ans*(ord+1)%m;
        s.push_back(ans);
        ord = ord*ord%m;
        tmpx = tmpx>>1;
    }

    ans = 1%m;
    ll r = x-1;
    if ( x == 1 ) {
        cout << 1%m << endl;
        return 0;
    }
    
    for ( int i = s.size()-1; i >= 0; --i ) {
        if ( ((x-1) & (1LL<<i)) == 0 ) {
            no /= 2;
            continue;
        }
        ll dir = r-no;
        ll tmpa = power(a, dir, m);
        ans += tmpa*s[i]%m;
        ans %= m;
        r = r-no;
        no /= 2;
    }

    cout << ans << endl;
}