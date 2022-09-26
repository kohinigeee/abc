#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;
using ll = long long;

int main()
{
    vector<ll> dpr;
    vector<ll> a;
    vector<ll> arev;
    int n;
    ll l, r;
    ll sum = 0;

    cin >> n >> l >> r;

    dpr = a = arev = vector<ll>(n, -1);

    for ( int i = 0; i < n; ++i ) {
        cin >> a[i]; arev[n-1-i] = a[i];
        sum += a[i];
    }

    dpr[0] = min(r, arev[0]);
    for ( int i = 1; i < n; ++i ) {
        dpr[i] = min( dpr[i-1]+arev[i], r*(i+1));
    }

    // cout << "test" << endl;
    ll ans = dpr[n-1];
    ans = min(ans, sum);
    ans = min(ans, l*n);
    ans = min(ans, r*n);

    for ( int i = 0; i < n-1; ++i ) {
        // printf("i = %d, r = %d", i, n-2-i);
        ll tmp = l*(i+1) + dpr[n-2-i];
        ans = min(ans, tmp);
    }

    cout << ans << endl;
}