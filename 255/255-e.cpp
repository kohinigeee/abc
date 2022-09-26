#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;

int main()
{
    int n, m;
    vector<ll> s;
    vector<ll> x;
    vector<ll> dis;
    map<ll, int> mp;

    cin >> n >> m;
    for ( int i = 1; i < n; ++i ) {
        ll tmp; cin >> tmp; s.push_back(tmp);
    }

    for ( int i = 0; i < m; ++i ) {
        ll tmp; cin >> tmp; x.push_back(tmp);
    }

    dis = vector<ll>(n, 0);

    for ( int i = 1; i < n; ++i ) {
        dis[i] = s[i-1]-dis[i-1];
    }

    int ans = 0;

    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < m; ++j ) {
            int tmp = 1;
            if ( i%2 ) tmp *= -1;

            ll c = (x[j]-dis[i])*tmp;

            if ( mp.find(c) == mp.end() ) mp[c] = 1;
            else mp[c] += 1;
            ans = max(ans, mp[c]);
        }

    }

    cout << ans << endl;
}