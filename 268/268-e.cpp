#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;
using ll = long long;

int main()
{
    int n;
    vector<ll> sum;
    vector<ll> sum_rev, d, d_rev;

    cin >> n;
    sum = vector<ll>(2*n, 0);
    sum_rev = vector<ll>(2*n, 0);
    d = vector<ll>(2*n, 0), d_rev = vector<ll>(2*n, 0);

    for ( int i = 0; i < n; ++i ) {
        int p; cin >> p;
        // if ( p != 5 ) continue;
        int t;
        if ( p <= i ) t = n-(i-p);
        else t = p-i;

        int r = t+n/2;
        sum[t+1] += 1; sum[r+1] -= 1;
        sum_rev[t+n-1] += 1; 
        sum_rev[r] -= 1;

        d[r+1] -= (n/2);
        d_rev[r] -= (n-1)/2;
    }


    for ( int i = 1; i < sum.size(); ++i ) {
        sum[i] += sum[i-1];
        sum_rev[sum_rev.size()-1-i] += sum_rev[sum_rev.size()-i];
    }

    for ( int i = 0; i < sum.size(); ++i ) { sum[i] += d[i]; sum_rev[i] += d_rev[i];}
    for ( int i = 1; i < sum.size(); ++i ) {
        sum[i] += sum[i-1];
        sum_rev[sum_rev.size()-1-i] += sum_rev[sum_rev.size()-i];
    }

    // cout << endl;
    // for ( int i = 0; i < 2*n; ++i ) printf("%2d ", i); cout << endl;
    // for ( auto v: sum ) printf("%2d ", v); cout << endl;
    // for ( auto v: sum_rev) printf("%2d ", v); cout <<endl;

    long long ans = (1LL<<60);

    for ( int i = 0; i < n; ++i ) {
        long long tmp = sum[i]+sum[i+n];
        tmp += sum_rev[i]+sum_rev[i+n];
        ans = min(ans, tmp);
    }
    // cout << endl;

    cout << ans << endl;
}