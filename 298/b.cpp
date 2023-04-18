#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>

using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

using shrink_type = long long;
class Shrink {
    vector<int> ord;

    public:
    Shrink( const vector<shrink_type>& v ) {
        set<shrink_type> s;

        for ( auto i : v ) s.insert(i);
        for ( auto i : s ) ord.push_back(i);
    }

    int get(shrink_type x ) {
        if ( x < ord[0] ) return -1;
        // if ( x > ord.back() ) return ord.size()+1;
        auto it = lower_bound(ord.begin(), ord.end(), x);
        return it-ord.begin();
    }

    vector<int> get_array(const vector<shrink_type>& v ) {
        vector<int> ans(v.size());
        for ( int i = 0; i < v.size(); ++i ) ans[i] = get(v[i]);
        return ans;
    }

};

int main()
{
    int n;
    cin >> n;

    vector<shrink_type> tmpr(n), tmpc(n);
    vector<ll> x(n);

    for ( int i = 0; i < n; ++i ) cin >> tmpr[i] >> tmpc[i] >> x[i];

    Shrink row(tmpr), col(tmpc);

    vector<int> r = row.get_array(tmpr);
    vector<int> c = col.get_array(tmpc);

    n = n+1;
    vector<ll> csum(n), rsum(n);
    map<pair<int,int>, ll> mp;
    for ( int i = 0; i < n-1; ++i ) {
        csum[c[i]] += x[i];
        rsum[r[i]] += x[i];
        mp[make_pair(r[i],c[i])] = x[i];
        // printf("r = %d, c = %d\n", r[i], c[i]);
    }

    vector<int> cord(n);
    for ( int i = 0; i < n; ++i ) cord[i] = i;
    sort(cord.begin(), cord.end(), [&csum](int a, int b) {
        return csum[a] > csum[b];
    });

    ll ans = 0;
    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < n; ++j ) {
            int nc = cord[j];
            ans = max(ans, rsum[i]+csum[nc]-mp[make_pair(i, nc)]);
            // printf("r = %d, c = %d, ans = %d\n", i, nc, ans);
            if ( mp[make_pair(i,nc)] == 0 ) break;
        }
    }

    cout << ans << endl;
}