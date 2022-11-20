#include<vector>
#include<iostream>
#include<cmath>

#define MAXV 20000
using namespace std;
using ll = long long;

ll n;
ll x, y;

bool canMake( vector<ll>& a, ll x ) {
    // cout << "Make " << endl;
    if ( a.size() == 0 ) {
        if ( x == 0 ) return true;
        else return false;
    }

    vector<ll> cnt(2*MAXV+5, -10);

    cnt[a[0]+MAXV] = 0;
    cnt[-a[0]+MAXV] = 0;

    for ( int i = 1; i < a.size(); ++i ) {
        // cout << "i = " << i << endl;
        vector<ll> res;

        for ( ll v = -MAXV; v <= MAXV; ++v ) {
            if ( cnt[v+MAXV] == i-1 ) {
                res.push_back(v+a[i]+MAXV);
                res.push_back(v-a[i]+MAXV);
            }
        }
        for ( auto v : res ) {
            // cout << "v = " << v << endl;
            if ( v < 0 || v > 2*MAXV ) continue;
            else cnt[v] = i;
        }
    }
    if ( cnt[x+MAXV] == a.size()-1 ) return true;
    else return false;
}

int main()
{
    cin >> n >> x >> y;

    vector<ll> even;
    vector<ll> odd;
    ll a1;

    cin >> a1;
    x = abs(x-a1);

    for ( int i = 2; i <= n; ++i ) {
        ll a; cin >> a;
        if ( i%2 == 1 ) odd.push_back(a);
        else even.push_back(a);
    }

    if ( canMake(odd, x) && canMake(even, y) ) cout << "Yes" << endl;
    else cout << "No" << endl;
}