#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

int main()
{
    int n, k;
    
    cin >> n >> k;
    vector<ll> a(n), b(n);
    vector<int> a_ok(n), b_ok(n);

    for ( int i = 0; i < n; ++i ) cin >> a[i];
    for ( int i = 0; i < n; ++i ) cin >> b[i];

    a_ok[0] = b_ok[0] = 1;

    for  (int i = 1; i < n; ++i ) {
        if ( a_ok[i-1] ) {
            ll tmp = a[i-1]+k;
            ll tmp2 = a[i-1]-k;
            if ( (tmp2 <= a[i]) && (a[i] <= tmp) ) a_ok[i] = 1;
            if ( tmp2 <= b[i] && b[i] <= tmp ) b_ok[i] = 1;
        }

        if ( b_ok[i-1] ) {
            ll tmp = b[i-1]+k;
            ll tmp2 = b[i-1]-k;
            if ( tmp2 <= a[i] && a[i] <= tmp ) a_ok[i] = 1;
            if ( tmp2 <= b[i] && b[i] <= tmp ) b_ok[i] = 1;
        }
    }

    if ( a_ok[n-1] || b_ok[n-1] ) cout << "Yes" << endl;
    else cout << "No" << endl;
}