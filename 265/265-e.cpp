#include<iostream>
#include<map>
#include<utility>
#include<set>
#include<vector>
#include<cstdio>

#define MOD 998244353
#define N 300

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
// using ll = long long;


//first:x座標 second:y座標
int n, m;

vector<ll> dx(3,0);
vector<ll> dy(3,0);

pll func( const pll& p, int i, int j, int k) {
    pll tmp = p;
    tmp.first += dx[0]*i+j*dx[1]+k*dx[2];
    tmp.second += dy[0]*i+j*dy[1]+k*dy[2];
    return tmp;
}

int main()
{
    // vector<map<pll,ll>> moves;
    // cout << "test1" << endl;
    set<pll> obs;
    cin >> n >> m;
    cin >> dx[0] >> dy[0] >> dx[1] >> dy[1] >> dx[2] >> dy[2];
    for ( int i = 0; i < m; ++i ) {
        ll x, y; cin >> x >> y;
        obs.insert(make_pair(x,y));
    }

    // ll dp[N+1][N+1][N+1];
    // vector<vector<vector<ll>>> dp = vector<vector<vector<ll>>>( N+1, vector<vector<ll>>(N+1, vector<ll>(N+1, 0)));
    vector<vector<ll>> dp = vector<vector<ll>>(N+1, vector<ll>(N+1, 0));
    dp[0][0] = 1;

    for ( int i = 1; i <= n; ++i ) {

        vector<vector<ll>> tmpdp = vector<vector<ll>>(N+1, vector<ll>(N+1, 0));
        for ( int j = 0; j <= i; ++j ) {
            for ( int k = 0; j+k <= i; ++k ) {
                int s = i-j-k;

                pll p = func(make_pair(0,0), j, k, s);
                if ( obs.find(p) != obs.end() ) continue;
                pll tmp = p;
                ll cnt = 0;
                
                if ( j >= 1  ) {
                    cnt += dp[j-1][k];
                    cnt %= MOD;
                }
                if ( k >= 1 ) {
                    cnt += dp[j][k-1];
                    cnt %= MOD;
                }
                if ( s >= 1 ) {
                    cnt += dp[j][k];
                    cnt %= MOD;
                }
                tmpdp[j][k] = cnt;
                // printf("i = %d, j = %d, k = %d, s = %d, cnt = %d\n", i, j, k, s, cnt);
            }
        }
        dp = tmpdp;
    }

    ll ans = 0;
    for ( int i = 0; i <= n; ++i ) {
        for ( int j = 0; i+j <= n; ++j ) {
            ans += dp[i][j];
            ans %= MOD;
        }
    }
    cout << ans << endl;
}
