#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

using ll = long long;

int main()
{
    ll x, a, d, n;
    ll ans;

    cin >> x >> a >> d >> n;

    ll tmpx = x;
    ll hasi = a+(n-1)*d;

    ll l = min(a, hasi);
    ll r = max(a, hasi);

    if ( x <= l ) {
        ans = abs(x-l);
    } else if ( x >= r ) {
        ans = abs(x-r);
    } else {
        ll upx = x;
        ll downx = x;

        while(1) {
            if ( (upx-a)%d == 0 ) break;
            ++upx;
        }
        while(1) {
            if ( (downx-a)%d == 0 ) break;
            --downx;
        }
        ans = min(abs(upx-x), abs(downx-x));
    }

    cout << ans << endl;
}