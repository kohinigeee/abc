#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>

using namespace std;
using ll = long long;

ll a, b;

double calc(ll n ) {
    return a/sqrt(n)+(n-1)*b;
}

int func(ll n ) {

    double r = calc(n+1)-calc(n);
    double l = calc(n-1)-calc(n);

    if ( r >= 0 && l >= 0 ) return 0;
    if ( r >= 0 && l < 0 ) return 1;
    if ( r < 0 && l >= 0 ) return -1;
    return 2;
}

int main()
{
   ll l = 1, r = (1LL<<30);
   cin >> a >> b;
   ll m;

   double tmp = calc(1)-calc(2);

   if ( tmp <= 0 ) {
    double ans = calc(1);
    printf("%.9lf\n", ans);
   }

   while(r-1 > l ) {
    ll mid = (l+r)/2;
    int result = func(mid);
    if ( result == 0 ) {
        m = mid;
        break;
    }
    if ( result == 1 ) {
        r = mid;
    }
    if ( result == -1 ) {
        l = mid;
    }
    }

    double ans = calc(m);
    printf("%.9lf\n", ans);
}