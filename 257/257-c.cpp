#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
using ll = long long;

int main()
{
    string tmp;
    int n;

    vector<ll> chil;
    vector<ll> adal;

    cin >> n;
    cin >> tmp;
    for ( int i = 0; i < n; ++i ) {
        ll w; cin >> w;
        if ( tmp[i] == '0' ) chil.push_back(w);
        else adal.push_back(w);
    }

    sort(chil.begin(), chil.end());
    sort(adal.begin(), adal.end());
    ll ans = max(chil.size(), adal.size());
}