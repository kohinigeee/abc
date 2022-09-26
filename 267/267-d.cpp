#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

int main()
{
    int m, n;
    vector<ll> a;
    vector<ll> sum;

    cin >> n >> m;
    a = vector<ll>(n, 0);
    sum = vector<ll> (n+1, 0);

    for ( int i = 0; i < n; ++i ) cin >> a[i];
    // sum[0] = a[0];
    for ( int i = 1; i <= n; ++i ) {
        sum[i] = sum[i-1] + a[i-1];
    }

    ll tmp = 0;
    for ( int k = 0; k < m; ++k ) {
        tmp += a[k]*(k+1);
    }
    ll ans = tmp;
    // cout  << "tmp asn = " << ans << endl;

    for ( int k = m; k < n; ++k ) {
        tmp = tmp-(sum[k]-sum[k-m]);
        tmp += m*a[k];
        ans = max(ans,tmp);
    }

    cout << ans << endl;
}