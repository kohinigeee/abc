#include<iostream>
#include<vector>
#include<set>

using ll = long long;
using namespace std;

const ll maxv = 1000000000;

auto biset(multiset<ll>& s, int k ) {
    ll no = 0;
    ll ok = maxv;

    while( ok - no > 1 ) {
        ll mid = (no+ok)/2;
        int idx = distance(s.begin(), s.upper_bound(mid));
        if ( idx >= k ) ok = mid;
        else no = mid;
    }

    return ok;
}

int main()
{
    int n, m, k;

    cin >> n >> m >> k;
    vector<ll> a(n);

    for ( int i = 0; i < n; ++i ) cin >> a[i];

    ll ans = 0;
    multiset<ll> s;
    for ( int i = 0; i < m; ++i ) {
        s.insert(a[i]);
    }
    s.insert(maxv+5000);

    auto it = s.begin();
    for ( int i = 0; i < k; ++i ) {
        ans += *(it);
        ++it;
    }

    vector<ll> results;

    results.push_back(ans);
    int l = 0;
    int r = m;

    auto bki = s.begin();
    for ( int i = 0; i < k-1; ++i ) {
        ++bki;
    }

    while( r < n) {
        ll bk = *bki;
        // printf("a[l] = %d, a[r] = %d, b[k] = %d\n", a[l], a[r], bk);
        auto ei = s.find(a[l]);
        if ( a[l] > bk ) {
            s.erase(ei);
            s.insert(a[r]);
            if ( a[r] < bk ) {
                --bki;
                ans = ans-bk+a[r];
            } 
        } else if ( a[l] < bk ) {
            ++bki;
            ll bk1 = *(bki); --bki;
            // printf("b[k+1] = %d\n", bk1);
            s.erase(ei);
            s.insert(a[r]);
            if ( a[r] < bk ) {
                ans = ans-a[l]+(a[r]);
            }
            else {
                ++bki;
                ans = ans-a[l]+(*bki);
            }
        } else {
            if ( a[r] < bk ) {
                ans = ans-a[l]+a[r];
                s.insert(a[r]);
                --bki;
            } else {
                s.insert(a[r]);
                ++bki;
                ans = ans-a[l]+(*bki);
            }
            s.erase(ei);
        }
        results.push_back(ans);

        ++l;
        ++r;
    }

    for ( auto v : results ) cout << v << " "; cout << endl;
}