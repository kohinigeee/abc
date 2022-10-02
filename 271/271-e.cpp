#include<iostream>
#include<vector>
#include<algorithm>

#define INF (1LL<<60)

using ll = long long;

class Edge {
    public:
    ll s, t, c;

    Edge( ll s, ll t, ll c ) : s(s), t(t), c(c) {}
};

using namespace std;

int main()
{
    vector<Edge> v;
    vector<ll> d;

    ll n, m, k;

    cin >> n >> m >> k;

    d = vector<ll>(n, INF);
    d[0] = 0;
    for ( int i = 0; i < m; ++i ) {
        ll a, b, c;
        cin >> a >> b >> c; --a; --b;
        v.push_back(Edge(a,b,c));
    }

    for ( int i = 0; i < k; ++i ) {
        int no; cin >> no; --no;
        Edge e = v[no];

        if ( d[e.s] == INF ) continue;
        d[e.t] = min(d[e.s]+e.c, d[e.t]);
    }

    if ( d[n-1] == INF ) cout << -1 << endl;
    else cout << d[n-1] << endl;
}
