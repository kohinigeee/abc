#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

vector<ll> a;
ll n, k;

ll cal ( ll m ) {
    ll ans = 0;
    for ( auto v : a ) {
        ans += min(m, v);
    }
    return ans;
}

int main()
{
    cin >> n >> k;
    a = vector<ll>(n, 0);

    for ( int i = 0; i < n; ++i ) {
        cin >> a[i];
    }

    ll l, r;
    l = 0; r = (1LL<<60);

    while( l+1 < r ) {
        ll mid = (l+r)/2;
        ll sum = cal(mid);
        if ( sum > k ) r = mid;
        else l = mid;
    }

    ll remain = k-cal(l);

    for ( auto& v : a ) {
        v = max(0LL, v-l);
    }

    for ( auto v : a ) {
        if ( v > 0 && remain > 0 ) {
            --v; --remain;
        }
        cout << v << " ";
    }
}