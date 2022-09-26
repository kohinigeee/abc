#include<iostream>
#include<utility>
#include<vector>

using namespace std;

using ll = long long;
using pll = pair<ll,ll>;

ll gaiseki ( pair<ll,ll>& p1, pair<ll,ll>& p2) {
    return p1.first*p2.second - p1.second*p2.first;
}


int main()
{
    vector<pll> points;


    for ( int i = 0; i < 4; ++i ) {
        ll x, y; cin >> x >> y;
        points.push_back(make_pair(x,y));
    }

    for ( int i = 0; i < 4; ++i ) {
        pair<ll,ll> p1 = points[i], p2 = points[(i+1)%4], p3 = points[(i+2)%4];

        pll v1 = make_pair(p2.first-p1.first, p2.second-p1.second);
        pll v2 = make_pair(p3.first-p1.first, p3.second-p1.second);

        ll gai = gaiseki(v1,v2);
        if ( gai < 0 ) { cout << "No" << endl; return 0; }
    }

    cout << "Yes" << endl;
}