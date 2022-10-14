#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

ll findm(vector<int> vec ) {
    int cnt = 1;
    ll v = vec[0];

    for ( int i = 1; i < vec.size(); ++i ) {
        if ( v == vec[i] ) { ++cnt; continue; }
        if ( cnt == 0 ) { v = vec[i]; ++cnt; }
        else --cnt;
    }
    
    cnt = 0;
    int border = vec.size()/2+1;

    for ( const auto& x : vec ) if ( v == x ) ++cnt;
    return ( cnt >= border ) ? v : -1; 
}

int main()
{
    vector<int> d;

    int maxv = 0;

    int n;
    int ans = -1;
    
    cin >> n;
    d = vector<int>(n);
    for ( auto& v : d ) cin >> v;

    for ( auto v : d ) if ( maxv < v ) maxv = v;

    for ( int i = 3; i <= maxv; ++i ) {
        vector<int> tmp = d;
        for ( auto& v : tmp ) v %= i;
        ll m = findm(tmp);
        if ( m != -1 ) ans = i;

    }

    // ll m = findm(d);

    cout << ans << endl;
}