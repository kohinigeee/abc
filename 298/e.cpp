#include<iostream>
#include<vector>
#include<queue>

using namespace std;
using ll = long long;

const ll MOD = 998244353;

ll kousoku(ll x, ll y ) {
    ll ans = 1;
    ll ord = x;

    while( y > 0 ) {
        if ( y & 1 ) {
            ans *= ord;
            ans %= MOD;
        }
        ord *= ord;
        ord %= MOD;
        y = (y>>1);
    }

    return ans;
}

int main()
{
    int q;
    ll val = 1;
    ll ord = 1;
    queue<int> que;

    que.push(1);
    cin >> q;
    for ( int i = 0; i < q; ++i ) {
        int cmd; cin >> cmd;
        if ( cmd == 1 ) {
            int x; cin >> x;
            val = (val*10+x);
            val %= MOD;
            ++ord;
            que.push(x);
        } else if ( cmd == 2 ) {
            ll x = que.front(); que.pop();
            x = x*kousoku(10, que.size())%MOD;
            val = val-x;
            if ( val < 0 ) val += MOD;
        } else {
            cout << val << endl;
        }
    }
}