#include<iostream>
#include<set>

using namespace std;
using ll = long long;

int main()
{
    set<ll> s;
    int n;
    ll x;

    cin >> n  >> x;
    for ( int i = 0; i < n; ++i ) {
        ll a; cin >> a;
        s.insert(a);
    }

    string ans = "No";
    for ( ll it : s ) {
        ll tmpx = it+x;
        if ( s.find(tmpx) != s.end() ) ans = "Yes"; 
    }

    cout << ans << endl;
}