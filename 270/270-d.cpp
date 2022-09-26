#include<iostream>
#include<vector>
#include<utility>

using namespace std;
using ll = long long;

using vi = vector<int>;
using DP = vector<pair<ll,int>>; //second はとる個数

int n, k;
DP taka, aoki;
vi a;

int main()
{
    cin >> n >> k;

    for ( int i = 0; i < k; ++i ) {
        int tmpa; cin >> tmpa;
        a.push_back(tmpa);
    }

    taka = DP( n+1, make_pair(0,0));
    aoki = DP( n+1, make_pair(0,0));


    for ( int i = 1; i <= n; ++i ) {
        for ( auto av : a ) {
            if ( av > i ) continue;
            ll tmpsum = 0;
            tmpsum = av;
            ll take_aoki = aoki[i-av].second;
            tmpsum += taka[i-av-take_aoki].first;
            if ( taka[i].first < tmpsum ) {
                taka[i] = make_pair(tmpsum, av);
            }
        }

         for ( auto av : a ) {
            if ( av > i ) continue;
            ll tmpsum = 0;
            tmpsum = av;
            ll take_taka = taka[i-av].second;
            tmpsum += aoki[i-av-take_taka].first;
            if ( aoki[i].first < tmpsum ) {
                aoki[i] = make_pair(tmpsum, av);
            }
        }
    }

    cout << taka[n].first << endl;

    // for ( auto v : taka ) cout << "( " << v.first << ", " << v.second << ") ";
    // cout << endl;

    //  for ( auto v : aoki) cout << "( " << v.first << ", " << v.second << ") ";
    // cout << endl;
}