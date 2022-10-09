#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main()
{
    long long n, m;
    vector<long long> a;
    vector<vector<long long>> manu;

    cin >> n >> m;
    for ( long long i = 0; i < n; ++i ) {
        long long tmp; cin >> tmp;
        a.push_back(tmp);
    }

    manu = vector<vector<long long>>(m+1);

    for ( long long i = 0; i < n; ++i ) {
        long long v = a[i];
        long long sm = 0;

        if ( v < 0 ) {
            sm = (-v)/(i+1);
            v += sm*(i+1);
        }

        if ( v < 0 ) {
            v += (i+1);
            ++sm;
        }
        if( sm <= m ) manu[sm].push_back(v);
        for ( long long j = sm+1; j <= m; ++j ) {
            v += (i+1);
            if ( v > n ) break;
            manu[j].push_back(v);
        }
    }

    for ( long long i = 1; i <= m; ++i ) {
        vector<long long> exist(manu[i].size()+1);
        for ( auto v: manu[i]) {
            if ( v < exist.size() ) exist[v] = 1;
        }
        long long rem = 0;
        while(exist[rem]) ++rem;
        cout << rem << endl;
    }
}