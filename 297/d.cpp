#include<iostream>

using ll = long long;
using namespace std;

int main()
{
    ll a, b;
    ll ans = 0;

    cin >> a >> b;
    while( a != b ) {
        if ( a < b ) swap(a,b);
        ll dis = (a-b);
        ll cnt = dis/b;
        if ( dis%b ) ++cnt;
        a -= cnt*b;
        ans +=  cnt;
    }

    cout << ans << endl;
}