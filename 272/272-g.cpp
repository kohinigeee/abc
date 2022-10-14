#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

ll findm(vector<ll> vec ) {
    int cnt = 1;
    ll v = vec[0];

    for ( int i = 1; i < vec.size(); ++i ) {
        if ( v == vec[i] ) { ++cnt; continue; }
        if ( cnt == 0 ) { v = vec[i]; ++cnt; }
        else --cnt;
    }
    
    cnt = 0;
    int border = vec.size()/2+1;

    for ( const auto& x : vec ) if ( v == x ) ++cnt;
    return ( cnt >= border ) ? v : -1; 
}

vector<ll> getPrimes( ll x ) {
    vector<ll> primes;
    vector<ll> d(x+1, 1);

    for ( ll i = 2; i <= x; i += 2 ) d[i] = 0;

    for ( ll i = 3; i <= x; ++i ) {
        if ( !d[i] ) continue;
        for ( ll j = i*2; j <= x; j += i ) d[j] = 0;
    }

    d[4] = 1;
    for ( ll i = 3; i <= x; ++i ) if ( d[i] ) primes.push_back(i);

    return primes;
}

ll findM( ll a, ll b , vector<ll> A, vector<ll>& primes ) {
    ll x = abs(A[a]-A[b]);

    if ( x <= 2 ) return -1;

    for ( const auto p : primes ) {
        if ( p*p > x ) break;
        if ( x%p != 0 ) continue;
        vector<ll> tmp = A;
        for ( auto& v : tmp ) v %= p;
        ll m = findm(tmp);
        if ( m != -1 ) return p;
    }
    vector<ll> tmp = A;
    for ( auto& v : tmp ) v %= x;
    ll m = findm(tmp);
    if ( m != -1 ) return x;

    return -1;
}

int main()
{
    vector<ll> prime;
    vector<ll> A;
    ll ans = -1;
    int n;

    prime = getPrimes(40000);

    cin >> n;
    A = vector<ll>(n);
    for ( auto& v: A ) cin >> v;
    sort(A.begin(), A.end());

    if ( findm(A) != -1 ) { cout << 3 << endl; return 0; }

    ans = findM(0, 2, A, prime);

    for ( int i = 0; i+1 < n; ++i ) {
        ll m = findM(i, i+1, A, prime);
        if ( m != -1 ) { ans = m; break; } 
    }
    cout << ans << endl;
}