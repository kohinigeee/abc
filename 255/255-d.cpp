#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

using ll = long long;

int main()
{
    vector<ll> a;
    vector<ll> sum;
    ll n, q;
    ll ans = 0;

    cin >> n >> q;
    a = vector<ll>(n, 0);
    sum = vector<ll>(n, 0);
    for ( int i = 0; i < n; ++i ) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    sum[0] = a[0];
    for ( int i = 1; i < n; ++i ) sum[i] = sum[i-1]+a[i];

    for ( int i = 0; i < q; ++i ) {
        ll x; cin >> x;
        ll ans = 0;

        auto l = lower_bound(a.begin(), a.end(), x);
        ll cntl = l-a.begin();
        auto r = upper_bound(a.begin(), a.end(), x);
        ll cntr = a.end()-r;

        if ( cntl == n ) {
            ans += abs(x*n-sum[n-1]);
        } else if ( cntl > 0 ) {
            ans += abs(x*cntl-sum[cntl-1]);
        }

        if ( cntr == n ) {
            ans += abs(x*n-sum[n-1]);
        } else if ( cntr > 0 ) {
            ans += abs(x*cntr-(sum[n-1]-sum[n-cntr-1]));
        }
        cout << ans << endl;
    }

}