#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

long long gcd ( long long a, long long b ) {
    long long r;

    while ( r = a%b ) {
        a = b;
        b = r;
    }
    return b;
}

int main()
{
    int n;
    vector<ll> a;
    ll b = 1;

    cin >> n;
    a = vector<ll>(n);
    for ( auto& v : a )cin >> v;

    long long gcdv = gcd(a[0], a[1]);
    for ( auto v : a ) gcdv = gcd(gcdv, v); 
    for ( auto& v: a ) v /= gcdv;

    ll ans = 0;

    for ( auto& v: a ) {
        while(v%2==0) {
            v /= 2;
            ++ans;
        }
        while(v%3==0) {
            v /= 3;
            ++ans;
        }
        if ( v != 1 ) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;

}