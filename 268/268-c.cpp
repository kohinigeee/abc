#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> p;
    vector<int> d;
    vector<int> sum;

    int n;
    cin >> n;
    p = vector<int>(n);
    d = vector<int>(n);

    for ( int i = 0; i < n; ++i ) {
        cin >> p[i];
        if ( p[i] >= i ) {
            d[p[i]] = p[i]-i;
        } else {
            d[p[i]] = n-i+p[i];
        }
    }

    // for ( int i = 0; i < n; ++i ) cout << d[i] << endl;

    sum = vector<int>(n+1);
    for ( int i = 0; i < n; ++i ) {
        int tmpd = d[i]-1;
        if ( d[i] == 0 ) tmpd = n-1;
        sum[tmpd] += 1;
        sum[d[i]] += 1;
        sum[d[i]+1] += 1;
    }

    // cout << endl;
    int ans = 0;
    for ( int i = 0; i < n; ++i ) {
        ans = max(sum[i], ans);
    }
    cout << ans << endl;
}