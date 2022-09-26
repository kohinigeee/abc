#include<iostream>
#include<vector>

using namespace std;

using ll = long long;

ll sigma( ll a, ll d, ll n ) {
    ll an = a+d*(n-1);
    return (a+an)*n/2;
}

ll euclid(ll a, ll b ) {
    ll r;
    while( (r=a%b) ) {
        a = b;
        b = r;
    }
    return b;
}

int main()
{
    ll n;
    ll a,b;

    cin >> n >> a >> b;

    if ( a == 1 || b == 1 ) { cout << 0 << endl; return 0;}

    ll gcd = euclid(a,b);
    ll lcm = a*(b/gcd);

    ll ans = n*(n+1)/2;

    ans -= sigma(a, a, n/a);
    ans -= sigma(b, b, n/b);
    ans += sigma(lcm, lcm, n/lcm);

    cout << ans << endl;

}