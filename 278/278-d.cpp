#include<iostream>
#include<vector>
#include<utility>
#include<map>


using namespace std;
using ll = long long;

using pii = pair<int,int>;

int main()
{
   int n, q;
   pii allv = make_pair(0, -2);
   map<int,ll> mp;
   vector<ll> a;

   cin >> n;
   for ( int i = 0; i < n; ++i ) {
    int tmpa; cin >> tmpa;
    a.push_back(tmpa);
   } 

   cin >> q;
   for ( int i = 0; i < q; ++i ) {
    int cmd; cin >> cmd;
    if ( cmd == 1 ) {
        int x; cin >> x;
        allv = make_pair(x, i);
        mp = map<int,ll>(); 
    }
    if ( cmd == 2 ) {
        int j, x; cin >> j >> x;
        --j;
        if ( mp.find(j) == mp.end() ) mp[j] = 0;
        mp[j] += x;
    }
    if ( cmd == 3 ) {
        int j;
        cin >> j; --j;
        ll ans;
        if ( allv.second >= 0 ) ans = allv.first;
        else ans = a[j];
        if ( mp.find(j) != mp.end() ) ans += mp[j];
        cout << ans << endl; 
    }
   }
}