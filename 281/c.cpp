#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

int main()
{
    int n;
    ll t;
    vector<ll> a;

    cin >> n >> t;
    a = vector<ll>(n);
    ll sum = 0;

    for ( int i = 0; i < n; ++i ) {
        cin >> a[i];
        sum += a[i];
    }

    t %= sum;
    int no;
    for ( int i = 0; i < n; ++i ) {
        if ( a[i] > t ) {
            no = i+1;
            break;
        }
        t -= a[i];
    }

    cout << no << " " << t << endl;
}