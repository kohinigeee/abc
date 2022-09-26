#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

int take_bit(ll x, int d ) { // x の　d桁めをとる
    return (x>>d) & 1;
}

int main()
{
    ll n, c;
    vector<int> t;
    vector<ll> a;


    cin >> n >> c;
    vector<vector<int>> ans(n, vector<int>(31, 0));
    for ( int i = 0; i < n; ++i ) {
        int tmpt; ll tmpa;
        cin >> tmpt >> tmpa;
        t.push_back(tmpt); a.push_back(tmpa);
    }

    // cout << "test" << endl;

    for ( int i = 0; i < 31; ++i ) {
        int d = i;
        vector<int> dp1(n+1, 1);
        vector<int> dp0(n+1, 0);

        for ( int j = 1; j <= n; ++j ) {
            int ti = t[j-1]; ll ai = a[j-1];
            if ( ti == 1 ) {
                dp1[j] = dp1[j-1]&take_bit(ai, d);
                dp0[j] = dp0[j-1]&take_bit(ai, d);
            } else if ( ti == 2 ) {
                dp1[j] = dp1[j-1]|take_bit(ai,d);
                dp0[j] = dp0[j-1]|take_bit(ai,d);
            } else {
                dp1[j] = dp1[j-1]^take_bit(ai,d);
                dp0[j] = dp0[j-1]^take_bit(ai,d);
            }
        }

        int ci = take_bit(c,d);
        for ( int j = 1; j <= n; ++j ) {
            if ( ci == 0 ) ci = dp0[j];
            else ci = dp1[j];
            ans[j-1][i] = ci;
        }
    }

    for ( int i = 0; i < n; ++i ) {
        ll sum = 0;
        ll base = 1;
        for ( int j = 0; j < 31; ++j ) {
            sum += base*ans[i][j];
            base *= 2;
        }
        cout << sum << endl;
    }
}