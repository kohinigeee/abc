#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

ll n, p, q, r;
vector<ll> a;
vector<ll> sum;

bool func( int x ) {
    ll P = p+sum[x]-a[x];
    ll Q = p+q+sum[x]-a[x];
    ll R = p+q+r+sum[x]-a[x];
    bool f1 = binary_search(sum.begin(), sum.end(), P);
    bool f2 = binary_search(sum.begin(), sum.end(), Q);
    bool f3 = binary_search(sum.begin(), sum.end(), R);

    return (f1 && f2 && f3 );
}

int main()
{

    cin >> n >> p >> q >> r;
    a = vector<ll>(n,0);
    sum = vector<ll>(n,0);
    for ( int i = 0; i < n; ++i ) cin >> a[i];
    sum[0] = a[0];
    for ( int i = 1; i < n; ++i ) sum[i] += sum[i-1]+a[i];
    // for ( int i = 0; i < n; ++i ) cout << sum[i] << " "; cout << endl;


    // if ( ! ( p < q && q < r ) ) { cout << "No" << endl; return 0;} 
    for ( int i = 0; i < n; ++i ) {
        if ( func(i) ) { cout << "Yes" << endl; return 0; }
    }
    cout << "No" << endl;
}