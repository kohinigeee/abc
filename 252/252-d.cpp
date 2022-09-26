#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

ll func(int no, vector<int>& a ) {
    ll ans = 0;
    for ( int i = no+1; i < a.size(); ++i ) {
        for ( int j = i+1; j < a.size(); ++j ) {
            if ( a[no] == a[i] ) continue;
            if ( a[no] == a[j] ) continue;
            if ( a[i] == a[j] ) continue;
            ans += 1;
        }
    }

    return ans;
}

int main()
{
    int n;
    vector<int> a;
    vector<int> cnt;
    ll pairs = 0;
    ll ans = 0;

    cin >> n;
    a = vector<int>(n, 0);
    cnt = vector<int>(200000+1, 0);

    for ( int i = 0; i < n; ++i ) {
        cin >> a[i];
        cnt[a[i]] += 1;
    }

    for ( auto i : cnt ) pairs += ll(i)*(i-1)/2;

    for ( int i = 0; i < n; ++i ) {
        // cout << endl;
        ll x = a[i];
        pairs -= ll(cnt[x])*(cnt[x]-1)/2;
        cnt[x] -= 1;
        ll pairx = ll(cnt[x])*(cnt[x]-1)/2;
        pairs += pairx;

        // cout << "pairsx = " << pairx << endl;

        ll s = (n-i-1);
        ll tmp = pairs+ll(cnt[x])*(s-cnt[x]);
        ans += s*(s-1)/2-tmp;

        // cout << "a[i] = " << a[i] << ", tmp = " << s*(s-1)/2-tmp << ", func = " << func(i, a) << endl;
    }

    cout << ans << endl;
}