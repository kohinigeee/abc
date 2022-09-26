#include<iostream>
#include<vector>
#include<cstdio>

#define N 100

using namespace std;
using ll = long long;

double dp[N+1][6];


int main()
{
    int n;

    cin >> n;
    for ( int i = 0; i <= n; ++i ) {
        for ( int j = 0; j < 6; ++j ) dp[i][j] = 0;
    }

    for ( int i = 0; i < 6; ++i ) dp[N-1][i] = 3.5;
    for ( int i = N-2; i >= N-n; --i ) {
        double e = 0;
        for ( int j = 0; j < 6; ++j ) e += dp[i+1][j];
        e /= 6;

        for ( int j = 0; j < 6; ++j ) {
            if ( (j+1) < e ) dp[i][j] = e;
            else dp[i][j]= j+1;
        }
    }

    double ans = 0;
    for ( int i = 0; i < 6; ++i ) ans += dp[N-n][i];
    printf("%.15f\n", ans/6);
}