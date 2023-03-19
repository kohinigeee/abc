#include<iostream>
#include<vector>
#include<utility>

using namespace std;
using ll = long long;

int main()
{
    ll L, n1, n2;
    vector<pair<ll,ll>> v1, v2;
    
    cin >> L >> n1 >> n2;
    for ( int i = 0; i < n1; ++i ) {
        ll l, v; cin >> v >> l;
        v1.push_back(make_pair(v,l));
    }
    for ( int i = 0; i < n2; ++i ) {
        ll l, v; cin >> v >> l;
        v2.push_back(make_pair(v,l));
    }


    int idx1 = 0, idx2 = 0; 
    ll now_value1 = -1, now_value2 = -1;
    ll now_l1 = 0, now_l2 = 0;
    ll now_r1 = 0, now_r2 = 0;
    ll ans = 0;

    while(now_r1 < L || now_r2 < L) {
        if ( now_r1 <= now_r2 ) {
            now_value1 = v1[idx1].first;
            now_l1 = now_r1;
            now_r1 += v1[idx1].second;
            ++idx1;
        } else {
            now_value2 = v2[idx2].first;
            now_l2 = now_r2;
            now_r2 += v2[idx2].second;
            ++idx2;
        }

        if ( now_value1 == now_value2 ) {
            ll l = max(now_l1, now_l2);
            ll r = min(now_r1, now_r2);
            ans += r-l;
        }
    }

    cout << ans << endl;
}