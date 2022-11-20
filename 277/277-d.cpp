#include<iostream>
#include<vector>
#include<map>

using namespace std;
using ll = long long;

int main()
{
    vector<int> q;
    ll vsum = 0;

    map<int,int> mp;
    int n, m;

    cin >> n >> m;
    for ( int i = 0; i < n; ++i ) {
        int tmp; cin >> tmp;
        vsum += tmp;
        if ( mp.find(tmp%m) == mp.end() ) mp[tmp%m] = 0;
        mp[tmp%m] += 1;
    }


    while(q.size() < n ) {
        auto it = mp.begin();
        while( it != mp.end() ) {
            q.push_back(it->first);
            it->second -= 1;
            if ( it->second == 0 ) mp.erase(it->second);
            ++it;
        }
    }

    vector<int> tmp = q;
    for ( auto v : tmp ) q.push_back(v);

    int l = 0, r = 0;
    ll sum = 0;
    ll ans = 0;
   
    while ( l < n ) {
        r = l;
        sum = q[l];
        while( q[r+1]%m == (q[r]+1)%m ) {
            sum += q[r];
            r++;
            if ( l-r >= n ) break;
        }
        ans = max(ans, sum);
        l = r+1;
    }

    cout << vsum-ans << endl; 
}