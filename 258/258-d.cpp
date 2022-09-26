#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

using ll = long long;

int main()
{
    vector<ll> a, b;
    ll n, x;
    ll sum = 0;
    ll minb = (1LL<<60);
    ll ans = (1LL<<60);

    cin >> n >> x;
    a = vector<ll>(n,0); b = vector<ll>(n,0);

    for ( int i = 0; i < n; ++i ) cin >> a[i] >> b[i];
    for ( int i = 0; i < n; ++i ) {
        ll score = 0;
        sum += a[i]+b[i];
        minb = min(minb, b[i]);

        ll k = x-i-1;
        if ( k < 0 ) break;
        score = sum+k*minb;
        ans = min(score, ans);
    }

    cout << ans << endl;
}