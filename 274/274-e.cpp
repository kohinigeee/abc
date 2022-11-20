#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<cmath>
#include<string>
#include<bitset>
#include<cstdio>

#define INF (1LL<<60)

using namespace std;
using t_set = int;
using ll = long long;
using pll = pair<ll,ll>;

int n;
int m;
ll maxset;

//縦軸が集合 横軸が最後の点
//j番目(0 origin)の宝箱はn+j番目
vector<vector<ll>> dp(maxset, vector<ll>(n+m));

int take_bit(t_set x, int i) {
    return (x>>i)&1;
}

double calDis(pll p1, pll p2 ) {
    ll dx = p1.first-p2.first;
    ll dy = p1.second-p2.second;
    return sqrt(dx*dx+dy*dy);
}

int noOfBoosts( t_set x ) {
    int ans = 0;
    for ( int i = 0; i < m; ++i ) {
        ans += take_bit(x, i+n);
    }
    return ans;
}

int main()
{
    vector<pll> towns, tres;
    vector<pll> pos;

    cin >> n >> m;
    maxset = (1LL<<(n+m));
    
    for ( int i = 0; i < n+m; ++i ) {
        ll x, y; cin >> x >> y;
        pos.push_back(make_pair(x,y));
    }
    // for ( int i = 0; i < n; ++i ) {
    //     ll x, y; cin >> x >> y;
    //     towns.push_back(make_pair(x,y));
    // }
    // for ( int i = 0; i < m; ++i ) {
    //     ll p, q; cin >> p >> q;
    //     tres.push_back(make_pair(p,q));
    // }

    vector<vector<double>> dp(maxset, vector<double>(n+m, INF));
    queue<pair<t_set,int>> que;

    for ( int i = 0; i < n+m; ++i ) {
       t_set s = (1<<i);
       dp[s][i] = calDis(pos[i], make_pair(0,0));
    }

    for ( int s = 1; s < maxset; ++s ) {
        for ( int a = 0; a < m+n; ++a ) {
            for ( int b = 0; b < m+n; ++b ) {
                //a から bへの辺が移動が存在する
                if ( a == b ) continue;
                if ( take_bit(s, a) && take_bit(s, b) ) {
                    t_set prev = (~(1<<b) & s );
                    int speed = 1<<noOfBoosts(prev);
                    double dis = calDis(pos[a], pos[b]);
                    dp[s][b] = min(dp[s][b], dp[prev][a]+(dis/speed));
                }
            }
        }
    }

    // cout << "test2" << endl;
    double ans = INF;

    t_set s = (1<<(n))-1;
    // cout << "s = " << bitset<3>(s) << endl;
    for ( int i = 0; i <= m; ++i ) {
        s = (s|(1<<(n-1+i)));
        // cout << "s = " << bitset<3>(s) << endl;
        int speed = 1<<i;

        // cout << "s = :" << bitset<3>(s) << endl;
        for ( int j = 0; j < n+i; ++j ) {
            double dis = calDis(make_pair(0,0), pos[j])/speed;
            dis += dp[s][j];
            ans = min(ans, dis);
        }
    }
    // cout << "test3" << endl;
    printf("%.9lf\n", ans);

  
}