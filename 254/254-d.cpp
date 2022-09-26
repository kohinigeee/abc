#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

using vi = vector<int>;

int main()
{
    vi f, cnt;
    int n;
    long long ans = 0;

    cin >> n;
    f = vi(n+1, 1);
    cnt = vi(n+1, 0);

    for ( int i = 2; i <= n; ++i ) {
        if ( i*i > n ) break;
        int tmp = i*i;
        for ( int j = tmp; j <= n; j += tmp ) {
            f[j] = tmp;
        }
    }

    for ( int i = 1; i <= n; ++i ) {
        f[i] = i/f[i];
        cnt[f[i]] += 1;
    }

    for ( int i = 1; i <= n; ++i ) {
        ans += cnt[i]*cnt[i];
    }

    cout << ans << endl;
}