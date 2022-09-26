#include<iostream>
#include<vector>
#include<iostream>

#define MAXT 100000

using namespace std;

using ll = long long;
using vl = vector<ll>;

class Sunuke {
    public:
    ll t, x, a;
    
    Sunuke ( ll t1, ll x1, ll a1 ) : t(t1), x(x1), a(a1) {}
};

vector<vl> dp = vector<vl>(MAXT+1, vl(5, 0));

int main()
{
    ll n;
    vector<Sunuke> v;

    int cnt = 0;

    cin >> n;
    for ( int i = 0; i < n; ++i ) {
        ll t, x, a; cin >> t >> x >> a;
        if ( x > t ) continue;
        v.push_back(Sunuke(t,x,a));
    }

    v.push_back(Sunuke(MAXT+10, -1, 0));

    for ( ll i = 1; i <= MAXT; ++i ) {
        for ( int j = 0; j < 5; ++j ) {
            if ( i > 0 ) dp[i][j] = dp[i-1][j];
            for ( int k = 1; k < 4; ++k ) {
                ll tmpi1 = i-k;
                ll tmpj1 = j+k; ll tmpj2 = j-k;

                if ( tmpi1 >= 0 && tmpj1 < 5 ) {
                    dp[i][j] = max(dp[i][j], dp[tmpi1][tmpj1]);
                }
                if ( tmpi1 >= 0 && tmpj2 >= 0 ) {
                    dp[i][j] = max(dp[i][j], dp[tmpi1][tmpj2]);
                }
            }
            if ( v[cnt].t == i && v[cnt].x == j ) dp[i][j] += v[cnt++].a;
        }
    }

    ll ans = 0;
    for ( int i = 0; i < 5; ++i ) {
        ans = max(ans, dp[MAXT][i]);
    }
    cout << ans << endl;
}