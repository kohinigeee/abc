#include<iostream>
#include<vector>
#include<map>

using namespace std;
using ll = long long;

map<ll,ll> mp3;
map<ll,ll> mp2;

ll func( ll n ) {
    if ( mp2.find(n) != mp2.end() ) return mp2[n];

    ll tmp2 = n/2;
    ll tmp3 = n/3;
    ll v2, v3;
    if ( mp2.find(tmp2) == mp2.end() ) {
        v2 = func(tmp2);
    } else v2 = mp2[tmp2];
    if ( mp2.find(tmp3) == mp2.end() ) v3 = func(tmp3);
    else v3 = mp2[tmp3]; 

    mp2[n] = v2+v3;
    return v2+v3;
}

int main()
{
    ll n;

    cin >> n;
    mp2[0] = 1;
    cout << func(n) << endl;
}