#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;
using ll = long long;

map<ll, vector<ll>> mapx; //同一x座標上のマス
map<ll, vector<ll>> mapy; //同一y座標上のマス
//行がy , 列がx

ll h, w;
ll n;
ll rs, cs;
ll q;

int main()
{

    cin >> h >> w >> rs >> cs;
    cin >> n;

    for ( int i = 0; i < n; ++i ) {
        ll r, c;
        cin >> r >> c;
        if ( mapx.find(c) == mapx.end() ) { mapx[c] = vector<ll>(); }
        mapx[c].push_back(r);
        if ( mapy.find(r) == mapy.end() ) { mapy[r] = vector<ll>(); }
        mapy[r].push_back(c);
    }

    for ( auto it = mapx.begin(); it != mapx.end(); ++it ) sort(it->second.begin(), it->second.end());
    for ( auto it = mapy.begin(); it != mapy.end(); ++it ) sort(it->second.begin(), it->second.end());

    cin >> q;
    while(q--) {
        char d; ll l;
        bool f = true;

        cin >> d >> l;

        if ( d == 'L' ) {
            ll move = l;
            if ( mapy.find(rs) != mapy.end() ) {
                vector<ll>& vec = mapy[rs];
                if ( vec[0] <= cs ) {
                    ll wall = *(--lower_bound(vec.begin(), vec.end(), cs));
                    cs = max(wall+1, cs-l);
                    l = 0;
                }
            }
            cs = max(1LL, cs-l);
        } else if ( d == 'R' ) {
            ll move = l;
            if ( mapy.find(rs) != mapy.end() ) {
                vector<ll>& vec = mapy[rs];
                if ( vec.back() > cs ) {
                    ll wall = *(lower_bound(vec.begin(), vec.end(), cs));
                    cs = min(wall-1, cs+l);
                    l = 0;
                }
            }
            cs = min(w, cs+l);
        } else if ( d == 'D' ) {
            ll move = l;
            if ( mapx.find(cs) != mapx.end() ) {
                vector<ll>& vec = mapx[cs];
                if ( vec.back() > rs ) {
                    ll wall = *(lower_bound(vec.begin(), vec.end(), rs));
                    rs = min(wall-1, rs+l);
                    l = 0;
                }
            }
            rs = min(h, rs+l);
        } else if ( d == 'U' ) {
            ll move = l;
            // cout << "U" << endl;
            if ( mapx.find(cs) != mapx.end() ) {
                vector<ll>& vec = mapx[cs];
                // cout << "vec :";
                // for ( auto v : vec ) cout << v << " "; cout << endl;
                if ( vec[0] < rs ) {
                    auto it = (--lower_bound(vec.begin(), vec.end(), rs));
                    ll wall = *it;
                    // cout << "wall =" << wall << endl;
                    rs = max(wall+1, rs-l);
                    l = 0;
                }
            }
            rs = max(1LL, rs-l);
        }

        cout << rs << " " << cs << endl;
    }
}