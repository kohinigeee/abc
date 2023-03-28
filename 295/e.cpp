#include<iostream>
#include<vector>

#define M (998244353LL)

using ll = long long;
using namespace std;

ll power2(ll x, ll y ) {
    if ( x == 0 ) return 1;
    ll ans = 1;
    ll ord = 1;

    while( y > 0 ) {
        ord *= ord;
        ord %= M;
        if ( y & 1 ) {
            ans *= ord;
            ans %= M;
        }
        y = y>>1;
    }
    return ans;
}

ll rev(ll x) {
    return power2(x, M-2);
}

vector<ll> make_cmb(ll n) {
    vector<ll> ans(n+1,1);

    for ( ll i = 1; i <= n; ++i ) {
        ans[i] = ans[i-1]*(n-i+1)/i;
    }
    return ans;
}

int main()
{
    int n, m, k;
    ll ans = 0;
    vector<int> a;
    int cnt_0 = 0;

    cin >> n >> m >> k;

    a = vector<int>(n);
    for ( int i = 0; i < n; ++i ) {
        cin >> a[i];
        if ( a[i] == 0 ) ++cnt_0;
    }

    ll tmpm = rev(power2(m, cnt_0));
    for ( int i = 1; i <= m; ++i ) {
        cout << "i = " << i << endl;
        int s = 0;
        for ( int j = 0; j < n; ++j ) {
            if ( a[j] >= i ) ++s;
        }

        int u = max(0, n-k+1-s);
        cout << "s = " << s << ", u = " << u << endl;
        vector<ll> cmb = make_cmb(cnt_0);
        ll sum = 0;
        for ( int j = u; j <= cnt_0; ++j ) {
            cout << "j = " << j << endl;
            ll tmp1 = power2(m-i+1, j);
            ll tmp2 = power2(i-1, cnt_0-j);
            cout << "tmp1 = " << tmp1 << ", tmp2 = " << tmp2 << endl;
            sum += cmb[j]%M*tmp1%M*tmp2%M*tmpm%M;
        }

        cout << "sum = " << sum << endl;
        ans += sum;
        ans %= M;
    }

    cout << ans << endl;
}