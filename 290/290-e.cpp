#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

ll kousoku2(ll x, int y, ll p ) {
    ll ans = 1;
    ll base = x;
    while( y > 0 ) {
        if ( y&1 ) {
            ans *= base;
            ans %= p;
        }
        base *= base;
        base %= p;
        y = y >> 1;
    }
    return ans;
}

ll rev_mod(ll x, ll p ) {
    return kousoku2(x, p-2, p);
}


int main()
{
   vector<ll> dp;
   ll n;
   ll p;

   cin >> n; 
   cin >> p;

   dp = vector<ll>(n+1, -1);

   dp[0] = 0; dp[1] = 1;

   const ll modp = 998244353;
   ll rev100 = rev_mod(100, modp); 
   for ( ll x = 2; x <= n; ++x ) {
    dp[x] = (dp[x-2]+1)*p%modp+(dp[x-1]+1)*(100-p)%modp;
    dp[x] = dp[x]*rev100%modp;
   }

   cout << dp[n] << endl;
   
}