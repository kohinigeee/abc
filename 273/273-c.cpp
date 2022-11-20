#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;
using ll = long long;

int main()
{
    set<ll> s;
    ll n;
    vector<ll> a;
    vector<ll> b;
    vector<ll> c;
    vector<ll> ans;

    cin >> n;
    a = vector<ll>(n);
    for ( auto& v : a ) cin >> v;
    for ( auto& v : a ) s.insert(v);


    for ( auto it = s.begin(); it != s.end(); ++it ) {
        b.push_back(*it);
    }

    for ( auto v : a ) {
        auto it = lower_bound(b.begin(), b.end(), v);
        ll tmpn = (b.end()-it-1);
        // cout << "tmpn = " << tmpn << endl;

        c.push_back(tmpn);
    }

    ans = vector<ll>(n, 0);

    for ( auto v : c ) ans[v] += 1;
    for ( auto v : ans ) cout << v << endl;
}