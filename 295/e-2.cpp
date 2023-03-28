#include<iostream>
#include<vector>

using namespace std;
using ll = long long;
const ll M = 998244353;

long long comb[2500][2500];

ll power2(ll x, ll y ) {
    ll ans = 1;
    ll ord = x;

    while( y > 0 ) {
        if ( y & 1 ) {
            ans *= ord;
            ans %= M;
        }
        ord *= ord;
        ord %= M;
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

int main(){
    
    for ( int i = 0; i < 2500; ++i ) comb[i][0] = 1;
    comb[1][1] = 1;

    for ( int i = 2; i < 2500; ++i ) {
        for ( int j = 1; j <= i; ++j ) {
            comb[i][j] = comb[i-1][j-1]+comb[i-1][j];
            comb[i][j] %= M;
        }
    }

    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);

    for ( int i = 0; i < n; ++i ) cin >> a[i];
    ll ans = 0;

    for ( int i = 1; i <= m; ++i ) {
        int zero = 0, rem = n-k+1;

        for ( int j = 0; j < n; ++j ) {
            if ( a[j] >= i ) --rem;
            if ( a[j] == 0 ) ++zero;
        }

        if ( rem < 0 || zero < rem ) {
            ans += ( rem < 0  ? 1 : 0);
            continue;
        }

        ll p = (m-i+1)*rev(m)%M;
        // ll q = (1-p)%M;
        // if ( q < 0 ) q += M;

        vector<ll> p_pow(zero+1);
        vector<ll> q_pow(zero+1); 
        p_pow[0] = 1;
        q_pow[0] = 1;
        ll tmp = 1-p%M;
        if ( tmp < 0 ) tmp += M;
        for ( int j = 1; j <= zero; ++j ) {
            p_pow[j] = p_pow[j-1]*p%M;
            q_pow[j] = q_pow[j-1]*(tmp)%M;
            // if ( q_pow[j] < 0 ) q_pow[j] += M;
        }

        for ( int j = rem; j <= zero; ++j ) {
            ans += comb[zero][j]%M*p_pow[j]%M*q_pow[zero-j];
            ans %= M;
        }
    }

    cout << ans%M << endl;
}