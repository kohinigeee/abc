#include<iostream>
#include<vector>
#include<string>

using namespace std;
using ll = long long;

int main()
{
    ll n;
    ll c[10];
    ll cnt[10];

    int mini = 1;

    cnt[0] = 0;
    cin >> n;
    for ( int i = 0; i < 9; ++i ) {
        cin >> c[i+1]; cnt[i+1] = 0;
    }

    for ( int i = 2; i < 10; ++i ) {
        if ( c[i] <= c[mini] ) mini = i;
    }

    cnt[mini] = n/c[mini];
    n = n-c[mini]*cnt[mini];

    // cout << "mini = " << mini << endl;
    // for ( int i = 1; i < 10; ++i ) cout << cnt[i] << " "; cout <<endl;

    for ( int i = 9; i > mini; --i ) {
        // cout << endl;
        // cout << "i = " << i << endl;

        int tmp = c[i]-c[mini];
        int tmp_cnt = n/tmp;

        cnt[i] += tmp_cnt;
        cnt[mini] -= tmp_cnt;
        n = n-tmp*tmp_cnt;

        // cout << "n = " << n << endl;
        // for ( int i = 1; i < 10; ++i ) cout << cnt[i] << " "; cout <<endl;
    }

    string ans;

    for ( int i = 9; i > 0; --i ) {
        if ( cnt[i] == 0 ) continue;
        string tmp(cnt[i], i+'0');
        ans += tmp;
    }

    cout << ans << endl;
}