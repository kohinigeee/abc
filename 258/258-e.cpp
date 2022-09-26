#include<iostream>
#include<vector>
#include<map>

using namespace std;
using ll = long long;

int main()
{
    ll n, q, x;
    vector<ll> w;
    vector<ll> next;
    ll sumw = 0;

    cin >> n >> q >> x;
    w = vector<ll>(n, 0);
    next = vector<ll>(n, -1);
    vector<int> check = vector<int>(n, 0);

    for ( int i = 0; i < n; ++i ) { cin >> w[i]; sumw += w[i]; }

    ll N = x/sumw;
    x = x-N*sumw;

    ll sum = 0;
    ll l = 0, r = 0;

    while( l < n ) {
        while( sum < x ) {
            sum += w[r];
            ++r; if ( r >= n ) r -= n;
        }
        while( l < n && sum >= x ) {
            next[l] = r;
            sum -= w[l]; ++l;
        }
    }

    // for ( auto v : next ) cout << v << " "; cout << endl;

    int st = 0; //周期の最初
    int syuki = 0;
    int cnt = 0;
    while(1) {
        if ( check[st] > 0 ) {
            syuki = cnt-check[st]+1;
            break;
        }
        check[st] = ++cnt;
        st = next[st];
    }

    map<int, int> mp; // key = 箱の番目, value = どの芋になるのか
  

    for ( int i = 0; i < n; ++i ) {
        if ( check[i] > 0 ) mp[check[i]] = i;
    }

    for ( int i = 0; i < q; ++i ) {
        ll k; cin >> k;

        if ( x == 0 ) {
            cout << n*N << endl; continue;
        }

        if ( k < check[st] ) {
            int simo = mp[k];
            int ans = next[simo]-simo;
            if ( ans <= 0 ) ans += n;
            ans += n*N;
            cout << ans << endl;
            continue;
        } else {
            k -= check[st];
            k %= syuki;
            // cout << "k = " << k << endl;
            int simo = mp[check[st]+k];
            int ans = next[simo]-simo;
            if ( ans <= 0 ) ans += n;
            ans += n*N;
            // cout << "ans = " << ans << endl;
            cout << ans << endl;
            continue;
        }
    }

}