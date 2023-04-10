#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    vector<int> ok(w+1, 0);

    for ( int i = 0; i < n; ++i ) cin >> a[i];

    long long ans = 0;    
    for ( int i = 0; i < n; ++i ) {
        int tmp1 = a[i];
        if ( tmp1 > w ) continue;
        if ( ok[tmp1] == 0 ) {
            ++ans; ok[tmp1] = 1;
        } 
        for ( int j = i+1; j < n; ++j ) {
            int tmp2 = tmp1+a[j];
            if ( tmp2 > w ) continue;
            if ( ok[tmp2] == 0 ) {
                ++ans; ok[tmp2] = 1;
            }
            for ( int k = j+1; k < n; ++k ) {
                int tmp3 = tmp2+a[k];
                if ( tmp3 > w ) continue;
                if ( ok[tmp3] == 0 ) {
                    ++ans;
                    ok[tmp3] = 1;
                }
            }
        }
    }

    cout << ans << endl;
}