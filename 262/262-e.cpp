#include<iostream>
#include<vector>
#include<algorithm>

#define MODK 998244353

using namespace std;
using ll = long long;

class Combo {
    public:
    long long n, p;
    vector<long long> inv, fac, finv;

    public:
    Combo ( long long n1, long long p1 ) {
        n = n1; p = p1;
        inv = vector<long long>(n+1, -1);
        fac = vector<long long>(n+1, -1);
        finv = vector<long long>(n+1, -1);

        fac[0] = fac[1] = 1;
        inv[1] = 1;
        inv[0] = 1;

        for ( long long i = 2; i <= n; ++i ) {
            fac[i] = fac[i-1]*i;
            fac[i] %= p;
            inv[i] = p-inv[p%i]*(p/i)%p;
            finv[i] = finv[i-1]*inv[i]%p;
        }
    }

    long long get( long long s, long long t ) { // s C t を求める
        if ( s > n ) return 0;
        if ( t < 0 || t > s ) return 0;
        if ( t == 0 || s == t ) return 1;

        return fac[s]*finv[s-t]%p*finv[t]%p;
    }
};


int main()
{
    vector<int> d;
    int n, m, k;
    ll ans = 0;
    ll odd = 0;

    cin >> n >> m >> k;
    d = vector<int>(n, 0);

    Combo com = Combo(n, MODK);

    for ( int i = 0; i < m; ++i ) {
        int u, v; cin >> u >> v;
        --u; --v;
        ++d[u]; ++d[v];
    }

    for ( int i = 0; i < n; ++i ) {
        if ( d[i] % 2 == 1 ) ++odd;
    }

    ll even = n-odd;

    for ( int i = 0; i <= min(int(odd), int(k) ); i += 2 ) {
        ans += com.get(odd, i) * com.get(even, (k-i)) %MODK;
        ans %= MODK;
    }
    cout << ans << endl;
}