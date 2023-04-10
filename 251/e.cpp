#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;
using ll = long long;

const ll inf = (1LL<<60);

int main()
{
    int n; cin >> n;
    vector<ll> a(n);

    for ( int i = 0; i < n; ++i ) cin >> a[i];

    vector<vector<ll>> dp0(n, vector<ll>(2,-1));
    vector<vector<ll>> dp1(n, vector<ll>(2,-1));

    dp0[0][0] = 0; dp0[0][1] = inf;

    for ( int i = 1; i < n; ++i ) {
        dp0[i][0] = dp0[i-1][1];
        dp0[i][1] = min(dp0[i-1][0], dp0[i-1][1])+a[i];
    }

    ll ans0 = dp0[n-1][1];

   dp1[0][0] = inf; dp1[0][1] = a[0];
   for ( int i = 1; i < n; ++i ) {
        dp1[i][0] = dp1[i-1][1];
        dp1[i][1] = min(dp1[i-1][0], dp1[i-1][1])+a[i];
   }
   ll ans1 = min(dp1[n-1][0], dp1[n-1][1]);


    cout << min(ans1, ans0) << endl;
}