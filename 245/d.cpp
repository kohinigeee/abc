#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

int main()
{
    int n, m;

    cin >> n >> m;
    vector<ll>a(n+1), b(m+1);
    vector<ll>c(n+m+1);
    vector<ll>tmpc(n+m+1);

    for ( int i = 0; i <= n; ++i ) cin >> a[i];
    for ( int i = 0; i <= n+m; ++i ) {
        cin >> c[i];
        tmpc[i] = c[i];
    }

    for ( int i = m; i >= 0; --i ) {
        b[i] = c[n+i]/a[n];
        
        for ( int j = n-1; j >= 0; --j ) {
            c[i+j] -= a[j]*b[i];
        }
    }

    for ( auto v : b ) cout << v << " "; cout << endl;
}