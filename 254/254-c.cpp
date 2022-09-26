#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

using vi  = vector<int>;
using vvi = vector<vi>;

int main()
{
    vvi v;
    int n, k;
    int maxv = 0;

    cin >> n >> k;
    v = vvi( k, vi());

    for ( int i = 1; i <= n; ++i ) {
        int tmp; cin >> tmp;
        v[i%k].push_back(tmp);
    }

    vi idx(k, 0);
    for ( int i = 0; i < k; ++i ) sort(v[i].begin(), v[i].end());
    for ( int i = 1; i <= n; ++i ) {
        int tmp = v[i%k][idx[i%k]++];
        if ( tmp < maxv ) {
            cout << "No" << endl;
            return 0;
        }
        else maxv = tmp;
    }

    cout << "Yes" << endl;
}